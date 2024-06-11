#pragma once
#include <stack>
#include <vector>

#include "Player.hpp"
#include "Trade.hpp"
#include "catanBoard/Board.hpp"
#include "catanBoard/Enums.hpp"
#include "catanBoard/Resource.hpp"
#include "DCards/DevelopmentCard.hpp"
#include "DCards/PromotionCard.hpp"
#include "DCards/KnightCard.hpp"
#include "DCards/VictoryPointCard.hpp"
#include "DCards/RoadBuildingCard.hpp"
#include "DCards/MonopolyCard.hpp"
#include "DCards/YearOfPlentyCard.hpp"
#include <ctime>

class Catan {
   private:
    std::vector<Player*> players;
    Board board;
    int currentPlayerIndex;
    Player* playerWithBiggestArmy = nullptr;
    int turnsCounter = 0;
    std::stack<DevelopmentCard*> developmentCards;

   public:
    Catan(Player* p1, Player* p2, Player* p3) : players{p1, p2, p3}, board(), currentPlayerIndex(0) {
        // Initialize development cards
        std::srand(std::time(0));
        for (int i = 0; i < 14; i++) {
            developmentCards.push(DevelopmentCard::createCard(CardType::KNIGHT));
        }
        for (int i = 0; i < 5; i++) {
            
            developmentCards.push(DevelopmentCard::createCard(CardType::KNIGHT));
            developmentCards.push(DevelopmentCard::createCard(CardType::VICTORY_POINT));
            developmentCards.push(DevelopmentCard::createCard(CardType::ROAD_BUILDING));
            developmentCards.push(DevelopmentCard::createCard(CardType::MONOPOLY));
        }
        vector<DevelopmentCard*> temp;

        while (!developmentCards.empty()) {
            temp.push_back(developmentCards.top());
            developmentCards.pop();
        }
        std::random_shuffle(temp.begin(), temp.end());
        for (auto card : temp) {
            developmentCards.push(card);
        }
    }
    void gameDescription(); // description 
    int chooseStartingPlayer();
    void endTurn();
    Board& getBoard();
    Player* checkWinner();
    vector<Player*> getPlayers() { return players; }
    void startGame();
    int getSettlementPlacementFromUser();
    int getRoadPlacementFromUser();
    void placeSettlement();
    void placeRoad();
    void placeCity();
    void checkBiggestArmy();
    DevelopmentCard* drawDevelopmentCard();
    void shuffleDevelopmentCards();  // implement this method
    void buyDevelopmentCard();
    bool playDevelopmentCard();
    int rollDice();
    void ridHalfCards();
    void placeKnight();
    void makeTrade();
    void showCards();
    string cardTypeToString(CardType cardType);
};
