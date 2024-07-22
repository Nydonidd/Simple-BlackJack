#include "Card.h"

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

Card::Rank Card::getRank() const { return rank; }

Card::Suit Card::getSuit() const { return suit; }

std::string rankToString(Card::Rank rank) {
	switch (rank) {
		case Card::TWO: return "Two";
		case Card::THREE: return "Three";
		case Card::FOUR: return "Four";
		case Card::FIVE: return "Five";
		case Card::SIX: return "Six";
		case Card::SEVEN: return "Seven";
		case Card::EIGHT: return "Eight";
		case Card::NINE: return "Nine";
		case Card::TEN: return "Ten";
		case Card::JACK: return "Jack";
		case Card::QUEEN: return "Queen";
		case Card::KING: return "King";
		case Card::ACE: return "Ace";
		default: return "Unknown";
	}
}

std::string suitToString(Card::Suit suit) {
	switch (suit) {
	case Card::CLUBS: return "Clubs";
	case Card::DIAMONDS: return "Diamonds";
	case Card::HEARTS: return "Hearts";
	case Card::SPADES: return "Spades";
	default: return "Unknown";
	}
}


