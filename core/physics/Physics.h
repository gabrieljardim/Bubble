#ifndef PHYSICS_H
#define PHYSICS_H

#include "Vector2D.h"
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Player;
class Circle;
class Rect;
class Object;

namespace Physics
{

//COLISÕES

bool testCollision(Circle*, Circle*);

bool testCollision(Circle*, Rect*);

bool testCollision(Rect*,Circle*);

bool testCollision(Rect*, Rect*);

bool testCollisionTopScreen(Circle*);

bool testCollisionDownScreen(Circle*);

bool testCollisionRightScreen(Circle*);

bool testCollisionLeftScreen(Circle*);

bool testCollisionTopScreen(Rect*);

bool testCollisionDownScreen(Rect*);

bool testCollisionRightScreen(Rect*);

bool testCollisionLeftScreen(Rect*);

void collisionResponse(Object*, Object*, Vector2D, double);

void collisionResponse(Rect*, Rect*, Vector2D, double);

void collisionResponse(Player*, Rect*, Vector2D, double);
//CINEMÁTICA

void updateSpeed(Object*);

void addImpulse(Object*,Vector2D);

void addForce(Object*,Vector2D);

void removeForce(Object*);

void moveObject(Object*);

void dragObject(Object* a, double forcaDrag);

void updateSpeedWithGravity(Object*a, Vector2D gravity);

}

#endif // PHYSICS_H
