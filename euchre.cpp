// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include "Card.h"
#include "Player.h"
#include "Pack.h"
using namespace std;

class Game
{
   private:
    int game_round;
    int points_team_one;
    int points_team_two;
    // points of player 0 and 2
    int trickcount_team_one;
    // points of player 1 and 3
    int trickcount_team_two;
    Pack pack;
    // pointers of players
    vector<Player*> player_list;
    // upcard
    Card upcard;
    // trump
    std::string trump;
    // delear's index in vector
    int dealer_index;
    // player of the trump series
    Player *player_trump;
    

public:

    // initialising the game variables
    Game():game_round(0),points_team_one(0),points_team_two(0),trickcount_team_one(0),
    trickcount_team_two(0), upcard(Card()),
    trump(Card::SUIT_CLUBS), dealer_index(0)
    { }
    
    // getter function for points for team one
    int get_points_one()
    {
        return trickcount_team_one;
    }
    
    // getter fucntion for points for team two
    int get_points_two()
    {
        return trickcount_team_two;
    }
    
    // getter function for dealer's index
    int get_dealers_index()
    {
        return dealer_index;
    }
    
    int get_points_team_one()
    {
        return points_team_one;
    }
    int get_points_team_two()
    {
        return points_team_two;
    }
    
    //function to generate players
    void generate_players(std::string player_name, std::string player_type)
    {
        Player *player = Player_factory(player_name, player_type);
        player_list.push_back(player);
    }
    
    // initialising pack by reading it from a file
    void pack_initialsing(std::string filename_copy)
    {
        ifstream fin(filename_copy);
        if (!fin.is_open())
        {
            cout << "Error opening " << filename_copy << endl;
            return;
        }
        // include pack for initialisation
        pack = Pack(fin);
        fin.close();
    }
    // shuffle the cards
    void shuffle_card(std::string shuffle_type)
    {
        if (shuffle_type == "shuffle")
        {
            pack.shuffle();
        }
        else
        {
            pack.reset();
        }
    }
    
