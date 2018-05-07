#include "Board.h"
#include <iostream>
using namespace std;
Board::Board(int num){
    board = new square*[num];
    for(int i = 0; i < num;++i){
        board[i] = new square[num];
        for(int j = 0; j < num;++j){
            board[i][j] = '.';
        }
    }
    size = num;
}
Board::Board(const Board& b){
    size = b.size;
    board = new square*[size];
    for(int i = 0; i < size;++i){
        board[i] = new square[size];
        for(int j = 0; j < size;++j){
            board[i][j] = b.board[i][j];
        }
    }
}
Board::~Board(){
    for(int i = 0; i < size;++i){
        delete[] board[i];
    }
    delete[] board;
}
ostream& operator<<(ostream& out,Board const &b){
    string res = "";
    for(int i = 0; i<b.size; ++i){
        for(int j = 0; j<b.size; ++j){
            res+=b.board[i][j];
        }
        res+="\n";
    }
    return out<<res;
}
square& Board::operator[](const pair<int,int>& someIndex){
    if(someIndex.first>=size||someIndex.second>=size){
        throw(IllegalCoordinateException(someIndex));
    }
    return board[someIndex.first][someIndex.second];
}
Board& Board::operator=(char c){
    if(c=='.'){
         for(int i = 0; i < size;++i){
            for(int j = 0; j < size;++j){
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
    if(size>0){
        this->~Board();
    }
    size=b.size;
    board = new square*[size];
    for(int i = 0; i < size;++i){
        board[i] = new square[size];
        for(int j = 0; j < size;++j){
            board[i][j] = b.board[i][j];
        }
    }
    return *this;
}
bool Board::operator==(Board &b)const{
    if(size!=b.size){
        return false;
    }
    bool flag = true;
    for(int i = 0;i < size; ++i){
        for(int j = 0;j < size; ++j){
            if(board[i][j]!=b.board[i][j]){
                flag = false;
            }
        }
    }
    return flag;
}
