#include "PlayerState.h"
#include "../../player/Player.h"
#include <cmath>

PlayerState::PlayerState(Player* p) : m_player(p)
{
	//ctor
}

PlayerState::~PlayerState()
{
	//dtor
}

void PlayerState::load()
{
	//anim.unload();
}
void PlayerState::draw()
{
	//anim.draw(player.pos, player.angle);
}

void PlayerState::update()
{


    //anim.update();
}

void PlayerState::processEvent()
{

}

void PlayerState::unload()
{
	//anim.unload();
}

int PlayerState::getCurrentFrameWidth()
{
	//return anim.getCurrentFrameWidth();
	return 0; //placeholder
}

int PlayerState::getCurrentFrameHeight()
{
	//return anim.getCurrentFrameHeight();
	return 0; //placeholder

}