    void who_is_dealer_index(int round)
    {
        int round_copy = round % 4;
        Player *dealer = player_list[round_copy];
        cout << dealer->get_name() << " deals" << std::endl;
        dealer_index = round_copy;
    }
    
    
    void distribute_cards_and_upcard()
    {
        
        player_list[(dealer_index + 1) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 1) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 1) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 2) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 2) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 3) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 3) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 3) % 4]->add_card(pack.deal_one());
        player_list[dealer_index]->add_card(pack.deal_one());
        player_list[dealer_index]->add_card(pack.deal_one());
        player_list[(dealer_index + 1) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 1) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 2) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 2) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 2) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index+ 3) % 4]->add_card(pack.deal_one());
        player_list[(dealer_index + 3) % 4]->add_card(pack.deal_one());
        player_list[dealer_index]->add_card(pack.deal_one());
        player_list[dealer_index]->add_card(pack.deal_one());
        player_list[dealer_index]->add_card(pack.deal_one());
        upcard = pack.deal_one();
        cout << upcard.get_rank() << " of " << upcard.get_suit() << " turned up" <<
        std::endl;
    }
    
   void making_trump()
    {
        std::string order_up_suit_copy = "";
        bool value = false;
        for (int i = 1 ; i < 4; i++)
        {
            value = player_list[(dealer_index+i)% 4]->make_trump(upcard,false,
                                                                 1, order_up_suit_copy);
            if (value == true)
            {
                trump = order_up_suit_copy;
                cout << player_list[(dealer_index + i) % 4]->get_name() << " orders up "
                << trump << std::endl << std::endl;
                player_trump = player_list[(dealer_index + i) % 4];
                player_list[dealer_index]->add_and_discard(upcard);
                return;
            }
            else
            {
       cout << player_list[(dealer_index + i) % 4]->get_name() << " passes" << std::endl;
            }
        }
        value = player_list[dealer_index]->make_trump(upcard,true, 1, order_up_suit_copy);
        if (value == true)
        {
            trump = order_up_suit_copy;
            cout << player_list[dealer_index]->get_name() << " orders up "
            << trump << std::endl << std::endl;
            player_trump = player_list[dealer_index];
            player_list[dealer_index]->add_and_discard(upcard);
            return;
        }
        else
        {
            cout << player_list[dealer_index]->get_name() << " passes" << std::endl;
        }
        for (int i = 1 ; i < 4; i++)
        {
            value = player_list[(dealer_index + i) % 4]->make_trump(upcard,
                                                            false, 2, order_up_suit_copy);
            if (value == true)
            {
                trump = order_up_suit_copy;
                cout << player_list[(dealer_index + i) % 4]->get_name() << " orders up "
                << trump << std::endl << std::endl;
                player_trump = player_list[(dealer_index + i) % 4];
                return;
            }
            else
            {
       cout << player_list[(dealer_index + i) % 4]->get_name() << " passes" << std::endl;
            }
        }
        player_list[dealer_index]->make_trump(upcard, true, 2, order_up_suit_copy);
        trump = order_up_suit_copy;
        player_trump = player_list[dealer_index];
        cout << player_list[dealer_index]->get_name() << " orders up " << trump <<
        std::endl << std::endl;
}
    
    void led_card_and_play_five_tricks()
    {
        Player *lead_player = player_list[(dealer_index + 1) % 4];
        int index = 0;
        vector<Card> play_hand;
        vector<Player*> player_hand;
        Card led, play, highest = Card();
        trickcount_team_one = 0;
        trickcount_team_two = 0;
        for (int i = 0; i < 5; i++)
        {
            led = lead_player->lead_card(trump);
            cout << led.get_rank() << " of " << led.get_suit() << " led by "
            << lead_player->get_name() << std::endl;
            play_hand.push_back(led);
            player_hand.push_back(lead_player);
            for (int i = 0; i < 4; i++)
            {
                if (lead_player == player_list[i])
                {
                    index = i;
                }
            }
            for (int i = 1; i < 4; i++)
            {
                play = player_list[(index + i) % 4]->play_card(led, trump);
                cout << play.get_rank() << " of " << play.get_suit() << " played by " <<
                player_list[(index + i) % 4]->get_name() << std::endl;
                play_hand.push_back(play);
                player_hand.push_back(player_list[(index + i) % 4]);
            }
            int index_highest_card = 0;
            highest = play_hand[0];
            for (int i = 0; i < static_cast<int>(play_hand.size()); i++)
            {
                if (Card_less(highest, play_hand[i], led, trump))
                {
                    highest = play_hand[i];
                    index_highest_card = i;
                }
            }
            lead_player = player_hand[index_highest_card];
        cout << lead_player->get_name() << " takes the trick" << std::endl << std::endl;
            player_hand.clear();
            play_hand.clear();
            if (lead_player->get_name() == player_list[0]->get_name() ||
                lead_player->get_name() == player_list[2]->get_name())
            {
                trickcount_team_one++;
            }
            else
            {
                trickcount_team_two++;
            }
        }
     }
    
    void print_hand_winner()
    {
        std::cout << player_list[0]->get_name() << " and " << player_list[2]->get_name()
        << " have " << points_team_one << " points" << std::endl;
        std::cout << player_list[1]->get_name() << " and " << player_list[3]->get_name()
        << " have " << points_team_two << " points" << std::endl;
        std::cout << std::endl;
    }
    
    void print_hand_team_one()
    {
        std::cout << player_list[0]->get_name() << " and " <<
        player_list[2]->get_name() << " win the hand" << std::endl;
    }
    
    void print_hand_team_two()
    {
        std::cout << player_list[1]->get_name() << " and " <<
        player_list[3]->get_name() << " win the hand" << std::endl;
    }
    
    void print_game_winner()
    {
        if (points_team_one > points_team_two)
        {
            std::cout << player_list[0]->get_name() << " and " <<
            player_list[2]->get_name() << " win!" << std::endl;
        }
        else
        {
            std::cout << player_list[1]->get_name() << " and " <<
            player_list[3]->get_name() << " win!" << std::endl;
        }
        std::cout << std::endl;
    }
    
    void point_of_each_team()
    {
        std::string winning_team = "";
        std::string order_up_team = "";
    if (trickcount_team_one == 3 || trickcount_team_one == 4 || trickcount_team_one == 5)
        {
            winning_team = "Team One";
        }
        else
        {
            winning_team = "Team Two";
        }
        if (player_trump->get_name() == player_list[0]->get_name() ||
            player_trump->get_name() == player_list[2]->get_name())
        {
            order_up_team = "Team One";
        }
        else 
        {
            order_up_team = "Team Two";
        }
        if (winning_team == "Team One")
        {
             if (order_up_team == "Team One")
             {
                 if (trickcount_team_one == 3|| trickcount_team_one == 4)
                 {
                     points_team_one = points_team_one + 1;
                     print_hand_team_one();
                 }
                 else
                 {
                     points_team_one = points_team_one + 2;
                     print_hand_team_one();
                     std::cout << "march!" << std::endl;
                 }
             }
            else
            {
                points_team_one = points_team_one + 2;
                print_hand_team_one();
                std::cout << "euchred!" << std::endl;
            }
        }
        else
        {
            if (order_up_team == "Team Two")
            {
                if (trickcount_team_two == 3|| trickcount_team_two == 4)
                {
                    points_team_two = points_team_two + 1;
                    print_hand_team_two();
                }
                else
                {
                    points_team_two = points_team_two + 2;
                    print_hand_team_two();
                    std::cout << "march!" << std::endl;
                }
            }
           else
           {
               points_team_two = points_team_two + 2;
               print_hand_team_two();
               std::cout << "euchred!" << std::endl;
           }
            
        }
        print_hand_winner();
    }
    
    void play_entire_game(int points_win, std::string shuffle_copy)
    {
        while ((points_team_one < points_win) && (points_team_two < points_win))
        {
            std::cout << "Hand " << game_round << std::endl;
            shuffle_card(shuffle_copy);
            who_is_dealer_index(game_round);
            distribute_cards_and_upcard();
            making_trump();
            led_card_and_play_five_tricks();
            point_of_each_team();
            game_round++;
        }
        print_game_winner();
    }
    
    void delete_players()
    {
        for (int i = 0; i < static_cast<int>(player_list.size()); i++)
        {
            delete player_list[i];
        }
    }
};
        
void print_error()
{
    std::cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
              << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
              << "NAME4 TYPE4" << std::endl;
    
}
   

int main(int argc, char *argv[])
{
    if (argc != 12)
    {
        print_error();
        return 1;
    }
    Game hand;
    std::string filename = argv[1];
    hand.pack_initialsing(filename);
    std::string shuffle_argument = argv[2];
    if (shuffle_argument != "shuffle" && shuffle_argument != "noshuffle")
    {
        print_error();
        return 2;
    }
    int points_to_win = atoi(argv[3]);
    if (points_to_win < 1 || points_to_win > 100)
    {
        print_error();
        return 3;
    }
    for (int i = 5; i < 12; i = i + 2)
    {
        std::string player_type = argv[i];
        if (player_type != "Simple" && player_type != "Human")
        {
            print_error();
            return 1;
        }
    }
    for (int i = 4; i < 12; i = i + 2)
    {
        std::string player_name = argv[i];
        std::string player_type = argv[i+1];
        hand.generate_players(player_name, player_type);
    }
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
    hand.play_entire_game(points_to_win, shuffle_argument);
    hand.delete_players();
    return 0;
}
