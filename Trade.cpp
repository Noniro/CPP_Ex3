#include "Trade.hpp"
#include "Player.hpp"
#include <algorithm>

bool Trade::accept() {
    char choice;
    while (true) {
        cout << receiver->getName() +" do you accept the trade? (y/n)" << endl;
        cin >> choice;
        if (choice == 'y') {
            break;
        } else if (choice == 'n') {
            cout << "Trade declined" << endl;
            return false;
        } else {
            cout << "Invalid input. Please enter (y/n)." << endl;
        }
    }

    // Check if the receiver has enough resources
    for (auto& [resource, amount] : request) {
        if (receiver->getResource(resource) < amount) {
            cout<<receiver->getName() + "dont have the requested resources"<< endl;
            return false;
        }
    }

    // Transfer the resources
    for (auto& [resource, amount] : request) {
        receiver->removeResource(resource, amount);
        sender->addResource(resource, amount);
    }
    for (auto& [resource, amount] : offer) {
        sender->removeResource(resource, amount);
        receiver->addResource(resource, amount);
    }

    return true;
}