#include <iostream>
#include "deck.h"
#include <cstdlib>
#include <ctime>
#include "view.h"
#include "model.h"

using namespace std;

int main()
{
    srand(time(NULL));

    View game_view;
    menu x;
    x = game_view.display_menu();

    Model game_model;

    Status_of_game status;
    status =  game_model.start_new_game(x);

    next_turn next;
    next = game_view.display_turn(status);

    while(next != next_turn::exit)
    {
        status = game_model.start_next_turn(next);
        next = game_view.display_turn(status);
    }

    return 0;
}
