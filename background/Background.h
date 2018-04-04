#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "../core/allegro/Allegro.h"

class Background
{
    public:
        Background();
        void load();
        void draw();
        void unload();

        virtual ~Background();
    protected:
    private:
        ALLEGRO_BITMAP * fundo;
};

#endif // BACKGROUND_H
