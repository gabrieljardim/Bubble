#ifndef PLAYERWALKING_H
#define PLAYERWALKING_H

#include "../core/states/PlayerState.h"
#include "../core/physics/Vector2D.h"

class Player;

class PlayerWalking : public PlayerState
{
    public:
        PlayerWalking(Player* p);
        void load();
        void draw();
        void update();
        void processEvent();
        void unload();
        void moveLeft();
        void moveRight();
        virtual ~PlayerWalking();
    protected:
    private:
        Vector2D m_walkVector;
        bool flipped;

};

#endif // PLAYERWALKING_H
