/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "IMap.h"

void register_imap_types() {
    ClassDB::register_class<IMap>();
}

void unregister_imap_types() {
   // Nothing to do here in this example.
}
