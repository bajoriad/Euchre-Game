// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

// add your code below
Card::Card():rank(RANK_TWO),suit(SUIT_SPADES) {}

Card::Card(const std::string &rank_in, const std::string &suit_in):rank(rank_in),
suit(suit_in) {}

std::string Card::get_rank() const
{
    return rank;
}

std::string Card::get_suit() const
{
    return suit;
}

std::string Card::get_suit(const std::string &trump) const
{
    std::string suit_copy = "";
    if (is_left_bower(trump))
    {
        suit_copy = trump;
    }
    else
    {
        suit_copy = suit;
    }
    return suit_copy;
}

bool Card::is_face() const
{
    if (rank == RANK_JACK || rank == RANK_ACE || rank == RANK_KING || rank == RANK_QUEEN)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Card::is_right_bower(const std::string &trump) const
{
    if (suit == trump && rank == RANK_JACK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Card::is_left_bower(const std::string &trump) const
{
    bool value  = false;
   if (trump == SUIT_SPADES)
   {
       if (rank == RANK_JACK && suit == SUIT_CLUBS)
       {
           value = true;
       }
   }
   else if (trump == SUIT_CLUBS)
   {
       if (rank == RANK_JACK && suit == SUIT_SPADES)
       {
           value = true;
       }
   }
    else if (trump == SUIT_DIAMONDS)
    {
        if (rank == RANK_JACK && suit == SUIT_HEARTS)
        {
           value = true;
        }
    }
    else if (trump == SUIT_HEARTS)
    {
        if (rank == RANK_JACK && suit == SUIT_DIAMONDS)
        {
            value = true;
        }
    }
    else
    {
        value = false;
    }
    return value;
}

bool Card::is_trump(const std::string &trump) const
{
    if (suit == trump || is_left_bower(trump))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator==(const Card &lhs, const Card &rhs)
{
    std::string lhs_rank = lhs.get_rank();
    std::string rhs_rank = rhs.get_rank();
    std::string lhs_suit = lhs.get_suit();
    std::string rhs_suit = rhs.get_suit();
    if ((lhs_rank == rhs_rank) && (lhs_suit == rhs_suit))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(const Card &lhs, const Card &rhs)
{
    bool value= false;
    std::string lhs_rank = lhs.get_rank();
    std::string rhs_rank = rhs.get_rank();
    std::string lhs_suit = lhs.get_suit();
    std::string rhs_suit = rhs.get_suit();
    int lhs_rank_index = 0;
    int rhs_rank_index = 0;
    int lhs_suit_index = 0;
    int rhs_suit_index = 0;
    
    if (lhs_rank != rhs_rank)
    {
        for (int i = 7; i < NUM_RANKS; i++)
        {
            if (RANK_NAMES_BY_WEIGHT[i] == lhs_rank)
            {
                lhs_rank_index = i;
            }
        }
        for (int i = 7; i < NUM_RANKS; i++)
        {
            if (RANK_NAMES_BY_WEIGHT[i] == rhs_rank)
            {
                rhs_rank_index = i;
            }
        }
        if (lhs_rank_index < rhs_rank_index)
        {
            value = true;
        }
        else
        {
            value = false;
        }
    }
    else if (lhs_rank == rhs_rank)
    {
        for (int i = 0; i < NUM_SUITS; i++)
        {
            if (SUIT_NAMES_BY_WEIGHT[i] == lhs_suit)
            {
                lhs_suit_index = i;
            }
        }
        
        for (int i = 0; i < NUM_SUITS; i++)
        {
            if (SUIT_NAMES_BY_WEIGHT[i] == rhs_suit)
            {
                rhs_suit_index = i;
            }
        }
        if (lhs_suit_index < rhs_suit_index)
        {
            value = true;
        }
        else
        {
            value = false;
        }
    }
    return value;
}

bool operator<=(const Card &lhs, const Card &rhs)
{
    return (lhs < rhs || lhs == rhs);
}

bool operator>(const Card &lhs, const Card &rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const Card &lhs, const Card &rhs)
{
    return (lhs > rhs || lhs == rhs);
}


bool operator!=(const Card &lhs, const Card &rhs)
{
    return !(lhs == rhs);
}

std::string Suit_next(const std::string &suit)
{
    std::string next_suit = "";
    if (suit == Card::SUIT_SPADES)
    {
        next_suit = Card::SUIT_CLUBS;
    }
    else if (suit == Card::SUIT_CLUBS)
    {
        next_suit = Card::SUIT_SPADES;
    }
    else if (suit == Card::SUIT_HEARTS)
    {
        next_suit = Card::SUIT_DIAMONDS;
    }
    else if (suit == Card::SUIT_DIAMONDS)
    {
        next_suit = Card::SUIT_HEARTS;
    }
    return next_suit;
}

std::ostream & operator<<(std::ostream &os, const Card &card)
{
    os << card.get_rank() << " of " << card.get_suit();
    return os;
}

bool Card_less(const Card &a, const Card &b, const std::string &trump)
{
    std::string a_suit = a.get_suit();
    std::string b_suit = b.get_suit();
    bool value = false;
    if ((!a.is_trump(trump)) && b_suit == trump)
    {
        value = true;
    }
    else if ((a.is_trump(trump)) && (!b.is_trump(trump)))
    {
        value = false;
    }
    else if (a.is_trump(trump) && b.is_trump(trump))
    {
        
        if (a_suit == trump && b_suit == trump)
        {
            if (b.is_right_bower(trump))
            {
                value = true;
            }
            else if (a.is_right_bower(trump))
            {
                value = false;
            }
            else if ( a < b)
            {
                value = true;
            }
            else
            {
                value = false;
            }
        }
        else if (a.is_left_bower(trump) && b_suit == trump)
        {
            if (b.is_right_bower(trump))
            {
                value = true;
            }
            else
            {
                value = false;
            }
        }
        else if (a_suit == trump && b.is_left_bower(trump))
        {
            if (a.is_right_bower(trump))
            {
                value = false;
            }
            else { value = true; }
        }
    }
    else
    {
        if (a < b)
        {
            value = true;
        }
        else { value = false; }
    }
    return value;
}

bool Card_less(const Card &a, const Card &b, const Card &led_card,
               const std::string &trump)
{
    std::string a_suit = a.get_suit(trump);
    std::string b_suit = b.get_suit(trump);
    std::string a_suit_copy = a.get_suit();
    std::string b_suit_copy = b.get_suit();
    std::string led_card_suit = led_card.get_suit(trump);
    bool value = false;
    
    if ((a_suit != trump && b_suit == trump) || (a_suit != led_card_suit &&
        a_suit != trump && b_suit == led_card_suit))
    {
        value = true;
    }
    else if ((a_suit == trump && b_suit != trump) || (a_suit == led_card_suit &&
               b_suit != trump && b_suit != led_card_suit))
    {
        value = false;
    }
    else if (a_suit == trump && b_suit == trump)
    {
        if ((b.is_right_bower(trump)) || (b.is_left_bower(trump) &&
                                          (!a.is_right_bower(trump))))
        {
            value = true;
        }
        else if ((a.is_right_bower(trump)) || (a.is_left_bower(trump) &&
                                               (!b.is_right_bower(trump))) )
        {
            value = false;
        }
        else
        {
            if (a < b)
            {
                value = true;
            }
            else
            {
                value = false;
            }
        }
    }
    else
    {
        if (a < b) {  value = true; }
        else { value = false; }
    }
    return value;
}
// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec (see the appendices) before implementing
// the following operator overload functions:
//   operator<<
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=
