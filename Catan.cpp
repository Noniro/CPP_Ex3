// catan.cpp
#include "Catan.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <vector>


using namespace std;

void Catan::startGame() {
    int startingP = chooseStartingPlayer();
    getBoard().printBoard();

    // Each player places a settlement and road
    for (int i = 0; i < players.size(); i++) {
    currentPlayerIndex = (startingP + i) % players.size();
    cout<<players[currentPlayerIndex]->getName() + "turn."<<endl;
    while (true) {
        try {
            int vertex = getSettlementPlacementFromUser();
            getBoard().placeSettlement(players[currentPlayerIndex], vertex, turnsCounter);
            break;  // If no exception was thrown, break the loop
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // The user will be prompted to enter a new number in the next iteration of the loop
        }
    }
    while (true) {
        try {
            int edge = getRoadPlacementFromUser();
            getBoard().placeRoad(players[currentPlayerIndex], edge);
            break;  // If no exception was thrown, break the loop
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // The user will be prompted to enter a new number in the next iteration of the loop
        }
    }
}

    // Each player places a second settlement and road in reverse order
    for (int i = players.size() - 1; i >= 0; i--) {
    currentPlayerIndex = (startingP + i) % players.size();
    cout<<players[currentPlayerIndex]->getName() + "turn."<<endl;
    while (true) {
        try {
            int vertex = getSettlementPlacementFromUser();
            getBoard().placeSettlement(players[currentPlayerIndex], vertex, turnsCounter);
            break;  // If no exception was thrown, break the loop
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // The user will be prompted to enter a new number in the next iteration of the loop
        }
    }
    while (true) {
        try {
            int edge = getRoadPlacementFromUser();
            getBoard().placeRoad(players[currentPlayerIndex], edge);
            break;  // If no exception was thrown, break the loop
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            // The user will be prompted to enter a new number in the next iteration of the loop
        }
    }
}
}


    int Catan::chooseStartingPlayer() {
        int startingPlayerIndex = rand() % players.size();
        cout << "The starting player is: " << players[startingPlayerIndex]->getName() << endl;
        currentPlayerIndex = startingPlayerIndex;
        return startingPlayerIndex;
    }

    int Catan::rollDice() {
        int roll1 = rand() % 6 + 1;
        int roll2 = rand() % 6 + 1;
        int sum = roll1 + roll2;
        cout << players[currentPlayerIndex]->getName() << " rolled " << sum << endl;

    // check which tiles have the number rolled
    // for each tile, check if there is a settlement on it
    // if there is, give the player the corresponding resource
        if(sum == 7) {
            // Implement logic for when a 7 is rolled
            cout << "A 7 was rolled. players with more than 7 cards must discard half of their cards." << endl;
            ridHalfCards();
            return sum;
        }

    for (int i = 0; i < board.getTiles().size(); i++) {
        if (board.getTiles()[i]->number == sum && board.getTiles()[i]->robber == false){
            for (auto &vertex : board.getTiles()[i]->vertices) {
                if(vertex->owner != nullptr){
                    if(vertex->type == Building::SETTLEMENT){
                        vertex->owner->addResource(board.getTiles()[i]->Tiletype, 1);
                    }
                    else if(vertex->type == Building::CITY){
                        vertex->owner->addResource(board.getTiles()[i]->Tiletype, 2);
                    }
                }
            }
        }
    }
    return sum;
}

