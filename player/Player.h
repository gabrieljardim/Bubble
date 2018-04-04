#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <iostream>
#include "../core/geometry/Rect.h"
#include "../core/physics/Vector2D.h"
#include "../core/allegro/Allegro.h"
#include "../core/geometry/Circle.h"

using namespace std;

class PlayerState;
class BubbleBullet;


class Player:public Rect
{
    public:
        Player(GameWorld* gw, Vector2D position);
        void draw();
        void load();
        void unload();
        void update();
        void processEvent();
        void changeState(string name);


        bool& canJump(){return m_canJump;}
        bool& drawFlippedAnim(){return m_flippedAnim;}
        BubbleBullet* getBubble() {return m_bubble;}
        void setBubble(BubbleBullet* b){m_bubble = b;}
        void moveLeft();
        void moveRight();
        void moveLeftOnAir(double intensity);
        void moveRightOnAir(double intensity);
        void jump();
        virtual ~Player();
    protected:
    private:
        ALLEGRO_BITMAP * img;
        PlayerState* currentState;
        map<string, PlayerState*> states;
        double m_horizontalMoveMaxSpeed;
        bool m_canJump;
        bool m_flippedAnim;
        Vector2D m_walkVector;
        BubbleBullet* m_bubble;

};

#endif // PLAYER_H
