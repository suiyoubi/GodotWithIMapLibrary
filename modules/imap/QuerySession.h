//
// Created by Ao on 2019-11-11.
//

#ifndef INFLUENCEMAP_QUERYSESSION_H
#define INFLUENCEMAP_QUERYSESSION_H


#include <vector>
#include <tuple>
#include "InfluenceMap.h"

class QuerySession {

public:
    QuerySession(int target_x, int target_y, InfluenceMap *influence_map);

    void SetTarget(int x, int y);
    void LinkInfluenceMap(InfluenceMap *influence_map);
    void Initialize();
    void DestroySession();
    void Debug();
    std::vector<int> GeneratePath(int start_x, int start_y);

    float* distArray;
    int* prevArray;

private:
    int total_vertex;
    InfluenceMap *influence_map;
    std::tuple<int, int> target;
};


#endif //INFLUENCEMAP_QUERYSESSION_H
