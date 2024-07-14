#include "Catan.hpp"
#include "Player.hpp"
#include <iostream>
#include "DCards/DevelopmentCard.hpp"
#include "catanBoard/Resource.hpp"

int main() {
    std::cout<<"Welcome to Catan!"<<std::endl;


    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);


    Catan game(&p1,&p2,&p3);

    // Start the game
// game.startGame();  // uncomment this line for the starting game iteration.
//~~~~~~~~~~~~~~~~~~~~~GAME-PREVEIW-SECTION~~~~~~~~~~~~~~~~~~~~~~~//
p1.addResource(Resource::Type::BRICK, 5);
p1.addResource(Resource::Type::ROCK, 5);
p1.addResource(Resource::Type::WHEAT, 5);
p1.addResource(Resource::Type::SHEEP, 5);
p1.addResource(Resource::Type::WOOD, 5);

p2.addResource(Resource::Type::BRICK, 5);
p2.addResource(Resource::Type::ROCK, 5);
p2.addResource(Resource::Type::WHEAT, 5);
p2.addResource(Resource::Type::SHEEP, 5);
p2.addResource(Resource::Type::WOOD, 5);

p3.addResource(Resource::Type::BRICK, 5);
p3.addResource(Resource::Type::ROCK, 5);
p3.addResource(Resource::Type::WHEAT, 5);
p3.addResource(Resource::Type::SHEEP, 5);
p3.addResource(Resource::Type::WOOD, 5);

game.getBoard().placeSettlement(&p1, 13, 0);
game.getBoard().placeRoad(&p1, 20);
game.getBoard().placeSettlement(&p2, 30, 0);
game.getBoard().placeRoad(&p2, 45);
game.getBoard().placeSettlement(&p3, 33, 0);
game.getBoard().placeRoad(&p3, 40);

game.getBoard().placeSettlement(&p3, 15, 0);
game.getBoard().placeRoad(&p3, 22);
game.getBoard().placeSettlement(&p2, 32, 0);
game.getBoard().placeRoad(&p2, 48);
game.getBoard().placeSettlement(&p1, 40, 0);
game.getBoard().placeRoad(&p1, 58);

cout<<"THIS IS A GAME PREVIEW!"<<endl;
//~~~~~~~~~~~~~~~~~~END-PREVEIW~~~~~~~~~~~~~~~~~~~~~~~~~~// 

Player* winner = nullptr;
// Main game loop
while (winner == nullptr) {
    std::string action;
    std::cout << "\nEnter action: \n 1: roll \n 2: play_card \n";
    std::cin >> action;

    if (action == "1") {
        game.rollDice();
    } else if (action == "2") {
       bool isplayed= game.playDevelopmentCard();
        if(!isplayed){
            continue;
        }
        game.endTurn();
        winner = game.checkWinner();
    } else {
        std::cout << "Invalid action" << std::endl;
        continue;
    }

    while (action != "7") {
        std::cout << "\nEnter action:\n 1: Show_all_Cards \n 2: place_Building \n 3: buy_card \n 4: play_card \n 5: make_trade \n 6: show_gameBoard \n 7: end_turn \n 9: how_to_play\n ";
        std::cin >> action;
        if(action == "1"){
            game.showCards();
        }else if (action == "2") {
            cout<<"Enter action:\n 1: place_road\n 2: place_settlement\n 3: place_city\n any other key: cancel\n";
            std::cin >> action;
            if (action == "1") {
                try{
                game.placeRoad();
                }
                catch(const std::exception& e){
                    std::cerr << e.what() << '\n';
                }
            } else if (action == "2") {
                try{
                game.placeSettlement();
                }catch(const std::exception& e){
                    std::cerr << e.what() << '\n';
                }
            } else if (action == "3") {
                try{
                game.placeCity();
                }catch(const std::exception& e){
                    std::cerr << e.what() << '\n';
                }
            }
        } else if (action == "3") {
            game.buyDevelopmentCard();
        } else if (action == "4") {
            game.playDevelopmentCard();
        } else if (action == "5") {
            cout<<"Enter action:\n 1: trade_resources\n 2: trade_cards\n any other key: cancel\n";
            std::cin >> action;
            if (action == "1") {
                game.makeTrade();
            } else if (action == "2") {
                game.makeCardTrade();
            }
        } else if (action == "6") {
            game.getBoard().printBoard();
        } else if (action == "7") {
            game.endTurn();
            winner = game.checkWinner();
            break;
        } else if (action == "9") {
            game.gameDescription();
        } else {
            std::cout << "Invalid action \n" << std::endl;
        }
    }
}
return 0;
}