void Catan::ridHalfCards() {
    for (int i = 0; i < players.size(); i++) {
        if (players[i]->getTotalResources() > 7) {
            cout << players[i]->getName() << " choose half from your cards to discard. \n" << endl;
            
            map<Resource, int> resources = players[i]->getResources();
            int half = players[i]->getTotalResources() / 2;
            int discarded = 0;
            while(discarded < half){
                for(auto &pair : resources){
                    if(pair.second > 0 && discarded < half){
                        cout << "You have " << pair.second << " " << pair.first.toEmoji() << ". How many do you want to discard?" << endl;
                        int amount;
                        cin >> amount;
                        if (cin.fail()) {
                        cin.clear();  // clear the fail state
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
                        cout << "Invalid input. Please enter an integer." << endl;
                        continue;  // skip the rest of the loop and start the next iteration
                    }

                        if(amount <= 0 || amount > pair.second){
                            cout << "Invalid amount" << endl;
                            continue;
                         }
                         players[i]->removeResource(pair.first, amount);
                         pair.second -= amount;
                         discarded += amount;
                    }
                }
            }
        }
    }
}

Board& Catan::getBoard() {
    return board;
}
    

    DevelopmentCard* Catan::drawDevelopmentCard() {
        if (developmentCards.empty()) {
             throw std::runtime_error("No more development cards left .______.");
        }
        DevelopmentCard* card = developmentCards.top();
        developmentCards.pop();
        return card;
    }

    void Catan::buyDevelopmentCard() {
    Player& player = *players[currentPlayerIndex];
    map<Resource, int> resources = player.getResources();
    if (resources[Resource::Type::ROCK] < 1 || resources[Resource::Type::WHEAT] < 1 || resources[Resource::Type::SHEEP] < 1) {
        cout<<"Not enough resources to buy a development card. (* ￣︿￣)"<<endl;
        return;
    }
        player.removeResource(Resource::Type::ROCK, 1);
        player.removeResource(Resource::Type::WHEAT, 1);
        player.removeResource(Resource::Type::SHEEP, 1);
        DevelopmentCard* card = drawDevelopmentCard();
        player.addDevelopmentCard(card);
        cout<<player.getName() + " bought a development card. ( ͡° ͜ʖ ͡°)"<<endl;
        if(card->getType() == CardType::KNIGHT){
            player.incrementKnights();
            checkBiggestArmy();
        }
        if(card->getType() == CardType::VICTORY_POINT){
            player.addPoints(1);
        }
        delete card;
    
}

    bool Catan::playDevelopmentCard() {
    Player* currentPlayer = players[currentPlayerIndex];
    map<CardType, int> playerCards = currentPlayer->getDevelopmentCards();
    if(playerCards.empty()){
        cout<<"No development cards to play. (˘･_･˘)"<<endl;
        return false;
    }

    // Create a mapping from CardType values to names
    map<CardType, std::string> cardNames = {
        {CardType::KNIGHT, "Knight"},
        {CardType::VICTORY_POINT, "Victory Point"},
        {CardType::ROAD_BUILDING, "Road Building"},
        {CardType::YEAR_OF_PLENTY, "Year of Plenty"},
        {CardType::MONOPOLY, "Monopoly"}
    };

    // Print the player's cards
    cout << "Enter a number which card to play from your cards:\n";
    int option = 1;
    vector<CardType> cardTypes;
    for (const auto& pair : playerCards) {
        std::cout << option << ". " << cardNames[pair.first] << ":" << pair.second << "\n";
        cardTypes.push_back(pair.first);
        option++;
    }
    // Get the user's choice
    int choice;
    cin >> choice;
    if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input. Please enter an integer." << endl;
        return false;
    }
    if (choice < 1 || choice > playerCards.size()) {
        cout << "Invalid choice. Please enter a number between 1 and " << playerCards.size() << endl;
        return false;
    }
    
    // Get the card type from the user's choice
    CardType chosenType = cardTypes[choice - 1];
    if(chosenType==CardType::KNIGHT || chosenType==CardType::VICTORY_POINT){
        cout<<"This card is a passive card!"<<endl;
        return false;
    }
    PromotionCard* chosenCard = dynamic_cast<PromotionCard*>(DevelopmentCard::createCard(chosenType));
    chosenCard->play(*currentPlayer, *this);
    currentPlayer->removeDevelopmentCard(chosenType);
    delete chosenCard;
    return true;
    }

    int Catan::getSettlementPlacementFromUser() {
        cout << "Enter the vertex number where you want to place your settlement: ";
        int vertex;
        cin >> vertex;
        if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input. Please enter an integer." << endl;
        return -1;
        }
        return vertex;
    }

    int Catan::getRoadPlacementFromUser() {
        cout << "Enter the edge number where you want to place your road: ";
        int edge;
        cin >> edge;
        if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input. Please enter an integer." << endl;
        return -1;
        }
        return edge;
    }

    void Catan::placeSettlement() {
        map<Resource, int> resources = players[currentPlayerIndex]->getResources();
        if(resources[Resource::Type::BRICK] < 1 || resources[Resource::Type::WOOD] < 1 ||
           resources[Resource::Type::WHEAT] < 1 || resources[Resource::Type::SHEEP] < 1) {
            cout << "Not enough resources to place a settlement." << endl;
            return;
        }
        int vertex = getSettlementPlacementFromUser();
        if (!board.hasConnectedRoad(players[currentPlayerIndex], vertex)) {
        cout << "No connected road." << endl;
        return;
        }
        try{
            board.placeSettlement(players[currentPlayerIndex], vertex, turnsCounter);
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return;
        }
        players[currentPlayerIndex]->removeResource(Resource::Type::BRICK, 1);
        players[currentPlayerIndex]->removeResource(Resource::Type::WOOD, 1);
        players[currentPlayerIndex]->removeResource(Resource::Type::WHEAT, 1);
        players[currentPlayerIndex]->removeResource(Resource::Type::SHEEP, 1);
        
}

    void Catan::placeRoad() {
        map<Resource, int> resources = players[currentPlayerIndex]->getResources();
        if(resources[Resource::Type::BRICK] < 1 || resources[Resource::Type::WOOD] < 1) {
            cout << "Not enough resources to place a road." << endl;
            return;
        }
        int edge = getRoadPlacementFromUser();
        try{
            board.placeRoad(players[currentPlayerIndex], edge);
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return;
        }
        players[currentPlayerIndex]->removeResource(Resource::Type::BRICK, 1);
        players[currentPlayerIndex]->removeResource(Resource::Type::WOOD, 1);
    }

    void Catan::placeCity() {
        map<Resource, int> resources = players[currentPlayerIndex]->getResources();
        if(resources[Resource::Type::ROCK] < 3 || resources[Resource::Type::WHEAT] < 2) {
            cout << "Not enough resources to place a city." << endl;
            return;
        }
        int vertex = getSettlementPlacementFromUser();
        try{
            board.placeCity(players[currentPlayerIndex], vertex);
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return;
        }
        players[currentPlayerIndex]->removeResource(Resource::Type::ROCK, 3);
        players[currentPlayerIndex]->removeResource(Resource::Type::WHEAT, 2);
    }

    void Catan::placeKnight() {
    int tileIndex;
    while (true) {
        cout << "Enter the tile index where you want to place your knight: ";
        cin >> tileIndex;
        try {
            board.placeKnight(players[currentPlayerIndex], tileIndex);
            break;  // If placeKnight doesn't throw an exception, break out of the loop
        } catch (const invalid_argument &e) {
            cout << "Error: " << e.what() << endl;
            // If an exception is thrown, the loop will continue and the user will be prompted again
        }
    } 
    players[currentPlayerIndex]->incrementKnights();
}

   void Catan::showCards() {
    cout << "1. Show resources" << endl;
    cout << "2. Show development cards" << endl;
    int choice;
    cin >> choice;

    // Check if the input was not an integer
    if (cin.fail()) {
        cin.clear();  // Clear the error state of the cin object
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the line
        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    if (choice == 1) {
        map<Resource, int> resources = players[currentPlayerIndex]->getResources();
        if (resources.empty()) {
            cout << "No resources (；′⌒`)" << endl;
            return;
        }
        for (const auto &pair : resources) {
            cout << pair.first.toEmoji() << " : " << pair.second << endl;
        }
    } else if (choice == 2) {
        map<CardType, int> developmentCards = players[currentPlayerIndex]->getDevelopmentCards();
        if (developmentCards.empty()) {
            cout << "No development cards ಥ_ಥ" << endl;
            return;
        }
        vector<CardType> cardTypes;
        cout << "Enter card number for description:" << endl;
        for (const auto &pair : developmentCards) {
            cout << cardTypeToString(pair.first) << " : " << pair.second << endl;
            cardTypes.push_back(pair.first);
        }
        int cardNumber;
        cin >> cardNumber;
        if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input. Please enter an integer." << endl;
        return;
    }
        if (cardNumber < 1 || cardNumber > developmentCards.size()) {
            cout << "Invalid card number" << endl;
            return;
        }
        CardType cardType = cardTypes[cardNumber - 1];
        DevelopmentCard* card = DevelopmentCard::createCard(cardType);
        card->description();
    } else {
        cout << "Invalid choice" << endl;
    }
}

