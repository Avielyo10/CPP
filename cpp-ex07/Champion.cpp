#include "Champion.h"

const Coordinate Champion::play(const Board& board){
    if(board[{0,board.size()-1}]=='.'){
        return {0,board.size()-1};
    }
    if(board[{board.size()-1,0}]=='.'){
        return {board.size()-1,0};
    }
    uint i = board.size()-1, j = 0;
    while(j<board.size()){
        Coordinate c{i,j};
	    if (board[c]=='.') {
			return c;
		}
        i--;
        j++; 
    }
    return {0,0};
}