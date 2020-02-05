/**
 * Definition for a point source IM layer
 **/

#ifndef IMAP_IMAP_POINT
#define IMAP_IMAP_POINT

#include <vector>

#include "imlayer_draw.h"

class IMLayerPointSource : public IMLayerDraw {
	GDCLASS(IMLayerPointSource, IMLayerDraw);

public:
	IMLayerPointSource();

	void init(int start_x, int start_y, int width, int height);
	void set_dimens(int width, int height);

protected:
	static void _bind_methods();
};

#endif //IMAP_IMAP_POINT