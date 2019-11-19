#include "rasformat.h"

#include <cstdlib>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QException>


QPixmap *RASFormat::load(QFile *file)
{
    /* Loading data from file into datastream */
    data = new QDataStream(file);

    /* Reading header */
    *data >> magic;

    if (magic != 0x59a66a95) {
        qDebug() << "File is not RAS formatted!";
        return nullptr;
    }

    *data >> width;
    *data >> height;
    *data >> depth;
    *data >> length;
    *data >> type;
    *data >> mapType;
    *data >> mapLength;

    qDebug() << depth;

    /* Validating header */
    if (width < 1 or height < 1 or width > INT_MAX or height > INT_MAX or length > INT_MAX) {
        qDebug() << "Dimensions of RAS file are wrong!";
        return nullptr;
    }

    if (depth != 32 and depth != 24 and depth != 8 and depth != 4 and depth != 1) {
        qDebug() << "Depth is wrong!";
        return nullptr;
    }

    /* Preparing data structures */
    QByteArray bmp_data(width * height * 4, Qt::Initialization());

    char *color_palette = new char[mapLength];
    if (mapType > 0)
        data->readRawData(color_palette, static_cast<int>(mapLength));

    quint8 *scanline = static_cast<quint8 *>(
        malloc(sizeof(quint8) * static_cast<unsigned long>(width))
    );

    /* Parsing the image */
    try {
        qint32 p = 0;
        for (qint32 y = 0; y < height; y++) {
            for (qint32 i = 0; i < width; i++) {
                qint8 tmp = readByte();
                scanline[i] = static_cast<quint8>(tmp);
            }

            if (width % 2 == 1) {
                readByte();
            }

            if (mapType > 0 and mapLength == 768) {
                for (qint32 x = 0; x < width; x++) {
                    bmp_data.insert(p++, static_cast<char>(color_palette[scanline[x] + 512]));
                    bmp_data.insert(p++, static_cast<char>(color_palette[scanline[x] + 256]));
                    bmp_data.insert(p++, static_cast<char>(color_palette[scanline[x]]));
                    p++;
                }
            } else {
                for (qint32 x = 0; x < width; x++) {
                    bmp_data.insert(p++, static_cast<char>(scanline[x]));
                    bmp_data.insert(p++, static_cast<char>(scanline[x]));
                    bmp_data.insert(p++, static_cast<char>(scanline[x]));
                    p++;
                }
            }
        }
    } catch (QException e) {
        qDebug() << "Could not read RAS file:" << e.what();
        return nullptr;
    }

    /* Placing previously parsed data onto pixmap */
    QPixmap *pixmap = new QPixmap(width, height);
    pixmap->loadFromData(bmp_data, nullptr, Qt::AutoColor);

    free(scanline);

    return pixmap;
}


qint8 RASFormat::readByte()
{
    qint8 tmp;
    *data >> tmp;
    return tmp;
}
