#include "model.h"

Model::Model()
{
    m_player_1.points = 0;
    m_player_2.points = 0;
    m_player_1.type = player_type::human;
    m_player_2.type = player_type::human;
    m_deck.reset_deck_and_shuffle();
}


Status_of_game Model::start_new_game(menu user_choice)
{
    if(user_choice == menu::exit)
    {
       // to do: implement exit
    }
    else if(user_choice == menu::new_game_2_players)
    {
        m_player_2.type = player_type::human;
    }
    else if(user_choice == menu::new_game_with_computer)
    {
        m_player_2.type = player_type::computer;
    }

    m_player_1.cards.push_back(m_deck.get_one_card());
    m_player_1.cards.push_back(m_deck.get_one_card());

    update_points(m_player_1);

    m_player_2.cards.push_back(m_deck.get_one_card());
    m_player_2.cards.push_back(m_deck.get_one_card());

    update_points(m_player_2);

    Status_of_game status;
    status.player_1 = m_player_1;
    status.player_2 = m_player_2;

    if(m_player_1.points == 21 && m_player_2.points == 21)
    {
        status.status = game_status::draw;
    }
    else if (m_player_1.points == 21)
    {
        status.status = game_status::player_1_won;
    }
    else if (m_player_2.points == 21)
    {
        status.status = game_status::player_2_won;
    }
    else
    {
        status.status = game_status::player_1_turn;
    }

    return status;
}

void Model::update_points(Player &player)
{
    player.points = 0;
    int Number_of_A = 0;
    for(unsigned int i=0; i<player.cards.size(); i++)
    {
        int x = player.cards[i].points;
        if(x !=11)
        {
            player.points +=x;
        }
        else
        {
            Number_of_A++;
        }
    }
    if (Number_of_A>=1)
    {
        player.points = player.points + Number_of_A - 1;
        if(player.points > 10)
        {
            player.points += 1;
        }
        else
        {
            player.points += 11;
        }
    }
}
