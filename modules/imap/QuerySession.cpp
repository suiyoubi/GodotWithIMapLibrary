//
// Created by Ao on 2019-11-11.
//

#include "QuerySession.h"
#include "InfluenceMapConstant.h"
#include <cassert>
#include <iostream>


void QuerySession::Initialize() {

    for(int i = 0; i < total_vertex; ++i) {
        distArray[i] = float(InfluenceMapConstant::HUGE_INT_VALUE);
        prevArray[i] = InfluenceMapConstant::HUGE_INT_VALUE;
    }

    assert(influence_map != nullptr);

    influence_map->GenerateShortestPath(std::get<0>(target), std::get<1>(target), prevArray, distArray);
}

std::vector<int> QuerySession::GeneratePath(int start_x, int start_y) {
    std::vector<int> path;

    int target_index = influence_map->TileIndex(std::get<0>(target), std::get<1>(target));
    int current_index = influence_map->TileIndex(start_x, start_y);

    while(current_index != target_index) {
        path.push_back(current_index);

        current_index = prevArray[current_index];
    }

    path.push_back(target_index);
    return path;
}

void QuerySession::DestroySession() {

    delete distArray;
    delete prevArray;

    distArray = nullptr;
    prevArray = nullptr;
    influence_map = nullptr;
}


void QuerySession::SetTarget(int x, int y) {
    target = std::make_tuple(x, y);
}

void QuerySession::LinkInfluenceMap(InfluenceMap *influence_map) {
    this->influence_map = influence_map;
}

QuerySession::QuerySession(int target_x, int target_y, InfluenceMap *influence_map) {
    int total_vertex = influence_map->GetNumGridY() * influence_map->GetNumGridX();
    distArray = new float [total_vertex];
    prevArray = new int [total_vertex];
    this->total_vertex = total_vertex;
    this->target = std::make_tuple(target_x, target_y);
    this->influence_map = influence_map;
}

void QuerySession::Debug() {

    int i = 0;
    while(i < total_vertex) {
        printf("%d ", prevArray[i]);
        i++;
        if(i%10 == 0) {
            printf("\n");
        }
    }

    while(i < total_vertex) {
        printf("%d ", int(distArray[i]));
        i++;
        if(i%10 == 0) {
            printf("\n");
        }
    }
}
