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
    QImage image;

    *data >> width;
    *data >> height;
    *data >> depth;
    *data >> length;
    *data >> type;
    *data >> mapType;
    *data >> mapLength;

//    qDebug() << width;
//    qDebug() << height;
//    qDebug() << depth;
//    qDebug() << length;
//    qDebug() << type;
//    qDebug() << mapType;
//    qDebug() << mapLength;

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

    char *color_palette = new char[mapLength];
    data->readBytes(color_palette, mapLength);

    quint8 *scanline = nullptr;

    try {
        quint8 p = 0;
        scanline = new quint8(static_cast<quint8>(width) + 1);

        for (qint32 y = 0; y < height; y++) {
            for (qint32 i = 0; i < width; i++) {
                scanline[i] = static_cast<quint8>(readRawByte());
            }

            if (width % 2 == 1) {
                readRawByte();
            }

            if (mapType > 0 and mapLength == 768) {
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
    } catch (QException e) {
        qDebug() << "Could not read RAS file!";
        return nullptr;
    }

    qDebug() << "bmp_data" << bmp_data[1];

    QPixmap *pixmap = new QPixmap(width, height);
//    pixmap->loadFromData(bmp_data, sizeof(&bmp_data), nullptr, Qt::AutoColor);

    qDebug() << pixmap;

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
