#include "WelcomesScreen.h"
#include "../core/game/Game.h"

WelcomeScreen::WelcomeScreen()
{
    m_anim.load("sprites/welcome.png",1, 0 ,false);
}

void WelcomeScreen::load()
{
}

void WelcomeScreen::unload()
{
}
void WelcomeScreen::processEvent()
{
    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_ENTER))
        Game::Instance()->changeState("faseTeste");
}
void WelcomeScreen::update()
{
}
void WelcomeScreen::draw()
{
     m_anim.draw(Vector2D(Allegro::getWidth()/2, Allegro::getHeight()/2), 0, false);
}

WelcomeScreen::~WelcomeScreen()
{
    //dtor
}
