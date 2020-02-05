/**
 * Definition for a point source IM layer
 **/

#ifndef IMAP_IMAP_ADD
#define IMAP_IMAP_ADD

#include <vector>

#include "imlayer.h"

class IMLayerAdd : public IMLayer {
	GDCLASS(IMLayerAdd, IMLayer);

public:
	IMLayerAdd();

	void add_layer(Ref<IMLayer> layer);

	double get_value_at(int x, int y);

protected:
	static void _bind_methods();

private:
	std::vector<Ref<IMLayer> > layers;
};

#endif //IMAP_IMAP_ADD