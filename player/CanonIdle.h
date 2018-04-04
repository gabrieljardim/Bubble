#ifndef CANONIDLE_H
#define CANONIDLE_H

#include "CanonState.h"

class Canon;

class CanonIdle : public CanonState
{
    public:
        CanonIdle(Canon* c);
        void load();
        void draw();
        void update();
        void processEvent();
        void unload();
        virtual ~CanonIdle();
    protected:
    private:
        Animation* m_currentAnim;
        Animation m_selectedAnim;
        int radius;
        int current_radius;
        bool m_canShoot;
};

#endif // CANONIDLE_H
