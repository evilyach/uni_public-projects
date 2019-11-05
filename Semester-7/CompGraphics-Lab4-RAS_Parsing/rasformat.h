#ifndef RASFORMAT_H
#define RASFORMAT_H

#include <QDataStream>
#include <QFile>
#include <QObject>

class RASFormat : public QObject
{
    Q_OBJECT

public:
    RASFormat() {}
    QPixmap *load(QFile *file);

private:
    qint8 readRawByte();
    int readByte();

    QDataStream *data;
    bool rle;

    quint32 magic;
    qint32 width;
    qint32 height;
    qint32 depth;
    quint32 length;
    quint32 type;
    quint32 mapType;
    quint32 mapLength;

    char *tmp;
    uint tmplen = 1;

    int current = 0;
    int run_len = 0;
    int run_index = 0;
};

#endif // RASFORMAT_H
