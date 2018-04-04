#include "Game.h"
#include "../../levels/WelcomesScreen.h"
#include "../../levels/GameOverScreen.h"
#include "../../levels/YouWin.h"
#include <iostream>
using namespace std;

Game::Game()
{
    posx = posy = 0;
    closeGame = false;
    states.insert(pair<string, GameState*>("faseTeste", new FaseTeste())); //Insere uma instancia de uma classe filha de GameState
    states.insert(pair<string, GameState*>("welcomeScreen", new WelcomeScreen())); //Insere uma instancia de uma classe filha de GameState
    states.insert(pair<string, GameState*>("gameOverScreen", new GameOverScreen()));
    states.insert(pair<string, GameState*>("youWin", new YouWin()));
    currentState = states.at("welcomeScreen"); //Escolhe um dos Estados
    currentState->load(); //Carrega o estado
    debugMode = false;
}

Game::~Game()
{

}


Game* Game::Instance()
{
    static Game j;
    return &j;
}

//Desenha na tela
void Game::draw()
{
    currentState->draw();
}

//Processa o Input
void Game::processEvent()
{
    if(al_key_down(&state,ALLEGRO_KEY_ESCAPE))
    {
        closeGame = true; //Apertando ESC, o Game altera o atributo para fechar a janela
    }
    else if(al_key_down(&state,ALLEGRO_KEY_H))
    {
        debugMode = true;
    }
    else if(al_key_down(&state,ALLEGRO_KEY_G))
    {
        debugMode = false;
    }
    currentState->processEvent();
}

void Game::loop()
{
    while (1)
    {

        al_wait_for_event( Allegro::event_queue, &event ); //Espera eventos na fila
        al_get_keyboard_state(&state); //Pega o estado do teclado
        if (event.type == ALLEGRO_EVENT_TIMER)
        {

            processEvent();
            currentState->update();

            refresh = true; //A cada frame, chame um update
        }

        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || closeGame) //Se clicar no X ou se o atributo closeGame for true ele fecha o Game
        {
            currentState->unload(); //descarrega a fase atual e fecha o Game
            break;
        }
        if(al_is_event_queue_empty(Allegro::event_queue) && refresh)
        {
            if(debugMode)
            al_clear_to_color(al_map_rgb(0, 0, 0));
            else
            al_clear_to_color(al_map_rgb(100, 200, 230));

            draw();
            al_flip_display();
            refresh = false;
        }

    }
}

//Muda o estado
void Game::changeState(string name)
{
    Game::Instance()->currentState->unload(); //Descarrega o estado atual
    Game::Instance()->currentState = Game::Instance()->states.at(name); //Muda pro estado dado no parametro do método
    Game::Instance()->currentState->load(); //Carrega o próximo estado
}
