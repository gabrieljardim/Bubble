#ifndef PLAYERIDLE_H
#define PLAYERIDLE_H

#include "../core/states/PlayerState.h"


class PlayerIdle : public PlayerState
{
    public:
        PlayerIdle(Player* p);
        void load();
        void draw();
        void update();
        void processEvent();
        void unload();
        virtual ~PlayerIdle();
    protected:
    private:
};

#endif
