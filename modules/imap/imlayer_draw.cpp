#include "imlayer_draw.h"

#include <stdlib.h>
#include <algorithm>

IMLayerDraw::IMLayerDraw() {
}

void IMLayerDraw::_bind_methods() {
	ClassDB::bind_method(D_METHOD("draw_point", "x", "y", "value"), &IMLayerDraw::draw_point);
	ClassDB::bind_method(D_METHOD("draw_rect", "x1", "y1", "x2", "y2", "value"), &IMLayerDraw::draw_rect);
}

void IMLayerDraw::init(int start_x, int start_y, int width, int height) {
	set_offset(start_x, start_y);
	set_dimens(width, height);
}

void IMLayerDraw::set_dimens(int width, int height) {
	IMLayer::set_dimens(width, height);

	values = new double[width * height];
}

void IMLayerDraw::draw_point(int x, int y, double value) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		values[index(x, y)] = value;
	}
}

void IMLayerDraw::draw_rect(int x1, int y1, int x2, int y2, double value) {
	for (int y = y1; y <= y2; y++) {
		for (int x = x1; x <= x2; x++) {
			draw_point(x, y, value);
		}
	}
}

double IMLayerDraw::get_value_at(int x, int y) {
	int rel_x = x - this->start_x;
	int rel_y = y - this->start_y;

	if (rel_x >= 0 && rel_x < this->width && rel_y >= 0 && rel_y < this->height) {
		return values[index(rel_x, rel_y)];
	} else {
		return 0;
	}
}