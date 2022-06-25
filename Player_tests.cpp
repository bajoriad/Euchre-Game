// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_insertion_and_get_name)
{
    Player *non_human = Player_factory("Sam", "Simple");
    ASSERT_EQUAL("Sam", non_human->get_name());
    
    Player *human = Player_factory("Jack", "Human");
    ASSERT_EQUAL("Jack", human->get_name());
    ostringstream s1;
    ostringstream s2;
    s1 << *non_human;
    s2 << *human;
    ASSERT_EQUAL(s1.str(), "Sam");
    ASSERT_EQUAL(s2.str(), "Jack");
    
    delete human;
    delete non_human;
}

// making trump when no face cards for round 1
TEST(maketrump_no_face_cards)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    std::string trump = Card::SUIT_CLUBS;
    
    bool orderup = bob->make_trump(jack_hearts, 0, 1, trump);
    ASSERT_FALSE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(maketrump_one_face_card)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
    std::string trump = Card::SUIT_CLUBS;
    bool orderup = bob->make_trump(jack_hearts, 1, 1, trump);
    ASSERT_FALSE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(maketrump_two_face_card)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    Card jack_hearts(Card::RANK_JACK, Card::SUIT_HEARTS);
    std::string trump = "";
    bool orderup = bob->make_trump(jack_hearts, 1, 1, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_HEARTS);
    bob->add_and_discard(jack_hearts);
     
    Card led_card = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    
    ASSERT_EQUAL(bob->play_card(led_card, trump),Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(bob->play_card(led_card, trump),Card(Card::RANK_KING, Card::SUIT_HEARTS));
    ASSERT_EQUAL(bob->play_card(led_card, trump),Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    ASSERT_EQUAL(bob->play_card(led_card, trump),Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(bob->play_card(led_card, trump),Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    delete bob;
}

TEST(maketrump_three_face_cards)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    
    Card nine_clubs(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    std::string trump;
    bool orderup = bob->make_trump(nine_clubs, 1, 1, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(make_trump_four_face_cards)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    
    Card ten_clubs(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    std::string trump;
    bool orderup = bob->make_trump(ten_clubs, 0, 1, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(make_trump_left_bower_and_face_card)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    
    Card ten_clubs(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    std::string trump;
    bool orderup = bob->make_trump(ten_clubs, 0, 1, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

// round 2 testing
TEST(make_trump_no_face_card_round_two)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));

    Card ten_hearts(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    std::string trump = Card::SUIT_CLUBS;
    bool orderup = bob->make_trump(ten_hearts, 0, 2, trump);
    ASSERT_FALSE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(make_trump_one_face_card_round_two)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    
    Card ten_spades(Card(Card(Card::RANK_TEN, Card::SUIT_SPADES)));
    std::string trump = Card::SUIT_HEARTS;
    bool orderup = bob->make_trump(ten_spades, 0, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(make_trump_two_face_card_round_two)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    
    Card ten_spades(Card(Card(Card::RANK_TEN, Card::SUIT_SPADES)));
    std::string trump = Card::SUIT_HEARTS;
    bool orderup = bob->make_trump(ten_spades, 0, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(make_trump_three_face_card_round_two)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    
    Card ten_spades(Card(Card(Card::RANK_TEN, Card::SUIT_SPADES)));
    std::string trump = Card::SUIT_HEARTS;
    bool orderup = bob->make_trump(ten_spades, 0, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(make_trump_four_face_card_round_two)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    
    Card ten_spades(Card(Card(Card::RANK_TEN, Card::SUIT_SPADES)));
    std::string trump = Card::SUIT_HEARTS;
    bool orderup = bob->make_trump(ten_spades, 0, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_CLUBS);
    delete bob;
}

TEST(make_trump_left_bower)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    
    Card ten_clubs(Card(Card(Card::RANK_TEN, Card::SUIT_CLUBS)));
    std::string trump = Card::SUIT_HEARTS;
    bool orderup = bob->make_trump(ten_clubs, 0, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    delete bob;
}

TEST(dealer)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    
    Card ten_clubs(Card(Card(Card::RANK_TEN, Card::SUIT_CLUBS)));
    std::string trump = Card::SUIT_HEARTS;
    bool orderup = bob->make_trump(ten_clubs, 1, 2, trump);
    ASSERT_TRUE(orderup);
    ASSERT_EQUAL(trump, Card::SUIT_SPADES);
    delete bob;
}

// led card testing
TEST(lead_card_all_trump)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    delete bob;
}

TEST(lead_one_trump_and_four_non_trump)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), Card(Card::RANK_KING, Card::SUIT_CLUBS));
    delete bob;
}

TEST(lead_two_trump_and_three_non_trump)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_DIAMONDS), Card(Card::RANK_KING, Card::SUIT_CLUBS));
    delete bob;
}

TEST(lead_three_trump_and_two_non_trump)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), Card(Card::RANK_KING, Card::SUIT_CLUBS));
    delete bob;
}

