#ifndef TESTE_H
#define TESTE_H
#include "GameState.h"
#include "Allegro.h"
class Teste : public GameState
{
    public:
        Teste();
        virtual ~Teste();
        void draw();
        void load();
        void unload();
        void update();
        void processEvent(ALLEGRO_EVENT &, ALLEGRO_KEYBOARD_STATE);
    protected:
    private:
};

#endif // TESTE_H
