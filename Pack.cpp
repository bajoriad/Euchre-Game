// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include <array>
#include "Card.h"
#include "Pack.h"

using namespace std;

Pack::Pack()
{
    next = 0;
    int index = 0;
    for (int suit = 0; suit < NUM_SUITS; suit++)
    {
        for (int rank = 7; rank < NUM_RANKS; rank++)
        {
            cards[index] = Card(RANK_NAMES_BY_WEIGHT[rank], SUIT_NAMES_BY_WEIGHT[suit]);
            if (index != 23)
            {
                index++;
            }
        }
    }
}

Pack::Pack(std::istream& pack_input)
{
    next = 0;
    std::string rank ="";
    std::string suit = "";
    std::string charac = "";
    for (int i = 0; i < PACK_SIZE; i++)
    {
        pack_input >> rank >> charac >> suit;
        cards[i] = Card(rank, suit);
    }
}

Card Pack::deal_one()
{
    Card card_copy = cards[next];
    next++;
    return card_copy;
}

void Pack::reset()
{
    next = 0;
}

void Pack::shuffle()
{
    std::array<Card, (PACK_SIZE/2)> first_half;
    std::array<Card, (PACK_SIZE/2)> second_half;
    for (int i = 0; i < 7; i++)
    {
        for (int index_first = 0; index_first < (PACK_SIZE/2); index_first++)
        {
            first_half[index_first] = cards[index_first];
        }
        for (int index_second = 0; index_second < (PACK_SIZE/2); index_second++)
        {
            second_half[index_second] = cards[index_second + 12];
        }
        for (int index = 0; index < (PACK_SIZE/2); index++)
        {
            cards[(index * 2)] = second_half[index];
        }
        for (int index = 0; index < (PACK_SIZE/2); index++)
        {
            cards[(index * 2) + 1] = first_half[index];
        }
    }
    reset();
}
            

bool Pack::empty() const
{
    if (next == 24)
    {
        return true;
    }
    else
    {
        return false;
    }
}
