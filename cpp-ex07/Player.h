#include <iostream>
#include "Board.h"
#pragma once
using namespace std;

class Player{
    public:
        char myChar;
        string myName;
        virtual const string name()const{return myName;}
        virtual const Coordinate play(const Board& board){return {0,0};}
        char& getChar(){return myChar;}
};