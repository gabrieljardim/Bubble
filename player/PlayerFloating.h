#ifndef PLAYERFLOATING_H
#define PLAYERFLOATING_H

#include "../core/states/PlayerState.h"


class PlayerFloating : public PlayerState
{
    public:
        PlayerFloating(Player* p);
        void load();
        void draw();
        void update();
        void processEvent();
        void unload();
        virtual ~PlayerFloating();
    protected:
    private:
        double m_leftMoveIntensity;
        double m_rightMoveIntensity;
        double m_moveIntesityDefault;
        int debugCount;
        Animation m_jumpAnim;
        Animation* m_currentAnim;
};

#endif // PLAYERFLOATING_H
