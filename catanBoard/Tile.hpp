#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Enums.hpp"
#include "Resource.hpp"
#include "../Player.hpp"
#include "Edge.hpp"

using namespace std;

    class Vertex;
    class Player;
    class Tile {
    public:
        Resource Tiletype;
        string resourceEmoji; // rmoji of the resource
        int number; // The dice number for this tile
        vector<shared_ptr<Vertex>> vertices;
        vector<shared_ptr<Edge>> edges;
        vector<shared_ptr<Player>> players;
        bool robber;

        Tile(Resource Tiletype, string emoji, int number) : Tiletype(Tiletype), resourceEmoji(emoji), number(number) {}
        virtual ~Tile() = default;
    };

    class WoodTile : public Tile {
    public:
        WoodTile(int number) : Tile(Resource::Type::WOOD, "🌲", number) {}
    };

    class SheepTile : public Tile {
    public:
        SheepTile(int number) : Tile(Resource::Type::SHEEP, "🐑", number) {}
    };

    class WheatTile : public Tile {
    public:
        WheatTile(int number) : Tile(Resource::Type::WHEAT, "🌾", number) {}
    };

    class BrickTile : public Tile {
    public:
        BrickTile(int number) : Tile(Resource::Type::BRICK, "🧱", number) {}
    };

    class RockTile : public Tile {
    public:
        RockTile(int number) : Tile(Resource::Type::ROCK, "⛰️", number) {}
    };

    class DesertTile : public Tile {
    public:
        DesertTile() : Tile(Resource::Type::NONE, "🏜️", 0) {}
    };

