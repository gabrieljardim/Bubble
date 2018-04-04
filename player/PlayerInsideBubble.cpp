#include "PlayerInsideBubble.h"
#include "BubbleBullet.h"
#include "../core/physics/Physics.h"

PlayerInsideBubble::PlayerInsideBubble(Player* p): PlayerState(p)
{

    m_anim.load("sprites/zeroidleanim.bmp", 3, 10 ,false);
}

void PlayerInsideBubble::load()
{


}


void PlayerInsideBubble::processEvent()
{

    bool input = false;

    if(!(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE)))
        input = true;

    if(input)
        m_canBurst = true;
    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE) && m_canBurst)
    {

        m_player->getBubble()->setCollidable(false);
        m_canBurst = false;

    }

    if(m_player->getBubble()->isCollidable() == false)
    {

        m_player->collidedWith(OTHER);
        m_player->changeState("floating");
    }

}

void PlayerInsideBubble::update()
{


    //Physics::updateSpeed(m_player);

    Vector2D dir = m_player->getBubble()->pos - m_player->pos;

    if(dir.length() < 5) //mudar para bubble get speed
    {

        m_player->vel = dir;
    }
    else
    {


    dir = dir.normalized() * 4;
    m_player->vel = dir;
    }

    Physics::moveObject(m_player);


}

void PlayerInsideBubble::draw()
{
    m_anim.draw(m_player->pos, 0, m_player->drawFlippedAnim());
}
void PlayerInsideBubble::unload()
{
}

PlayerInsideBubble::~PlayerInsideBubble()
{
    //dtor
}
