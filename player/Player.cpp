
#include <cmath>
#include <iostream>
#include "Player.h"
#include "../levels/GameWorld.h"
#include "../core/physics/Physics.h"
#include "../core/game/Game.h"
#include "PlayerWalking.h"
#include "PlayerIdle.h"
#include "PlayerFloating.h"
#include "PlayerWallSlide.h"
#include "PlayerInsideBubble.h"

using namespace std;


Player::Player(GameWorld* gw, Vector2D position): Rect(15, 21), m_canJump(true), m_walkVector(Vector2D(5,0))
{

    pos = position;
    m_horizontalMoveMaxSpeed = 5.0;
    states.insert(pair<string, PlayerState*>("walking", new PlayerWalking(this)));
    states.insert(pair<string, PlayerState*>("idle", new PlayerIdle(this)));
    states.insert(pair<string, PlayerState*>("floating", new PlayerFloating(this)));
    states.insert(pair<string, PlayerState*>("wallSlide", new PlayerWallSlide(this)));
    states.insert(pair<string, PlayerState*>("insideBubble", new PlayerInsideBubble(this)));
    currentState = states.at("idle");
    type = PLAYER;
    m_collidable = true;
    //m_collisionType = OTHER;



    stage = gw;
    acl= stage->getGravity();
    currentState->load();
    //load();
   /*
    states.insert(pair<string, PlayerState*>("vivo", new Alive(*this))); //Insere uma instancia de uma classe filha de GameState
    currentState = states.at("vivo"); //Escolhe um dos Estados
    currentState->load();
    //this->vel = Vector2D(0,3);
    this->speed = 2;
    this->dir = Vector2D(0,1);
    this->angle = 0;

    for(int i = 0; i < 10; i++)
    {
        b[i].visible = false;
    }

    */
    //ctor

}

void Player::load()
{
    /*this->img = al_load_bitmap ("images/nave3.png");*/
}
void Player::unload()
{

}
void Player::processEvent()
{


    currentState->processEvent();
    /*if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_SPACE))
    {
        this->changeState("jump";)
    }*/


    //currentState->processEvent(event, state);

   /* ALLEGRO_MOUSE_STATE state_mouse;
    al_get_mouse_state(&state_mouse);

    if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        if(event.mouse.button & 1) {


        mouse_pos.setX(state_mouse.x);
        mouse_pos.setY(state_mouse.y);


        fire();
    }
*/

}
void Player::update()
{

   /* Physics::updateSpeedWithGravity(this, stage->getGravity());
    if(pos.getY() < 400)
        Physics::moveObject(this);*/
    currentState->update();
    resetCollisionDirecion();



    //std::cout << "Collided with floor: " << m_colliding_floor << std::endl;
}
void Player::draw()
{

    currentState->draw();
    //al_draw_filled_circle(pos.getX(), pos.getY(), 20, al_map_rgb(0,255,255));
    //al_draw_filled_rectangle(pos.getX() - half_width.getX(), pos.getY() - half_height.getY(), pos.getX() + half_width.getX(), pos.getY() + half_height.getY(), al_map_rgb(255,0,0));
    if(Game::Instance()->debugMode)
        al_draw_rectangle(pos.getX() - half_width.getX(), pos.getY() - half_height.getY(), pos.getX() + half_width.getX(), pos.getY() + half_height.getY(), al_map_rgb(255,0,0), 1.0);

}

/*

TO DO: Melhorar os métodos de movimento





*/
void Player::moveLeft()
{
    //if(vel.getX() > (-1* m_horizontalMoveMaxSpeed))
    vel.setX(0.0);
    vel = vel + (m_walkVector*-1);
}
void Player::moveRight()
{
    //if(vel.getX() < m_horizontalMoveMaxSpeed)
    vel.setX(0.0);
    vel = vel + m_walkVector;
}

void Player::moveLeftOnAir(double intensity)
{
    vel.setX(0.0);
    vel = vel + (m_walkVector*-1)* intensity;
}

void Player::moveRightOnAir(double intensity)
{
    vel.setX(0.0);
    vel = vel + m_walkVector * intensity;
}

void Player::jump()
{
    Physics::addImpulse(this, Vector2D(0, -12));
}
void Player::changeState(string name)
{

    currentState = states.at(name);
    currentState->load();
    std::cout << "Changed to state: " << name << std::endl;
//    Game::Instance()->currentState->unload(); //Descarrega o estado atual
//    Game::Instance()->currentState = Game::Instance()->states.at(name); //Muda pro estado dado no parametro do método
//    Game::getInstance()->currentState->load(); //Carrega o próximo estado
}


Player::~Player()
{
    //dtor
}
