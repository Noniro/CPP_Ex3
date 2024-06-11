#include "YearOfPlentyCard.hpp"
// #include "catanBoard/Resource.hpp"
#include "../Player.hpp"
#include <iostream>

void YearOfPlentyCard::play(Player& player, Catan& game) {
    // std::cout << "🌸 Year of plenty played!" << std::endl;
    // std::cout << "Choose two resources to take from the bank:" << std::endl;
    // std::cout << "1. 🌾" << std::endl 
    //           << "2. 🧱" << std::endl
    //           << "3. 🏔" << std::endl
    //           << "4. 🌲" << std::endl
    //           << "5. 🐑" << std::endl;
    // int choice1, choice2;
    // std::cin >> choice1;
    // std::cout << "Choose another resource:" << std::endl;
    // std::cin >> choice2;
    // switch (choice1) {
    //     case 1:
    //         player.addResource(Resource::Type::WHEAT, 1);
    //         break;
    //     case 2:
    //         player.addResource(Resource::Type::BRICK, 1);
    //         break;
    //     case 3:
    //         player.addResource(Resource::Type::ROCK, 1);
    //         break;
    //     case 4:
    //         player.addResource(Resource::Type::WOOD, 1);
    //         break;
    //     case 5:
    //         player.addResource(Resource::Type::SHEEP, 1);
    //         break;
    //     default:
    //         std::cout << "Invalid choice!" << std::endl;
    //         break;
    // }
    // switch (choice2) {
    //     case 1:
    //         player.addResource(Resource::Type::WHEAT, 1);
    //         break;
    //     case 2:
    //         player.addResource(Resource::Type::BRICK, 1);
    //         break;
    //     case 3:
    //         player.addResource(Resource::Type::ROCK, 1);
    //         break;
    //     case 4:
    //         player.addResource(Resource::Type::WOOD, 1);
    //         break;
    //     case 5:
    //         player.addResource(Resource::Type::SHEEP, 1);
    //         break;
    //     default:
    //         std::cout << "Invalid choice!" << std::endl;
    //         break;
    // }

}

void YearOfPlentyCard::description() {
    std::cout << "🌸 Year of Plenty card: When played, it allows the player to take two resources of their choice from the bank." << std::endl;
}

CardType YearOfPlentyCard::getType() {
    return CardType::YEAR_OF_PLENTY;
}