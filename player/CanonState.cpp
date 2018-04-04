#include "CanonState.h"
#include "Canon.h"

CanonState::CanonState(Canon* c) : m_canon(c)
{
    //ctor
}
void CanonState::load()
{
	//anim.unload();
}
void CanonState::draw()
{
	//anim.draw(player.pos, player.angle);
}

void CanonState::update()
{


    //anim.update();
}

void CanonState::processEvent()
{

}

void CanonState::unload()
{
	//anim.unload();
}

CanonState::~CanonState()
{
    //dtor
}
