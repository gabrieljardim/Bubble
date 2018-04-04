#ifndef OBJECT_H
#define OBJECT_H
#include "../allegro/Allegro.h"
#include "../physics/Vector2D.h"

class GameWorld;

enum Direction {

RIGHTWARD,
UPWARD,
LEFTWARD,
DOWNWARD,


};

enum Types {

    OTHER,
    PLATFORM,
    PLAYER,
    BUBBLE,
    SPIKE,
    GOAL

};
class Object
{
    public:
        Object();
        virtual ~Object();
        virtual void draw() = 0;

        Vector2D dir;
        Vector2D pos;
        Vector2D vel;
        Vector2D acl;
        double speed;
        double angle;
        double inv_mass;
        double elasticity;
        int type;
        int getType() {return type;}
        int collisionType() {return m_collisionType;}
        void collidedWith(int type) {m_collisionType = type;}
        bool isVisible(){return m_visible;}
        void setVisible(bool visible){m_visible = visible;}
        bool isCollidable(){return m_collidable;}
        void setCollidable(bool collidable){m_collidable = collidable;}
        bool getCollision() {return m_colliding;}
        void setCollision(bool opt) {m_colliding = opt;}
        GameWorld* stage;
    protected:
        bool m_visible;
        bool m_collidable;
        bool m_colliding;
        int m_collisionType;

    private:

};

#endif // OBJECT_H
