#include <iostream>
#include "core/allegro/Allegro.h"
#include "core/game/Game.h"

using namespace std;

int main()
{
    srand (time(NULL));
    int width = 1280;//1024;//852;
    int height = 720;//578;//480;

    Allegro::initialize(width, height); //Inicializa o Allegro e constroi os recursos
    Game* game = Game::Instance(); //Pega a instancia de Jogo

    game->loop(); //Executa o loop até sair

    Allegro::shutdown(); //Finaliza o Allegro e seus recursos

    return 0;
}
