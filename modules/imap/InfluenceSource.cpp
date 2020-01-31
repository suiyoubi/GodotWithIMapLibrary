//
// Created by Ao on 2019-10-28.
//

#include "InfluenceSource.h"
#include "InfluenceMapConstant.h"


InfluenceSource::InfluenceSource() : xGrid(InfluenceMapConstant::INVALID_SOURCE_ID) {}

InfluenceSource::InfluenceSource(int id, int x, int y, float value) :
sourceId(id),
xGrid(x),
yGrid(y),
value(value),
isCustomizedRadius(false),
radius(InfluenceMapConstant::INVALID_RADIUS) {}

InfluenceSource::InfluenceSource(int id, int x, int y, float value, float radius) :
sourceId(id),
xGrid(x),
yGrid(y),
value(value),
isCustomizedRadius(true),
radius(radius) {}

int InfluenceSource::GetXGrid() const {
    return xGrid;
}

int InfluenceSource::GetYGrid() const {
    return yGrid;
}

float InfluenceSource::GetValue() const {
    return value;
}

float InfluenceSource::GetRadius() const {
    return radius;
}

bool InfluenceSource::IsCustomized() const {
    return isCustomizedRadius;
}

std::string InfluenceSource::StringValue() const {
    return "id: " + std::to_string(sourceId) +
           ", xGrid: " + std::to_string(xGrid) +
           ", yGrid: " + std::to_string(yGrid) +
           ", value: " + std::to_string(value) +
           ", radius: " + (radius == InfluenceMapConstant::INVALID_RADIUS ? "not set" : std::to_string(radius)) +
           ", is_customized:" + (isCustomizedRadius ? "true" : "false");
}

bool InfluenceSource::IsValid() const {
    return this->sourceId != InfluenceMapConstant::INVALID_SOURCE_ID;
}

bool InfluenceSource::Equals(InfluenceSource anotherSource) const {
    return xGrid == anotherSource.GetXGrid() &&
           yGrid == anotherSource.GetYGrid() &&
           radius == anotherSource.GetRadius() &&
           value == anotherSource.GetValue();
}

int InfluenceSource::GetSourceId() const {
    return sourceId;
}



