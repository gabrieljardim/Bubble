#include "Goal.h"
#include "../core/game/Game.h"

Goal::Goal()
{
    m_anim.load("sprites/goalsprite.bmp",1, 0 ,false);
    m_collidable = true;
    m_visible = true;
    type = GOAL;
    m_collisionType = OTHER;
}

Goal::Goal(Vector2D position)
{
    m_anim.load("sprites/goalsprite.bmp",1, 0 ,false);
    type = GOAL;
    pos = position;
    m_collidable = true;
    m_visible = true;
    m_collisionType = OTHER;
}

void Goal::update()
{

        if(m_colliding && (m_collisionType == PLAYER))
            Game::changeState("youWin");

}
void Goal::draw()
{
    m_anim.draw(pos, 0, false);
}
Goal::~Goal()
{
    //dtor
}
