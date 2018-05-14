#include "exeptions.hpp"
#include "square.hpp"
#include <iostream>
using namespace std;
class Board{
    public:
    int size;
    square** board;
    Board(int num);
    Board(const Board& b);
    ~Board();
    friend ostream& operator<<(ostream& out,Board const &b);
    square& operator[](const pair<int,int>& someIndex);
    Board& operator=(char c);
    Board& operator=(Board &b);
    bool operator==(Board &b)const;
};
