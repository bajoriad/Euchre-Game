// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include <array>
#include "Card.h"
#include "Player.h"
#include <algorithm>
using namespace std;


class Simple : public Player
{
   private:
    // name of the player
    std::string simple_name;
    // hand of the player
    std::vector<Card> hand;
    
   public:
    // default constructor
    Simple();
    // non - default constructor
    Simple(std::string name_in) : simple_name(name_in) {}
    // getter name function
    virtual const std::string & get_name() const
    {
        return simple_name;
    }
    
    virtual void add_card(const Card &c)
    {
        assert((static_cast<int>(hand.size())) < MAX_HAND_SIZE);
        hand.push_back(c);
    }
    
    
    virtual bool make_trump(const Card &upcard, bool is_dealer,
                            int round, std::string &order_up_suit) const
    {
        assert(round == 1 || round == 2);
        int count = 0;
        std::string upcard_suit = upcard.get_suit();
        if (round == 1)
        {
            for (int i = 0; i < MAX_HAND_SIZE; i++)
            {
                if (((hand[i].get_suit() == upcard_suit) && hand[i].is_face()) ||
                    ((hand[i].is_left_bower(upcard_suit))))
                {
                    count++;
                }
            }
            if (count >= 2)
            {
                order_up_suit = upcard_suit;
                return true;
            }
            else
            {
                return false;
            }
        }
        else 
        {
            upcard_suit = Suit_next(upcard_suit);
            if (is_dealer == true)
            {
                order_up_suit = upcard_suit;
                return true;
            }
            for (int i = 0; i < MAX_HAND_SIZE; i++)
            {
                if (((hand[i].get_suit() == upcard_suit) && hand[i].is_face()) ||
                    (hand[i]).is_left_bower(upcard_suit))
                {
                    count++;
                }
            }
            if (count >= 1)
            {
                order_up_suit = upcard_suit;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    
    virtual void add_and_discard(const Card &upcard)
     {
        Card c;
        std::string trump_suit = upcard.get_suit();
        hand.push_back(upcard);
       
       for (int i = 0; i < (static_cast<int>(hand.size()) - 1); i++)
        {
            for (int j =  i + 1; j < (static_cast<int>(hand.size())); j++)
            {
                if(Card_less(hand[i], hand[j], trump_suit))
                   {
                       c = hand[(static_cast<int>(hand.size()) - 1)];
                       hand[(static_cast<int>(hand.size()) - 1)] = hand[i];
                       hand[i] = c;
                    }
             }
         }
        hand.pop_back();
     }
    
    virtual Card lead_card(const std::string &trump)
    {
        Card c_highest;
        int index = 0;
        int size = static_cast<int>(hand.size());
        assert(size >= 1);
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (hand[i].is_trump(trump))
            {
                count++;
            }
        }
        
        if (count != size)
        {
            std::vector<Card> non_trump;
            for (int i = 0; i < size; i++)
            {
                if((!hand[i].is_trump(trump)))
                {
                    non_trump.push_back(hand[i]);
                }
            }
            int non_trump_size = static_cast<int>(non_trump.size());
            c_highest = non_trump[0];
            for (int i = 0; i < non_trump_size; i++)
            {
                if (Card_less(c_highest, non_trump[i], trump))
                {
                    c_highest = non_trump[i];
                }
            }
            for (int i = 0; i < size; i++)
            {
                if (hand[i] == c_highest)
                {
                    index = i;
                }
            }
        }
        else
        {
            c_highest = hand[0];
            for (int i = 0; i < size; i++)
            {
                if (Card_less(c_highest, hand[i], trump))
                {
                    c_highest = hand[i];
                    index = i;
                }
            }
        }
        hand.erase(hand.begin()+index);
        return c_highest;
    }
    
    virtual Card play_card(const Card &led_card, const std::string &trump)
    {
        Card c_play;
        int index = 0;
        int count = 0;
        int size = static_cast<int>(hand.size());
        std::string led_card_suit = led_card.get_suit(trump);
        assert(size >= 1);
        for (int i = 0; i < size; i++)
        {
            if ((hand[i].get_suit(trump) == led_card_suit))
            {
                count++;
            }
        }
        if (count != 0)
        {
            std::vector<Card> lead_suit;
            for (int i = 0; i < size; i++)
            {
                if ((hand[i].get_suit(trump) == led_card_suit))
                {
                    lead_suit.push_back(hand[i]);
                }
            }
            int lead_suit_size = static_cast<int>(lead_suit.size());
            c_play = lead_suit[0];
            for (int i = 0; i < lead_suit_size; i++)
            {
                if (Card_less(c_play, lead_suit[i], led_card, trump))
                {
                    c_play = lead_suit[i];
                }
            }
            for (int i = 0; i < size; i++)
            {
                if(hand[i] == c_play)
                {
                    index = i;
                }
            }
        }
        else
        {
            c_play = hand[0];
            for (int i = 0; i < size; i++)
            {
                if (Card_less(hand[i], c_play, led_card, trump))
                {
                    c_play = hand[i];
                    index = i;
                }
            }
        }
        hand.erase(hand.begin()+index);
        return c_play;
    }
};

class Human : public Player
{
     private:
     //name of the player
    std::string human_name;
    // hand of the human player
    std::vector<Card> human_hand;
    
public:
    // default constructor
    Human();
    // non-default constructor
    Human(std::string name_in) : human_name(name_in) {}
    
    virtual const std::string & get_name() const
    {
        return human_name;
    }
    
    virtual void add_card(const Card &c)
    {
        assert((static_cast<int>(human_hand.size())) < MAX_HAND_SIZE);
        human_hand.push_back(c);
    }
    
    static void print(std::vector<Card> hand, std::string name)
    {
        int size = static_cast<int>(hand.size());
        std::sort(hand.begin(), hand.end());
        for (int i = 0; i < size; i++)
        {
            std::cout << "Human player " << name << "'s hand: [" << i << "] " <<
            hand[i] << std::endl;
        }
    }
    
    virtual bool make_trump(const Card &upcard, bool is_dealer,
                            int round, std::string &order_up_suit) const
    {
        assert(round == 1 || round == 2);
        std::string player_move = "";
        print(human_hand,human_name);
        std::cout << "Human player " << human_name <<
        ", please enter a suit, or \"pass\":" << std::endl;
        std::cin >> player_move;
        if (is_dealer == true && round == 2)
        {
            order_up_suit = player_move;
            return  true;
        }
        if (player_move == "Spades" || player_move == "Hearts" ||
            player_move == "Clubs" || player_move == "Diamonds")
        {
            order_up_suit = player_move;
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    virtual void add_and_discard(const Card &upcard)
    {
        int discard_index = 0;
        std::sort(human_hand.begin(), human_hand.end());
        print(human_hand,human_name);
        human_hand.push_back(upcard);
        std::cout << "Discard upcard: [-1]" << std::endl;
        std::cout << "Human player " << human_name <<
        ", please select a card to discard:" << std::endl;
        std::cin >> discard_index;
        if (discard_index == -1)
        {
            human_hand.erase(human_hand.begin()+5);
        }
        else
        {
            human_hand.erase(human_hand.begin()+discard_index);
        }
    }
        
    virtual Card lead_card(const std::string &trump)
    {
        Card led_card = Card();
        int card_number = 0;
        std::sort(human_hand.begin(), human_hand.end());
        print(human_hand,human_name);
        std::cout << "Human player " << human_name << ", please select a card:"
        << std::endl;
        std::cin >> card_number;
        led_card = human_hand[card_number];
        human_hand.erase(human_hand.begin()+card_number);
        return led_card;
        
    }
    
    virtual Card play_card(const Card &led_card, const std::string &trump)
    {
        Card play = Card();
        int card_number = 0;
        std::sort(human_hand.begin(), human_hand.end());
        print(human_hand,human_name);
        std::cout << "Human player " << human_name << ", please select a card:"
        << std::endl;
        std::cin >> card_number;
        play = human_hand[card_number];
        human_hand.erase(human_hand.begin()+card_number);
        return play;
    }
    
};

std::ostream & operator<<(std::ostream &os, const Player &p)
{
    os << p.get_name();
    return os;
    
}

Player * Player_factory(const std::string &name, const std::string &strategy)
{
   if (strategy == "Simple")
   {
       return new Simple(name);
   }
   else if (strategy == "Human")
   {
       return new Human(name);
   }
  assert(false);
  return nullptr;
    
}
