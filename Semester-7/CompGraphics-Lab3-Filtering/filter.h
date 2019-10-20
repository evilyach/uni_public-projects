#ifndef FILTER_H
#define FILTER_H

#include <QObject>

class Filter : public QObject
{
    Q_OBJECT

public:
    typedef enum {
        FK_3x3,
        FK_5x5,
        FK_7x7,
        FK_9x9
    } filter_kernel_t;

    void lff_blur_apply(QImage *image, filter_kernel_t mode);

private:
    double k[3][3] = {
        {0.1, 0.1, 0.1},
        {0.1, 0.2, 0.1},
        {0.1, 0.1, 0.1},
    };
};

#endif // FILTER_H
