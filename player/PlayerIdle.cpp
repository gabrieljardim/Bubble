#include "PlayerIdle.h"
#include "../core/physics/Physics.h"

PlayerIdle::PlayerIdle(Player* p) :PlayerState(p)
{
    m_anim.load("sprites/zeroidleanim.bmp", 3, 120 ,true);
}

void PlayerIdle::load()
{
    m_player->vel = Vector2D(0,0);
    m_anim.reset();

}


void PlayerIdle::processEvent()
{


    if(!al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE))
        m_player->canJump() = true;

    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_LEFT) || al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_RIGHT))
    {
        m_player->changeState("walking");
    }
    if(((m_player->getCollision()) && (m_player->collisionType() == SPIKE)))
       {
        m_player->pos = Vector2D(20, 400);
        m_player->vel = Vector2D(0, 0);
       }

    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE) && m_player->canJump())
    {
        m_player->jump();
        m_player->canJump() = false;
        m_player->changeState("floating");
    }
    else if(!m_player->getCollision())
    {
        m_player->changeState("floating");
    }

    if(((m_player->getCollision()) && (m_player->collisionType() == BUBBLE)))
       {
        m_player->changeState("insideBubble");
       }





}

void PlayerIdle::update()
{
    m_player->vel = Vector2D(0,0);
    /*Physics::updateSpeed(m_player);
    Physics::moveObject(m_player);*/
    //m_anim.update();
}

void PlayerIdle::draw()
{

    m_anim.draw(m_player->pos, 0, m_player->drawFlippedAnim());
}
void PlayerIdle::unload()
{
}

PlayerIdle::~PlayerIdle()
{
    //dtor
}
