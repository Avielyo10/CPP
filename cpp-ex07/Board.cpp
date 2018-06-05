#include "Board.h"
#include <iostream>
using namespace std;

Board::Board(int num){
    board = new Coordinate*[num];
    for(int i = 0; i < num;++i){
        board[i] = new Coordinate[num];
        for(int j = 0; j < num;++j){
            board[i][j] = '.';
        }
    }
    SIZE = num;
}
Board::Board(const Board& b){
    SIZE = b.SIZE;
    board = new Coordinate*[SIZE];
    for(int i = 0; i < SIZE;++i){
        board[i] = new Coordinate[SIZE];
        for(int j = 0; j < SIZE;++j){
            board[i][j] = b.board[i][j];
        }
    }
}
Board::~Board(){
    for(int i = 0; i < SIZE;++i){
        delete[] board[i];
    }
    delete[] board;
}
ostream& operator<<(ostream& out,Board const &b){
    string res = "";
    for(int i = 0; i<b.SIZE; ++i){
        for(int j = 0; j<b.SIZE; ++j){
            res+=b.board[i][j];
        }
        res+="\n";
    }
    return out<<res;
}
Coordinate& Board::operator[](const Coordinate& c)const{
    if(c.getIndexI()>=SIZE||c.getIndexJ()>=SIZE){
        throw(IllegalCoordinateException({c.getIndexI(),c.getIndexJ()}));
    }
    return board[c.getIndexI()][c.getIndexJ()];
}
// Coordinate& Board::operator[](const pair<int,int>& someIndex){
//     if(someIndex.first>=SIZE||someIndex.second>=SIZE){
//         throw(IllegalCoordinateException(someIndex));
//     }
//     return board[someIndex.first][someIndex.second];
// }
Board& Board::operator=(char c){
    if(c=='.'){
         for(int i = 0; i < SIZE;++i){
            for(int j = 0; j < SIZE;++j){
                board[i][j] = c;
            }
        } 
    }
    else{
        throw(IllegalCharException(c));
    }
    return *this;
}
Board& Board::operator=(Board &b){
    if(SIZE>0){
        this->~Board();
    }
    SIZE=b.SIZE;
    board = new Coordinate*[SIZE];
    for(int i = 0; i < SIZE;++i){
        board[i] = new Coordinate[SIZE];
        for(int j = 0; j < SIZE;++j){
            board[i][j] = b.board[i][j];
        }
    }
    return *this;
}
bool Board::operator==(Board &b)const{
    if(SIZE!=b.SIZE){
        return false;
    }
    bool flag = true;
    for(int i = 0;i < SIZE; ++i){
        for(int j = 0;j < SIZE; ++j){
            if(board[i][j]!=b.board[i][j]){
                flag = false;
            }
        }
    }
    return flag;
}
uint Board::size() const{
    return SIZE;
}
