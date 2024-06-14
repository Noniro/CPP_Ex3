#pragma once

#include <vector>
#include <map>
#include <string>
#include "Player.hpp"
#include <algorithm>
#include "catanBoard/Resource.hpp"

    
    class Player;
    class Trade;

using namespace std;

class Trade {
private:
    Player* sender;
    Player* receiver;
    map<Resource, int> offer; // The resources being offered 
    map<Resource, int> request; // The resources being requested in return

public:
    Trade(Player* sender, Player* receiver, map<Resource, int> offer, map<Resource, int> request)
        : sender(sender), receiver(receiver), offer(offer), request(request) {}

    bool accept();

};
