/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"

#include "imlayer.h"
#include "imlayer_add.h"
#include "imlayer_convolve.h"
#include "imlayer_draw.h"
#include "imlayer_point.h"

void register_imap_types() {
	ClassDB::register_virtual_class<IMLayer>();
	ClassDB::register_class<IMLayerDraw>();
	ClassDB::register_class<IMLayerPointSource>();
	ClassDB::register_class<IMLayerAdd>();
	ClassDB::register_class<IMLayerConvolve>();
}

void unregister_imap_types() {
	// Nothing to do here in this example.
}
