#ifndef CANONSHOOTING_H
#define CANONSHOOTING_H

#include "CanonState.h"

class Canon;


class CanonShooting : public CanonState
{
    public:
        CanonShooting(Canon* canon);
        void load();
        void processEvent();
        void update();
        void draw();
        void unload();
        virtual ~CanonShooting();
    protected:
    private:
       int m_currentRadius;
       Animation* m_currentAnim;
        Animation m_selectedAnim;
        bool m_done;
};

#endif // CANONSHOOTING_H
