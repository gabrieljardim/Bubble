#include "PlayerWallSlide.h"
#include "Player.h"
#include "../core/physics/Physics.h"

PlayerWallSlide::PlayerWallSlide(Player* p):PlayerState(p)
{
    m_anim.load("sprites/zerowallslideanim.bmp", 1, 6 ,true);
}

void PlayerWallSlide::load()
{

    m_anim.reset();

}
void PlayerWallSlide::draw()
{
    m_anim.draw(m_player->pos, 0, m_player->drawFlippedAnim());

}
void PlayerWallSlide::update()
{

    Physics::updateSpeed(m_player);
    m_player->vel.setY( m_player->vel.getY() * 0.7 );
    Physics::moveObject(m_player);
    m_anim.update();
    //m_player->vel.setX(0);
}
void PlayerWallSlide::processEvent()
{
    if(!al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE))
        m_player->canJump() = true;

    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE) && m_player->canJump())
    {

        if(m_player->isCollidingLeft())
            {
                m_player->moveRightOnAir(0.5);
                m_player->drawFlippedAnim() = false;
            }
        else{
                m_player->moveLeftOnAir(0.5);
                m_player->drawFlippedAnim() = true;
            }
        m_player->jump();
        m_player->canJump() = false;
        m_player->changeState("floating");
    }
    else if(!m_player->getCollision())
    {
        m_player->changeState("floating");
    }



}
void PlayerWallSlide::unload()
{
}

PlayerWallSlide::~PlayerWallSlide()
{
    //dtor
}

