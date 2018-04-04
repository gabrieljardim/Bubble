#include "GameOverScreen.h"

#include "../core/game/Game.h"

GameOverScreen::GameOverScreen()
{
    m_anim.load("sprites/gameover.png",1, 0 ,false);
}

void GameOverScreen::load()
{
}

void GameOverScreen::unload()
{
}
void GameOverScreen::processEvent()
{
    if(al_key_down(&(Game::Instance()->state),ALLEGRO_KEY_ENTER))
        Game::Instance()->changeState("faseTeste");
}
void GameOverScreen::update()
{
}
void GameOverScreen::draw()
{
     m_anim.draw(Vector2D(Allegro::getWidth()/2, Allegro::getHeight()/2), 0, false);
}

GameOverScreen::~GameOverScreen()
{
    //dtor
}
