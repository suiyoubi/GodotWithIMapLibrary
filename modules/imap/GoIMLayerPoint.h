/**
 * Definition for the point Layer wrapper class of InfluenceMap Layer.
 **/

#ifndef IMAP_IMAP_POINT
#define IMAP_IMAP_POINT

#include "imap_lib/IMLayerPoint.h"

class GoIMLayerPointSource : public GoIMLayerDraw {
	GDCLASS(GoIMLayerPointSource, GoIMLayerDraw);

public:
	GoIMLayerPointSource() {
		this->layer = new IMLayerPointSource();
		this->cast_layer = (IMLayerPointSource*) this->layer;
	}

	void init(int start_x, int start_y, int width, int height) {
		this->cast_layer->init(start_x, start_y, width, height);
	}

	int get_width() {
		return this->cast_layer->width;
	}

	double get_value_at(int x, int y) {
		return this->cast_layer->get_value_at(x, y);
	}
protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("get_width"), &GoIMLayerPointSource::get_width);
	}
private:
	IMLayerPointSource* cast_layer;
};

#endif //IMAP_IMAP_POINT