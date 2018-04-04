#include "YouWin.h"

#include "../core/game/Game.h"

YouWin::YouWin()
{
    m_anim.load("sprites/youwin.png",1, 0 ,false);
}

void YouWin::load()
{
}

void YouWin::unload()
{
}
void YouWin::processEvent()
{
    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_ENTER))
        Game::Instance()->changeState("faseTeste");
}
void YouWin::update()
{
}
void YouWin::draw()
{
     m_anim.draw(Vector2D(Allegro::getWidth()/2, Allegro::getHeight()/2), 0, false);
}

YouWin::~YouWin()
{
    //dtor
}
