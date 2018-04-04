#ifndef CANON_H
#define CANON_H

#include <map>
#include <iostream>

#include "../core/geometry/Rect.h"
#include "../core/physics/Vector2D.h"
#include "BubbleBullet.h"


class CanonState;

using namespace std;

class Canon : public Rect
{
    public:
        Canon(Vector2D position);
        Canon();
        void draw();
        void load();
        void unload();
        void update();
        void processEvent();
        void changeState(string name);
        void shoot();
        bool isSelected(){return m_selected;}
        void setSelected(bool selected){m_selected = selected;}
        void setDirection(int direction){m_direction = direction;}
        void resetBulletPosition();
        int getDirection(){return m_direction;}
        BubbleBullet* getBullet() {return &m_bullet;}
        virtual ~Canon();
    protected:
    private:
        map<string, CanonState*> states;
        CanonState* m_currentState;
        bool m_selected;
        BubbleBullet m_bullet;
        int m_direction;

};

#endif // CANON_H
