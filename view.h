#ifndef VIEW_H
#define VIEW_H
#include "general_types.h"

class View
{
public:
    View();
    menu display_menu();
    next_turn display_turn(Status_of_game game_status, menu user_choice);

private:
    std::string display_cards( std::vector<card> cards);
    next_turn display_turn_two_players(Status_of_game game_status);
    next_turn display_turn_computer(Status_of_game game_status);

};

#endif // VIEW_H
