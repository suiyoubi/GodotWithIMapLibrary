#include "imlayer.h"

IMLayer::IMLayer() {
}

void IMLayer::init(int x, int y, int width, int height) {
	set_offset(x, y);
	set_dimens(width, height);
}

void IMLayer::set_offset(int x, int y) {
	this->x = x;
	this->y = y;
}

void IMLayer::set_dimens(int width, int height) {
	this->width = width;
	this->height = height;
}

float IMLayer::get_value_at(int x, int y) {
	return 0;
}