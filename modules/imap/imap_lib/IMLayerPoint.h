//
// Created by Ao on 2020-02-04.
//

#ifndef LAYERED_INFLUENCE_MAP_IMLAYERPOINT_H
#define LAYERED_INFLUENCE_MAP_IMLAYERPOINT_H


#include <vector>

#include "IMLayerDraw.h"

class IMLayerPointSource : public IMLayerDraw {

public:
    const int INVALID_WIDTH = -1;
    const int INVALID_HEIGHT = -1;
    IMLayerPointSource();

    void init(int start_x, int start_y, int width, int height);
    void set_dimens(int width, int height);

};


#endif //LAYERED_INFLUENCE_MAP_IMLAYERPOINT_H
