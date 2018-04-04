#ifndef GOAL_H
#define GOAL_H

#include "../core/geometry/Rect.h"
#include "../core/physics/Vector2D.h"
#include "../core/animation/Animation.h"


class Goal : public Rect
{
    public:
        Goal();
        Goal(Vector2D position);
        void draw();
        void update();
        virtual ~Goal();
    protected:
    private:
        Animation m_anim;
};

#endif // GOAL_H
