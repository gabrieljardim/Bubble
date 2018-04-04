#include "Canon.h"
#include "CanonIdle.h"

#include "../core/allegro/Allegro.h"
#include "../core/geometry/Circle.h"
#include "CanonState.h"
#include "CanonShooting.h"

Canon::Canon()
{
    states.insert(pair<string, CanonState*>("idle", new CanonIdle(this)));
    states.insert(pair<string, CanonState*>("shooting", new CanonShooting(this)));
    m_currentState = states.at("idle");
    m_selected = false;
    m_bullet.radius = 30;
    m_bullet.setVisible(false);
}

Canon::Canon(Vector2D position)
{
    //ctor
    pos = position;
    states.insert(pair<string, CanonState*>("idle", new CanonIdle(this)));
    m_currentState = states.at("idle");
    m_selected = false;
}

void Canon::draw()
{
    m_currentState->draw();
    if(m_bullet.isVisible() == true)
        m_bullet.draw();
}
void Canon::load()
{

}
void Canon::unload()
{
}
void Canon::update()
{
    m_currentState->update();
    m_bullet.update();
}
void Canon::processEvent()
{
    m_currentState->processEvent();
}
void Canon::changeState(string name)
{
    m_currentState = states.at(name);
    m_currentState->load();
    std::cout << "Canon changed to state: " << name << std::endl;
}

void Canon::shoot()
{
    m_bullet.setVisible(true);
    m_bullet.setCollidable(true);


    if(m_direction == UPWARD)
        m_bullet.vel = Vector2D(0, -3);
    else if(m_direction == LEFTWARD)
        m_bullet.vel = Vector2D (-3, 0);
    else if(m_direction == RIGHTWARD)
        m_bullet.vel = Vector2D (3, 0);
    else
        m_bullet.vel = Vector2D(0, 3);

}

void Canon::resetBulletPosition()
{
    if(m_direction == UPWARD)
        m_bullet.pos =pos + Vector2D(0, -30);
    else if(m_direction == LEFTWARD)
        m_bullet.pos =pos + Vector2D(-30, 0);
    else if(m_direction == RIGHTWARD)
       m_bullet.pos =pos + Vector2D(30, 0);
    else
        m_bullet.pos =pos + Vector2D(0,30);

    m_bullet.vel = Vector2D (0 ,0);
}

Canon::~Canon()
{
    //dtor
}
