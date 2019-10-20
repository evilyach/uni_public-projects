#include "filter.h"
#include <QDebug>

#include <QImage>
#include <QColor>

void Filter::lff_blur_apply(QImage *image, filter_kernel_t mode)
{
    for (int i = 0; i < image->width(); i++) {
        for (int j = 0; j < image->height(); j++) {
            double a = 0.0; // Alpha channel
            double r = 0.0; // Red channel
            double g = 0.0; // Green channel
            double b = 0.0; // Blue channel

            for (int d = 0; d < 3; d++) {
                double a2 = 0.0;
                double r2 = 0.0;
                double g2 = 0.0;
                double b2 = 0.0;

                for (int c = 0; c < 3; c++) {
                    if ((i - 2 + d < 0) or (i - 2 + d > image->width()) or
                        (j - 2 + c < 0) or (j - 2 + c > image->height())) {
                        continue;
                    }

                    QColor color = image->pixel(i - 2 + d, j - 2 + c);

                    a2 += color.alpha() * this->k[d][c];
                    r2 += color.red()   * this->k[d][c];
                    g2 += color.green() * this->k[d][c];
                    b2 += color.blue()  * this->k[d][c];
                }

                a += a2;
                r += r2;
                g += g2;
                b += b2;
            }

            if (a < 0) a = 0;
            if (a > 255) a = 255;

            if (r < 0) r = 0;
            if (r > 255) r = 255;

            if (g < 0) g = 0;
            if (g > 255) g = 255;

            if (b < 0) b = 0;
            if (b > 255) b = 255;

            image->setPixel(i, j, qRgba(static_cast<int>(r),
                                        static_cast<int>(g),
                                        static_cast<int>(b),
                                        static_cast<int>(a)));
        }
    }
}
