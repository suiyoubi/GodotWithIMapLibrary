//
// Created by Ao on 2020-01-28.
//

#ifndef IMAP_IMAP_H
#define IMAP_IMAP_H

#include "core/reference.h"
#include "core/print_string.h"
#include "core/math/vector2.h"
#include "InfluenceMap.h"
#include <stdio.h>

class IMap : public Reference {
private:
	GDCLASS(IMap, Reference);

    InfluenceMap* map;

    int num_grid_x;
    int num_grid_y;
    float map_length;
    float map_width;
    float relative_x;
    float relative_y;
    float grid_size_x;
    float grid_size_y;

    Vector2 coordinate_to_grid(float x, float y);
    Vector2 grid_to_coordinate(int x, int y);
public:
    // Constructors --------------------------------
    // Default constructor
    IMap();

    void initialize_default_map();
    void create_imap(int num_grid_x, int num_grid_y, float forward_max, float forward_min, float right_max, float right_min);
    void add_influence_source(int id, float x, float y, float influence_value);
    void move_influence_source(int id, float x, float y);
    float get_influence_value_at(float x, float y);


    int test_return_int_value();

protected:
	static void _bind_methods();
};


#endif //IMAP_IMAP_H
