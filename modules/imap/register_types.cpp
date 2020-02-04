/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"

#include "imlayer_point.h"

void register_imap_types() {
	ClassDB::register_class<IMLayerPointSource>();
}

void unregister_imap_types() {
	// Nothing to do here in this example.
}
