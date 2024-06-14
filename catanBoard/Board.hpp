#pragma once

#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include <vector>
#include <memory> // shared_ptr
#include <string>
#include <map>

using namespace std;

    
class Player;

class Board {
    
private:
    vector<shared_ptr<Tile>> tiles;
    vector<shared_ptr<Vertex>> vertices;
    vector<shared_ptr<Edge>> edges;

    string getVertexKey(int tile, int vertexIndex) const;
    string getEdgeKey(int tile, int edgeIndex) const;
public:
    Board();
    void initialize();
    void placeSettlement(Player* player, int vertexIndex, int turnCount);
    void placeCity(Player* player, int vertexIndex);
    void placeRoad(Player* player, int edgeIndex);
    vector<shared_ptr<Tile>> getTiles() const { return tiles; }
    void printBoard();
    void placeKnight(Player* player, int tileIndex);
    vector<Resource> getVertexResource(int vertexIndex);
    bool hasConnectedRoad(Player* player, int edgeIndex);
    vector<shared_ptr<Vertex>> getVertices() const { return vertices; }
    vector<shared_ptr<Edge>> getEdges() const { return edges; }
    
};