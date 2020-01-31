//
// Created by Ao on 2019-10-27.
//

#include "InfluenceMap.h"
#include "InfluenceMapConstant.h"
#include <cmath>
#include <cassert>
#include <algorithm>

InfluenceMap::InfluenceMap() : InfluenceMap(InfluenceMapConstant::DEFAULT_LENGTH, InfluenceMapConstant::DEFAULT_WIDTH){
}

InfluenceMap::InfluenceMap(int numGridX, int numGridY) : InfluenceMap(numGridX, numGridY, InfluenceMapConstant::DEFAULT_PROPAGATE_RADIUS){
}

InfluenceMap::InfluenceMap(int numGridX, int numGridY, float default_propagate_radius)
: influences(static_cast<unsigned long>(numGridX), std::vector<float>(static_cast<unsigned long>(numGridY))),
numGridX(numGridX),
numGridY(numGridY),
default_propagate_radius(default_propagate_radius),
sources(std::vector<InfluenceSource>())
{}

void InfluenceMap::AddInfluenceSource(int id, int numGridX, int numGridY, float influenceValue) {
    assert(this->sources.size() <= InfluenceMapConstant::MAXIMUM_INFLUENCE_SOURCES);
    assert(IsLocationValid(numGridX, numGridY));

    auto source = InfluenceSource(id, numGridX, numGridY, influenceValue);
    sources.push_back(source);
    Propagate(source);
}

void InfluenceMap::AddInfluenceSource(int id, int numGridX, int numGridY, float influenceValue, float radius) {
    assert(this->sources.size() <= InfluenceMapConstant::MAXIMUM_INFLUENCE_SOURCES);
    assert(IsLocationValid(numGridX, numGridY));

    auto source = InfluenceSource(id, numGridX, numGridY, influenceValue, radius);
    sources.push_back(source);
    Propagate(source);
}

