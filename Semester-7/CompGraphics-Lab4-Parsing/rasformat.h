#ifndef RASFORMAT_H
#define RASFORMAT_H

#include <QObject>

class RASFormat
{
public:
    RASFormat();

private:
    typedef enum {
        old = 0,
        std = 1,
        rle = 2,
        rev = 3,
        tiff = 4,
        iff = 5,
        nonstd = 65536,
    } type_t;

    typedef enum {
        non = 0x00,
        rbg = 0x01,
        non_structured = 0x02
    } map_type_t;

    qint32 magic;
    qint32 width;
    qint32 height;
    qint32 depth;
    qint32 length;
    type_t type;
    map_type_t mapType;
    qint32 mapLength;
};

#endif // RASFORMAT_H
