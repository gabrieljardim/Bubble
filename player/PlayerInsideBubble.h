#ifndef PLAYERINSIDEBUBBLE_H
#define PLAYERINSIDEBUBBLE_H

#include "../core/states/PlayerState.h"


class PlayerInsideBubble : public PlayerState
{
    public:
        PlayerInsideBubble(Player* p);
        void load();
        void draw();
        void update();
        void processEvent();
        void unload();
        virtual ~PlayerInsideBubble();
    protected:
    private:
        bool m_canBurst;
};

#endif // PLAYERINSIDEBUBBLE_H