void InfluenceMap::PrintInfluenceMap() {

    for(auto i = 0; i < this->numGridX; ++i) {
        for (auto j = 0; j < this->numGridY; ++j) {
            std::cout << influences[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void InfluenceMap::Propagate(InfluenceSource source) {

    float radius = source.IsCustomized() ? source.GetRadius() : default_propagate_radius;
    int sourceX = source.GetXGrid();
    int sourceY = source.GetYGrid();
    float sourceInfluence = source.GetValue();

    if(radius == 0) {
        influences[sourceX][sourceY] += sourceInfluence;
        return;
    }

    for(int i = MaxOfTwo(int(sourceX - radius) - 1, 0); i <= sourceX + radius ;i ++)
        for(int j = MaxOfTwo(int(sourceY - radius) - 1, 0); j <= sourceY + radius; j++) {
            if(!IsLocationValid(i, j)) continue;
            int distanceSquare = (i - sourceX) * (i - sourceX) + (j - sourceY) * (j - sourceY);
            if( distanceSquare <= radius * radius) {
                influences[i][j] += sourceInfluence - sourceInfluence * std::sqrt(distanceSquare) / radius;
            }
        }

}

void InfluenceMap::PrintAllSources() {

    for (int i = 0; i < sources.size(); ++i) {
        std::cout << "Source" << i << ": " << sources[i].StringValue() << std::endl;
    }
}

std::vector<InfluenceSource> InfluenceMap::GetSourcesAt(int numGridX, int numGridY) {
    auto queriedSources = std::vector<InfluenceSource>();
    for(auto it = sources.begin(); it < sources.end(); it++) {
        if(it->GetXGrid() == numGridX && it->GetYGrid() == numGridY) {
            queriedSources.push_back(*it);
        }
    }

    return queriedSources;
}

InfluenceSource InfluenceMap::GetSourceWithId(int id) {
    for(auto it = sources.begin(); it < sources.end(); it++) {
        if(it->GetSourceId() == id) {
            return *it;
        }
    }

    return InfluenceSource();
}

std::vector<InfluenceSource> InfluenceMap::GetSourcesWithin(int leftX, int leftY, int rightX, int rightY) {
    auto queriedSources = std::vector<InfluenceSource>();

    for(auto it = sources.begin(); it < sources.end(); it++) {

        if(it->GetXGrid() >= leftX && it->GetYGrid() >= leftY && it->GetXGrid() <= rightX && it->GetYGrid() <= rightY ) {
            queriedSources.push_back(*it);
        }
    }

    return queriedSources;
}

void InfluenceMap::DeleteInfluenceSourcesAt(int numGridX, int numGridY) {
    std::vector<InfluenceSource> targetSources = GetSourcesAt(numGridX, numGridY);

    for(auto it = targetSources.begin(); it < targetSources.end(); ++it) {
        assert(it->IsValid());
        DeleteInfluenceSource(it->GetSourceId());
    }
}

void InfluenceMap::DeleteInfluenceSource(int sourceId) {
    for(auto it = sources.begin(); it < sources.end(); ++it) {
        if(it->GetSourceId() == sourceId) {

            // Restore the propagation for surroundings
            ErasePropagate(*it);

            sources.erase(it);

            break;
        }
    }
}

void InfluenceMap::ErasePropagate(InfluenceSource source) {

    InfluenceSource revert_source = source.GetRadius() == InfluenceMapConstant::INVALID_RADIUS ?
            InfluenceSource(source.GetSourceId(), source.GetXGrid(), source.GetYGrid(), -source.GetValue()) :
            InfluenceSource(source.GetSourceId(), source.GetXGrid(), source.GetYGrid(), -source.GetValue(), source.GetRadius());

    Propagate(revert_source);

    for(int i = 0; i < numGridX; ++i)
        for(int j = 0; j < numGridY; ++j) {
            if(std::abs(influences[i][j]) < 0.001) {
                influences[i][j] = 0;
            }
        }
}

void InfluenceMap::MoveInfluenceSource(int sourceId, int new_x, int new_y) {

    InfluenceSource source = GetSourceWithId(sourceId);

    if(source.GetXGrid() == new_x && source.GetYGrid() == new_y) {
        return;
    }
    
    DeleteInfluenceSource(sourceId);

    if(source.IsCustomized()) {
        AddInfluenceSource(source.GetSourceId(), new_x, new_y, source.GetValue(), source.GetRadius());
    } else {
        AddInfluenceSource(source.GetSourceId(), new_x, new_y, source.GetValue());
    }
}

void InfluenceMap::GenerateShortestPath(int src_x, int src_y, int *prev, float *dist) {

    int total_vertex = numGridX * numGridY;
    bool is_visit[10000]; //todo change it later

    for (int i = 0; i < total_vertex ; i++) {
        is_visit[i] = false;
    }

    dist[TileIndex(src_x, src_y)] = 0;

    while(true) {
        int min_value = InfluenceMapConstant::HUGE_INT_VALUE;
        int current_vertex = -1;
        for(auto i = 0; i < total_vertex; i++) {
            if(dist[i] < min_value && !is_visit[i]) {
                min_value = dist[i];
                current_vertex = i;
            }
        }
        if(min_value == InfluenceMapConstant::HUGE_INT_VALUE) {
            break;
        }
        is_visit[current_vertex] = true;

        std::tuple<int, int> u = LocationFromIndex(current_vertex);
        int u_x = std::get<0>(u), u_y = std::get<1>(u);

        if(IsLocationValid(u_x - 1, u_y) && dist[TileIndex(u_x - 1, u_y)] > dist[current_vertex] + influences[u_x-1][u_y] + 1){
            dist[TileIndex(u_x - 1, u_y)] = dist[current_vertex] + influences[u_x-1][u_y] + 1;
            prev[TileIndex(u_x - 1, u_y)] = current_vertex;
        }
        if(IsLocationValid(u_x, u_y - 1) && dist[TileIndex(u_x, u_y - 1)] > dist[current_vertex] + influences[u_x][u_y-1] + 1){
            dist[TileIndex(u_x, u_y - 1)] = dist[TileIndex(u_x, u_y)] + influences[u_x][u_y-1] + 1;
            prev[TileIndex(u_x, u_y - 1)] = current_vertex;
        }
        if(IsLocationValid(u_x + 1, u_y) && dist[TileIndex(u_x + 1, u_y)] > dist[current_vertex] + influences[u_x+1][u_y] + 1) {
            dist[TileIndex(u_x + 1, u_y)] = dist[current_vertex] + influences[u_x+1][u_y] + 1;
            prev[TileIndex(u_x + 1, u_y)] = current_vertex;
        }
        if(IsLocationValid(u_x, u_y + 1) && dist[TileIndex(u_x, u_y + 1)] > dist[current_vertex] + influences[u_x][u_y+1] + 1) {
            dist[TileIndex(u_x, u_y + 1)] = dist[TileIndex(u_x, u_y)] + influences[u_x][u_y+1] + 1;
            prev[TileIndex(u_x, u_y + 1)] = current_vertex;
        }

    }
}

void InfluenceMap::GenerateShortestPath(int src_x, int src_y, std::vector<int> *prev, std::vector<int> *dist) {

    int total_vertex = numGridX * numGridY;
    bool is_visit[1000000]; // todo change it later

    for (int i = 0; i < total_vertex ; i++) {
        is_visit[i] = false;
    }

    dist->at(TileIndex(src_x, src_y)) = 0;

    while(true) {
        int min_value = InfluenceMapConstant::HUGE_INT_VALUE;
        int current_vertex = -1;
        for(int i = 0; i < total_vertex; i++) {
            if(dist->at(i) < min_value && !is_visit[i]) {
                min_value = dist->at(i);
                current_vertex = i;
            }
        }
        if(current_vertex == -1) {
            break;
        }
        is_visit[current_vertex] = true;

        std::tuple<int, int> u = LocationFromIndex(current_vertex);
        int u_x = std::get<0>(u), u_y = std::get<1>(u);

        if(IsLocationValid(u_x - 1, u_y) && dist->at(TileIndex(u_x - 1, u_y)) > dist->at(current_vertex) + int(influences[u_x-1][u_y])) {
            dist->at(TileIndex(u_x - 1, u_y)) = dist->at(current_vertex) + int(influences[u_x-1][u_y]);
            prev->at(TileIndex(u_x - 1, u_y)) = current_vertex;
        }
        if(IsLocationValid(u_x, u_y - 1) && dist->at(TileIndex(u_x, u_y - 1)) > dist->at(current_vertex) + int(influences[u_x][u_y-1])) {
            dist->at(TileIndex(u_x, u_y - 1)) = dist->at(TileIndex(u_x, u_y)) + int(influences[u_x][u_y-1]);
            prev->at(TileIndex(u_x, u_y - 1)) = current_vertex;
        }
        if(IsLocationValid(u_x + 1, u_y) && dist->at(TileIndex(u_x + 1, u_y)) > dist->at(current_vertex) + int(influences[u_x+1][u_y])) {
            dist->at(TileIndex(u_x + 1, u_y)) = dist->at(current_vertex) + int(influences[u_x+1][u_y]);
            prev->at(TileIndex(u_x + 1, u_y)) = current_vertex;
        }
        if(IsLocationValid(u_x, u_y + 1) && dist->at(TileIndex(u_x, u_y + 1)) > dist->at(current_vertex) + int(influences[u_x][u_y+1])) {
            dist->at(TileIndex(u_x, u_y + 1)) = dist->at(current_vertex) + int(influences[u_x][u_y+1]);
            prev->at(TileIndex(u_x, u_y + 1)) = current_vertex;
        }

    }
}

int InfluenceMap::TileIndex(int x, int y) {
    return x * numGridX + y;
}

std::tuple<int, int> InfluenceMap::LocationFromIndex(int index) {
    return std::make_tuple(index/numGridX, index%numGridX);
}

bool InfluenceMap::IsLocationValid(int x, int y) {

    return x >= 0 && x < numGridX && y >= 0 && y < numGridY;
}

int InfluenceMap::MaxOfTwo(float x, float y) {
    return x > y ? x : y;
}

float InfluenceMap::GetInfluenceValueAt(int numGridX, int numGridY) {
    return influences[numGridX][numGridY];
}

int InfluenceMap::GetNumGridX() {
    return numGridX;
}

int InfluenceMap::GetNumGridY() {
    return numGridY;
}








