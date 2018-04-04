#ifndef SPIKE_H
#define SPIKE_H

#include "../core/animation/Animation.h"
#include "../core/physics/Physics.h"

class Spike
{
    public:
        Spike(Vector2D position, int direction);
        Spike();
        void setDirection(int direction) {m_direction = direction;}
        void setPosition(Vector2D position) {m_pos = position;}
        void draw();
        void draw(Vector2D position);
        double width();
        double height();
        virtual ~Spike();
    protected:
    private:
        Animation m_anim;
        Vector2D m_pos;
        int m_direction;
};

#endif // SPIKE_H
