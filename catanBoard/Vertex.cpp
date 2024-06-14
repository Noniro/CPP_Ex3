#include "Vertex.hpp"
#include "Tile.hpp" 

Vertex::Vertex(Player* owner, Building type) : owner(owner), type(type) {}

vector<Resource> Vertex::getResources() const {
    vector<Resource> resources;
    for (const auto& tile : tiles) {
        resources.push_back(tile->Tiletype);
    }
    return resources;
}

string Vertex::getColoredEmoji() const {
    if (owner == nullptr) {
        return emoji;
    } else {
        return owner->colorToANSICode() + emoji + "\033[0m";
    }
}

Player* Vertex::getOwner() const {
    return owner;
}
