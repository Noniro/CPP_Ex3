#pragma once

#include "DevelopmentCard.hpp"

class Catan;
class Player;

class PromotionCard : public DevelopmentCard {
    protected:
    bool used = false;
    
    public:
    PromotionCard(CardType type) : DevelopmentCard(type) {}
    virtual ~PromotionCard() = default;
    virtual void play(Player& player, Catan& game) = 0;
    void use() { used = true; }
    

};