
#include "Player.h"

class Champion: public Player{
    public:
	    const string name() const override { return "Aviel"; }
	    const Coordinate play(const Board& board) override;
};
