/**
 * Definition for a point source IM layer
 **/

#ifndef IMAP_IMAP_POINT
#define IMAP_IMAP_POINT

#include "imlayer.h"

class IMLayerPointSource : public IMLayer {
public:
	GDCLASS(IMLayerPointSource, Reference);

	IMLayerPointSource();

	float get_value_at(int x, int y);

	void add_source(int id, int x, int y);
	void move_source(int id, int x, int y);
	void remove_source(int id, int x, int y);

protected:
	static void _bind_methods();
};

#endif //IMAP_IMAP_POINT