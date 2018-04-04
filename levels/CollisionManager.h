#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>

class Object;
class Player;
class BubbleBullet;
class SpikePlatform;
class Platform;

class CollisionManager
{
    public:
        CollisionManager();
        void insertElement(Object* obj);
        void update();

        void handleCollision(Player* , Platform*);
        void handleCollision(Player*, BubbleBullet*);
        void handleCollision(Player*, SpikePlatform*);
        void handleCollision(BubbleBullet*, BubbleBullet*);
        void handleCollision(BubbleBullet*, Platform*);
        void handleCollision(BubbleBullet*, SpikePlatform*);

        virtual ~CollisionManager();
    protected:
    private:
        std::vector<Object*> m_objVector;

};

#endif // COLLISIONMANAGER_H
