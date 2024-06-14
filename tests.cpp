#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Catan.hpp"
#include "Player.hpp"
#include "DCards/DevelopmentCard.hpp"
#include "catanBoard/Resource.hpp"
#include "doctest.h"

TEST_CASE("Player resources") {
    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

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

    CHECK(p1.getResource(Resource::Type::BRICK) == 5);
    CHECK(p1.getResource(Resource::Type::ROCK) == 5);
    CHECK(p1.getResource(Resource::Type::WHEAT) == 5);
    CHECK(p1.getResource(Resource::Type::SHEEP) == 5);
    CHECK(p1.getResource(Resource::Type::WOOD) == 5);

    CHECK(p2.getResource(Resource::Type::BRICK) == 5);
    CHECK(p2.getResource(Resource::Type::ROCK) == 5);
    CHECK(p2.getResource(Resource::Type::WHEAT) == 5);
    CHECK(p2.getResource(Resource::Type::SHEEP) == 5);
    CHECK(p2.getResource(Resource::Type::WOOD) == 5);

    CHECK(p3.getResource(Resource::Type::BRICK) == 5);
    CHECK(p3.getResource(Resource::Type::ROCK) == 5);
    CHECK(p3.getResource(Resource::Type::WHEAT) == 5);
    CHECK(p3.getResource(Resource::Type::SHEEP) ==5);
    CHECK(p3.getResource(Resource::Type::WOOD) == 5);
}

TEST_CASE("Player development cards") {
    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

    p1.addDevelopmentCard(CardType::KNIGHT, 1);
    p1.addDevelopmentCard(CardType::VICTORY_POINT, 1);
    p1.addDevelopmentCard(CardType::ROAD_BUILDING, 1);
    p1.addDevelopmentCard(CardType::MONOPOLY, 1);

    p2.addDevelopmentCard(CardType::KNIGHT, 1);
    p2.addDevelopmentCard(CardType::VICTORY_POINT, 1);
    p2.addDevelopmentCard(CardType::ROAD_BUILDING, 1);
    p2.addDevelopmentCard(CardType::MONOPOLY, 1);

    p3.addDevelopmentCard(CardType::KNIGHT, 1);
    p3.addDevelopmentCard(CardType::VICTORY_POINT, 1);
    p3.addDevelopmentCard(CardType::ROAD_BUILDING, 1);
    p3.addDevelopmentCard(CardType::MONOPOLY, 1);

    CHECK(p1.getDevelopmentCards().at(CardType::KNIGHT) == 1);
    CHECK(p1.getDevelopmentCards().at(CardType::VICTORY_POINT) == 1);
    CHECK(p1.getDevelopmentCards().at(CardType::ROAD_BUILDING) == 1);
    CHECK(p1.getDevelopmentCards().at(CardType::MONOPOLY) == 1);

    CHECK(p2.getDevelopmentCards().at(CardType::KNIGHT) == 1);
    CHECK(p2.getDevelopmentCards().at(CardType::VICTORY_POINT) == 1);
    CHECK(p2.getDevelopmentCards().at(CardType::ROAD_BUILDING) == 1);
    CHECK(p2.getDevelopmentCards().at(CardType::MONOPOLY) == 1);

    CHECK(p3.getDevelopmentCards().at(CardType::KNIGHT) == 1);
    CHECK(p3.getDevelopmentCards().at(CardType::VICTORY_POINT) == 1);
    CHECK(p3.getDevelopmentCards().at(CardType::ROAD_BUILDING) == 1);
    CHECK(p3.getDevelopmentCards().at(CardType::MONOPOLY) == 1);
}
TEST_CASE("Trade") {
    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

    Trade trade(&p1, &p2, {{Resource::Type::BRICK, 1}}, {{Resource::Type::WOOD, 1}});

    // Save the original buffer of std::cin
    std::streambuf* cinBuffer = std::cin.rdbuf();

    // Create a new input stream with the 'y' input followed by a newline character
    std::istringstream testInput("y\n");

    // Redirect std::cin to your input stream
    std::cin.rdbuf(testInput.rdbuf());

    // Now when trade.accept() is called, it will read 'y' from std::cin
    CHECK(trade.accept() == false);

    p1.addResource(Resource::Type::BRICK, 1);
    p2.addResource(Resource::Type::WOOD, 1);
    trade = Trade(&p1, &p2, {{Resource::Type::BRICK, 1}}, {{Resource::Type::WOOD, 1}});

    // Create a new input stream with the 'y' input followed by a newline character for the second accept
    std::istringstream testInput2("y\n");

    // Redirect std::cin to your new input stream
    std::cin.rdbuf(testInput2.rdbuf());

    // Now when trade.accept() is called again, it will read 'y' from std::cin
    CHECK(trade.accept() == true);

    // Don't forget to restore the original std::cin buffer after the test
    std::cin.rdbuf(cinBuffer);

    CHECK(p1.getResource(Resource::Type::BRICK) == 0);
    CHECK(p1.getResource(Resource::Type::WOOD) == 1);
    CHECK(p2.getResource(Resource::Type::BRICK) == 1);
    CHECK(p2.getResource(Resource::Type::WOOD) == 0);
}

