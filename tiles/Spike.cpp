#include "Spike.h"
#include "../core/game/Game.h"
#include "../core/object/Object.h"

Spike::Spike()
{
    m_anim.load("sprites/spikesprite.bmp",1, 0 ,false);
}

Spike::Spike(Vector2D position, int direction) : m_pos(position), m_direction(direction)
{
    m_anim.load("sprites/spikesprite.bmp",1, 0 ,false);
}



void Spike::draw()
{
    if(0/*Game::Instance()->debugMode*/)
        al_draw_rectangle(m_pos.getX() - m_anim.getCurrentFrameWidth()/2, m_pos.getY() - m_anim.getCurrentFrameHeight()/2, m_pos.getX() + m_anim.getCurrentFrameWidth()/2, m_pos.getY() + m_anim.getCurrentFrameHeight()/2, al_map_rgb(255,0,0), 1.0);

    else {

    if(m_direction == UPWARD)
        m_anim.draw(m_pos, 0, false);
    else if(m_direction == RIGHTWARD)
       m_anim.draw(m_pos, 90, false);
    else if (m_direction == DOWNWARD)
        m_anim.draw(m_pos, 180, false);
    else
        m_anim.draw(m_pos, 270, false);
    }
}

void Spike::draw(Vector2D position)
{
    if(0/*Game::Instance()->debugMode*/)
        al_draw_rectangle(m_pos.getX() - m_anim.getCurrentFrameWidth()/2, m_pos.getY() - m_anim.getCurrentFrameHeight()/2, m_pos.getX() + m_anim.getCurrentFrameWidth()/2, m_pos.getY() + m_anim.getCurrentFrameHeight()/2, al_map_rgb(255,0,0), 1.0);

    else {

    if(m_direction == UPWARD)
        m_anim.draw(position, 0, false);
    else if(m_direction == RIGHTWARD)
       m_anim.draw(position, 90, false);
    else if (m_direction == DOWNWARD)
        m_anim.draw(position, 180, false);
    else
        m_anim.draw(position, 270, false);
    }
}

double Spike::height()
{
    return static_cast<double>(m_anim.getCurrentFrameHeight());
}

double Spike::width()
{
    return static_cast<double>(m_anim.getCurrentFrameWidth());

}

Spike::~Spike()
{
    //dtor
}
