/**
 * Definition for the base wrapper class of InfluenceMap Layer.
 **/

#ifndef GO_IM_LAYER_H
#define GO_IM_LAYER_H

#include "imap_lib/IMLayer.h"
#include "core/reference.h"

/** The base wrapper class for InfluenceMap Layer.
 * Every wrapper layer extends from this class, and this
 * allows the game developer to easily manage all layers
 * in a unified way.
 */
class GoIMLayer : public Reference {
	GDCLASS(GoIMLayer, Reference);

protected:
	/* Method that defines the method signatures that expose to the game.
	 * Only methods defined in this region appear in the drop-down button
	 * in Godot for auto-completion.
	 */
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("init", "start_x", "start_y", "width", "height"), &GoIMLayer::init);
		ClassDB::bind_method(D_METHOD("set_offset", "start_x", "start_y"), &GoIMLayer::set_offset);
		ClassDB::bind_method(D_METHOD("set_dimens", "width", "height"), &GoIMLayer::set_dimens);
		ClassDB::bind_method(D_METHOD("get_value_at", "x", "y"), &GoIMLayer::get_value_at);
	}

public:
	/* The constructor for any wrapper class is simply instantiate a
	 * corresponding Influence Map layer for it.
	 */
	GoIMLayer(){
		this->layer = new IMLayer();
	}

	/* The (start_x, start_y) parameters define the relatively position of 
	 * this layer compared to its parent layer.
	 * For the root layer, it is recommended to set start_x, start_y
	 * both to 0 in order to avoid unnecessary offset.
	 * (width, height) define the size of the actual influence map.
	 *
	 * TODO: Add Grid concept (similar to the other IM-lib version)
	 */
	virtual void init(int start_x, int start_y, int width, int height) {
		set_offset(start_x, start_y);
		set_dimens(width, height);
	}
	virtual void set_offset(int start_x, int start_y) {
		this->start_x = start_x;
		this->start_y = start_y;
		this->layer->set_offset(start_x, start_y);
	}
	virtual void set_dimens(int width, int height) {
		this->width = width;
		this->height = height;
		this->layer->set_dimens(width, height);
	}

	/* Return the influence map at coordinate (x, y).
	 * The coordinate is relative as well. 
	 */
	virtual double get_value_at(int x, int y) {
		return this->layer->get_value_at(x, y);
	}

	int start_x;
	int start_y;
	int width;
	int height;

	/* Unfortunately, this variable has to be public (exposed) for
	 * inherent wrapper layers to work properly.
	 */
	IMLayer* layer;

};

#endif // GO_IM_LAYER_H

