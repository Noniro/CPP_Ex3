#include "DevelopmentCard.hpp"
#include "KnightCard.hpp"
#include "MonopolyCard.hpp"
#include "RoadBuildingCard.hpp"
#include "VictoryPointCard.hpp"
#include "YearOfPlentyCard.hpp"


DevelopmentCard* DevelopmentCard::createCard(CardType type) {
    switch (type) {
        case CardType::KNIGHT:
            return new KnightCard();
        case CardType::VICTORY_POINT:
            return new VictoryPointCard();
        case CardType::ROAD_BUILDING:
            return new RoadBuildingCard();
        case CardType::MONOPOLY:
            return new MonopolyCard();
        case CardType::YEAR_OF_PLENTY:
            return new YearOfPlentyCard();
    }
    return nullptr;
}