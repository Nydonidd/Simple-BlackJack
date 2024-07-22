#include "Hand.h"
#include <iostream>

Hand::Hand(){}

void Hand::addCard(const Card& card) { cards.push_back(card); }

int Hand::getTotalValue() const { return calculateHandValue(); }

void Hand::clear() { cards.clear(); }

void Hand::printHand(bool dealer) const
{	
	if (dealer) {
		if (!cards.empty()) {
			const Card& card = cards.front();
			std::cout << rankToString(card.getRank()) << " of " << suitToString(card.getSuit()) << ", ";
		}
		std::cout << "[Hidden Card]\n" << std::endl;
	}
	else {
		for (size_t j = 0; j < cards.size(); j++) {
			const Card& card = cards[j];
			std::cout << rankToString(card.getRank()) << " of " << suitToString(card.getSuit());
			if (j < cards.size() - 1){
				std::cout << ", ";
			}
		}
		std::cout << "\n";
	}
}

int Hand::calculateHandValue() const
{
	int totalValue = 0;
	int aceCount = 0;

	for (const auto& card : cards) {
		Card::Rank rank = card.getRank();
		if (rank >= Card::TWO && rank <= Card::TEN) {
			totalValue += static_cast<int>(rank);
		}
		else if (rank >= Card::JACK && rank <= Card::KING) {
			totalValue += 10;
		}
		else if (rank == Card::ACE) {
			aceCount++;
			totalValue += 11;
		}
	}

	while (totalValue > 21 && aceCount > 0) {
		totalValue -= 10;
		aceCount--;
	}

	return totalValue;
}


