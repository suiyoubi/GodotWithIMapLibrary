//
// Created by Ao on 2019-10-28.
//

#ifndef INFLUENCEMAP_INFLUENCESOURCE_H
#define INFLUENCEMAP_INFLUENCESOURCE_H

#include <string>

class InfluenceSource {
private:
    int sourceId; // Unique Id
    int xGrid;
    int yGrid;
    float value;
    bool isCustomizedRadius;
    float radius; // Valid only when isCustomizedRadius is true
public:
    // Default constructor, generates a invalid source
    InfluenceSource();

    // Source without radius
    InfluenceSource(int id, int x, int y, float value);

    // Source with radius
    InfluenceSource(int id, int x, int y, float value, float radius);

    int GetSourceId() const;

    int GetXGrid() const;

    int GetYGrid() const;

    float GetValue() const;

    float GetRadius() const;
    
    bool IsCustomized() const;

    std::string StringValue() const;

    bool IsValid() const;

    bool Equals(InfluenceSource) const;
};


#endif //INFLUENCEMAP_INFLUENCESOURCE_H
