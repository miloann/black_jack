#include "model.h"
#include <iostream>

Model::Model()
{
    reset_game();
}


Status_of_game Model::start_new_game(menu user_choice)
{
    reset_game();
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

    m_whose_turn = player_turn::player_1_turn;
    m_player_1.play_type = playing::player_in_the_game;
    m_player_2.play_type = playing::player_in_the_game;

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

Status_of_game Model::start_next_turn(next_turn next)
{
    Status_of_game status;
    if(m_player_2.type == player_type::human)
    {
        status = start_next_turn_two_players(next);
    }
    else
    {
        status = start_next_turn_computer(next);
    }
    return status;
}

Status_of_game Model::start_next_turn_two_players(next_turn next)
{
    Player& player_in_game = m_whose_turn==player_turn::player_1_turn ? m_player_1 : m_player_2;

    switch (next)
    {
    case next_turn::player_get_new_card:
        player_in_game.play_type = playing::player_in_the_game;
        player_in_game.cards.push_back(m_deck.get_one_card());
        update_points(player_in_game);
        if(player_in_game.points == 21)
        {
            player_in_game.play_type = playing::player_stand;
        }
        break;

    case next_turn::player_stand:
        player_in_game.play_type = playing::player_stand;
        break;

    default:
        player_in_game.play_type = playing::player_stand; // never happend
    }

    Status_of_game status;
    status.player_1 = m_player_1;
    status.player_2 = m_player_2;

    if(m_player_1.points > 21)
    {
        status.status = game_status::player_2_won;
    }
    else if(m_player_2.points > 21)
    {
        status.status = game_status::player_1_won;
    }
    else if(m_player_1.play_type == playing::player_stand && m_player_2.play_type == playing::player_stand)
    {
        if(m_player_1.points > m_player_2.points)
        {
            status.status = game_status::player_1_won;
        }
        else if (m_player_1.points == m_player_2.points)
        {
            status.status = game_status::draw;
        }
        else
        {
            status.status = game_status::player_2_won;
        }
    }
    else if(m_player_1.play_type == playing::player_stand && m_player_2.play_type == playing::player_in_the_game)
    {
        m_whose_turn = player_turn::player_2_turn;
        status.status = game_status::player_2_turn;
    }
    else if(m_player_1.play_type == playing::player_in_the_game && m_player_2.play_type == playing::player_stand)
    {
        m_whose_turn = player_turn::player_1_turn;
        status.status = game_status::player_1_turn;
    }
    else if(m_player_1.play_type == playing::player_in_the_game && m_player_2.play_type == playing::player_in_the_game)
    {
        if(m_whose_turn==player_turn::player_1_turn )
        {
            m_whose_turn = player_turn::player_2_turn;
            status.status = game_status::player_2_turn;
        }
        else
        {
            m_whose_turn = player_turn::player_1_turn;
            status.status = game_status::player_1_turn;
        }
    }

    return status;
}

Status_of_game Model::start_next_turn_computer(next_turn next)
{
    Player& player_in_game = m_whose_turn==player_turn::player_1_turn ? m_player_1 : m_player_2;

    switch (next)
    {
    case next_turn::player_get_new_card:
        player_in_game.play_type = playing::player_in_the_game;
        player_in_game.cards.push_back(m_deck.get_one_card());
        update_points(player_in_game);
        if(player_in_game.points == 21)
        {
            player_in_game.play_type = playing::player_stand;
        }
        break;

    case next_turn::player_stand:
        player_in_game.play_type = playing::player_stand;
        break;

    default:
        player_in_game.play_type = playing::player_stand; // never happend
    }

    Status_of_game status;
    status.player_1 = m_player_1;
    status.player_2 = m_player_2;

    if(m_player_1.points > 21)
    {
        status.status = game_status::player_2_won;
    }
    else if(m_player_2.points > 21)
    {
        status.status = game_status::player_1_won;
    }
    else if(m_player_1.play_type == playing::player_stand && m_player_2.play_type == playing::player_stand)
    {
        if(m_player_1.points > m_player_2.points)
        {
            status.status = game_status::player_1_won;
        }
        else if (m_player_1.points == m_player_2.points)
        {
            status.status = game_status::draw;
        }
        else
        {
            status.status = game_status::player_2_won;
        }
    }
    else if(m_player_1.play_type == playing::player_stand && m_player_2.play_type == playing::player_in_the_game)
    {
        m_whose_turn = player_turn::player_2_turn;
        status.status = game_status::player_2_turn;
    }
    else if(m_player_1.play_type == playing::player_in_the_game && m_player_2.play_type == playing::player_in_the_game)
    {
        status.status = game_status::player_1_turn;
    }
    return status;
}

void Model::reset_game()
{
    m_player_1.points = 0;
    m_player_2.points = 0;
    m_player_1.type = player_type::human;
    m_player_2.type = player_type::human;
    m_deck.reset_deck_and_shuffle();
    m_player_1.cards.clear();
    m_player_2.cards.clear();
}




