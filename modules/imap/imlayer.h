/**
 * Base Influence Map Layer declaration.
 **/

#ifndef IMAP_IMAP_H
#define IMAP_IMAP_H

#include "core/reference.h"

class IMLayer : public Reference {
	GDCLASS(IMLayer, Reference);

public:
	IMLayer();

	void init(int start_x, int start_y, int width, int height);
	void set_offset(int start_x, int start_y);
	void set_dimens(int width, int height);

	float get_value_at(int x, int y);

protected:
	int start_x;
	int start_y;
	int width;
	int height;
};

#endif //IMAP_IMAP_H