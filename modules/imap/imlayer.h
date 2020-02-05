/**
 * Base Influence Map Layer declaration.
 **/

#ifndef IMAP_IMAP_H
#define IMAP_IMAP_H

#include "core/reference.h"

#include <iostream>
#include <string>

class IMLayer : public Reference {
	GDCLASS(IMLayer, Reference);

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("init", "start_x", "start_y", "width", "height"), &IMLayer::init);
		ClassDB::bind_method(D_METHOD("set_offset", "start_x", "start_y"), &IMLayer::set_offset);
		ClassDB::bind_method(D_METHOD("set_dimens", "width", "height"), &IMLayer::set_dimens);
		ClassDB::bind_method(D_METHOD("get_value_at", "x", "y"), &IMLayer::get_value_at);
	}

public:
	IMLayer(){};

	virtual void init(int start_x, int start_y, int width, int height) {
		set_offset(start_x, start_y);
		set_dimens(width, height);
	}
	virtual void set_offset(int start_x, int start_y) {
		this->start_x = start_x;
		this->start_y = start_y;
	}
	virtual void set_dimens(int width, int height) {
		this->width = width;
		this->height = height;
	}

	virtual double get_value_at(int x, int y) {
		return 0;
	}

	int start_x;
	int start_y;
	int width;
	int height;
};

#endif //IMAP_IMAP_H