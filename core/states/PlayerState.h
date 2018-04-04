#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include "../states/State.h"
#include "../animation/Animation.h"
#include "../../player/Player.h"
#include "../game/Game.h"
#include <iostream>

using namespace std;

//Interface básica de todos os estados do personagem
class PlayerState : public State
{
	public:
		PlayerState(Player* p);
		virtual ~PlayerState();

		virtual void load();
        virtual void unload();
        virtual void draw();
        virtual void update();
        virtual void processEvent();

        int getCurrentFrameWidth();
        int getCurrentFrameHeight();
	protected:
		Player* m_player;
		Animation m_anim;
};

#endif // PLAYERSTATE_H
