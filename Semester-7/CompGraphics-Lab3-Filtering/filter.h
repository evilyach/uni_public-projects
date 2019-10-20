#ifndef FILTER_H
#define FILTER_H

#include <QObject>

class Filter : public QObject
{
    Q_OBJECT

public:
    typedef enum {
        FK_3x3_K1,
        FK_3x3_K2,
        FK_3x3_K3,
        FK_5x5_K1,
        FK_7x7_K1,
        FK_9x9_K1
    } filter_kernel_t;

    void lffBlurApply(QImage *image, filter_kernel_t mode);

private:
    inline int index(int width, int x, int y) const {
        return x + width * y;
    }

    inline int mid(int val) const {
        return val / 2;
    }
};

#endif // FILTER_H
