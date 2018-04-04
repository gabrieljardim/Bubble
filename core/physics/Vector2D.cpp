#include "Vector2D.h"

Vector2D::Vector2D(double x, double y)
{
    //ctor
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D()
{
    x=0;
    y=0;
}

Vector2D::~Vector2D()
{
    //dtor
}

Vector2D Vector2D::projectedOn(Vector2D v)
{
    Vector2D u = Vector2D(this->x,this->y);
    double proj = (u*v)/(v*v);
    return  v.normalized()*proj;
}

double Vector2D::length()
{
    return sqrt(x*x + y*y);
}

Vector2D Vector2D::normalized()
{
    return Vector2D(getX()/this->length(),getY()/this->length());
}
