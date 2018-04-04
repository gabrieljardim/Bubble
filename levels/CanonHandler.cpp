#include "CanonHandler.h"
#include "../player/Canon.h"
#include "../core/game/Game.h"
CanonHandler::CanonHandler(int canomNum) : m_canonQty(canomNum), m_input(true)
{
    //ctor
    m_currentSelected = 0;
    init();
}
void CanonHandler::init()
{
    m_canon = new Canon[m_canonQty];
}
void CanonHandler::config(int canonNum, Vector2D position, int canonDirection)
{
    if(canonNum < m_canonQty)
        m_canon[canonNum].pos = position;

    m_canon[canonNum].setDirection(canonDirection);

    if(m_canon[canonNum].getDirection() == UPWARD)
        m_canon[canonNum].getBullet()->pos = m_canon[canonNum].pos + Vector2D(0,-30);
    if(m_canon[canonNum].getDirection() == RIGHTWARD)
        m_canon[canonNum].getBullet()->pos = m_canon[canonNum].pos + Vector2D(30,0);
    if(m_canon[canonNum].getDirection() == DOWNWARD)
        m_canon[canonNum].getBullet()->pos = m_canon[canonNum].pos + Vector2D(0,30);
    if(m_canon[canonNum].getDirection() == LEFTWARD)
        m_canon[canonNum].getBullet()->pos = m_canon[canonNum].pos + Vector2D(-30,0);

}

void CanonHandler::initialSelected(int selected)
{
    m_canon[m_currentSelected].setSelected(false);
    m_canon[selected].setSelected(true);
    m_currentSelected = selected;
}

Canon* CanonHandler::getCanon(int canonNum)
{
    if(canonNum < m_canonQty)
        return &m_canon[canonNum];

}

void CanonHandler::load()
{

}

void CanonHandler::processEvent()
{
    if((!al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_A)) && (!al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_D)))
    {
        m_input = true;

    }


    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_A )&& (m_input))
    {
        m_canon[m_currentSelected].setSelected(false);
        m_currentSelected--;
        if(m_currentSelected < 0)
            m_currentSelected = m_canonQty -1; //num canons -1
        m_currentSelected = m_currentSelected% m_canonQty;
        m_canon[m_currentSelected].setSelected(true);
        m_input = false;


    }
    else if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_D)&& (m_input))
    {

        m_canon[m_currentSelected].setSelected(false);
        m_currentSelected++;
        m_currentSelected = m_currentSelected%m_canonQty;
        m_canon[m_currentSelected].setSelected(true);
        m_input = false;
    }
    m_canon[m_currentSelected].processEvent();
}
void CanonHandler::update()
{
    for(int i = 0; i < m_canonQty; ++i)
        m_canon[i].update();
}
void CanonHandler::draw()
{
    for(int i = 0; i < m_canonQty; ++i)
        m_canon[i].draw();
}
CanonHandler::~CanonHandler()
{
    //dtor
}
