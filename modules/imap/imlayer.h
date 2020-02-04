/**
 * Base Influence Map Layer declaration.
 **/

#ifndef IMAP_IMAP_H
#define IMAP_IMAP_H

#include "core/reference.h"

class IMLayer : public Reference {
public:
	IMLayer();
	virtual float get_value_at(int x, int y);
};

#endif //IMAP_IMAP_H