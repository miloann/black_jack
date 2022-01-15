#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "deck.h"
#include "general_types.h"

class Model
{
public:
    Model();
    Status_of_game start_new_game(menu user_choice);
    void update_points(Player& player);
private:
    Player m_player_1;
    Player m_player_2;
    Deck m_deck;

};


#endif // MODEL_H
