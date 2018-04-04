#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

//Interface para telas do jogo (menu, jogo, fim...)
class GameState : public State
{
    public:
        GameState();
        virtual ~GameState();
    protected:
    private:



};

#endif // GAMESTATE_H
