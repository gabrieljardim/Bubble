#include "Background.h"

Background::Background()
{
    load();
    //ctor
}
void Background::load()
{
    this->fundo = al_load_bitmap ("images/space3.png");
}
void Background::draw()
{
    al_draw_bitmap(fundo,0,0,0);
}
void Background::unload()
{
    al_destroy_bitmap(this->fundo);
}
Background::~Background()
{
    //dtor
}
