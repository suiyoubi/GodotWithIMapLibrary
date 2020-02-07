/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"

#include "GoIMLayer.h"
#include "GoIMLayerDraw.h"
#include "GoIMLayerAdd.h"
// #include "imlayer_convolve.h"
// #include "imlayer_draw.h"
// #include "imlayer_point.h"

void register_imap_types() {
	ClassDB::register_virtual_class<GoIMLayer>();
	ClassDB::register_class<GoIMLayerDraw>();
	// ClassDB::register_class<IMLayerPointSource>();
	//ClassDB::register_class<GoIMLayerAdd>();
	// ClassDB::register_class<IMLayerConvolve>();
}

void unregister_imap_types() {
	// Nothing to do here in this example.
}
