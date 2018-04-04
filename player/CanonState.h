#ifndef CANONSTATE_H
#define CANONSTATE_H

#include "../core/states/State.h"
#include "../core/animation/Animation.h"


class Canon;

class CanonState : public State
{
    public:
        CanonState(Canon* c);

		virtual void load();
        virtual void unload();
        virtual void draw();
        virtual void update();
        virtual void processEvent();
        virtual ~CanonState();
    protected:

        Canon* m_canon;
        Animation m_anim;
    private:
};

#endif // CANONSTATE_H
