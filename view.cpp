#include "view.h"
#include <iostream>
#include<stdlib.h>

View::View()
{

}

menu View::display_menu()
{
    std::cout << "NEW GAME" << std::endl;
    std::cout << "[" << static_cast<int>(menu::new_game_2_players) << "]   Play game for 2 players" << std::endl;
    std::cout << "[" << static_cast<int>(menu::new_game_with_computer) << "]   Play game with computer" << std::endl;
    std::cout << "[" << static_cast<int>(menu::exit) << "]   Exit" << std::endl;
    int player_choice;
    std::cin >>  player_choice;
    return static_cast<menu>(player_choice);
}

next_turn View::display_turn(Status_of_game game_status)
{
    next_turn next;
    if(game_status.player_2.type == player_type::human)
    {
        next = display_turn_two_players(game_status);
    }
    else
    {
        next = display_turn_computer(game_status);
    }
    return next;
}

next_turn View::display_turn_two_players(Status_of_game game_status)
{
    system("CLS");
    display_points(game_status);

    switch(game_status.status)
    {
    case game_status::draw:
        std::cout << "DRAW! \nThe end of the game \n" << std::endl;
        return next_turn::exit;

    case game_status::player_1_won:
        std::cout << "Player 1 won! \nThe end of the game \n" << std::endl;
        return next_turn::exit;

    case game_status::player_2_won:
        std::cout << "Player 2 won! \nThe end of the game \n" << std::endl;
        return next_turn::exit;

    case game_status::player_1_turn:
        std::cout << "Player 1 turn" << std::endl;
        std::cout << "Do you want to get new card?" << std::endl;
        std::cout << "[" << static_cast<int>(next_turn::player_get_new_card) << "] Yes" << std::endl;
        std::cout << "[" << static_cast<int>(next_turn::player_stand) << "] No" << std::endl;
        int player_choice_1;
        std::cin >> player_choice_1;
        return static_cast<next_turn>(player_choice_1);

    case game_status::player_2_turn:
        std::cout << "Player 2 turn" << std::endl;
        std::cout << "Do you want to get new card?" << std::endl;
        std::cout << "[" << static_cast<int>(next_turn::player_get_new_card) << "] Yes" << std::endl;
        std::cout << "[" << static_cast<int>(next_turn::player_stand) << "] No" << std::endl;
        int player_choice_2;
        std::cin >> player_choice_2;
        return static_cast<next_turn>(player_choice_2);

    default:
        return next_turn::exit;
    }
}

next_turn View::display_turn_computer(Status_of_game game_status)
{
    if(game_status.player_1.play_type == playing::player_in_the_game)
    {
        system("CLS");
    }

    display_points(game_status);

    switch(game_status.status)
    {
    case game_status::draw:
        std::cout << "DRAW! \nThe end of the game \n" << std::endl;
        return next_turn::exit;

    case game_status::player_1_won:
        std::cout << "Player 1 won! \nThe end of the game \n" << std::endl;
        return next_turn::exit;

    case game_status::player_2_won:
        std::cout << "Player 2 won! \nThe end of the game \n" << std::endl;
        return next_turn::exit;

    case game_status::player_1_turn:
        std::cout << "Next turn! Do you want to get new card?" << std::endl;
        std::cout << "[" << static_cast<int>(next_turn::player_get_new_card) << "] Yes" << std::endl;
        std::cout << "[" << static_cast<int>(next_turn::player_stand) << "] No" << std::endl;
        int player_choice_1;
        std::cin >> player_choice_1;
        return static_cast<next_turn>(player_choice_1);

    case game_status::player_2_turn:
        std::cout << "Computer next turn" << std::endl;
        next_turn player_choice_2;
        if((game_status.player_2.points >= 18 && game_status.player_2.points <= 21) && (game_status.player_1.points = game_status.player_2.points) )
        {
            // draw better than risking a loss
            player_choice_2 = next_turn::player_stand;

        }
        else if(game_status.player_1.points > game_status.player_2.points)
        {
            player_choice_2 = next_turn::player_get_new_card;
        }
        else
        {
            player_choice_2 = next_turn::player_stand;
        }
        return player_choice_2;

    default:
        return next_turn::exit;
    }
}

void View::display_points(Status_of_game game_status)
{
    std::cout << "Player 1: " << std::endl;
    std::cout << display_cards(game_status.player_1.cards) << std::endl;
    std::cout << "Total points: " << game_status.player_1.points << std::endl << std:: endl;
    std::cout << "Player 2: " << std::endl;
    std::cout << display_cards(game_status.player_2.cards) << std::endl;
    std::cout << "Total points: " << game_status.player_2.points <<std::endl << std::endl;
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
