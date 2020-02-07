//
// Created by Ao on 2020-02-04.
//

#ifndef LAYERED_INFLUENCE_MAP_IMLAYERADD_H
#define LAYERED_INFLUENCE_MAP_IMLAYERADD_H

#include <vector>
#include "IMLayer.h"

class IMLayerAdd : public IMLayer{
public:
    IMLayerAdd();

    void add_layer(IMLayer* layer);

    double get_value_at(int x, int y) override;

    void init(int start_x, int start_y, int width, int height) override;

    int child_layer_count();


private:
    std::vector<IMLayer* > layers;
};


#endif //LAYERED_INFLUENCE_MAP_IMLAYERADD_H
