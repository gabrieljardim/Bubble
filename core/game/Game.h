#ifndef GAME_H
#define GAME_H

#include "../allegro/Allegro.h"
#include "../../levels/FaseTeste.h"
#include <map>
#include <iostream>

using namespace std;

class Game
{
    public:
        Game();
        virtual ~Game();
        void update();
        void draw();
        void processEvent();
        static void changeState(string );
        void loop();
        static Game* Instance();
        void setCloseGame(bool b){closeGame = b;}
        ALLEGRO_EVENT event;
        ALLEGRO_KEYBOARD_STATE state;
        bool debugMode;

    protected:
    private:
        int posx;
        int posy;
        bool refresh;
        bool closeGame;
        GameState* currentState;
        map<string, GameState*> states;

};

#endif // Game_H
