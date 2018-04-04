#ifndef PLATFORM_H
#define PLATFORM_H

#include "../core/geometry/Rect.h"


class Platform : public Rect
{
    public:
        Platform(double width, double height, Vector2D(position), ALLEGRO_COLOR color);
        void draw();
        virtual ~Platform();
    protected:
    private:
        ALLEGRO_COLOR m_color;
};

#endif // PLATFORM_H
