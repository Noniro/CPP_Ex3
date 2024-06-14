#pragma once
#include <string>
#include <memory>
#include "Vertex.hpp"
#include "../Player.hpp"

using namespace std;

class Edge{
    public:
    Player* owner; // the player that owns the edge(road)
    array<shared_ptr<Vertex>, 2> vertices; // the vertices that are connected to this edge
    Edge(shared_ptr<Vertex> v1, shared_ptr<Vertex> v2) : vertices{v1, v2} {}
    //get color of the owner
    string getColor() const {
        if (owner == nullptr) {
            return "\033[0m";
        } else {
            return owner->colorToANSICode();
        }
    }
    Player* getOwner() const {
        return owner;
    }
    ~Edge() {}
};
