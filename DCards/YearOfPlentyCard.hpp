#pragma once

#include "PromotionCard.hpp"

class Catan;
class Player;

class YearOfPlentyCard : public PromotionCard {
public:
    std::string emoji ()override {
        return "🌸";
    }
    YearOfPlentyCard() : PromotionCard(CardType::YEAR_OF_PLENTY) {}
    void play(Player& player, Catan& game) override;
    CardType getType();
    void description() override;
};


