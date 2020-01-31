//
// Created by Ao on 2019-10-27.
//

#ifndef INFLUENCEMAP_INFLUENCEMAP_H
#define INFLUENCEMAP_INFLUENCEMAP_H

#include <vector>
#include <iostream>
#include <tuple>

#include "InfluenceSource.h"

class InfluenceMap {
public:

    // Constructors --------------------------------

    // Default constructor, creating a influence map with default numGridX and numGridY
    InfluenceMap();
    // Influence map with specified numGridX and numGridY
    InfluenceMap(int numGridX, int numGridY);
    // Influence map with specified numGridX and numGridY and default_propagate_radius
    InfluenceMap(int numGridX, int numGridY, float default_propagate_radius);

    // Operations --------------------------------

    // Add an influence source to the specified location
    // Note: Multiple sources with same numGridX and numGridY are ALLOWED
    void AddInfluenceSource(int id, int numGridX, int numGridY, float influenceValue);
    void AddInfluenceSource(int id, int numGridX, int numGridY, float influenceValue, float radius);

    // Delete an existing influence source at a position
    // Delete all sources within the grid
    void DeleteInfluenceSourcesAt(int numGridX, int numGridY);
    // Delete the single source with given sourceId
    void DeleteInfluenceSource(int sourceId);

    // Move the source from a location to a new location
    void MoveInfluenceSource(int sourceId, int new_x, int new_y);


    // Visualization --------------------------------
    void PrintInfluenceMap();
    void PrintAllSources();

    // Queries --------------------------------
    int GetNumGridX();
    int GetNumGridY();
    InfluenceSource GetSourceWithId(int id);
    std::vector<InfluenceSource> GetSourcesAt(int numGridX, int numGridY);
    std::vector<InfluenceSource> GetSourcesWithin(int leftX, int leftY, int rightX, int rightY);
    float GetInfluenceValueAt(int numGridX, int numGridY);

    void GenerateShortestPath(int src_x, int src_y, int *prev, float *dist);
    void GenerateShortestPath(int src_x, int src_y, std::vector<int> *prev, std::vector<int> *dist);

    // Helper Functions --------------------------------
    int TileIndex(int x, int y);
    int MaxOfTwo(float x, float y);
	std::tuple<int, int> LocationFromIndex(int index);

    std::vector<std::vector<float>> influences;
private:

    void Propagate(InfluenceSource source);
    void ErasePropagate(InfluenceSource source);

    bool IsLocationValid(int x, int y);

    int numGridX;
    int numGridY;
    float default_propagate_radius;
    std::vector<InfluenceSource> sources;
};


#endif //INFLUENCEMAP_INFLUENCEMAP_H
