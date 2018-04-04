#include "CanonShooting.h"
#include "Canon.h"

CanonShooting::CanonShooting(Canon* c): CanonState(c)
{
    //ctor
     m_anim.load("sprites/canonidleanim.bmp", 1, 0 ,false);
     m_selectedAnim.load("sprites/canonselectedanim.bmp", 1, 0 ,false);
     m_currentAnim = &m_anim;
     m_done = false;

}

void CanonShooting::load()
{

    m_currentRadius = 0;
    m_done = false;
    m_canon->resetBulletPosition();
}


void CanonShooting::processEvent()
{

}


void CanonShooting::update()
{
    if(m_canon->isSelected())
        m_currentAnim = &m_selectedAnim;
    else
        m_currentAnim = &m_anim;

    if(m_currentRadius == m_canon->getBullet()->radius)
    {
        m_canon->shoot();
        m_currentRadius++;
        m_done = true;
    }

    if(m_done && !m_canon->getBullet()->isVisible())
        m_canon->changeState("idle");
}

void CanonShooting::draw()
{

    int radius = m_canon->getBullet()->radius;
    Vector2D pos = m_canon->getBullet()->pos;

    if(m_canon->getDirection() == UPWARD)
        m_currentAnim->draw(m_canon->pos, 0, false);
    else if(m_canon->getDirection() == RIGHTWARD)
        m_currentAnim->draw(m_canon->pos, 90, false);
    else if (m_canon->getDirection() == DOWNWARD)
        m_currentAnim->draw(m_canon->pos, 180, false);
    else
        m_currentAnim->draw(m_canon->pos, 270, false);


    if(m_currentRadius < radius) {
        for(int i = 0; i < m_currentRadius; i++)
        {

            al_draw_circle(pos.getX(), pos.getY(), i, al_map_rgba(0,0,50,  (i*15/m_currentRadius)),5);

        }

    m_currentRadius++;
    }

}


void CanonShooting::unload()
{

}

CanonShooting::~CanonShooting()
{
    //dtor
}
