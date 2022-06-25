// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Pack.h"
#include "unit_test_framework.h"

#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

TEST(test_pack_default_ctor) {
    Pack pack;
    Card first = pack.deal_one();
    ASSERT_EQUAL(Card::RANK_NINE, first.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, first.get_suit());
}

TEST(pack_defaultor)
{
    Pack pack;
    Card first = pack.deal_one();
    Card second = pack.deal_one();
    Card three = pack.deal_one();
    Card four = pack.deal_one();
    Card five = pack.deal_one();
    Card six = pack.deal_one();
    Card seven = pack.deal_one();
    Card eight = pack.deal_one();
    Card nine = pack.deal_one();
    Card ten = pack.deal_one();
    Card eleven = pack.deal_one();
    Card tweleve = pack.deal_one();
    Card thirteen = pack.deal_one();
    Card fourteen = pack.deal_one();
    Card fiveteen = pack.deal_one();
    Card sixteen = pack.deal_one();
    Card seventeen = pack.deal_one();
    Card eighteen = pack.deal_one();
    Card nineteen = pack.deal_one();
    Card twenty = pack.deal_one();
    Card twentyone = pack.deal_one();
    Card twentytwo = pack.deal_one();
    Card twentythree = pack.deal_one();
    Card twentyfour = pack.deal_one();
    ASSERT_TRUE(pack.empty());
    ASSERT_EQUAL(Card::RANK_NINE, first.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, first.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, second.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, second.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, three.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, three.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, four.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, four.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, five.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, five.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, six.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, six.get_suit());
    ASSERT_EQUAL(Card::RANK_NINE, seven.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, seven.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, eight.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, eight.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, nine.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, nine.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, ten.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, ten.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, eleven.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, eleven.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, tweleve.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, tweleve.get_suit());
    ASSERT_EQUAL(Card::RANK_NINE, thirteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, thirteen.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, fourteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, fourteen.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, fiveteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, fiveteen.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, sixteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, sixteen.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, seventeen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, seventeen.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, eighteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, eighteen.get_suit());
    ASSERT_EQUAL(Card::RANK_NINE, nineteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, nineteen.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, twenty.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twenty.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, twentyone.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentyone.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, twentytwo.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentytwo.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, twentythree.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentythree.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, twentyfour.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentyfour.get_suit());
    ASSERT_TRUE(pack.empty());
    pack.reset();
    ASSERT_FALSE(pack.empty());
    Card first_copy = pack.deal_one();
    Card second_copy = pack.deal_one();
    ASSERT_EQUAL(Card::RANK_NINE, first_copy.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, first_copy.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, second_copy.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, second_copy.get_suit());
}

TEST(istream_init)
{
    const string filename = "pack.in";
    ifstream ifs(filename);
    assert(ifs.is_open());
    Pack pack(ifs);
    Card first = pack.deal_one();
    Card second = pack.deal_one();
    Card three = pack.deal_one();
    Card four = pack.deal_one();
    Card five = pack.deal_one();
    Card six = pack.deal_one();
    Card seven = pack.deal_one();
    Card eight = pack.deal_one();
    Card nine = pack.deal_one();
    Card ten = pack.deal_one();
    Card eleven = pack.deal_one();
    Card tweleve = pack.deal_one();
    Card thirteen = pack.deal_one();
    Card fourteen = pack.deal_one();
    Card fiveteen = pack.deal_one();
    Card sixteen = pack.deal_one();
    Card seventeen = pack.deal_one();
    Card eighteen = pack.deal_one();
    Card nineteen = pack.deal_one();
    Card twenty = pack.deal_one();
    Card twentyone = pack.deal_one();
    Card twentytwo = pack.deal_one();
    Card twentythree = pack.deal_one();
    Card twentyfour = pack.deal_one();
    ASSERT_TRUE(pack.empty());
    ASSERT_EQUAL(Card::RANK_NINE, first.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, first.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, second.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, second.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, three.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, three.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, four.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, four.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, five.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, five.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, six.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, six.get_suit());
    ASSERT_EQUAL(Card::RANK_NINE, seven.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, seven.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, eight.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, eight.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, nine.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, nine.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, ten.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, ten.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, eleven.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, eleven.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, tweleve.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, tweleve.get_suit());
    ASSERT_EQUAL(Card::RANK_NINE, thirteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, thirteen.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, fourteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, fourteen.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, fiveteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, fiveteen.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, sixteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, sixteen.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, seventeen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, seventeen.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, eighteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, eighteen.get_suit());
    ASSERT_EQUAL(Card::RANK_NINE, nineteen.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, nineteen.get_suit());
    ASSERT_EQUAL(Card::RANK_TEN, twenty.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twenty.get_suit());
    ASSERT_EQUAL(Card::RANK_JACK, twentyone.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentyone.get_suit());
    ASSERT_EQUAL(Card::RANK_QUEEN, twentytwo.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentytwo.get_suit());
    ASSERT_EQUAL(Card::RANK_KING, twentythree.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentythree.get_suit());
    ASSERT_EQUAL(Card::RANK_ACE, twentyfour.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, twentyfour.get_suit());

}

