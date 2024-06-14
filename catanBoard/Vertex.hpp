#pragma once

#include "Enums.hpp"
#include "Resource.hpp"
#include <string>
#include <memory>  
#include <vector>

using namespace std;
    
class Player; // Forward declaration of Player
class Edge;  // Forward declaration of Edge
class Tile;  // Forward declaration of Tile

class Vertex{ // Represents a land vertex on the board
    public:
    Player* owner; // the player that owns the vertex(settlement)
    Building type; // settlement or city 
    string emoji = "✖";// 
    vector<shared_ptr<Edge>> edges; // the edges that are connected to this vertex
    vector<shared_ptr<Tile>> tiles; // the tiles that are connected to this vertex
    Vertex(Player* owner, Building type);
    Vertex() = default;
    vector<Resource> getResources() const;
    string getColoredEmoji() const;
    Player* getOwner() const;
    Building getType() const { return type; }

};
