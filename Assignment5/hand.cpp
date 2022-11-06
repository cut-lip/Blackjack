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
		c.drawCard();
	}
}

// Return the lowest value contained by the hand
// (returns INT_MAX if hand is empty)
int hand::handValueLow() {
	int low = INT_MAX;

	for (card c : currentHand) {

		// Search for the lowest value
		if ((int)c.getCardValue() < low) {
			low = (int)c.getCardValue();
		}
	}

	return low;
}

// Return the highest value contained by the hand
// (returns -1 if hand is empty)
int hand::handValueHigh() {
	int high = -1;

	for (card c : currentHand)
	{
		// If hand contains an Ace, return 11
		if ((int)c.getCardValue() == 1) {
			return 11;
		}

		// Search for the highest value
		if ((int)c.getCardValue() > high) {
			high = (int)c.getCardValue();
		}
	}

	return high;
}