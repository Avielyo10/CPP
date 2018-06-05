#include "Board.h"
#include "Player.h"

class TicTacToe{
    private:
    Board gameBoard;
    Player winPlayer;
    public:
    bool isWinner,isFull;
    TicTacToe(int num);
    ~TicTacToe(){}
    void play(Player& xPlayer,Player& oPlayer);
    Player winner() const;
    Board board() const;
    bool checkIfFull();
    void checkWinnings(Player& p);
    bool checkVer(Player& p);
    bool checkHor(Player& p);
    bool checkRDig(Player& p);
    bool checkLDig(Player& p);
};