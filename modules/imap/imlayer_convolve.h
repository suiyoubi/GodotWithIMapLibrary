/**
 * Definition for a point source IM layer
 **/

#ifndef IMAP_IMAP_CONVOLVE
#define IMAP_IMAP_CONVOLVE

#include <vector>

#include "imlayer.h"

class IMLayerConvolve : public IMLayer {
	GDCLASS(IMLayerConvolve, IMLayer);

public:
	IMLayerConvolve();

	void set_inputs(Ref<IMLayer> input, Ref<IMLayer> kernel);
	double get_value_at(int x, int y);

protected:
	static void _bind_methods();

private:
	Ref<IMLayer> input;
	Ref<IMLayer> kernel;
};

#endif //IMAP_IMAP_CONVOLVE