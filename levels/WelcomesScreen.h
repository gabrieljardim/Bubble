#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include "../core/states/GameState.h"
#include "../core/animation/Animation.h"


class WelcomeScreen : public GameState
{
    public:
        WelcomeScreen();
        void load();
        void unload();
        void processEvent();
        void update();
        void draw();
        virtual ~WelcomeScreen();
    protected:
    private:
        Animation m_anim;

};

#endif // WELCOMESCREEN_H
