#include "Player.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));

    // предметы первого игрока
    vector<char> bagFirst;
    bagFirst.push_back('a');
    bagFirst.push_back('b');
    bagFirst.push_back('c');
    bagFirst.push_back('d');
    
    // предметы второго игрока
    vector<char> bagSecond;
    bagSecond.push_back('a');
    bagSecond.push_back('r');
    bagSecond.push_back('x');
    bagSecond.push_back('y');
    
    Player firstPlayer("Г1", 10, 10, 100, bagFirst);
    Player secondPlayer("Г2", 0, 0, 100, bagSecond);
    
    cout << "Игрок 1: ";
    firstPlayer.show();
    
    cout << "Игрок 2: ";
    secondPlayer.show();
    
    cout << endl;
    cout << "Результаты операций:" << endl;
    
    Player resultPlus = firstPlayer + secondPlayer;
    cout << "firstPlayer + secondPlayer = ";
    resultPlus.show();
    
    Player resultMinus = firstPlayer - secondPlayer;
    cout << "firstPlayer - secondPlayer = ";
    resultMinus.show();
    
    Player resultDivide = firstPlayer / secondPlayer;
    cout << "firstPlayer / secondPlayer = ";
    resultDivide.show();
    
    // проверка копирования
    Player copyPlayer1(firstPlayer);      
    Player copyPlayer2 = secondPlayer;    
    
    copyPlayer1.show();
    copyPlayer2.show();

    return 0;
}
