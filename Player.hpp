#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include "catanBoard/Enums.hpp"
#include "DCards/DevelopmentCard.hpp"
#include "catanBoard/Resource.hpp"

    class DevelopmentCard;

    using namespace std;

    class Player {
    private:
        string name;
        PlayerColor color;
        int points;
        int knights;
        map<Resource, int> resources;
        map<CardType, int> developmentCards;

    public:
        Player(const string &name, PlayerColor color) : name(name), color(color), points(0) {} // Initialize the player with 0 points
        int getKnightsNum(){ return knights;}
        void incrementKnights(){knights++;}
        map <CardType, int> getDevelopmentCards(){return developmentCards;}
        string getName() const { return colorToANSICode() + name + "\033[0m"; }
        int getPoints() const { return points; }
        void addResource(const Resource &resource, int amount) {
            resources[resource] += amount;
            cout<<colorToANSICode() <<name<< "\033[0m"<<"Recived "<< amount<<" "<<resource.toEmoji()<<endl;
        }
        void addResources(const std::vector<Resource> &resources) {
            for (const auto &resource : resources) {
            addResource(resource, 1);
            }
        }
        map<Resource, int> getResources() const { return resources; }
        int getResource(const Resource &resource) const { // Return the amount of a specific resource
            auto it = resources.find(resource);
            if (it != resources.end()) {
                return it->second;
            } else {
                return 0;
            }
        }
        void removeResource(const Resource &resource, int amount) {
            resources[resource] -= amount;
            if (resources[resource] < 0) {
                resources[resource] = 0;
            }
        }
        void addDevelopmentCard(DevelopmentCard *card) {
            developmentCards[card->getType()]++;
        }
         
        void addPoints(int p) { points += p; }
        void decreacePoints(int p){points -=p;}
        void printPoints() const;
        int getTotalResources() {
            int total = 0;
            for (const auto &resource : resources) {
                total += resource.second;
            }
            return total;
        }
        std::string colorToANSICode() const {
        switch (color) {
            case PlayerColor::RED:
                return "\033[31m";
            case PlayerColor::BLUE:
                return "\033[34m";
            case PlayerColor::GREEN:
                return "\033[32m";
            default:
                return "\033[0m";  // Reset to default color
        }
    }

    };


