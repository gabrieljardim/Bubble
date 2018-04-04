#ifndef SPIKEPLATFORM_H
#define SPIKEPLATFORM_H

#include "../core/geometry/Rect.h"
#include "../core/physics/Vector2D.h"
#include "Spike.h"

class Spike;

class SpikePlatform : public Rect
{
    public:
        SpikePlatform(Vector2D position, int spikeQty, int direction);
        void init();
        void configVertical();
        void configHorizontal();
        void draw();
        virtual ~SpikePlatform();
    protected:
    private:
        int m_spikeQty;
        int m_direction;
        Spike m_spike;
        Vector2D* m_spikePosition;

};

#endif // SPIKEPLATFORM_H
