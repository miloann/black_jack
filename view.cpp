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

void View::display_turn(Status_of_game game_status)
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Player 1: " << std::endl;
    std::cout << display_cards(game_status.player_1.cards) << std::endl;
    std::cout << "Total points: " << game_status.player_1.points << std::endl << std:: endl;
    std::cout << "Player 2: " << std::endl;
    std::cout << display_cards(game_status.player_2.cards) << std::endl;
    std::cout << "Total points: " << game_status.player_2.points << std::endl;
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
