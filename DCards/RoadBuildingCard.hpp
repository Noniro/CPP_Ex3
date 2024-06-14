#pragma once

#include "PromotionCard.hpp"

class Catan;
class Player;

class RoadBuildingCard : public PromotionCard {
    public:
    std::string emoji() override {
        return "🚧";
    };
    RoadBuildingCard() : PromotionCard(CardType::ROAD_BUILDING) {}
    void play(Player& player, Catan& game) override;
    virtual void description() override;
};