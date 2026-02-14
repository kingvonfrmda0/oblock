#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Конструктор по умолчанию
Player::Player() {
    playerName = "Unknown";
    x = 0;
    y = 0;
    health = 100;
}

// Конструктор с параметрами
Player::Player(string name, int posX, int posY, int hp, vector<char> items) {
    playerName = name;
    x = posX;
    y = posY;
    health = hp;
    bag = items;
}

// Конструктор копирования
Player::Player(const Player& other) {
    playerName = other.playerName;
    x = other.x;
    y = other.y;
    health = other.health;
    bag = other.bag;
}

// Оператор присваивания
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        playerName = other.playerName;
        x = other.x;
        y = other.y;
        health = other.health;
        bag = other.bag;
    }
    return *this;
}

Player::~Player() {
}

// Функция для случайного имени
string Player::generateName() {
    string names[6] = {"Г1", "Г2", "Г3", "Г4", "Г5", "Г6"};
    int index = rand() % 6;
    return names[index];
}

// Оператор +
Player Player::operator+(const Player& other) {
    Player result;

    result.playerName = generateName();
    result.x = (x + other.x) / 2;
    result.y = (y + other.y) / 2;
    result.health = health;

    // копируем свои предметы
    result.bag = bag;

    // добавляем предметы второго игрока, если их нет
    for (int i = 0; i < other.bag.size(); i++) {

        bool found = false;

        for (int j = 0; j < result.bag.size(); j++) {
            if (other.bag[i] == result.bag[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            result.bag.push_back(other.bag[i]);
        }
    }

    return result;
}

// Оператор -
Player Player::operator-(const Player& other) {
    Player result;

    result.playerName = generateName();
    result.x = x;
    result.y = y;
    result.health = health;
    result.bag = bag;

    // удаляем первый найденный символ 'a'
    for (int i = 0; i < result.bag.size(); i++) {
        if (result.bag[i] == 'a') {
            result.bag.erase(result.bag.begin() + i);
            break;
        }
    }

    return result;
}

// Оператор /
Player Player::operator/(const Player& other) {
    Player result;

    result.playerName = generateName();
    result.x = x + other.x + 5;
    result.y = y + other.y - 5;
    result.health = health;

    int half1 = bag.size() / 2;
    for (int i = 0; i < half1; i++) {
        result.bag.push_back(bag[i]);
    }

    int half2 = other.bag.size() / 2;
    for (int i = half2; i < other.bag.size(); i++) {
        result.bag.push_back(other.bag[i]);
    }

    return result;
}

// Вывод информации
void Player::show() {

    cout << "[" << playerName << ", "
         << x << ", "
         << y << ", (";

    for (int i = 0; i < bag.size(); i++) {
        cout << bag[i];
        if (i < bag.size() - 1) {
            cout << ",";
        }
    }

    cout << ")]" << endl;
}
