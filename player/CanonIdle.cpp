#include "CanonIdle.h"
#include "Canon.h"
#include "../core/game/Game.h"
CanonIdle::CanonIdle(Canon* c): CanonState(c)
{
     m_anim.load("sprites/canonidleanim.bmp", 1, 0 ,false);
     m_selectedAnim.load("sprites/canonselectedanim.bmp", 1, 0 ,false);
     m_currentAnim = &m_anim;
     m_canShoot = false;
}
void CanonIdle::load()
{

}

void CanonIdle::draw()
{

   if(m_canon->getDirection() == UPWARD)
        m_currentAnim->draw(m_canon->pos, 0, false);
    else if(m_canon->getDirection() == RIGHTWARD)
        m_currentAnim->draw(m_canon->pos, 90, false);
    else if (m_canon->getDirection() == DOWNWARD)
        m_currentAnim->draw(m_canon->pos, 180, false);
    else
        m_currentAnim->draw(m_canon->pos, 270, false);
   /*if(m_canon->isVisible()) {
    for(int i = 0; i < radius; i++)
    {
       // if(i > (current_radius*0.9))
            al_draw_circle(m_canon->pos.getX(), m_canon->pos.getY() - 10, i, al_map_rgba(0,0,50,  (i*15/radius)),5);

    }
   }*/

}
void CanonIdle::update()
{
   if(m_canon->isSelected())
        m_currentAnim = &m_selectedAnim;
    else
        m_currentAnim = &m_anim;
}

void CanonIdle::processEvent()
{

 if(!(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_ENTER)))
    {
       m_canShoot = true;
    }

 if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_ENTER) && m_canShoot)
    {
        m_canon->changeState("shooting");
        m_canShoot = false;
    }
}
void CanonIdle::unload()
{

}

CanonIdle::~CanonIdle()
{
    //dtor
}