map<Resource, int> Catan::getRequestResources() {
    map<Resource, int> request;
    int resourceIndex;
    int amount;
    do {
        cout << "Choose a resource to request:" << endl;
        cout << "1. " << Resource(Resource::Type::WOOD).toEmoji() << endl;
        cout << "2. " << Resource(Resource::Type::BRICK).toEmoji()<<endl;
        cout << "3. " << Resource(Resource::Type::WHEAT).toEmoji()<<endl;
        cout << "4. " << Resource(Resource::Type::SHEEP).toEmoji() << endl;
        cout << "5. " << Resource(Resource::Type::ROCK).toEmoji()<<endl;
        cout << "9. Done" << endl;

        cin >> resourceIndex;

        if (resourceIndex >= 1 && resourceIndex <= 5) {
            cout << "Enter number of " + Resource(static_cast<Resource::Type>(resourceIndex-1)).toEmoji() << " to request." << endl;
            cin >> amount;
            request[Resource(static_cast<Resource::Type>(resourceIndex-1))] = amount;
        }
    } while (resourceIndex != 9);

    return request;
}


    void Catan::makeTrade() {
    //Get the player to trade with
    int player1 = currentPlayerIndex+1%3;
    int player2 = currentPlayerIndex+2%3;
    cout << "Enter the player you want to trade with:\n1." << players[player1]->getName()<<"\n2."<<players[player2]->getName()<<endl; ;
    int playerIndex;
    cin >> playerIndex;
    if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input." << endl;
        return;
    }
    if(playerIndex != 1 && playerIndex != 2){
        cout << "Invalid player index" << endl;
        return;
    }
    if(playerIndex == 1){
        playerIndex = player1;
    } else {
        playerIndex = player2;
    }
    Player* receiver = players[playerIndex];
    // Get the resources the player wants to offer
    Player* sender = players[currentPlayerIndex];
    map<Resource, int> senderResources = sender->getResources();
    if(senderResources.empty()){
        cout<<"No resources to trade (；′⌒`)"<<endl;
    }
    map<Resource, int> offer;
    for(const auto &pair : senderResources) {
    int amount;
    while (true) {
        cout << "You ("<<sender->getName()+")"<< " have " + to_string(pair.second) +" " << pair.first.toEmoji()  << " to trade." << endl;
        cout << "Enter the amount of " + pair.first.toEmoji() + " you want to offer:" << endl;
        cin >> amount;
        if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input. Please enter an integer." << endl;
        continue;  // skip the rest of the loop and start the next iteration
        }
        if(pair.second >= amount){
            offer[pair.first] = amount;
            break;  // If the player has enough resources, break the loop
        } else {
            cout << "You don't have enough " + pair.first.toEmoji() << " to trade." << endl;
            // The loop will continue, prompting the user to enter a new number
        }
    }
}
    // Get the resources the player wants to request
