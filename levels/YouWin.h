#ifndef YOUWIN_H
#define YOUWIN_H

#include "../core/states/GameState.h"
#include "../core/animation/Animation.h"


class YouWin : public GameState
{
    public:
        YouWin();
         void load();
        void unload();
        void processEvent();
        void update();
        void draw();
        virtual ~YouWin();
    protected:
    private:
        Animation m_anim;
};

#endif // YOUWIN_H
