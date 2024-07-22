#pragma once
#include <vector>
#include "Card.h"
#include <random>
#include <algorithm>

class Deck {
public:
	Deck();
	void shuffle();
	void printDeck() const;
	Card drawCard();
	bool isEmpty() const;

private:
	std::vector<Card> cards;
};

