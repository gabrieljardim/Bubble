#include "FaseTeste.h"
#include "../core/geometry/Rect.h"
#include "../core/geometry/Circle.h"
#include "../player/Player.h"
#include "../core/physics/Physics.h"
#include "../core/object/Object.h"
#include "../player/Canon.h"
#include "../core/game/Game.h"
#include "../tiles/Spike.h"
#include "../tiles/SpikePlatform.h"
#include "../tiles/Platform.h"
#include "../tiles/Goal.h"
#include "CanonHandler.h"

FaseTeste::FaseTeste()
{
    //ctor
    this->m_gravity = Vector2D(0,0.5);
    player = new Player(this, Vector2D(100, 400));
    rect = new Platform(1024, 25,  Vector2D(512, 570), al_map_rgb(128, 170, 220));
    //rect2 = new Platform(40, 100, Vector2D(100, 290), al_map_rgb(128, 170, 220));
    rect3 = new Platform(50, 200, Vector2D(280, 350), al_map_rgb(128, 170, 220));
    rect4 = new Platform(50, 200, Vector2D(975, 350), al_map_rgb(128, 170, 220));
    //rect4 = new Platform(50, 200, Vector2D(50, 350), al_map_rgb(128, 170, 220));



   /* rect = new Rect(400, 25);
    rect->pos = Vector2D(400, 570);
    rect2 = new Rect(40, 100);
    rect2->pos = Vector2D(100, 290);
    rect3 = new Rect(50, 100);
    rect3->pos = Vector2D(280, 230);
    rect4 = new Rect(50, 100);
    rect4->pos = Vector2D(460, 230);*/

    goal = new Goal(Vector2D(360, 520));

    spikePlatform1 = new SpikePlatform(Vector2D(920, 195), 4, LEFTWARD);
    spikePlatform2 = new SpikePlatform(Vector2D(335, 260), 4, RIGHTWARD);
    spikePlatform3 = new SpikePlatform(Vector2D(920, 355), 4, LEFTWARD);
    spikePlatform4 = new SpikePlatform(Vector2D(335, 450), 4, RIGHTWARD);
    spikePlatform5 = new SpikePlatform(Vector2D(700, 540), 50, UPWARD);
    spikePlatform6 = new SpikePlatform(Vector2D(440, 230), 25, UPWARD);
    spikePlatform7 = new SpikePlatform(Vector2D(815, 325), 25, UPWARD);
    spikePlatform8 = new SpikePlatform(Vector2D(440, 420), 25, UPWARD);


    m_canonHandler = new CanonHandler(5);
    m_canonHandler->config(0, Vector2D(190,535), UPWARD);
    m_canonHandler->config(1, Vector2D(335,165), RIGHTWARD);
    m_canonHandler->config(2, Vector2D(920,280), LEFTWARD);
    m_canonHandler->config(3, Vector2D(335,375), RIGHTWARD);
    m_canonHandler->config(4, Vector2D(920,470), LEFTWARD);

    m_canonHandler->initialSelected(0);

     m_collisionManager.insertElement(player);
     m_collisionManager.insertElement(rect);
     m_collisionManager.insertElement(rect3);
     m_collisionManager.insertElement(rect4);
     m_collisionManager.insertElement(m_canonHandler->getCanon(0)->getBullet());
     m_collisionManager.insertElement(m_canonHandler->getCanon(1)->getBullet());
     m_collisionManager.insertElement(m_canonHandler->getCanon(2)->getBullet());
     m_collisionManager.insertElement(m_canonHandler->getCanon(3)->getBullet());
     m_collisionManager.insertElement(m_canonHandler->getCanon(4)->getBullet());
     m_collisionManager.insertElement(spikePlatform1);
     m_collisionManager.insertElement(spikePlatform2);
     m_collisionManager.insertElement(spikePlatform3);
     m_collisionManager.insertElement(spikePlatform4);
     m_collisionManager.insertElement(spikePlatform5);
     m_collisionManager.insertElement(spikePlatform6);
     m_collisionManager.insertElement(spikePlatform7);
     m_collisionManager.insertElement(spikePlatform8);
     m_collisionManager.insertElement(goal);

}

void FaseTeste::load()
{

m_canonHandler->initialSelected(0);
player->pos = Vector2D(100, 400);
player->vel = Vector2D(0,0);



}

void FaseTeste::unload()
{

}

 /*void  FaseTeste::checkCollision()
 {

    bool collided = false;

     collided = Physics::testCollision(player, rect);
     collided += Physics::testCollision(player, rect2);
     collided += Physics::testCollision(player, rect3);
     collided += Physics::testCollision(player, rect4);
     collided += Physics::testCollision(player, rect4);
     if(Physics::testCollision(player, m_canonHandler->getCanon(0)->getBullet()) &&
        (m_canonHandler->getCanon(0)->getBullet()->isCollidable()))
    {
            player->collidedWith(BUBBLE);
            player->setBubble(m_canonHandler->getCanon(0)->getBullet());
            collided++;
    }

    if(Physics::testCollision(player, m_canonHandler->getCanon(1)->getBullet()) &&
        (m_canonHandler->getCanon(1)->getBullet()->isCollidable()))
    {
            player->collidedWith(BUBBLE);
            player->setBubble(m_canonHandler->getCanon(1)->getBullet());
            collided++;
    }


     player->setCollision(collided);
 }*/

void FaseTeste::processEvent()
{
    player->processEvent();
    m_canonHandler->processEvent();


}

void FaseTeste::update()

{


    m_canonHandler->update();
    player->update();
    goal->update();
    m_collisionManager.update();
    //checkCollision();

}
void FaseTeste::draw()
{


    /*spikePlatform1->draw();
    spikePlatform2->draw();
    spikePlatform3->draw();
    spikePlatform4->draw();
    spikePlatform5->draw();
    spikePlatform6->draw();
    spikePlatform7->draw();
    spikePlatform8->draw();*/
    rect->draw();
    //rect2->draw();
    rect3->draw();
    rect4->draw();
    player->draw();

    m_canonHandler->draw();

    goal->draw();
}


FaseTeste::~FaseTeste()
{
    //dtor
}
