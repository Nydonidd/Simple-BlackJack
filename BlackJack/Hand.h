#pragma once

#include "Card.h"
#include <vector>

class Hand {
public:
	Hand();

	void addCard(const Card& card);
	int getTotalValue() const;
	void clear();
	void printHand(bool dealer) const;

private:
	std::vector<Card> cards;
	int calculateHandValue() const;
};