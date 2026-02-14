#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
    string playerName;     // имя игрока
    int x;                 // координата X
    int y;                 // координата Y
    int health;            // здоровье
    vector<char> bag;      // рюкзак с предметами

    string generateName(); // генерация случайного имени

public:
    Player();
    Player(string name, int posX, int posY, int hp, vector<char> items);
    
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();
    
    Player operator+(const Player& other);
    Player operator-(const Player& other);
    Player operator/(const Player& other);
    
    void show();
};

#endif
