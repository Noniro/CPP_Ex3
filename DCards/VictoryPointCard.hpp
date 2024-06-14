#pragma once

#include "DevelopmentCard.hpp"

class VictoryPointCard : public DevelopmentCard {
    public:
    std::string emoji () override {
        return "🏆";
    }
    void description() override;


    VictoryPointCard() : DevelopmentCard(CardType::VICTORY_POINT) {}
};