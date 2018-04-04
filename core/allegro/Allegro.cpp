#include "Allegro.h"

int Allegro::getWidth()
{
    return al_get_display_width(display);
}

int Allegro::getHeight()
{
    return al_get_display_height(display);
}

Allegro::Allegro()
{
    //ctor
}

Allegro::~Allegro()
{
    //dtor
}


//Inicializa as funções e addons do Allegro
void Allegro::initialize(int width, int height)
{
    al_init();

    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(8);
    al_init_font_addon();
    al_init_ttf_addon();

    construct(width, height);

    al_start_timer(timer);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
}

//Constroi a tela e os recursos do Allegro (Fila de eventos, timer,...)
void Allegro::construct(int width, int height)
{


    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    al_set_new_display_option( ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST );
    display = al_create_display(width, height);

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0/fps);
}

//Destroi os recursos do Allegro
void Allegro::destruct()
{
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
}

//Desinstala as funções do Allegro
void Allegro::shutdown()
{
    al_shutdown_image_addon();
    al_shutdown_primitives_addon();
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_uninstall_audio();
    al_shutdown_font_addon();
    al_shutdown_ttf_addon();
    destruct();
}

//Atributos estáticos para uso em todo o projeto
ALLEGRO_EVENT_QUEUE* Allegro::event_queue = NULL;
const double Allegro::fps = 60.0;
ALLEGRO_DISPLAY* Allegro::display = NULL;
ALLEGRO_TIMER* Allegro::timer = NULL;