TEST_CASE("Catan winner") {
    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

    Catan game(&p1, &p2, &p3);

    p1.addPoints(10);
    CHECK(game.checkWinner() == &p1);
}

TEST_CASE("Building placing"){ // in this test just look awt toutput...
    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

    Catan game(&p1, &p2, &p3);

    game.getBoard().placeSettlement(&p1, 0, 0);
    game.getBoard().placeSettlement(&p2, 1, 0);
    game.getBoard().placeSettlement(&p3, 2, 0);
    game.getBoard().placeRoad(&p1, 0);
    game.getBoard().placeRoad(&p2, 2);
    game.getBoard().placeRoad(&p3, 4);
    game.getBoard().placeCity(&p1, 0);
    game.getBoard().placeCity(&p3, 2);
    game.getBoard().placeRoad(&p1, 6);
    game.getBoard().placeRoad(&p2, 7);
    game.getBoard().placeRoad(&p3, 8);
    //should see city road city and to 3 of them 2 roads connected.

}


TEST_CASE("dice_roll") {
    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);


    Catan game(&p1, &p2, &p3);

    // Place settlements for each player on tiles with known numbers
    game.getBoard().placeSettlement(&p1, 13, 0);
    game.getBoard().placeSettlement(&p2, 14, 0);
    game.getBoard().placeSettlement(&p3, 15, 0);



    SUBCASE("distribute resources") {

        p1.addResource(Resource::Type::WOOD, 1);
        p2.addResource(Resource::Type::BRICK, 1);
        p3.addResource(Resource::Type::SHEEP, 1);
        // Check that each player received the correct resources
        CHECK(p1.getResource(Resource::Type::WOOD) == 1);
        CHECK(p2.getResource(Resource::Type::BRICK) == 1);
        CHECK(p3.getResource(Resource::Type::SHEEP) == 1);

        p1.addResource(Resource::Type::WOOD, 2);

        CHECK(p1.getResource(Resource::Type::WOOD) == 3);
    }

    SUBCASE("Remove resources") {
        
        p1.removeResource(Resource::Type::WOOD, 1);
        p2.removeResource(Resource::Type::BRICK, 1);
        p3.removeResource(Resource::Type::SHEEP, 1);
        // Check that each player received the correct resources
        CHECK(p1.getResource(Resource::Type::WOOD) == 0);
        CHECK(p2.getResource(Resource::Type::BRICK) == 0);
        CHECK(p3.getResource(Resource::Type::SHEEP) == 0);

        p1.removeResource(Resource::Type::WOOD, 2);

        CHECK(p1.getResource(Resource::Type::WOOD) == 0);
    }
}

