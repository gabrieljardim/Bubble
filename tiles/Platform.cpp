#include "Platform.h"

Platform::Platform(double width, double height, Vector2D position, ALLEGRO_COLOR color): Rect(width, height)
{
    //ctor
    pos = position;
    m_color = color;
    type = PLATFORM;
    m_collidable = true;
}

void Platform::draw()
{
     al_draw_filled_rectangle(pos.getX() - half_width.getX(), pos.getY() - half_height.getY(), pos.getX() + half_width.getX(), pos.getY() + half_height.getY(), m_color);

}

Platform::~Platform()
{
    //dtor
}
