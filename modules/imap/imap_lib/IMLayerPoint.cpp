//
// Created by Ao on 2020-02-04.
//

#include <cmath>
#include "IMLayerPoint.h"

IMLayerPointSource::IMLayerPointSource() {
}

void IMLayerPointSource::init(int start_x, int start_y, int width, int height) {
    set_offset(start_x, start_y);
    set_dimens(width, height);
}

void IMLayerPointSource::set_dimens(int width, int height) {
    if (width != height || width % 2 != 1 || height % 2 != 1) {
        IMLayer::set_dimens(INVALID_WIDTH, INVALID_HEIGHT);
        return;
    }

    IMLayerDraw::set_dimens(width, height);

    double sigma = (width - 1) / 6.0;
    double r, s = 2.0 * sigma * sigma;

    // sum is for normalization
    double sum = 0.0;

    // generating nxn kernel
    for (int x = -width / 2; x <= width / 2; x++) {
        for (int y = -height / 2; y <= height / 2; y++) {
            r = sqrt(x * x + y * y);

            double val = (exp(-(r * r) / s)) / (M_PI * s);

            draw_point(x + width / 2, y + height / 2, val);
            sum += val;
        }
    }

    // normalising the Kernel
    for (int i = 0; i < width; ++i)
        for (int j = 0; j < height; ++j)
            draw_point(
                    i,
                    j,
                    get_value_at(i+this->start_x, j+this->start_y) / sum
                    );
}
