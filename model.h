#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "deck.h"
#include "general_types.h"

enum class player_turn
{
    player_1_turn=0,
    player_2_turn,
};

class Model
{
public:
    Model();
    Status_of_game start_new_game(menu user_choice);
    void update_points(Player& player);
    Status_of_game start_next_turn(next_turn next);

private:
    Player m_player_1;
    Player m_player_2;
    Deck m_deck;
    player_turn m_whose_turn;
};


#endif // MODEL_H
