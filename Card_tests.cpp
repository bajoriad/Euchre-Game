// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;

TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
    
    Card a;
    ASSERT_EQUAL(Card::RANK_TWO, a.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, a.get_suit());
}

TEST(Card_less_trump)
{
    Card d9 = Card(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card d10 = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card dJ = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card dQ = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card dK = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card dA = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card h9 = Card(Card::RANK_NINE, Card::SUIT_HEARTS);
    Card h10 = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card hJ = Card(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card hQ = Card(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card hK = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    Card hA = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c9 = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card c10 = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card cJ = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card cQ = Card(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card cK = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    Card cA = Card(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card s9 = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    Card s10 = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card sJ = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card sQ = Card(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card sK = Card(Card::RANK_KING, Card::SUIT_SPADES);
    Card sA = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    // trump suit and nothing
    ASSERT_FALSE(Card_less(d9, c10, Card::SUIT_DIAMONDS));
    // nothing and trump suit
    ASSERT_TRUE(Card_less(d9, c10, Card::SUIT_CLUBS));
    // nothing and nothing
    ASSERT_TRUE(Card_less(d9, c10, Card::SUIT_SPADES));
    // trump suit and right bower
    ASSERT_TRUE(Card_less(cK, cJ, Card::SUIT_CLUBS));
    // trump suit and trump suit (no left or right bower)
    ASSERT_FALSE(Card_less(cK, cQ, Card::SUIT_CLUBS));
    // left bower and right bower
    ASSERT_TRUE(Card_less(sJ, cJ, Card::SUIT_CLUBS));
    // trump suit and left bower
    ASSERT_TRUE(Card_less(cK, sJ, Card::SUIT_CLUBS));
    // left bower and trump suit
    ASSERT_FALSE(Card_less(cJ, cQ, Card::SUIT_CLUBS));
    // right bower and trump suit
    ASSERT_FALSE(Card_less(hJ, hK, Card::SUIT_HEARTS));
    // right bower and left bower
    ASSERT_FALSE(Card_less(hJ, dJ, Card::SUIT_HEARTS));
}

TEST(Card_less_trump_lead)
{
    Card d9 = Card(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card d10 = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card dJ = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card dQ = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card dK = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card dA = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card h9 = Card(Card::RANK_NINE, Card::SUIT_HEARTS);
    Card h10 = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card hJ = Card(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card hQ = Card(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card hK = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    Card hA = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c9 = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card c10 = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card cJ = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card cQ = Card(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card cK = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    Card cA = Card(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card s9 = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    Card s10 = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card sJ = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card sQ = Card(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card sK = Card(Card::RANK_KING, Card::SUIT_SPADES);
    Card sA = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    // trump suit and led suit are same
    // both normal trump suit cards
    ASSERT_FALSE(Card_less(dJ, hJ, hJ, Card::SUIT_DIAMONDS));
    ASSERT_TRUE(Card_less(dK, hJ, hJ, Card::SUIT_DIAMONDS));
    ASSERT_FALSE(Card_less(cK, cQ, cQ, Card::SUIT_CLUBS));
    // trump suit and left bower
    ASSERT_TRUE(Card_less(cK, cJ, cQ, Card::SUIT_CLUBS));
    // left bower and right bower
    ASSERT_FALSE(Card_less(cJ, sJ, cJ, Card::SUIT_CLUBS));
    // right bower and trump suit
    ASSERT_FALSE(Card_less(dJ, hK, hJ, Card::SUIT_HEARTS));
    // Cases where trump suit and lead suit are different
    // trump suit and trump suit (no left or right bower)
    ASSERT_FALSE(Card_less(hK, hQ, dQ, Card::SUIT_HEARTS));
    // left bower and trump suit(right bower)
    ASSERT_TRUE(Card_less(cJ, sJ, dQ, Card::SUIT_SPADES));
    ASSERT_TRUE(Card_less(cJ, sJ, sQ, Card::SUIT_SPADES));
    ASSERT_TRUE(Card_less(cJ, sJ, cQ, Card::SUIT_SPADES));
    // left bower and below right bower
    ASSERT_FALSE(Card_less(cJ, sK, dQ, Card::SUIT_SPADES));
    ASSERT_FALSE(Card_less(cJ, sK, cJ, Card::SUIT_SPADES));
    // led card and led card
    ASSERT_FALSE(Card_less(dK, dQ, dQ, Card::SUIT_HEARTS));
    // led card and left bower consideration
    ASSERT_FALSE(Card_less(dJ, dQ, dQ, Card::SUIT_HEARTS))
    // trump and led
    ASSERT_FALSE(Card_less(dJ, hQ, hK, Card::SUIT_DIAMONDS));
    // trump and led (left bowler)
    ASSERT_FALSE(Card_less(sJ, cJ, sJ, Card::SUIT_SPADES));
    // trump and nothing
    ASSERT_FALSE(Card_less(hJ, sJ, dJ, Card::SUIT_HEARTS));
    // led card and nothing
    ASSERT_FALSE(Card_less(hJ, cJ, hK, Card::SUIT_DIAMONDS));
}

TEST(card_operators)
{
    Card d9 = Card(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    Card d10 = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    Card dJ = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card dQ = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    Card dK = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    Card dA = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card h9 = Card(Card::RANK_NINE, Card::SUIT_HEARTS);
    Card h10 = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card hJ = Card(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card hQ = Card(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card hK = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    Card hA = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card c9 = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    Card c10 = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    Card cJ = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    Card cQ = Card(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card cK = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    Card cA = Card(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card s9 = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    Card s10 = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    Card sJ = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card sQ = Card(Card::RANK_QUEEN, Card::SUIT_SPADES);
    Card sK = Card(Card::RANK_KING, Card::SUIT_SPADES);
    Card sA = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    ASSERT_TRUE(sA == sA);
    ASSERT_TRUE(sK < sA);
    ASSERT_FALSE(hA < s9);
    ASSERT_TRUE(sK <= sA);
    ASSERT_TRUE(sK <= sK);
    ASSERT_TRUE(h9 <= c9);
    ASSERT_TRUE(sA >= sK);
    ASSERT_TRUE(sA >= sA);
    ASSERT_TRUE(h9 < sK);
    ASSERT_TRUE(h10 < hQ);
    ASSERT_TRUE(h10 != hQ);
    ASSERT_TRUE(dA > sQ);
    ASSERT_TRUE(d10 > c10);
}

TEST(get_and_constructor)
{
    Card three_spades = Card();
    ASSERT_EQUAL(three_spades.get_rank(), Card::RANK_TWO);
    ASSERT_EQUAL(three_spades.get_suit(), Card::SUIT_SPADES);
    
    Card jack_diamonds = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(jack_diamonds.get_rank(), Card::RANK_JACK);
    ASSERT_EQUAL(jack_diamonds.get_suit(), Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(jack_diamonds.get_suit(Card::SUIT_HEARTS), Card::SUIT_HEARTS);
}

TEST(suite_next)
{
    ASSERT_EQUAL(Suit_next(Card::SUIT_CLUBS), Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(Card::SUIT_SPADES), Card::SUIT_CLUBS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_DIAMONDS), Card::SUIT_HEARTS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_HEARTS), Card::SUIT_DIAMONDS);
}

TEST(is_face)
{
    Card suite = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_TRUE(suite.is_face());
    Card suite_copy = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    ASSERT_FALSE(suite_copy.is_face());
}

TEST(right_bower)
{
    Card suite = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card suite_copy = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    ASSERT_TRUE(suite.is_right_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(suite.is_right_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(suite_copy.is_right_bower(Card::SUIT_SPADES));
}

TEST(left_bower)
{
    Card suite = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card suite_copy = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    ASSERT_TRUE(suite.is_left_bower(Card::SUIT_CLUBS));
    ASSERT_FALSE(suite.is_left_bower(Card::SUIT_SPADES));
    ASSERT_FALSE(suite_copy.is_left_bower(Card::SUIT_SPADES));
}

TEST(trump)
{
    Card suite = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    Card suite_copy = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    ASSERT_TRUE(suite.is_trump(Card::SUIT_SPADES));
    ASSERT_TRUE(suite.is_trump(Card::SUIT_CLUBS));
    ASSERT_FALSE(suite_copy.is_trump(Card::SUIT_HEARTS));
    ASSERT_TRUE(suite_copy.is_trump(Card::SUIT_SPADES));
}

TEST(test_get_suit) {
    const std::string trump ="Diamonds";
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(c.is_left_bower(trump));
    ASSERT_FALSE(d.is_left_bower(trump));
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, c.get_suit(trump));
    ASSERT_TRUE(c.is_face());
    ASSERT_FALSE(c.is_right_bower(trump));
    ASSERT_FALSE(d.is_right_bower(trump));
    ASSERT_TRUE(c.is_trump(trump));
    
}

TEST(test_operators) {
    Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card d(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(c<d);
    Card a(Card::RANK_KING, Card::SUIT_SPADES);
    Card b(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(a>b);
    ASSERT_TRUE(a!=b);
    Card e(Card::RANK_KING, Card::SUIT_SPADES);
    Card f(Card::RANK_KING, Card::SUIT_SPADES);
    ASSERT_TRUE(e==f);
    
    
}


TEST(test_cardless_no_led){
    //c is left bower, d non trump
    const Card c(Card::RANK_JACK, Card::SUIT_HEARTS);
    const Card d(Card::RANK_KING, Card::SUIT_CLUBS);
    const std::string trump ="Diamonds";
    ASSERT_FALSE(Card_less(c, d, trump));
    // next suit lower rank smaller than non trump higher rank
    const Card a(Card::RANK_KING, Card::SUIT_HEARTS);
    const Card b(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_TRUE(Card_less(a, b, trump));
    // left bower higher than trump ace
    const Card e(Card::RANK_JACK, Card::SUIT_HEARTS);
    const Card f(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(Card_less(e, f, trump));
    
}

TEST(test_cardless_no_led1){
    // trump(spades) 9 higher than dimonds ace
    const Card c(Card::RANK_NINE, Card::SUIT_SPADES);
    const Card d(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    const std::string trump ="Spades";
    ASSERT_FALSE(Card_less(c, d, trump));
    // left bower less than right bower
    const Card a(Card::RANK_JACK, Card::SUIT_SPADES);
    const Card b(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_FALSE(Card_less(a, b, trump));
    // left bower bigger than trump ace
    const Card e(Card::RANK_ACE, Card::SUIT_SPADES);
    const Card f(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(f.is_left_bower(trump));
    ASSERT_TRUE(Card_less(e, f, trump));
    // left bower lower than right bower
    ASSERT_TRUE(Card_less(f, a, trump));
    // left bower bigger than other ace
    const Card g(Card::RANK_ACE, Card::SUIT_HEARTS);
    const Card h(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(Card_less(f, g, trump));
    ASSERT_FALSE(Card_less(f, h, trump));
    // trump 9 higher than any ace
    ASSERT_FALSE(Card_less(c, g, trump));
    ASSERT_FALSE(Card_less(c, h, trump));
    // dimond king lower than heart ace
    const Card i(Card::RANK_KING, Card::SUIT_DIAMONDS);
    const Card j(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_TRUE(Card_less(i, j, trump));
}

TEST(test_cardless_led_same_as_trump){
    // trump(spades) 9 higher than dimonds ace
    const Card c(Card::RANK_NINE, Card::SUIT_SPADES);
    const Card d(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    const std::string trump ="Spades";
    const Card L(Card::RANK_NINE, Card::SUIT_SPADES);
    ASSERT_FALSE(Card_less(c, d,L, trump));
    // left bower less than right bower
    const Card a(Card::RANK_JACK, Card::SUIT_SPADES);
    const Card b(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_FALSE(Card_less(a, b, L,trump));
    // left bower bigger than trump ace
    const Card e(Card::RANK_ACE, Card::SUIT_SPADES);
    const Card f(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_TRUE(f.is_left_bower(trump));
    ASSERT_TRUE(f.is_trump(trump));
    ASSERT_TRUE(e.is_trump(trump));
    ASSERT_TRUE(Card_less(e, f,L, trump));
    // left bower lower than right bower
    ASSERT_TRUE(Card_less(f, a, L,trump));
    // left bower bigger than other ace
    const Card g(Card::RANK_ACE, Card::SUIT_HEARTS);
    const Card h(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(Card_less(f, g,L, trump));
    ASSERT_FALSE(Card_less(f, h,L, trump));
    // trump 9 higher than any ace
    ASSERT_FALSE(Card_less(c, g,L, trump));
    ASSERT_FALSE(Card_less(c, h, L,trump));
    // dimond king lower than heart ace
    const Card i(Card::RANK_KING, Card::SUIT_DIAMONDS);
    const Card j(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_TRUE(Card_less(i, j, L,trump));
}

TEST(test_cardless_led_diff_than_trump){
    const std::string trump ="Spades";
    const Card L(Card::RANK_KING, Card::SUIT_HEARTS);
    // trump 9 higher than led ace
    const Card c(Card::RANK_NINE, Card::SUIT_SPADES);
    const Card d(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_FALSE(Card_less(c, d,L, trump));
    // led 9 higher than dimond ace
    const Card a(Card::RANK_NINE, Card::SUIT_HEARTS);
    const Card b(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(Card_less(a, b, L,trump));
}

TEST(test_cardless_led_diff_than_trump1){
    const std::string trump ="Spades";
    const Card L(Card::RANK_KING, Card::SUIT_CLUBS);
    // left bower higher than led ace
    const Card c(Card::RANK_JACK, Card::SUIT_CLUBS);
    const Card d(Card::RANK_ACE, Card::SUIT_CLUBS);
    ASSERT_FALSE(Card_less(c, d,L, trump));
    // led 9 higher than dimond ace
    const Card a(Card::RANK_NINE, Card::SUIT_CLUBS);
    const Card b(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    ASSERT_FALSE(Card_less(a, b, L,trump));
    // left bower higher than dimond ace
    ASSERT_FALSE(Card_less(c, b, L,trump));
}

TEST_MAIN()
