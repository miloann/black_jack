#include "deck.h"

Deck::Deck()
{
    create_all_cards();
}

card Deck::get_one_card()
{
    card return_card = m_cards[m_cards.size()-1];
    m_cards.pop_back();
    return return_card;
}


void Deck::reset_deck_and_shuffle()
{

}

bool Deck::is_empty()
{
    return m_cards.empty();
}

void Deck::create_all_cards()
{
    const char suit_tab[4] = {3, //♥
                              4, //♦
                              5, //♣
                              6};  //♠

    const std::string rank_tab[4]={"J","D","K","A"};
    for(int i=0; i<4; i++)
    {
        for (int j =2; j<11; j++)
        {
            card tmp_card;
            tmp_card.points = j;
            tmp_card.rank = std::to_string(j);
            tmp_card.suit = suit_tab[i];
            m_cards.push_back(tmp_card);
        }

        for(int k=0; k<4; k++)
        {
            card tmp_card;
            if(k != 3)
            {
               tmp_card.points = 10;
            }
            else
            {
                tmp_card.points = 11;
            }
            tmp_card.rank = rank_tab[k];
            tmp_card.suit = suit_tab[i];

            m_cards.push_back(tmp_card);
        }
    }




}
