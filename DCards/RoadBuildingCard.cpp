#include <iostream>
#include "RoadBuildingCard.hpp"
#include "../Catan.hpp"
#include <limits>

void RoadBuildingCard::play(Player& player, Catan& game) {
    std::cout << "🚧 Road Building card played!\n" << std::endl;
    game.placeRoad(); 
    game.placeRoad();
}


void RoadBuildingCard::description() {
    std::cout << "🚧 Road Building card: When played, it allows the player to build two roads for free." << std::endl;
}