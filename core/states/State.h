#ifndef STATE_H
#define STATE_H

#include "../allegro/Allegro.h"

// Interface básica para qualquer State utilizado em qualquer parte do jogo
class State
{
	public:
		State();
		virtual ~State();

		virtual void load() = 0;
        virtual void unload() = 0;
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void processEvent() = 0;
	protected:
	private:
};

#endif // STATE_H
