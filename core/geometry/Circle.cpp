#include "Circle.h"
#include <allegro5/allegro_primitives.h>
#include <cmath>

Circle::Circle(const double radius):
    Object(), radius(radius)
{
}

Circle::Circle(void)
{

}

Circle::~Circle(void)
{
}

void Circle::draw(void)
{
    al_draw_circle(pos.getX(), pos.getY(), radius, al_map_rgb(255,0,0), 1.0);
}
