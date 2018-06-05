#include "exeptions.hpp"
#include "Coordinate.hpp"
#include <iostream>
#pragma once
using namespace std;

class Board{
    public:
    int SIZE;
    Coordinate** board;
    Board(){}
    Board(int num);
    Board(const Board& b);
    ~Board();
    uint size() const;
    friend ostream& operator<<(ostream& out,Board const &b);
    // Coordinate& operator[](const pair<int,int>& someIndex);
    Coordinate& operator[](const Coordinate& c)const;
    Board& operator=(char c);
    Board& operator=(Board &b);
    bool operator==(Board &b)const;
};
