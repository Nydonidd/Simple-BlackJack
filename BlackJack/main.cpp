#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

void playerTurn(Hand& playerHand, Deck& deck) {
	char choice;

	do {
		std::cout << "\nPlayers Hand: "; 
		playerHand.printHand(false);
		std::cout << "Hand Value: " << playerHand.getTotalValue() << "\n" << std::endl;

		std::cout << "Hit or Stand? [h]/[s]\n" << std::endl;

		std::cin >> choice;

		if (choice == 'h') {
			playerHand.addCard(deck.drawCard());
		}
	} while (choice != 's' && playerHand.getTotalValue() <= 21);
}

void dealerTurn(Hand& dealerHand, Deck& deck) {
	while (dealerHand.getTotalValue() < 17){
		dealerHand.addCard(deck.drawCard());
	}
}


int main() {
	Deck deck;
	deck.shuffle();

	Hand playerHand;
	Hand dealerHand;

	std::cout << "--------BLACKJACK--------\n" << std::endl;

	playerHand.addCard(deck.drawCard());
	playerHand.addCard(deck.drawCard());

	dealerHand.addCard(deck.drawCard());
	dealerHand.addCard(deck.drawCard());

	std::cout << "Dealers Hand: ";
	dealerHand.printHand(true);

	playerTurn(playerHand, deck);

	std::cout << "\nDealers Hand: ";
	dealerHand.printHand(false);
	std::cout << "Dealers total value: " << dealerHand.getTotalValue() << "\n" << std::endl;

	std::cout << "Players Hand: ";
	dealerHand.printHand(false);
	std::cout << "Players total value: " << playerHand.getTotalValue() << "\n" << std::endl;
	

	if (playerHand.getTotalValue() > 21) {
		std::cout << "HAHAHAHAHAA YOU WENT BUST!! BETTER LUCK NEXT TIME";
	}
	else {
		dealerTurn(dealerHand, deck);

		std::cout << "Dealer's Hand: ";
		dealerHand.printHand(false);
		std::cout << "Dealer's total value: " << dealerHand.getTotalValue() << std::endl;

		if (dealerHand.getTotalValue() > 21) {
			std::cout << "\nNOOOO DEALER WENT BUST!!! " << std::endl;
		}
		else if(playerHand.getTotalValue() < dealerHand.getTotalValue()){
			std::cout << "\nHAHAHAHA DEALER WINS!! " << std::endl;
		}
		else if (playerHand.getTotalValue() > dealerHand.getTotalValue()) {
			std::cout << "\nNOOO DEALER GOT BEAT BY PLAYER :(" << std::endl;
		}
		else if (playerHand.getTotalValue() == dealerHand.getTotalValue()) {
			std::cout << "\nwow, dealer drawed player :O" << std::endl;
		}

	}

	char again;

	std::cout << "\nWould you like to play again? [y]/[n]";
	std::cin >> again;

	if (again == 'y') {
		system("CLS");
		main();
	}
	else {
		std::cout << "Thank you for playing!\nExiting..." << std::endl;
		exit(0);
	}

	return 0;
}