TEST(shuffle)
{
    Pack pack;
    pack.shuffle();
    Card first = pack.deal_one();
    Card second = pack.deal_one();
    Card three = pack.deal_one();
    Card four = pack.deal_one();
    Card five = pack.deal_one();
    Card six = pack.deal_one();
    Card seven = pack.deal_one();
    Card eight = pack.deal_one();
    Card nine = pack.deal_one();
    Card ten = pack.deal_one();
    Card eleven = pack.deal_one();
    Card tweleve = pack.deal_one();
    Card thirteen = pack.deal_one();
    Card fourteen = pack.deal_one();
    Card fiveteen = pack.deal_one();
    Card sixteen = pack.deal_one();
    Card seventeen = pack.deal_one();
    Card eighteen = pack.deal_one();
    Card nineteen = pack.deal_one();
    Card twenty = pack.deal_one();
    Card twentyone = pack.deal_one();
    Card twentytwo = pack.deal_one();
    Card twentythree = pack.deal_one();
    Card twentyfour = pack.deal_one();
    ASSERT_EQUAL(first, Card(Card::RANK_KING, Card::SUIT_CLUBS));
    ASSERT_EQUAL(second, Card(Card::RANK_JACK, Card::SUIT_HEARTS));
    ASSERT_EQUAL(three, Card(Card::RANK_NINE, Card::SUIT_SPADES));
    ASSERT_EQUAL(four, Card(Card::RANK_ACE, Card::SUIT_CLUBS));
    ASSERT_EQUAL(five, Card(Card::RANK_QUEEN, Card::SUIT_HEARTS));
    ASSERT_EQUAL(six, Card(Card::RANK_TEN, Card::SUIT_SPADES));
    ASSERT_EQUAL(seven, Card(Card::RANK_NINE, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(eight, Card(Card::RANK_KING, Card::SUIT_HEARTS));
    ASSERT_EQUAL(nine, Card(Card::RANK_JACK, Card::SUIT_SPADES));
    ASSERT_EQUAL(ten, Card(Card::RANK_TEN, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(eleven, Card(Card::RANK_ACE, Card::SUIT_HEARTS));
    ASSERT_EQUAL(tweleve, Card(Card::RANK_QUEEN, Card::SUIT_SPADES));
    ASSERT_EQUAL(thirteen, Card(Card::RANK_JACK, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(fourteen, Card(Card::RANK_NINE, Card::SUIT_CLUBS));
    ASSERT_EQUAL(fiveteen, Card(Card::RANK_KING, Card::SUIT_SPADES));
    ASSERT_EQUAL(sixteen, Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(seventeen, Card(Card::RANK_TEN, Card::SUIT_CLUBS));
    ASSERT_EQUAL(eighteen, Card(Card::RANK_ACE, Card::SUIT_SPADES));
    ASSERT_EQUAL(nineteen, Card(Card::RANK_KING, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(twenty, Card(Card::RANK_JACK, Card::SUIT_CLUBS));
    ASSERT_EQUAL(twentyone, Card(Card::RANK_NINE, Card::SUIT_HEARTS));
    ASSERT_EQUAL(twentytwo, Card(Card::RANK_ACE, Card::SUIT_DIAMONDS));
    ASSERT_EQUAL(twentythree, Card(Card::RANK_QUEEN, Card::SUIT_CLUBS));
    ASSERT_EQUAL(twentyfour, Card(Card::RANK_TEN, Card::SUIT_HEARTS));
}
// Add more tests here

TEST_MAIN()
