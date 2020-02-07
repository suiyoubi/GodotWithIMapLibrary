#ifndef GO_IM_LAYER_H
#define GO_IM_LAYER_H

#include "imap_lib/IMLayer.h"
#include "core/reference.h"

class GoIMLayer : public Reference {
	GDCLASS(GoIMLayer, Reference);

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("init", "start_x", "start_y", "width", "height"), &GoIMLayer::init);
		ClassDB::bind_method(D_METHOD("set_offset", "start_x", "start_y"), &GoIMLayer::set_offset);
		ClassDB::bind_method(D_METHOD("set_dimens", "width", "height"), &GoIMLayer::set_dimens);
		ClassDB::bind_method(D_METHOD("get_value_at", "x", "y"), &GoIMLayer::get_value_at);
	}

public:
	GoIMLayer(){
		this->layer = new IMLayer();
	}

	virtual void init(int start_x, int start_y, int width, int height) {
		set_offset(start_x, start_y);
		set_dimens(width, height);
	}
	virtual void set_offset(int start_x, int start_y) {
		this->start_x = start_x;
		this->start_y = start_y;
		this->layer->set_offset(start_x, start_y);
	}
	virtual void set_dimens(int width, int height) {
		this->width = width;
		this->height = height;
		this->layer->set_dimens(width, height);
	}

	virtual double get_value_at(int x, int y) {
		return this->layer->get_value_at(x, y);
	}

	int start_x;
	int start_y;
	int width;
	int height;

	IMLayer* layer;
};

#endif // GO_IM_LAYER_H

