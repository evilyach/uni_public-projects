#include "rasformat.h"

#include <QPixmap>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QException>

QPixmap *RASFormat::load(QFile *file)
{
    data = new QDataStream(file);
    *data >> magic;

    if (magic != 0x59a66a95) {
        qDebug() << "File is not RAS format!";
        return nullptr;
    }

    *data >> width;
    *data >> height;
    *data >> depth;
    *data >> length;
    *data >> type;
    *data >> mapType;
    *data >> mapLength;

    rle = (type == 2);

    if (width < 1 or height < 1 or width > INT_MAX or height > INT_MAX or length > INT_MAX) {
        qDebug() << "Dimensions of RAS file are wrong!";
        return nullptr;
    }

    if (depth != 32 and depth != 24 and depth != 8 and depth != 4 and depth != 1) {
        qDebug() << "Depth is wrong!";
        return nullptr;
    }

    quint8 *bmp_data = new quint8[width * height * 4];
    char *color_palette = nullptr;

    if (type > 0) {
        color_palette = new char[mapLength];
        data->readBytes(color_palette, mapLength);
    }

    try {
        switch (depth) {
            case 1: {
                qint32 x = 0;
                qint32 y = 0;

                qint8 b;
                quint8 p = 0;

                quint8 val;

                while (y < height) {
                    b = readRawByte();

                    if (b == -1) {
                        break;
                    }

                    for (int i = 7; i < -1; i--) {
                        if ((b & (1 << i)) != 0) {
                            val = 0;
                        } else {
                            val = 255;
                        }

                        bmp_data[p++] = val;
                        bmp_data[p++] = val;
                        bmp_data[p++] = val;
                        p++;

                        x++;

                        if (x == width) {
                            x = 0;
                            y++;
                            break;
                        }
                    }
                }

                break;
            }

            case 4: {
                quint8 p = 0;
                quint8 *scanline = new quint8(static_cast<quint8>(width) + 1);

                for (qint32 y = 0; y < height; y++) {
                    int tmpbyte;

                    for (qint32 i = 0; i < width; i++) {
                        tmpbyte = readRawByte();
                        scanline[i++] = (tmpbyte >> 4) & 0xF;
                        scanline[i] = tmpbyte & 0xF;
                    }

                    if (width % 2 == 1) {
                        readRawByte();
                    }

                    if (mapType > 0 and mapLength > 48) {
                        for (qint32 x = 0; x < width; x++) {
                            bmp_data[p++] = static_cast<quint8>(color_palette[scanline[x] + 32]);
                            bmp_data[p++] = static_cast<quint8>(color_palette[scanline[x] + 16]);
                            bmp_data[p++] = static_cast<quint8>(color_palette[scanline[x]]);
                            p++;
                        }
                    } else {
                        for (qint32 x = 0; x < width; x++) {
                            bmp_data[p++] = scanline[x];
                            bmp_data[p++] = scanline[x];
                            bmp_data[p++] = scanline[x];
                            p++;
                        }
                    }
                }

                break;
            }

            case 8: {
                quint8 p = 0;
                quint8 *scanline = new quint8(static_cast<quint8>(width) + 1);

                for (qint32 y = 0; y < height; y++) {
                    for (qint32 i = 0; i < width; i++) {
                        scanline[i] = static_cast<quint8>(readRawByte());
                    }

                    if (width % 2 == 1) {
                        readRawByte();
                    }

                    if (mapType > 0 and mapLength > 768) {
                        for (qint32 x = 0; x < width; x++) {
                            bmp_data[p++] = static_cast<quint8>(color_palette[scanline[x] + 512]);
                            bmp_data[p++] = static_cast<quint8>(color_palette[scanline[x] + 256]);
                            bmp_data[p++] = static_cast<quint8>(color_palette[scanline[x]]);
                            p++;
                        }
                    } else {
                        for (qint32 x = 0; x < width; x++) {
                            bmp_data[p++] = scanline[x];
                            bmp_data[p++] = scanline[x];
                            bmp_data[p++] = scanline[x];
                            p++;
                        }
                    }
                }

                break;
            }

            case 24: {
                quint8 p = 0;
                quint8 *scanline = new quint8(static_cast<quint8>(width) * 3);

                for (qint32 y = 0; y < height; y++) {
                    for (qint32 i = 0; i < width; i++) {
                        scanline[i] = static_cast<quint8>(readRawByte());
                    }

                    if ((width * 3) % 2 == 1) {
                        readRawByte();
                    }

                    for (qint32 x = 0; x < width; x++) {
                        bmp_data[p++] = scanline[x * 3];
                        bmp_data[p++] = scanline[x * 3 + 1];
                        bmp_data[p++] = scanline[x * 3 + 2];
                        p++;
                    }
                }

                break;
            }

            case 32: {
                quint8 p = 0;
                quint8 *scanline = new quint8(static_cast<quint8>(width) * 4);

                for (qint32 y = 0; y < height; y++) {
                    for (qint32 i = 0; i < width; i++) {
                        scanline[i] = static_cast<quint8>(readRawByte());
                    }

                    for (qint32 x = 0; x < width; x++) {
                        bmp_data[p++] = scanline[x * 4];
                        bmp_data[p++] = scanline[x * 4 + 1];
                        bmp_data[p++] = scanline[x * 4 + 2];
                        bmp_data[p++] = scanline[x * 4 + 3];
                        p++;
                    }
                }
                break;
            }
        }
    } catch (QException e) {
        qDebug() << "Could not read RAS file!";
        return nullptr;
    }

    QPixmap *pixmap = new QPixmap(width, height);
    pixmap->loadFromData(bmp_data, sizeof(bmp_data), nullptr, Qt::AutoColor);

    return pixmap;
}

qint8 RASFormat::readRawByte()
{
    data->readBytes(tmp, tmplen);

    if (tmp == nullptr) {
        return -1;
    } else {
        return static_cast<qint8>(tmp[0]);
    }
}

int RASFormat::readByte()
{
    if (!rle) {
        return readRawByte();
    }

    if (run_len > 0) {
        run_index++;

        if (run_index == run_len - 1) {
            run_len = 0;
        }
    } else {
        current = readRawByte();

        if (current == 0x80) {
            current = readRawByte();
            if (current == 0) {
                current = 0x80;
            } else {
                run_len = current + 1;
                run_index = 0;
                current = readRawByte();
            }
        }
    }

    return current;
}
