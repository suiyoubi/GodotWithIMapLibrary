//
// Created by Ao on 2020-02-04.
//

#ifndef LAYERED_INFLUENCE_MAP_IMLAYERCONVOLVE_H
#define LAYERED_INFLUENCE_MAP_IMLAYERCONVOLVE_H


#include "IMLayer.h"

class IMLayerConvolve : public IMLayer {

public:
    IMLayerConvolve();

    void set_inputs(IMLayer* input, IMLayer* kernel);
    double get_value_at(int x, int y);

private:
    IMLayer* input;
    IMLayer* kernel;
};


#endif //LAYERED_INFLUENCE_MAP_IMLAYERCONVOLVE_H
