#include "imlayer_point.h"

#include <stdlib.h>
#include <algorithm>

IMLayerPointSource::IMLayerPointSource() {
}

void IMLayerPointSource::_bind_methods() {
	ClassDB::bind_method(D_METHOD("init", "x", "y", "width", "height"), &IMLayerPointSource::init);
	ClassDB::bind_method(D_METHOD("set_offset", "x", "y"), &IMLayerPointSource::set_offset);
	ClassDB::bind_method(D_METHOD("set_dimens", "width", "height"), &IMLayerPointSource::set_dimens);
	ClassDB::bind_method(D_METHOD("get_value_at", "x", "y"), &IMLayerPointSource::get_value_at);
}

void IMLayerPointSource::init(int start_x, int start_y, int width, int height) {
	set_offset(start_x, start_y);
	set_dimens(width, height);
}

void IMLayerPointSource::set_dimens(int width, int height) {
	IMLayer::set_dimens(width, height);

	values = std::vector<std::vector<float> >(width, std::vector<float>(height));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			values[y][x] = std::max(width, height) - std::abs((x - width / 2) + (y - height / 2));
		}
	}
}

float IMLayerPointSource::get_value_at(int x, int y) {
	int rel_x = x - this->start_x;
	int rel_y = y - this->start_y;

	if (rel_x >= 0 && rel_x < this->width && rel_y >= 0 && rel_y < this->height) {
		return values[y][x];
	} else {
		return 0;
	}
}