#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include "../core/states/GameState.h"
#include "../core/animation/Animation.h"


class GameOverScreen : public GameState
{
    public:
        GameOverScreen();
        void load();
        void unload();
        void processEvent();
        void update();
        void draw();
        virtual ~GameOverScreen();
    protected:
    private:
        Animation m_anim;
};

#endif // GAMEOVERSCREEN_H
