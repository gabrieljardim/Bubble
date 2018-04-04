#include "BubbleBullet.h"
#include "../core/physics/Physics.h"
BubbleBullet::BubbleBullet()
{
    //ctor
    type = BUBBLE;
    m_collisionType = OTHER;
    m_collidable = false;
    m_visible = false;
    vel = Vector2D (0 ,0);

}
void BubbleBullet::update()
{
    Physics::moveObject(this);

    if(m_collidable == false)
        m_visible = false;

    /*cout << "Inside Collisiton Type 2: " << this->collisionType() <<endl;
    cout << "Platform: " << PLATFORM << endl;
    cout << "Spike: " << SPIKE << endl;
    cout << "Bubble: " << BUBBLE << endl;
    cout << endl;*/

    if(Physics::testCollisionDownScreen(this) || Physics::testCollisionRightScreen(this)
       || Physics::testCollisionLeftScreen(this) || Physics::testCollisionTopScreen(this)
       || (m_colliding && (this->collisionType() == PLATFORM)) || (m_colliding && (this->collisionType() == SPIKE) ))
        {
            m_visible = false;
            m_collidable = false;
        }
}

void BubbleBullet::draw()
{


    for(int i = 0; i < radius; i++)
    {
        // if(i > (current_radius*0.9))
        al_draw_circle(pos.getX(), pos.getY(), i, al_map_rgba(0,0,50,  (i*15/radius)),5);

    }
}

BubbleBullet::~BubbleBullet()
{
    //dtor
}
