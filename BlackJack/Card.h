#pragma once
#include <string>

class Card {

public:
	enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
	enum Rank { TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

	Card(Rank r, Suit s);

	Rank getRank() const;
	Suit getSuit() const;

private:
	Rank rank;
	Suit suit;
};

std::string rankToString(Card::Rank rank);
std::string suitToString(Card::Suit suit);



