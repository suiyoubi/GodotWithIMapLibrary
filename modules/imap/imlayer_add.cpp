#include "imlayer_add.h"

IMLayerAdd::IMLayerAdd() {
	layers = std::vector<Ref<IMLayer> >(0);
}

void IMLayerAdd::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add_layer", "layer"), &IMLayerAdd::add_layer);
}

void IMLayerAdd::add_layer(Ref<IMLayer> layer) {
	layers.push_back(layer);
}

double IMLayerAdd::get_value_at(int x, int y) {
	int rel_x = x - this->start_x;
	int rel_y = y - this->start_y;

	if (rel_x >= 0 && rel_x < this->width && rel_y >= 0 && rel_y < this->height) {
		double result = 0;

		for (Ref<IMLayer> layer : layers) {
			result += layer->get_value_at(rel_x, rel_y);
		}

		return result;
	} else {
		return 0;
	}
}