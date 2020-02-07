//
// Created by Ao on 2020-02-04.
//

#include "IMLayerAdd.h"

IMLayerAdd::IMLayerAdd() {
    layers = std::vector<IMLayer* >(0);
}

void IMLayerAdd::add_layer(IMLayer* layer) {
    layers.push_back(layer);
}

double IMLayerAdd::get_value_at(int x, int y) {
    int rel_x = x - this->start_x;
    int rel_y = y - this->start_y;

    if (rel_x >= 0 && rel_x < this->width && rel_y >= 0 && rel_y < this->height) {
        double result = 0;

        for (IMLayer* layer : layers) {
            result += layer->get_value_at(rel_x, rel_y);
        }

        return result;
    } else {
        return 0;
    }
}

void IMLayerAdd::init(int start_x, int start_y, int width, int height) {
    IMLayer::init(start_x, start_y, width, height);
}

int IMLayerAdd::child_layer_count() {
    return static_cast<int>(this->layers.size());
}
