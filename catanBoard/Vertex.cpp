#include "Vertex.hpp"
#include "Tile.hpp"  // Include Tile.hpp to get the full definition of Tile

Vertex::Vertex(Player* owner, Building type) : owner(owner), type(type) {}

vector<Resource> Vertex::getResources() const {
    vector<Resource> resources;
    for (const auto& tile : tiles) {
        resources.push_back(tile->Tiletype);
    }
    return resources;
}