map<Resource, int> request = getRequestResources();

    // Create the trade
    Trade trade(sender, receiver, offer, request);

    //print the trade
    cout<<"player "<<sender->getName()<<" offers player "<<receiver->getName()<<endl;
    for(const auto &pair : offer){
        cout<<pair.second<<" "<< pair.first.toEmoji() <<endl;   
    }
    cout<<"for"<<endl;
    for(const auto &pair : request){
        cout<<pair.second<<" "<<pair.first.toEmoji()<<endl;   
    }
    trade.accept();
}

void Catan::makeCardTrade() {
    Player* sender = players[currentPlayerIndex];
    map<CardType, int> senderCards = sender->getDevelopmentCards();
    if(senderCards.empty()){
        cout<<"No development cards to trade (；′⌒`)"<<endl;
        return;
    }
    //Get the player to trade with
    int player1 = currentPlayerIndex+1%3;
    int player2 = currentPlayerIndex+2%3;
    cout << "Enter the player you want to trade with:\n1." << players[player1]->getName()<<"\n2."<<players[player2]->getName()<<endl; ;
    int playerIndex;
    cin >> playerIndex;
    if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input." << endl;
        return;
    }
    if(playerIndex != 1 && playerIndex != 2){
        cout << "Invalid player index" << endl;
        return;
    }
    if(playerIndex == 1){
        playerIndex = player1;
    } else {
        playerIndex = player2;
    }
    Player* receiver = players[playerIndex];
    // Get the Development cards the player wants to offer
    map<CardType, int> offer;
    for(const auto &pair : senderCards) {
    int amount;
    while (true) {
        cout << "You ("<<sender->getName()+")"<< " have " + to_string(pair.second) +" " << cardTypeToString(pair.first)  << " to trade." << endl;
        cout << "Enter the amount of " + cardTypeToString(pair.first) + " you want to offer:" << endl;
        cin >> amount;
        if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input. Please enter an integer." << endl;
        continue;  // skip the rest of the loop and start the next iteration
        }
        if(pair.second >= amount){
            offer[pair.first] = amount;
            break;  // If the player has enough resources, break the loop
        } else {
            cout << "You don't have enough " + cardTypeToString(pair.first) << " to trade." << endl;
            // The loop will continue, prompting the user to enter a new number
        }
    }
}
    // Get the Resources the player wants to request
    map<Resource, int> request = getRequestResources();

    //print the trade
    cout<<"player "<<sender->getName()<<" offers player "<<receiver->getName()<<endl;
    for(const auto &pair : offer){
        cout<<pair.second<<" "<< cardTypeToString(pair.first) <<endl;   
    }
    cout<<"for"<<endl;
    for(const auto &pair : request){
        cout<<pair.second<<" "<<pair.first.toEmoji()<<endl;   
    }
    char choice;
    while (true) {
        cout << receiver->getName() +" do you accept the trade? (y/n)" << endl;
        cin >> choice;
        if (choice == 'y') {
            break;
        } else if (choice == 'n') {
            cout << "Trade declined" << endl;
            return;
        } else {
            cout << "Invalid input. Please enter (y/n)." << endl;
        }
    }
    for (auto& [resource, amount] : request) {
        if (receiver->getResource(resource) < amount) {
            cout<<receiver->getName() + " dont have the requested resources"<< endl;
            cout<<"Trade declined"<<endl;
            return;
        }
    }
    // Transfer the resources
    for (auto& [resource, amount] : request) {
        receiver->removeResource(resource, amount);
        sender->addResource(resource, amount);
    }
    for (auto& [CardType, amount] : offer) {
        sender->removeDevelopmentCard(CardType, amount);
        receiver->addDevelopmentCard(CardType, amount);
    }

}

    



    string Catan::cardTypeToString(CardType cardType) {
    switch (cardType) {
        case CardType::KNIGHT:
            return "⚔ Knight";
        case CardType::VICTORY_POINT:
            return "🏆 Victory Point";
        case CardType::ROAD_BUILDING:
            return "🚧 Road Building";
        case CardType::YEAR_OF_PLENTY:
            return "🌸 Year of Plenty";
        case CardType::MONOPOLY:
            return "🏦 Monopoly";
        default:
            throw std::invalid_argument("Invalid card type");
    }
}

    
    Player* Catan::checkWinner() {
        for (int i = 0; i < players.size(); i++) {
            if (players[i]->getPoints() >= 10) {
                return players[i];
            }
        }
        return nullptr;
    }

     void Catan::checkBiggestArmy() {
        Player* bigPPArmy = nullptr;
        int knightsNum = 3;
        for(int i = 0; i < players.size(); i++) {
            if(players[i]->getKnightsNum() > knightsNum) {
                bigPPArmy = players[i];
                knightsNum = players[i]->getKnightsNum();
            }
        }
        if (playerWithBiggestArmy != bigPPArmy) {
            if (playerWithBiggestArmy != nullptr) {
                playerWithBiggestArmy->decreacePoints(2);
            }
            if (bigPPArmy != nullptr) {
                bigPPArmy->addPoints(2);
            }
            playerWithBiggestArmy = bigPPArmy;
        }
    }

    void Catan::endTurn() {
        if(players[currentPlayerIndex]->getPoints() >= 10){
            cout << "The winner is: " << players[currentPlayerIndex]->getName() << endl;
            return;
        }
        turnsCounter++;
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        cout<<players[currentPlayerIndex]->getName() + " turn."<<endl;
        board.printBoard();
    }

    void Catan::gameDescription() {
        cout << "Enter action:\n"
                << "1: How_to_play\n"
                << "2: Costs\n"
                << "3: Development cards\n"
                << "4: Resources\n"
                << "5: Victory points\n"
                << "6: Buildings\n"
                << "9: Return to game\n";
        int choice;
        cin >> choice;
        if (cin.fail()) {
        cin.clear();  // clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the bad input
        cout << "Invalid input. Please enter an integer." << endl;
        return;  // skip the rest of the loop and start the next iteration
        }
        if (choice == 1) {
            cout << "Each player takes turns rolling the dice by pressing '1' and collecting resources based on the number rolled. Players can use resources to build settlements, roads, and cities, as well as buy development cards. The first player to reach 10 points wins the game." << endl;
        } else if (choice == 2) {
            cout << "Costs:\n"
                    << "Settlement: 1 brick 🧱, 1 wood 🌲, 1 wheat 🌾, 1 sheep 🐑\n"
                    << "Road: 1 brick 🧱, 1 wood 🌲\n"
                    << "City: 3 rock ⛰, 2 wheat 🌾\n"
                    << "Development card: 1 rock ⛰, 1 wheat 🌾, 1 sheep 🐑\n"; 
        } else if (choice == 3) {
            cout << "Development cards are special cards that players can buy and play to gain an advantage in the game." << endl;
            cout << "When holding a development card, players can read the description of the card." << endl;
        } else if (choice == 4) {
            cout << "There are 5 resources in the game: Wood, Sheep, Wheat, Brick, and Rock. Players can collect resources by building settlements and cities on tiles with corresponding numbers." << endl;
        } else if (choice == 5) {
            cout << "Victory points are earned by building settlements, cities, and having the largest army. The first player to reach 10 points wins the game." << endl;
        } else if (choice == 6) {
            cout << "Players can build settlements, roads, and cities on the board. Settlements and cities provide resources, while roads connect settlements and cities." 
                    << "Settlement: 1 point, 1 resource\n"
                    << "City: 2 points, 2 resources\n"
                    << "Road: for connecting settlements and cities\n";
        } else if (choice == 9) {
            return;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
                

