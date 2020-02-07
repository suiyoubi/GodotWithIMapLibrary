/**
 * Definition for the Addition Layer wrapper class of InfluenceMap Layer.
 **/

#ifndef IMAP_IMAP_ADD
#define IMAP_IMAP_ADD

#include "imap_lib/IMLayerAdd.h"
#include "GoIMLayer.h"

class GoIMLayerAdd : public GoIMLayer {
	GDCLASS(GoIMLayerAdd, GoIMLayer);

public:
	GoIMLayerAdd() {
		this->layer = new IMLayerAdd();
		this->cast_layer = (IMLayerAdd*) this->layer;
	}

	void add_layer(Ref<GoIMLayer> go_layer) {
		this->cast_layer->add_layer(go_layer->layer);
	}

	double get_value_at(int x, int y) {
		return this->cast_layer->get_value_at(x, y);
	}

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("add_layer", "layer"), &GoIMLayerAdd::add_layer);
	}
private:
	IMLayerAdd* cast_layer;
};

#endif //IMAP_IMAP_ADD