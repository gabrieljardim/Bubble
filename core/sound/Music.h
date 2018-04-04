#ifndef MUSIC_H
#define MUSIC_H

#include "../allegro/Allegro.h"

class Music
{
    public:
        Music();
        void play();
        void stop();
        void loadMusic(char*);
        void unloadMusic();
        virtual ~Music();
    protected:
    private:
        ALLEGRO_SAMPLE* music;
        ALLEGRO_SAMPLE_INSTANCE* musicInstance;
};

#endif // MUSIC_H
