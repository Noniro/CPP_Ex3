
# Catan Terminal Game
A terminal-based version of the popular board game Catan. 

## Author
name: [Yuval Vogdan]
email: [yuvalv126@gmail.com]
github: [https://github.com/Noniro}

## Overview
this is a terminal based game. the game is a simplefied version of the popular board game Catan. the game is played by 3 players. on an 19 tiles board like the original game. in this version the gameplay is exactly the same except for knights, robber and the ports and will be explained in the game rules section. each player has a color and a name. During the game the players will be able to build settlements, cities and roads. the game ends when a player reaches 10 points. 

## Table of Contents
- [Author](#author)
- [Overview](#overview)
- [Game Rules](#game-rules)
- [setup](#setup)
- [Gameplay](#gameplay)
- [Project Structure](#project-structure)
- [Classes](#classes)
  - [Catan](#catan)
  - [DCards directory](#dcards-directory)
  - [catanBoard directory](#catanboard-directory)



## Author
Name: [Your Name]  
Email: [Your Email]  
GitHub: [Your GitHub Profile Link]


## Game Rules
The game makes the player choose 2 settelments and roads to place on the board. the player can only place the settelments on the corners of the tiles where the X's are marked and roads on the edges of the tiles. settelments cannot be placed freely and next to each other meaning at least two roads are seperating betwin them. And roads like settelments cannot be placed freely and must be connected to the settelments or another road. In each turn the player must first roll the dices or play a development card. If the player chose to play first a development card the turn will end for him when he plays the card. If the player chose to roll the dices he will get resources according to the number he rolled. the player then can build roads, settelments or cities, buy development cards or trade with the other players resources and development cards. the player can also play a development card if he has one.

### Objective
The objective of the game is to be the first player to reach 10 points. Points are earned by building settlements, cities, and roads, and by having the longest road and the largest army.
there is only one winner in the game!

### Setup
In the main.cpp file you can set how the game will run. the game.gameStart function initiates the first loop of the game where each player choosing 2 settelments and roads to place on the board. theres an example of an already set game in the main.cpp file.
Run the game. (in the terminal 'make' and then './catan').

### Gameplay
This game is a terminal based game. In the start of each turn the game board is printed to show the updated board and the player will have 2 options. to roll the dices or play a development card: 


![Screenshot_26](https://github.com/Noniro/CPP_Ex3/assets/118755760/e2141d7f-46fa-4f91-9c17-5defb70ff785)



the player needs to input the number of the action he wants to do. 
after rolling the dices (1) the player will get resources according to the number he rolled.
and a menu will appear with the following options example: 
~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
![Screenshot_27](https://github.com/Noniro/CPP_Ex3/assets/118755760/393d7cb9-6273-480d-b433-e1fb0030b248)

 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 A sertain action can open a new menu with more options.
 to exit a menu you can press 9 or any other key or number that is not an option.
 New players can access the how_to_play menu by pressing 9 in the main menu to get help on how to play the game, the rules, costs and the objective of the game.
 

### Scoring
The game ends when a player reaches 10 points. Points are earned by building settlements, cities, and roads, and by having the largest army.
settelment grants 1 point.
city grants 2 points. -(uprading a settelment to a city)
vicotry point card grants 1 point. -(a development card named victory point)
largest army grants 2 points. -(having the largest amount of knights)


## Project Structure

### Classes

#### Catan
- catan this class is responsible for keeping any data that is related to the game and all the game functions that a player have excess to. the game board, the players, the development cards, the dice roll and the turn order and the function for placing a settelment,city or road that will reduce the players resources accordingly and will call the main function in the related class.
for example: 

```cpp
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
            board.placeSettlement(players[currentPlayerIndex], vertex, turnsCounter); //calls the main function in the board class
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            return;
        }
        players[currentPlayerIndex]->removeResource(Resource::Type::BRICK, 1);
        players[currentPlayerIndex]->removeResource(Resource::Type::WOOD, 1);
        players[currentPlayerIndex]->removeResource(Resource::Type::WHEAT, 1);
        players[currentPlayerIndex]->removeResource(Resource::Type::SHEEP, 1);
        
}
```

- Player - this class is responsible for keeping any data that is related to the player. the player name, color, resources, development cards and points the player class mainly got getters and setters methods.
#### DCards directory 
 this directory contains all the development cards classes. each class is a different development card. the development cards are: knight, monopoly, road building, year of plenty and victory point. while the knight and victory point cards are passive cards and the other cards are active cards. The hirearchy of the development cards is as follows:

                /-> Knight        /-> Monopoly
DevelopmentCard --> PromotionCard --> YearOfPlenty 
                \-> VictoryPoint  \-> RoadBuilding

* DevelopmentCard is an abstract class with basic card fields and virtual methods. 
- Knight is a class that inherits from DevelopmentCard.
- VictoryPoint is a class that inherits from DevelopmentCard.
* PromotionCard is an abstract class that inherits from DevelopmentCard and has a pure virtual method 'play'.
- Monopoly is a class that inherits from PromotionCard.
- YearOfPlenty is a class that inherits from PromotionCard.
- RoadBuilding is a class that inherits from PromotionCard.


#### catanBoard directory 
this directory contains all the classes that are related to the game board. 
* Tile , Edge and Vertex are classes to keep the relation between each tile and his 6 vertices and 6 edges. each vertex has its edges that are connected to it and each edge has its vertices that are connected to it. the tile class has a number and a resource type. the edge class has a road and the vertex class has a settelment that are both represented by a player pointer (owner).
* Board class is responsible for keeping any data that is related to the board. the tiles, the vertices and edges. the board class also contains the functions related to the Board.
the board constructor is a defalut constructor and initializes the board when called with all the tiles, vertices and edges. 



