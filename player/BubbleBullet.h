#ifndef BUBBLEBULLET_H
#define BUBBLEBULLET_H

#include "../core/geometry/Circle.h"

class Player;
class BubbleBullet : public Circle
{
    public:
        BubbleBullet();
        void update();
        void draw();
        virtual ~BubbleBullet();
    protected:
    private:
};

#endif // BUBBLEBULLET_H
