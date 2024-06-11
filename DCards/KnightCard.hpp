#pragma once

#include "DevelopmentCard.hpp"

class KnightCard : public DevelopmentCard {
    public:
    std::string emoji () override {
        return "⚔️";
    }
    KnightCard() : DevelopmentCard(CardType::KNIGHT) {}
    
    void description() override;
};
    