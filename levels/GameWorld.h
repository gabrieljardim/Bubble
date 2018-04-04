#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "../core/states/GameState.h"
#include "../core/physics/Vector2D.h"


class GameWorld : public GameState
{
    public:
        GameWorld();
        double getSpeed(){return m_speed;}  //controlar a velocidade inteira da fase
        Vector2D getGravity(){return m_gravity;}
        virtual ~GameWorld();
    protected:
        Vector2D m_gravity;
        double m_speed;

    private:
};

#endif // GAMEWORLD_H
