#include "CollisionManager.h"
#include "../core/geometry/Rect.h"
#include "../core/geometry/Circle.h"
#include "../player/Player.h"
#include "../core/physics/Physics.h"
#include "../core/object/Object.h"
#include "../player/Canon.h"
#include "../core/game/Game.h"
#include "../tiles/Spike.h"
#include "../tiles/Goal.h"
#include "../tiles/SpikePlatform.h"
#include "../tiles/Platform.h"

CollisionManager::CollisionManager()
{
    //ctor
}

void CollisionManager::insertElement(Object* obj)
{

    m_objVector.push_back(obj);

}

void CollisionManager::update()
{
    bool result = false;

    for(unsigned int i = 0; i < m_objVector.size(); ++i)
    m_objVector[i]->setCollision(false);

    for(unsigned int i = 0; i < m_objVector.size(); ++i)
    {
        //m_objVector[i]->setCollision(false);

        for(unsigned int j = i+1; j < m_objVector.size(); ++j)
        {

            //m_objVector[j]->setCollision(false);

            if(m_objVector[i]->isCollidable() && m_objVector[j]->isCollidable())
            {



            if((m_objVector[i]->getType() == PLAYER) && (m_objVector[j]->getType() == BUBBLE))
            {
                bool result = false;


                result = Physics::testCollision(static_cast<Circle*>(m_objVector[j]), static_cast<Rect*>(m_objVector[i]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(BUBBLE);
                    m_objVector[j]->collidedWith(PLAYER);
                   (static_cast<Player*>(m_objVector[i]))->setBubble(static_cast<BubbleBullet*>(m_objVector[j]));

                }

            }

           else if((m_objVector[j]->getType()) == PLAYER && (m_objVector[i]->getType() == BUBBLE))
            {

                result = Physics::testCollision(static_cast<Circle*>(m_objVector[i]), static_cast<Rect*>(m_objVector[j]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[j]->collidedWith(BUBBLE);
                    m_objVector[i]->collidedWith(PLAYER);
                    (static_cast<Player*>(m_objVector[j]))->setBubble(static_cast<BubbleBullet*>(m_objVector[i]));

                }

            }
            else if((m_objVector[i]->getType() == PLAYER) && (m_objVector[j]->getType() == PLATFORM))
            {

                 bool result = false;
                 result = Physics::testCollision(static_cast<Player*>(m_objVector[i]), static_cast<Rect*>(m_objVector[j]));


                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(PLATFORM);
                    m_objVector[j]->collidedWith(PLAYER);

                }
            }

            else if((m_objVector[i]->getType() == PLATFORM) && (m_objVector[j]->getType() == PLAYER))
            {
                bool result = false;


                result = Physics::testCollision(static_cast<Player*>(m_objVector[j]),static_cast<Rect*>(m_objVector[i]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(PLAYER);
                    m_objVector[j]->collidedWith(PLATFORM);

                }
            }

            else if((m_objVector[i]->getType() == PLAYER) && (m_objVector[j]->getType() == SPIKE))
            {
                bool result = false;
                result = Physics::testCollision(static_cast<Player*>(m_objVector[i]), static_cast<Rect*>(m_objVector[j]));

                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(SPIKE);
                    m_objVector[j]->collidedWith(PLAYER);

                }
            }

            else if((m_objVector[i]->getType() == SPIKE) && (m_objVector[j]->getType() == PLAYER))
            {
                bool result = false;

                result = Physics::testCollision(static_cast<Player*>(m_objVector[j]), static_cast<Rect*>(m_objVector[i]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(PLAYER);
                    m_objVector[j]->collidedWith(SPIKE);

                }
            }

            else if((m_objVector[i]->getType() == BUBBLE) && (m_objVector[j]->getType() == SPIKE))
            {
                bool result = false;

                result = Physics::testCollision(static_cast<Circle*>(m_objVector[i]), static_cast<Rect*>(m_objVector[j]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(SPIKE);
                    m_objVector[j]->collidedWith(BUBBLE);

                }
            }

            else if((m_objVector[i]->getType() == SPIKE) && (m_objVector[j]->getType() == BUBBLE))
            {
                bool result = false;

                result = Physics::testCollision(static_cast<Circle*>(m_objVector[j]), static_cast<Rect*>(m_objVector[i]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(BUBBLE);
                    m_objVector[j]->collidedWith(SPIKE);

                }
            }

            else if((m_objVector[i]->getType() == BUBBLE) && (m_objVector[j]->getType() == PLATFORM))
            {
                bool result = false;

                result = Physics::testCollision(static_cast<Circle*>(m_objVector[i]), static_cast<Rect*>(m_objVector[j]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(PLATFORM);
                    m_objVector[j]->collidedWith(BUBBLE);

                }
            }

            else if((m_objVector[i]->getType() == PLATFORM) && (m_objVector[j]->getType() == BUBBLE))
            {
                bool result = false;

                result = Physics::testCollision(static_cast<Circle*>(m_objVector[j]), static_cast<Rect*>(m_objVector[i]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {
                    m_objVector[i]->collidedWith(BUBBLE);
                    m_objVector[j]->collidedWith(PLATFORM);

                }
            }
             else if((m_objVector[i]->getType() == BUBBLE) && (m_objVector[j]->getType() == BUBBLE))
            {
                bool result = false;

                result = Physics::testCollision(static_cast<Circle*>(m_objVector[j]), static_cast<Circle*>(m_objVector[i]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(BUBBLE);
                    m_objVector[j]->collidedWith(BUBBLE);

                }
            }




             else if((m_objVector[i]->getType() == PLAYER) && (m_objVector[j]->getType() == GOAL))
            {
                bool result = false;
                result = Physics::testCollision(static_cast<Rect*>(m_objVector[i]), static_cast<Rect*>(m_objVector[j]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {
                    m_objVector[i]->collidedWith(GOAL);
                    m_objVector[j]->collidedWith(PLAYER);

                }
            }
             else if((m_objVector[i]->getType() == GOAL) && (m_objVector[j]->getType() == PLAYER))
            {
                bool result = false;
                result = Physics::testCollision(static_cast<Rect*>(m_objVector[j]), static_cast<Rect*>(m_objVector[i]));
                m_objVector[i]->setCollision(m_objVector[i]->getCollision() + result);
                m_objVector[j]->setCollision(m_objVector[j]->getCollision() + result);

                if(result)
                {

                    m_objVector[i]->collidedWith(PLAYER);
                    m_objVector[j]->collidedWith(GOAL);

                }
            }



            }
            }



}

}
CollisionManager::~CollisionManager()
{
    //dtor
}
