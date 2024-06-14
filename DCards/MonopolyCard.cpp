#include <iostream>
#include "MonopolyCard.hpp"
#include <limits>
#include "../Catan.hpp"

using namespace std;

void MonopolyCard::play(Player& player, Catan& game) {
    cout<<"🏦 Monopoly Card played!"<<endl;
    cout<<"Choose a resource to steal from all the other players:"<<endl;
    cout<<"1. 🌾"<<endl
        <<"2. 🧱"<<endl
        <<"3. 🏔"<<endl
        <<"4. 🌲"<<endl
        <<"5. 🐑"<<endl;
    int choice;

    while (true) {
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();  // clear the fail state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
            cout << "Invalid input. Please enter an integer between 1 and 5." << endl;
            continue;
        }
        break;
    }
    switch (choice) {
        case 1:
            for (auto &p : game.getPlayers()) {
                if (p != &player) {
                    int amount = p->getResource(Resource::Type::WHEAT);
                    p->removeResource(Resource::Type::WHEAT, amount);
                    player.addResource(Resource::Type::WHEAT, amount);
                }
            }
            break;
        case 2:
            for (auto &p : game.getPlayers()) {
                if (p != &player) {
                    int amount = p->getResource(Resource::Type::BRICK);
                    p->removeResource(Resource::Type::BRICK, amount);
                    player.addResource(Resource::Type::BRICK, amount);
                }
            }
            break;
        case 3:
            for (auto &p : game.getPlayers()) {
                if (p != &player) {
                    int amount = p->getResource(Resource::Type::ROCK);
                    p->removeResource(Resource::Type::ROCK, amount);
                    player.addResource(Resource::Type::ROCK, amount);
                }
            }
            break;
        case 4:
            for (auto &p : game.getPlayers()) {
                if (p != &player) {
                    int amount = p->getResource(Resource::Type::WOOD);
                    p->removeResource(Resource::Type::WOOD, amount);
                    player.addResource(Resource::Type::WOOD, amount);
                }
            }
            break;
        case 5:
            for (auto &p : game.getPlayers()) {
                if (p != &player) {
                    int amount = p->getResource(Resource::Type::SHEEP);
                    p->removeResource(Resource::Type::SHEEP, amount);
                    player.addResource(Resource::Type::SHEEP, amount);
                }
            }
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            break;
    }

}

void MonopolyCard::description() {
    std::cout<<"🏦 Monopoly Card - when playing this card you get to choose a specific resource to steal from all the other players."<<std::endl;
}