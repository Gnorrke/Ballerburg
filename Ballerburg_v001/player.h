#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(int player);
    void setTurn();
    void resetTurn();
    bool getTurn();
    bool turn = false;
    int player;
};

#endif // PLAYER_H
