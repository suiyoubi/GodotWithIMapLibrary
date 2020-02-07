//
// Created by Ao on 2020-02-04.
//

#ifndef LAYERED_INFLUENCE_MAP_IMLAYERDRAW_H
#define LAYERED_INFLUENCE_MAP_IMLAYERDRAW_H


#include "IMLayer.h"

class IMLayerDraw : public IMLayer {

public:
    IMLayerDraw();

    void init(int start_x, int start_y, int width, int height);
    void set_dimens(int width, int height);

    void draw_point(int x, int y, double value);
    void draw_rect(int x1, int y1, int x2, int y2, double value);

    double get_value_at(int x, int y);

protected:

    int index(int x, int y) const { return x + width * y; }

    double *values;
};


#endif //LAYERED_INFLUENCE_MAP_IMLAYERDRAW_H
