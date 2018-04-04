#ifndef CANONHANDLER_H
#define CANONHANDLER_H

#include "../core/physics/Vector2D.h"

class Canon;



class CanonHandler
{
public:
    CanonHandler(int canonNum);
    void config(int canonNum, Vector2D position, int canonDirection);
    void initialSelected(int selected);
    Canon* getCanon(int canonNum);
    void load();
    void processEvent();
    void update();
    void draw();
    virtual ~CanonHandler();
protected:
private:

    void init();
    Canon* m_canon;
    int m_canonQty;
    int m_currentSelected;
    bool m_input;
};

#endif // CANONHANDLER_H
