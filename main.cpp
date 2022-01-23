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
    menu user_choice = game_view.display_menu();
    Model game_model;

    while(user_choice != menu::exit)
    {
        Status_of_game status;
        status =  game_model.start_new_game(user_choice);

        next_turn next;
        next = game_view.display_turn(status);

        while(next != next_turn::exit)
        {
            status = game_model.start_next_turn(next);
            next = game_view.display_turn(status);
        }

        user_choice = game_view.display_menu();
    }
    return 0;
}
