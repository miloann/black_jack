#ifndef DECK_H
#define DECK_H
#include <string>
#include <vector>

struct card
{
    int points;
    char suit;
    std::string rank;
};

class IDeck // Interface for Deck
{
public:
    virtual card get_one_card()=0;
    virtual void reset_deck_and_shuffle()=0;
    virtual bool is_empty()=0;
};

class Deck: public IDeck
{
public:
    Deck();
    // IDeck interface
    card get_one_card() override;
    void reset_deck_and_shuffle() override;
    bool is_empty() override;
private:
    void create_all_cards();
    std::vector<card> m_cards;

};

#endif // DECK_H
