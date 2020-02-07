/**
 * Definition for the draw Layer wrapper class of InfluenceMap Layer.
 **/

#ifndef GO_IM_LAYER_DRAW_H
#define GO_IM_LAYER_DRAW_H

#include "imap_lib/IMLayerDraw.h"
#include "GoIMLayer.h"

class GoIMLayerDraw : public GoIMLayer {
	GDCLASS(GoIMLayerDraw, GoIMLayer);

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("draw_point", "x", "y", "value"), &GoIMLayerDraw::draw_point);
		ClassDB::bind_method(D_METHOD("draw_rect", "x1", "y1", "x2", "y2", "value"), &GoIMLayerDraw::draw_rect);
	}

	int index(int x, int y) const { return x + width * y; }
public:
	GoIMLayerDraw() {
		this->layer = new IMLayerDraw();
		this->cast_layer = (IMLayerDraw*) this->layer;
	}

	void init(int start_x, int start_y, int width, int height) {
		this->cast_layer->init(start_x, start_y, width, height);
	}

	void set_dimens(int width, int height) {
		this->cast_layer->set_dimens(width, height);
	}

	void draw_point(int x, int y, double value) {
		this->cast_layer->draw_point(x, y, value);
	}
	void draw_rect(int x1, int y1, int x2, int y2, double value) {
		this->cast_layer->draw_rect(x1, y1, x2, y2, value);
	}

	double get_value_at(int x, int y) {
		return this->cast_layer->get_value_at(x, y);
	}
private:
	IMLayerDraw* cast_layer;
};

#endif // GO_IM_LAYER_DRAW_H