/**
 * Definition for a point source IM layer
 **/

#ifndef IMAP_IMAP_DRAW
#define IMAP_IMAP_DRAW

#include <vector>

#include "imlayer.h"

class IMLayerDraw : public IMLayer {
	GDCLASS(IMLayerDraw, IMLayer);

public:
	IMLayerDraw();

	void init(int start_x, int start_y, int width, int height);
	void set_dimens(int width, int height);

	void draw_point(int x, int y, double value);
	void draw_rect(int x1, int y1, int x2, int y2, double value);

	double get_value_at(int x, int y);

protected:
	static void _bind_methods();

	int index(int x, int y) const { return x + width * y; }

	double *values;
};

#endif //IMAP_IMAP_DRAW