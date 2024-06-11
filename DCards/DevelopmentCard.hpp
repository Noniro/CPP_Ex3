#pragma once
#include <memory>
#include <string>
#include <vector>

class Catan;

enum class CardType {
    KNIGHT,
    VICTORY_POINT,
    ROAD_BUILDING,
    MONOPOLY,
    YEAR_OF_PLENTY,
};

class DevelopmentCard {
   protected:
    CardType type;

   public:
    DevelopmentCard(CardType type) : type(type) {}
    static DevelopmentCard* createCard(CardType type); 
    virtual ~DevelopmentCard() = default;
    CardType getType() const { return type; }
    virtual std::string emoji() = 0;
    virtual void description() = 0;
    
};