TEST_CASE("development_cards") {
    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

    Catan game(&p1, &p2, &p3);

    SUBCASE("buy a card") {
        // Give player enough resources to buy a development card
        p1.addResource(Resource::Type::WHEAT, 1);
        p1.addResource(Resource::Type::SHEEP, 1);
        p1.addResource(Resource::Type::ROCK, 1);

        game.buyDevelopmentCard();
        // Buy a development card

        // Check that player has the card
        CHECK(p1.getDevelopmentCards().size() == 1);

    }

    SUBCASE("play a card") {
        // Give player a knight card
        DevelopmentCard* chosenCard = game.drawDevelopmentCard();
        if (chosenCard->getType() == CardType::KNIGHT)
        {
            p1.incrementKnights();
            p1.addDevelopmentCard(chosenCard);
            CHECK(p1.getKnightsNum() == 1);
        }
        else
        {
            CHECK(p1.getKnightsNum() == 0);
        // Check that player's knight count increased
        }
    }
}

    TEST_CASE("simulate user input for trade") {
    // Save the original buffer of std::cin
    std::streambuf* cinBuffer = std::cin.rdbuf();

    // Create a new input stream with the input you want to test
    std::istringstream testInput("1\n5\n5\n5\n0\n0\n4\n5\n5\n5\n9\ny\n");
    // Redirect std::cin to your input stream
    std::cin.rdbuf(testInput.rdbuf());

    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

    Catan game(&p1, &p2, &p3);

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

    game.makeTrade();

    // Check if the trade was successful
    CHECK(p1.getResource(Resource::Type::BRICK) == 0);
    CHECK(p1.getResource(Resource::Type::ROCK) == 10);
    CHECK(p1.getResource(Resource::Type::WHEAT) == 0);
    CHECK(p1.getResource(Resource::Type::SHEEP) == 10);
    CHECK(p1.getResource(Resource::Type::WOOD) == 0);

    CHECK(p2.getResource(Resource::Type::BRICK) == 10);
    CHECK(p2.getResource(Resource::Type::ROCK) == 0);
    CHECK(p2.getResource(Resource::Type::WHEAT) == 10);
    CHECK(p2.getResource(Resource::Type::SHEEP) == 0);
    CHECK(p2.getResource(Resource::Type::WOOD) == 10);

    // Restore std::cin to its original state
    std::cin.rdbuf(cinBuffer);
    



    SUBCASE("trade a development card when player doesn't have any") {
        game.makeCardTrade();
        CHECK(p1.getDevelopmentCards().size() == 0);
    }

    SUBCASE("trade resources when the other player doesn't have any") {
    // Save the original buffer of std::cin
    std::streambuf* cinBuffer = std::cin.rdbuf();

    // Create a new input stream with the input you want to test
    std::istringstream testInput("1\n0\n0\n0\n0\n0\n1\n0\n5\n10\n9\ny\n1\n0\n0\n0\n0\n0\n1\n0\n5\n10\n9\ny\n");
    
    // Redirect std::cin to your input stream
    std::cin.rdbuf(testInput.rdbuf());

    Player p1("AVNER", PlayerColor::RED);
    Player p2("IZTIK", PlayerColor::BLUE);
    Player p3("YAIR", PlayerColor::GREEN);

    Catan game(&p1, &p2, &p3);

    p1.addResource(Resource::Type::BRICK, 1);
    p1.addResource(Resource::Type::ROCK, 10);
    p1.addResource(Resource::Type::SHEEP, 10);

    game.makeTrade();

    // Check if the trade was successful
    CHECK(p1.getResource(Resource::Type::BRICK) == 1);
    CHECK(p1.getResource(Resource::Type::ROCK) == 10);
    CHECK(p1.getResource(Resource::Type::SHEEP) == 10);

    CHECK(p2.getResource(Resource::Type::BRICK) == 0);
    CHECK(p2.getResource(Resource::Type::ROCK) == 0);
    CHECK(p2.getResource(Resource::Type::SHEEP) == 0);

    // Restore std::cin to its original state
    std::cin.rdbuf(cinBuffer);
    }
        
}




