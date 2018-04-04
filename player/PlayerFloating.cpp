#include "PlayerFloating.h"
#include "Player.h"
#include "../core/physics/Physics.h"

PlayerFloating::PlayerFloating(Player* p): PlayerState(p)
{

    m_anim.load("sprites/zerofallanim.bmp", 3, 10 ,false);
    m_jumpAnim.load("sprites/zerojumpanim.bmp", 4, 5 ,false);
}

void PlayerFloating::load()
{

    m_anim.reset();
    m_jumpAnim.reset();
    if(m_player->vel.getY() > 0)
        m_currentAnim = &m_anim;
    else
        m_currentAnim = &m_jumpAnim;

    m_moveIntesityDefault = 0.2;
    debugCount = 0;
    m_leftMoveIntensity = m_moveIntesityDefault;
    m_rightMoveIntensity = m_moveIntesityDefault;

}


void PlayerFloating::processEvent()
{
    /*if(m_player->isCollidingTop())
        cout << "TOP"<< endl;
    if(m_player->isCollidingBottom() == BOTTOM)
        cout << "BOTTOM" << endl;
    if(m_player->isCollidingLeft())
        cout << "LEFT" << endl;
    if(m_player->isCollidingRight())
        cout << "RIGHT" << endl;*/

    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_LEFT))
    {
        m_leftMoveIntensity += 0.8/39;
        m_rightMoveIntensity = m_moveIntesityDefault;
        m_player->moveLeftOnAir(m_leftMoveIntensity);
        m_player->drawFlippedAnim() = true;
        debugCount = 0;
    }
    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_RIGHT))
    {
        m_rightMoveIntensity+=0.8/39;
        debugCount++;
        m_leftMoveIntensity = m_moveIntesityDefault;
        m_player->moveRightOnAir(m_rightMoveIntensity);
        m_player->drawFlippedAnim() = false;        //std::cout << m_player->vel.getX() << std::endl;
    }

    if(((m_player->getCollision()) && (m_player->collisionType() == SPIKE)))
       {
        Game::Instance()->changeState("gameOverScreen");
       }

    else if(m_player->getCollision() && (m_player->isCollidingBottom()) && (m_player->collisionType() == PLATFORM))
    {
        m_player->changeState("idle");
    }

    else if(m_player->getCollision() && (m_player->isCollidingTop()) && (m_player->collisionType() == PLATFORM))
    {
        m_player->vel.setY(0.0);
    }

    else if(((m_player->getCollision()) && (m_player->collisionType() == BUBBLE)))
       {
        m_player->changeState("insideBubble");
       }

    else if(((m_player->getCollision()) && (m_player->collisionType() == SPIKE)))
       {
        m_player->pos = Vector2D(20, 400);
        m_player->vel = Vector2D(0, 0);
       }

    /*if(m_player->getCollision() && ((m_player->isCollidingLeft())) || (m_player->isCollidingRight()))
    {
        m_player->changeState("wallSlide");
    }*/
}

void PlayerFloating::update()
{




    if(m_player->vel.getY() > 0)
        m_currentAnim = &m_anim;
    else
        m_currentAnim = &m_jumpAnim;

    m_currentAnim->update();


    Physics::updateSpeed(m_player);
    Physics::moveObject(m_player);


}

void PlayerFloating::draw()
{
    m_currentAnim->draw(m_player->pos, 0, m_player->drawFlippedAnim());
}
void PlayerFloating::unload()
{
}

PlayerFloating::~PlayerFloating()
{
    //dtor
}