TEST(lead_four_trump_and_one_non_trump)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    
    ASSERT_EQUAL(bob->lead_card(Card::SUIT_SPADES), Card(Card::RANK_KING, Card::SUIT_CLUBS));
    delete bob;
}

TEST(one_lead_suit)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_CLUBS), Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    delete bob;
}

TEST(lead_and_suit_same_1)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_CLUBS), Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    delete bob;
}

TEST(lead_and_suit_same_2)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_CLUBS), Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    delete bob;
}

TEST(two_lead_suit)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_CLUBS), Card(Card::RANK_KING, Card::SUIT_HEARTS));
    delete bob;
}

TEST(three_lead_suit)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_CLUBS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_CLUBS), Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    delete bob;
    
}

TEST(four_lead_suit)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_CLUBS), Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    delete bob;
}

TEST(five_lead_suit)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_CLUBS), Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    delete bob;
}
    
TEST(no_lead_suit)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    
    Card lead = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    ASSERT_EQUAL(bob->play_card(lead, Card::SUIT_DIAMONDS), Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    delete bob;
}

TEST(add_and_discard_1)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    
    bob->add_and_discard(Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    
    Card led_card = bob->lead_card(Card::SUIT_HEARTS);
    ASSERT_EQUAL(led_card, Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    delete bob;
}

TEST(add_and_discard_2)
{
    Player *bob = Player_factory("Bob", "Simple");
    bob->add_card(Card(Card::RANK_KING, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    bob->add_card(Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    bob->add_card(Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    
    bob->add_and_discard(Card(Card::RANK_TEN, Card::SUIT_HEARTS));
    
    Card led_card = bob->lead_card(Card::SUIT_HEARTS);
    ASSERT_EQUAL(led_card, Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    delete bob;
}

TEST(test_add_and_discard1) {
  // Bob's hand
  Player * bob = Player_factory("Bob", "Simple");
  bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
  bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_ACE, Card::SUIT_CLUBS));

  // Bob adds a card to his hand and discards one card
  bob->add_and_discard(
    Card(Card::RANK_KING, Card::SUIT_SPADES) // upcard
  );

  // Bob leads
  Card card_led = bob->lead_card(Card::SUIT_SPADES);

  // Verify the card Bob selected to lead
  Card ace_clubs(Card::RANK_JACK, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, ace_clubs); //check led card

  delete bob;
}

// have to discard a trump
TEST(test_add_and_discard2) {
  // Bob's hand
  Player * bob = Player_factory("Bob", "Simple");
  bob->add_card(Card(Card::RANK_JACK, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
  bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));

  // Bob adds a card to his hand and discards one card
  bob->add_and_discard(
    Card(Card::RANK_QUEEN, Card::SUIT_SPADES) // upcard
  );

  // Bob leads
  Card card_led = bob->lead_card(Card::SUIT_SPADES);

  // Verify the card Bob selected to lead
  Card ace_clubs(Card::RANK_JACK, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, ace_clubs); //check led card

  delete bob;
}

// lead with the added card
TEST(test_add_and_discard3) {
  // Bob's hand
  Player * bob = Player_factory("Bob", "Simple");
  bob->add_card(Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
  bob->add_card(Card(Card::RANK_JACK, Card::SUIT_CLUBS));
  bob->add_card(Card(Card::RANK_ACE, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_TEN, Card::SUIT_SPADES));
  bob->add_card(Card(Card::RANK_KING, Card::SUIT_SPADES));

  // Bob adds a card to his hand and discards one card
  bob->add_and_discard(
    Card(Card::RANK_JACK, Card::SUIT_SPADES) // upcard
  );

  // Bob leads
  Card card_led = bob->lead_card(Card::SUIT_SPADES);

  // Verify the card Bob selected to lead
  Card ace_clubs(Card::RANK_JACK, Card::SUIT_SPADES);
  ASSERT_EQUAL(card_led, ace_clubs); //check led card

  delete bob;
}

TEST_MAIN()
