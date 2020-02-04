/**
 * Definition for a point source IM layer
 **/

#ifndef IMAP_IMAP_POINT
#define IMAP_IMAP_POINT

#include <vector>

#include "imlayer.h"

class IMLayerPointSource : public IMLayer {
	GDCLASS(IMLayerPointSource, IMLayer);

public:
	IMLayerPointSource();

	void init(int start_x, int start_y, int width, int height);
	void set_dimens(int width, int height);

	float get_value_at(int x, int y);

protected:
	static void _bind_methods();

private:
	std::vector<std::vector<float> > values;
};

#endif //IMAP_IMAP_POINT