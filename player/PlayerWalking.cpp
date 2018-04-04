#include "PlayerWalking.h"
#include "Player.h"
#include "../core/game/Game.h"
#include "../core/physics/Physics.h"

PlayerWalking::PlayerWalking(Player* p):PlayerState(p), m_walkVector(Vector2D(5,0))
{

    m_anim.load("sprites/zerowalkanim.bmp", 10, 6 ,true);
}


void PlayerWalking::load()
{
    m_player->vel.setY(0.0);
    m_anim.reset();

}
void PlayerWalking::draw()
{
    m_anim.draw(m_player->pos, 0, m_player->drawFlippedAnim());

}
void PlayerWalking::update()
{

    //Physics::updateSpeed(m_player);
    //m_player->vel.setY(0.0);
    Physics::moveObject(m_player);
    m_anim.update();
    //m_player->vel.setX(0);
}
void PlayerWalking::processEvent()
{
    bool input = false;

    if(!al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE))
        m_player->canJump() = true;


    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_LEFT))
    {
        m_player->moveLeft();
        m_player->drawFlippedAnim() = true;
        input = true;
    }
    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_RIGHT))
    {
        m_player->moveRight();
        m_player->drawFlippedAnim() = false;
        input = true;
    }

    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE) && m_player->canJump())
    {
        m_player->canJump() = false;
        m_player->jump();
        m_player->changeState("floating");
    }

    if(((m_player->getCollision()) && (m_player->collisionType() == SPIKE)))
       {
        Game::Instance()->changeState("gameOverScreen");
       }


     if(((m_player->getCollision()) && (m_player->collisionType() == BUBBLE)))
       {
        m_player->changeState("insideBubble");
       }

    if(!m_player->getCollision())
    {
        m_player->changeState("floating");
    }





    if(!input)
        m_player->changeState("idle");
}
void PlayerWalking::unload()
{
}


PlayerWalking::~PlayerWalking()
{
    //dtor
}
