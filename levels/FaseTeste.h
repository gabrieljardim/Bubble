#ifndef FASETESTE_H
#define FASETESTE_H

#include "GameWorld.h"
#include "CollisionManager.h"


class Rect;
class Circle;
class Player;
class Object;
class CanonHandler;
class Spike;
class SpikePlatform;
class Platform;
class Goal;

class FaseTeste : public GameWorld
{
    public:
        FaseTeste();
        void load();
        void unload();
        void processEvent();
        void update();
        void draw();
        virtual ~FaseTeste();
    protected:
    private:
        Player* player;
        Platform* rect;
        Platform* rect2;
        Platform* rect3;
        Platform* rect4;
        Spike* spike;
        CanonHandler* m_canonHandler;
        SpikePlatform* spikePlatform1;
        SpikePlatform* spikePlatform2;
        SpikePlatform* spikePlatform3;
        SpikePlatform* spikePlatform4;
        SpikePlatform* spikePlatform5;
        SpikePlatform* spikePlatform6;
        SpikePlatform* spikePlatform7;
        SpikePlatform* spikePlatform8;
        Goal* goal;
        CollisionManager m_collisionManager;

};

#endif // FASETESTE_H
