//
// Created by Ao on 2020-01-28.
//

#include "IMap.h"

IMap::IMap() {

}

int IMap::test_return_int_value() {
	return 1;
}

void IMap::_bind_methods() {
    ClassDB::bind_method(D_METHOD("test_return_int_value"), &IMap::test_return_int_value);
    ClassDB::bind_method(D_METHOD("initialize_default_map"), &IMap::initialize_default_map);
    ClassDB::bind_method(D_METHOD("add_influence_source", "id", "x", "y", "influence_value"), &IMap::add_influence_source);
    ClassDB::bind_method(D_METHOD("move_influence_source", "id", "x", "y"), &IMap::move_influence_source);
    ClassDB::bind_method(D_METHOD("get_influence_value_at", "x", "y"), &IMap::get_influence_value_at);
}

void IMap::initialize_default_map() {
	print_line("Calling IMap::initialize_default_map");
	this->create_imap(4, 3, 40, 0, 30, 0);
}

void IMap::create_imap(int num_grid_x, int num_grid_y, float forward_max, float forward_min, float right_max, float right_min) {
	print_line("Calling IMap::createIMap");
	this->map = new InfluenceMap(4, 3);
	this->map_length = forward_max - forward_min;
	this->map_width = right_max - right_min;
	this->relative_x = forward_min;
	this->relative_y = right_min;
	this->num_grid_x = num_grid_x;
	this->num_grid_y = num_grid_y;
	this->grid_size_x = this->map_length / this->num_grid_x;
	this->grid_size_y = this->map_width / this->num_grid_y;
}

void IMap::add_influence_source( int id, float x, float y, float influence_value) {
	print_line("Calling IMap::add_influence_source");
	Vector2 grid = coordinate_to_grid(x, y);
	this->map->AddInfluenceSource(id, grid.x, grid.y, influence_value);
}

void IMap::move_influence_source(int id, float x, float y) {
	print_line("Calling IMap::move_influence_source");
	Vector2 grid = coordinate_to_grid(x, y);
	this->map->MoveInfluenceSource(id, grid.x, grid.y);
}

float IMap::get_influence_value_at(float x, float y) {	
	print_line("Calling IMap::get_influence_value_at");
	Vector2 grid = coordinate_to_grid(x, y);
	// should do a check to see if source exists or no.
	return this->map->GetInfluenceValueAt(grid.x, grid.y);
}


Vector2 IMap::coordinate_to_grid(float x, float y) {
	return Vector2(
		int((x - this->relative_x) / this->map_length * this->num_grid_x),
		int((y - this->relative_y) / this->map_width * this->num_grid_y)
	);
}

Vector2 IMap::grid_to_coordinate(int x, int y) {
	return Vector2(
		((float) x) / this->num_grid_x * this->map_length + this->relative_x + this->grid_size_x / 2,
		((float) y) / this->num_grid_y * this->map_width + this->relative_y + this->grid_size_y / 2
	);
}