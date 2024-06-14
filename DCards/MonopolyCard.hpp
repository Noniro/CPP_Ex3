#pragma once

#include "DevelopmentCard.hpp"
#include "PromotionCard.hpp"

class Catan;
class Player;

class MonopolyCard : public PromotionCard {
    public:
    std::string emoji () override {
        return "🏦";
    }
    MonopolyCard() : PromotionCard(CardType::MONOPOLY) {}
    void play(Player& player, Catan& game) override;
    virtual void description() override;
};