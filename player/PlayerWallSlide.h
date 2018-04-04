#ifndef PLAYERWALLSLIDE_H
#define PLAYERWALLSLIDE_H

#include "../core/states/PlayerState.h"

class Player;

class PlayerWallSlide : public PlayerState
{
    public:
        PlayerWallSlide(Player* p);
        void load();
        void draw();
        void update();
        void processEvent();
        void unload();
        void moveLeft();
        void moveRight();
        virtual ~PlayerWallSlide();
    protected:
    private:
};

#endif // PLAYERWALLSLIDE_H
