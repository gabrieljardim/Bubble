#include "SoundEffect.h"

SoundEffect::SoundEffect()
{
    //ctor
}

void SoundEffect::loadSE(char* path)
{
    soundEffect = al_load_sample(path);
    soundEffectInstance = al_create_sample_instance(soundEffect);
    al_attach_sample_instance_to_mixer(soundEffectInstance, al_get_default_mixer());
}

void SoundEffect::play()
{
    al_play_sample_instance(soundEffectInstance);
}

void SoundEffect::unloadSE()
{
    al_destroy_sample(soundEffect);
    al_destroy_sample_instance(soundEffectInstance);
}

SoundEffect::~SoundEffect()
{
    //dtor
}
