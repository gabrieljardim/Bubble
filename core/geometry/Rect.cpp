#include "../geometry/Rect.h"
#include "../game/Game.h"
#include <allegro5/allegro_primitives.h>
#include <cmath>

Rect::Rect(const double half_width, const double half_height)
{
    this->half_width= Vector2D(half_width,0);
    this->half_height= Vector2D(0,half_height);
}

Vector2D Rect::getVertex(int i)
{
        if(i==0) return pos+half_width + half_height;
        if(i==1) return pos+ half_width - half_height;
        if(i==2) return pos-half_width + half_height;
        return pos- half_width - half_height;
}

Rect::Rect(void)
{

}

Rect::~Rect(void)
{
}

void Rect::draw(void)
{

    if(Game::Instance()->debugMode)
        al_draw_rectangle(pos.getX() - half_width.getX(), pos.getY() - half_height.getY(), pos.getX() + half_width.getX(), pos.getY() + half_height.getY(), al_map_rgb(255,0,0), 1.0);
    else
        al_draw_filled_rectangle(pos.getX() - half_width.getX(), pos.getY() - half_height.getY(), pos.getX() + half_width.getX(), pos.getY() + half_height.getY(), al_map_rgb(80,150,50));


}
