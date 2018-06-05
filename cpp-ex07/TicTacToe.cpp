#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe(int num){
   Board temp {num};
   gameBoard = temp;
}
Board TicTacToe::board() const{
    return gameBoard;
}
Player TicTacToe::winner() const{
    for(int i =0;i<gameBoard.SIZE;++i){
        for(int j =0;j<gameBoard.SIZE;++j){
            gameBoard.board[i][j] = '.';
        }
    }
    return winPlayer;
}
bool TicTacToe::checkVer(Player& p){
   for(int i = 0;i<gameBoard.SIZE;++i){
        int counter=0;
        for (int j = 0;j<gameBoard.SIZE;++j){
            if(gameBoard.board[j][i]==p.myChar){
                counter++;
            }
        }
        if(counter==gameBoard.SIZE){
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkHor(Player& p){
    for(int i = 0;i<gameBoard.SIZE;++i){
        int counter=0;
        for (int j = 0;j<gameBoard.SIZE;++j){
            if(gameBoard.board[i][j]==p.myChar){
                counter++;
            }
        }
        if(counter==gameBoard.SIZE){
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkRDig(Player& p){
    int counter=0;
    int i = 0, j = gameBoard.SIZE-1;
    while(i<gameBoard.SIZE){
        if(gameBoard.board[i][j]==p.myChar){
           counter++; 
        }
        i++;
        j--;
    }
    if(counter==gameBoard.SIZE){
        return true;
    }
    return false;
}
bool TicTacToe::checkLDig(Player& p){
    int counter=0;
    int i = 0;
    while(i<gameBoard.SIZE){
        if(gameBoard.board[i][i]==p.myChar){
           counter++; 
        }
        i++;
    }
    if(counter==gameBoard.SIZE){
        return true;
    }
    return false;
}

void TicTacToe::checkWinnings(Player& p){
    if((checkVer(p)||checkHor(p)||checkRDig(p)||checkLDig(p))&&gameBoard.SIZE>2){
        isWinner=true;
        winPlayer.myName = p.name(); 
        winPlayer.myChar = p.getChar();
    }
}
bool TicTacToe::checkIfFull(){
    for(int i = 0;i<gameBoard.SIZE;++i){
        for (int j = 0;j<gameBoard.SIZE;++j){
            if(gameBoard.board[i][j]=='.'){
                return false;
            }
        }
    }
    return true;
}
void TicTacToe::play(Player& xPlayer,Player& oPlayer){
    isFull = false, isWinner = false;
    xPlayer.myChar='X';
    oPlayer.myChar='O';
    while(!isWinner&&!isFull){
        try{
          Coordinate x = xPlayer.play(gameBoard);
          if(gameBoard[x]=='.'){
            gameBoard[x] = xPlayer.getChar();
            checkWinnings(xPlayer);
            isFull = checkIfFull(); 
            }
          else{
            winPlayer.myName = oPlayer.name();
            winPlayer.myChar = oPlayer.getChar();
            break;
        }  
        }catch(string& ex){
            winPlayer.myChar = oPlayer.getChar();
            winPlayer.myName = oPlayer.name();
            break;
        }
        if(isFull&&!isWinner){
            winPlayer.myName = oPlayer.name();
            winPlayer.myChar = oPlayer.getChar();
            break;
        }
        try{
            Coordinate o = oPlayer.play(gameBoard);
            if(!isWinner&&!isFull&&gameBoard[o]=='.'){
            gameBoard[o] = oPlayer.getChar();
            checkWinnings(oPlayer);
            isFull = checkIfFull();  
            }else{
                winPlayer.myName = xPlayer.name();
                winPlayer.myChar = xPlayer.getChar();
                break;
            }
        }catch(string& ex){
           winPlayer.myChar = xPlayer.getChar();
           winPlayer.myName = xPlayer.name();
           break; 
        }
        if(isFull&&!isWinner){
            winPlayer.myName = oPlayer.name();
            winPlayer.myChar = oPlayer.getChar();
        }
    }
}