#include "Trade.hpp"
#include "Player.hpp"
#include <algorithm>
#include <limits>


bool Trade::accept() {
    string line;
    while (true) {
        cout << receiver->getName() + " do you accept the trade? (y/n)" << endl;
        if (cin.peek() == '\n') {  // only ignore if there's a newline in the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear the input buffer
        }
        getline(cin, line);
        if (!line.empty()) {
            char choice = line[0];
            if (choice == 'y') {
                break;
            } else if (choice == 'n') {
                cout << "Trade declined" << endl;
                return false;
            }
        }
        cout << "Invalid input. Please enter (y/n)." << endl;
    }

    // Check if the receiver has enough resources
    for (auto& [resource, amount] : request) {
        if (receiver->getResource(resource) < amount) {
            cout<<receiver->getName() + " dont have the requested resources"<< endl;
            cout<<"Trade declined"<<endl;
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