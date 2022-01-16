#ifndef GENERAL_TYPES_H
#define GENERAL_TYPES_H
#include "deck.h"

enum class menu
{
    new_game_2_players = 0,
    new_game_with_computer,
    exit
};

enum class next_turn
{
    player_get_new_card= 0,
    player_stand,
    exit,
};

enum class player_type
{
   human=0,
   computer
};

enum class playing
{
    player_in_the_game = 0,
    player_stand,
};

struct Player
{
    int points;
    std::vector<card> cards;
    player_type type;
    playing play_type;
};

enum class game_status
{
    player_1_turn = 1,
    player_2_turn,
    player_1_won,
    player_2_won,
    draw,
};

struct Status_of_game
{
    Player player_1;
    Player player_2;
    game_status status;
};


#endif // GENERAL_TYPES_H
