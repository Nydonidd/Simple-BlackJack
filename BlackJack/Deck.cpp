#include "Deck.h"
#include <iostream>
#include <stdexcept>

Deck::Deck(){
	for (int suit = Card::HEARTS; suit <= Card::SPADES; ++suit) {
		for (int rank = Card::TWO; rank <= Card::ACE; ++rank) {
			cards.emplace_back(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
		}
	}
}

void Deck::shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
}

void Deck::printDeck() const {
    for (const auto& card : cards) {
        std::cout << rankToString(card.getRank()) << " of " << suitToString(card.getSuit()) << std::endl;
    }
}

Card Deck::drawCard()
{
	if (isEmpty()) {
		throw std::out_of_range("No cards left in the deck.\n");
	}
	Card card = cards.back();
	cards.pop_back();
	return card;
}

bool Deck::isEmpty() const
{
	return cards.empty();
}
