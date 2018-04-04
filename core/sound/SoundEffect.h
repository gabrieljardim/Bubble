#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H


#include "../allegro/Allegro.h"

class SoundEffect
{
    public:
        SoundEffect();

        void play();
        void loadSE(char*);
        void unloadSE();

        virtual ~SoundEffect();
    protected:
    private:
        ALLEGRO_SAMPLE* soundEffect;
        ALLEGRO_SAMPLE_INSTANCE* soundEffectInstance;
};

#endif // SOUNDEFFECT_H
