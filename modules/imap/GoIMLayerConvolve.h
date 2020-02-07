/**
 * Definition for calculating the covolution wrapper class of InfluenceMap Layer.
 **/

#ifndef IMAP_IMAP_CONVOLVE
#define IMAP_IMAP_CONVOLVE

#include "imap_lib/IMLayerConvolve.h"

class GoIMLayerConvolve : public GoIMLayer {
	GDCLASS(GoIMLayerConvolve, GoIMLayer);

public:
	GoIMLayerConvolve() {
		this->layer = new IMLayerConvolve();
		this->cast_layer = (IMLayerConvolve*) this->layer;
	}

	void set_inputs(Ref<GoIMLayer> input, Ref<GoIMLayer> kernel) {
		this->cast_layer->set_inputs(input->layer, kernel->layer);
	}
	
	double get_value_at(int x, int y) {
		return this->cast_layer->get_value_at(x, y);
	}

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("set_inputs", "input", "kernel"), &GoIMLayerConvolve::set_inputs);
	}

private:
	IMLayerConvolve* cast_layer;
};

#endif //IMAP_IMAP_CONVOLVE