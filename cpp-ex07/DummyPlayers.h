#pragma once
#include "Player.h"

/* 
	This player scans the board looping on x then on y, 
	and plays on the first empty cell. 
*/
class XYPlayer: public Player {
public:
	const string name() const override { return "XYPlayer"; }
	const Coordinate play(const Board& board) override;
};

class testPlayer : public Player{
public:
	const string name() const override { return "testPlayer"; }
	const Coordinate play(const Board& board) override{
		if(board[{0,1}]=='.'){
			return {0,1};
		}if(board[{1,0}]=='.'){
			return {1,0};
		}if(board[{2,0}]=='.'){
			return {2,0};
		}if(board[{2,2}]=='.'){
			return {2,2};
		}
		return {0,0};
	}
};

/* 
	This player scans the board looping on y then on x, 
	and plays on the first empty cell. 
*/
class YXPlayer: public Player {
public:
	const string name() const override { return "YXPlayer"; }
	const Coordinate play(const Board& board) override;
};


/* 
   This player makes illegal moves - 
   it tries to override cells of the other player.
   It should always lose. 
*/
class IllegalPlayer: public Player {
public:
	const string name() const override { return "YXPlayer"; }
	const Coordinate play(const Board& board) override;
};


/* 
	This player always throws an exception.
	It should always lose. 
*/
class ExceptionPlayer: public Player {
public:
	const string name() const override { return "YXPlayer"; }
	const Coordinate play(const Board& board) override;
};
