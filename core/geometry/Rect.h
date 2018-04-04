#ifndef RECT_H
#define RECT_H

#include "../object/Object.h"

enum CollisionPosition {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT

};

class Rect : public Object
{
public:

    Rect(const double half_width, const double half_height);
    Rect(void);
    virtual ~Rect(void);

    Vector2D getVertex(int);
    virtual void draw(void);
    bool isCollidingLeft() {return m_collisionDirection[LEFT];}
    bool isCollidingRight() {return m_collisionDirection[RIGHT];}
    bool isCollidingTop() {return m_collisionDirection[TOP];}
    bool isCollidingBottom() {return m_collisionDirection[BOTTOM];}
    void resetCollisionDirecion(){m_collisionDirection[BOTTOM] = m_collisionDirection[TOP] =m_collisionDirection[LEFT] =m_collisionDirection[RIGHT] = false; }
    void setCollisionDirection(int direction) {m_collisionDirection[direction] = true;}

    Vector2D half_width;
    Vector2D half_height;
protected:

    bool m_collisionDirection[4];
};

#endif // RECT_H
