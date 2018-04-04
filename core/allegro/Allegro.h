#ifndef ALLEGRO_H
#define ALLEGRO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Allegro
{
    public:
        Allegro();
        virtual ~Allegro();
        static void initialize(int width, int height);
        static void construct(int width, int height);
        static void shutdown();
        static void destruct();

        static int getWidth();
        static int getHeight();


        static ALLEGRO_EVENT_QUEUE* event_queue;
        static ALLEGRO_DISPLAY* display;
        static ALLEGRO_TIMER* timer;
        static const double fps;
    protected:
    private:

};

#endif // ALLEGRO_H
