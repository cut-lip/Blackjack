/*
	Nicholas Cutlip
	CS 361
	Assignment #7
	deck.h
	Cpp file for the declarations of the hand class.
*/

#include "hand.h"

// Construct empty hand
hand::hand() : currentHand() {}

// Add card to hand
void hand::addCardToHand(card newCard) {
	currentHand.push_back(newCard);
}

// Display the current hand on the screen
void hand::drawHand() {

	// For each card in the hand, draw the card on the screen
	for (card c : currentHand) {
		cout << c;
	}
}

// Return the minimum value of the hand
// (Ace is valued as 1)
int hand::handValueLow() {
	int low = 0;

	// Sum the values of the hand's cards
	for (card c : currentHand) {
		
		// If value is face card, increment sum by 10
		if ((int)c.getCardValue() == 10 || (int)c.getCardValue() == 11 || (int)c.getCardValue() == 12) {
			low += 10;

			// Increment sum by card value
		} else {
			low += (int)c.getCardValue();
		}
	}

	return low;
}

// Return the maximum total value of the hand
// (Ace is valued as 11)
int hand::handValueHigh() {
	int high = 0;

	// Sum the values of the hand's cards
	for (card c : currentHand) {

		// If value is Ace, increment sum by 11
		if ((int)c.getCardValue() == 1) {
			high += 11;

		// If value is face card, increment sum by 10
		} else if ((int)c.getCardValue() == 10 || (int)c.getCardValue() == 11 || (int)c.getCardValue() == 12) {
			high += 10;

		// Otherwise increment sum by card value
		} else {
			high += (int)c.getCardValue();
		}
	}

	return high;
}