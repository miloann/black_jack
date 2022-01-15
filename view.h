#ifndef VIEW_H
#define VIEW_H
#include "general_types.h"



class View
{
public:
    View();
    menu display_menu();
    void display_turn(Status_of_game game_status);

private:
    std::string display_cards( std::vector<card> cards);

};

#endif // VIEW_H
