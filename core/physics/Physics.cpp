#include "Physics.h"

#include "../geometry/Circle.h"
#include "../geometry/Rect.h"
#include "../../player/Player.h"
#include "../allegro/Allegro.h"

#include <iostream>

namespace Physics
{


double positionOnAxis(Vector2D point,Vector2D axis)
{
    return axis*(point.projectedOn(axis));
}

double firstPositionOnAxis(Circle* c,Vector2D axis)
{
    return positionOnAxis(c->pos+axis.normalized()*c->radius,axis);
}

double secondPositionOnAxis(Circle* c,Vector2D axis)
{
    return positionOnAxis(c->pos-axis.normalized()*c->radius,axis);
}

bool testCollision(Circle* a, Circle* b)
{
    double dcenter = (a->pos - b->pos).length();

    if(dcenter < a->radius + b->radius)
    {
        Vector2D normal = (a->pos - b->pos).normalized();

        double depth = (a->radius + b->radius) - dcenter;

        //collisionResponse(a, b, normal, depth);

        return true;
    }
    return false;
}

bool testCollision(Circle* b, Rect* a)
{


    Vector2D quinasA[4];
    Vector2D eixos[8];
    double overlaps[8];

    eixos[0]= a->half_width;
    eixos[1]= a->half_height;
    eixos[2]= b->pos - a->getVertex(0);
    eixos[3]= b->pos - a->getVertex(1);
    eixos[4]= b->pos - a->getVertex(2);
    eixos[5]= b->pos - a->getVertex(3);


    quinasA[0]= a->pos+ a->half_width + a->half_height;
    quinasA[1]= a->pos+ a->half_width - a->half_height;
    quinasA[2]= a->pos- a->half_width + a->half_height;
    quinasA[3]= a->pos- a->half_width - a->half_height;

    int i;
    int j;
    double valorA;
    double valorB;
    double maxAEixo;
    double maxBEixo;
    double minAEixo;
    double minBEixo;
    bool hasOverlap;
    for(j=0;j<6;j++)
    {
        hasOverlap=false;
        maxAEixo = positionOnAxis(quinasA[0],eixos[j]);
        maxBEixo = firstPositionOnAxis(b,eixos[j]);
        minAEixo = maxAEixo;
        minBEixo = firstPositionOnAxis(b,eixos[j]);
        for(i=1;i<4;i++)
        {
            valorA = positionOnAxis(quinasA[i],eixos[j]);
            if(i==1) valorB = firstPositionOnAxis(b,eixos[j]);
            if(i==2) valorB = secondPositionOnAxis(b,eixos[j]);
            minAEixo = min (valorA,minAEixo);
            minBEixo = min (valorB,minBEixo);
            maxAEixo = max (valorA,maxAEixo);
            maxBEixo = max (valorB,maxBEixo);
        }
        if(minBEixo<minAEixo && minAEixo<maxBEixo)
        {
            hasOverlap=true;
            overlaps[j]=min(minAEixo-minBEixo,maxBEixo-minAEixo)*(-1);
        }
        if(minAEixo<minBEixo && minBEixo<maxAEixo)
        {
            hasOverlap=true;
            overlaps[j]= min(maxAEixo-minBEixo,minBEixo-minAEixo);
        }

        if(hasOverlap==false)
        {
            return false;
        }
    }
    double minOverlap=overlaps[0];
    int index=0;
    for(i=1;i<6;i++)
    {

            if(fabs(overlaps[i])<fabs(minOverlap))
            {
                minOverlap=overlaps[i];
                index=i;
            }
    }
   // collisionResponse(a,b,eixos[index].normalized()*(-1),minOverlap);

    return true;
}

bool testCollision(Rect* a, Circle* b)
{
   return testCollision(b,a);
}

bool testCollision(Rect* a, Rect* b)
{

    if((a->pos.x + a->half_width.x) < (b->pos.x - b->half_width.x)) return false;

    if((a->pos.x - a->half_width.x) > (b->pos.x + b->half_width.x)) return false;


    if((a->pos.y + a->half_height.y) < (b->pos.y - b->half_height.y))return false;

    if((a->pos.y - a->half_height.y) > (b->pos.y + b->half_height.y))return false;


    Vector2D normal;
    //a->pos.setY(-2.0 + a->pos.getY());
    double distanceX = a->pos.x - b->pos.x;
    double distanceY = a->pos.y - b->pos.y;
    double minDistanceX = a->half_width.x + b->half_width.x;
    double minDistanceY = a->half_height.y + b->half_height.y;

    double depthX = distanceX > 0 ? minDistanceX - distanceX : -minDistanceX - distanceX;
    double depthY = distanceY > 0 ? minDistanceY - distanceY : -minDistanceY - distanceY;

    /*if(abs(depthY) < abs(depthX))
        normal=  Vector2D(0, depthY);
    else
        normal = Vector2D(depthX, 0);*/
    normal = Vector2D(depthX, depthY);

    if(a->type == PLAYER)
    {

        collisionResponse((Player*)a, b, normal, 1.0);

    }
    else
        collisionResponse(a, b, normal, 1.0);
    return true;
}

bool testCollisionTopScreen(Circle* a)
{
	if(a->pos.getY() + a->radius <= 0)
	{
		return true;
	}
	return false;
}

bool testCollisionDownScreen(Circle* a)
{
	if(a->pos.getY() - a->radius>=Allegro::getHeight())
	{
		return true;
	}
	return false;
}


bool testCollisionRightScreen(Circle* a)
{
	if(a->pos.getX() - a->radius>= Allegro::getWidth())
	{
		return true;
	}
	return false;
}


bool testCollisionLeftScreen(Circle* a)
{
	if(a->pos.getX() + a->radius<=0)
	{
		return true;
	}
	return false;
}

bool testCollisionTopScreen(Rect* a)
{
    for( int i=0;i<3;i++)
    {
        if(a->getVertex(i).getY()<=0)
        {
            return true;
        }
    }
    return false;
}

bool testCollisionDownScreen(Rect* a)
{
	for(int i=0;i<3;i++)
    {
        if(a->getVertex(i).getY()>=600)
        {
            return true;
        }
    }
    return false;
}


bool testCollisionRightScreen(Rect* a)
{
	for( int i=0;i<3;i++)
    {
        if(a->getVertex(i).getX()<=0)
        {
            return true;
        }
    }
    return false;
}


bool testCollisionLeftScreen(Rect* a)
{
	for(int i=0;i<3;i++)
    {
        if(a->getVertex(i).getX()>=800)
        {
            return true;
        }
    }
    return false;
}

void collisionResponse(Player* a, Rect* b, Vector2D normal, double depth)
{

    double player_left = (a->pos - a->half_width).getX();
    double player_right = (a->pos + a->half_width).getX();
    double player_top = (a->pos - a->half_height).getY();
    double player_bottom = (a->pos + a->half_height).getY();

    double rect_left = (b->pos - b->half_width).getX();
    double rect_right = (b->pos + b->half_width).getX();
    double rect_top = (b->pos - b->half_height).getY();
    double rect_bottom = (b->pos + b->half_height).getY();

    /*if(((a->half_width.getX() + b->half_width.getX()) <= abs(a->pos.getX() - b->pos.getX())) && (player_left <= rect_right))
        std::cout << "LEFT" << std::endl;//a->setCollisionType(LEFT);
    else if(((a->half_width.getX() + b->half_width.getX()) <= abs(a->pos.getX() - b->pos.getX())) && (player_right >= rect_left ))
       std::cout << "RIGHT" << std::endl;// a->setCollisionType(RIGHT);
    else if(((a->half_height.getY() + b->half_height.getY()) <= abs(a->pos.getY() - b->pos.getY())) && (player_bottom >= rect_top ))
        std::cout << "BOTTOM" << std::endl;//a->setCollisionType(BOTTOM);
    else if(((a->half_height.getY() + b->half_height.getY()) <= abs(a->pos.getY() - b->pos.getY())) && (player_top <= rect_bottom ))
       std::cout << "TOP" << std::endl;// a->setCollisionType(TOP);





    if(normal.getX() == 0.0) {
        std::cout  << "vertical" << std::endl;
        a->vel.setY(0.0);
    }
    else if(normal.getY() == 0.0) {
        std::cout  << "horizontal" << std::endl;
        a->vel.setX(0.0);
        a->vel.setY(-0.5);
    }*/

    if(abs(normal.getY()) > abs(normal.getX()))
        {
            if(player_right >= rect_left && player_left < rect_left)
                a->setCollisionDirection(RIGHT);
            else
                a->setCollisionDirection(LEFT);

            a->pos = a->pos + (Vector2D(normal.getX(), 0.0));
        }
    else
        {

            if(player_bottom >= rect_top && player_top < rect_top)
                a->setCollisionDirection(BOTTOM);
            else
                a->setCollisionDirection(TOP);

            a->pos = a->pos + (Vector2D(0.0, normal.getY()));
            //a->vel.setY(0.0); //ajuste feito em y
        }

    //calcular em qual lado ocorreu



}

void collisionResponse(Rect* a, Rect* b, Vector2D normal, double depth) {std::cout << "Estou no lugar errado" <<std::endl;}

void collisionResponse(Object* a, Object* b, Vector2D normal, double depth)
{
   double impulso= normal*(a->vel-b->vel)*
    (1.0+sqrt(a->elasticity*b->elasticity));

    a->pos = a->pos+ normal*(depth*a->inv_mass/
    (a->inv_mass+b->inv_mass));
    b->pos = b->pos- normal*(depth*b->inv_mass/
    (a->inv_mass+b->inv_mass));

    a->vel =a->vel - normal*(impulso*a->inv_mass/
   (a->inv_mass+b->inv_mass));
    b->vel = b->vel + normal*(impulso*b->inv_mass/
    (a->inv_mass+b->inv_mass));

}

void dragObject(Object* a, double forcaDrag)
{
   if(a->vel.length()==0) return;
   Vector2D drag = a->vel.normalized()*forcaDrag*(-1);

   if(drag.length()> a->vel.length())
   {
       a->vel= Vector2D ();
   }
   else
   {
       a->vel = a->vel+drag;
   }
}

void addForce(Object*a,Vector2D force)
{
	a->acl = a->acl+force;
}

void removeForce(Object* a) {

    a->acl = Vector2D(0 , 0);
}

void updateSpeed(Object*a)
{
     a->vel = a->vel + a->acl;
}

void addImpulse(Object* a,Vector2D impulse)
{
	a->vel= a->vel+ impulse;
}

void moveObject(Object* a)
{
    a->pos=a->pos+a->vel;
}

void updateSpeedWithGravity(Object*a, Vector2D gravity)
{
     a->vel = a->vel + a->acl + gravity;
}

}
