#include "view.h"
#include <iostream>
#include<stdlib.h>

View::View()
{

}

menu View::display_menu()
{
    system("CLS");
    std::cout << "[0]   Play game for 2 players" << std::endl;
    std::cout << "[1]   Play game with computer" << std::endl;
    std::cout << "[2]   Exit" << std::endl;
    int player_choice;
    std::cin >>  player_choice;
    return static_cast<menu>(player_choice);
}

next_turn View::display_turn(Status_of_game game_status)
{
    return display_turn_two_players(game_status);
}

next_turn View::display_turn_two_players(Status_of_game game_status)
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Player 1: " << std::endl;
    std::cout << display_cards(game_status.player_1.cards) << std::endl;
    std::cout << "Total points: " << game_status.player_1.points << std::endl << std:: endl;
    std::cout << "Player 2: " << std::endl;
    std::cout << display_cards(game_status.player_2.cards) << std::endl;
    std::cout << "Total points: " << game_status.player_2.points <<std::endl << std::endl;

    switch(game_status.status)
    {
    case game_status::draw:
        std::cout << "DRAW! \nThe end of the game" << std::endl;
        return next_turn::exit;

    case game_status::player_1_won:
        std::cout << "Player 1 won! \nThe end of the game" << std::endl;
        return next_turn::exit;

    case game_status::player_2_won:
        std::cout << "Player 2 won! \nThe end of the game" << std::endl;
        return next_turn::exit;

    case game_status::player_1_turn:
        std::cout << "Player 1 turn" << std::endl;
        std::cout << "Do you want to get new card?" << std::endl;
        std::cout << "[0] Yes" << std::endl;
        std::cout << "[1] No" << std::endl;
        int player_choice_1;
        std::cin >> player_choice_1;
        return static_cast<next_turn>(player_choice_1);

    case game_status::player_2_turn:
        std::cout << "Player 2 turn" << std::endl;
        std::cout << "Do you want to get new card?" << std::endl;
        std::cout << "[0] Yes" << std::endl;
        std::cout << "[1] No" << std::endl;
        int player_choice_2;
        std::cin >> player_choice_2;
        return static_cast<next_turn>(player_choice_2);

    default:
        return next_turn::exit;
    }
}

std::string View::display_cards(std::vector<card> cards)
{
    std::string ret_value;
    for (unsigned int i=0; i< cards.size(); i++)
    {
        ret_value = ret_value + cards[i].rank + cards[i].suit + " ";
    }
    return ret_value;
}
