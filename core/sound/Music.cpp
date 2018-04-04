#include "Music.h"

Music::Music()
{
    //ctor
}

void Music::loadMusic(char* path)
{
    music = al_load_sample(path);
    musicInstance = al_create_sample_instance(music);
    al_attach_sample_instance_to_mixer(musicInstance, al_get_default_mixer());
    al_set_sample_instance_playmode(musicInstance, ALLEGRO_PLAYMODE_LOOP);
}

void Music::play()
{
    al_play_sample_instance(musicInstance);
}
void Music::stop()
{
    al_stop_sample_instance(musicInstance);
}

void Music::unloadMusic()
{
    al_destroy_sample(music);
    al_destroy_sample_instance(musicInstance);
}

Music::~Music()
{

}





