/*
	Nicholas Cutlip
	CS 361
	Assignment #7
	deck.h
	Header file for the declarations of the hand class.
*/
#pragma once

#include "card.h"
#include <iostream>
#include <vector>

class hand {
public:
	// Construct empty hand object
	hand();

	// Add card to hand
	void addCardToHand(card newCard);

	// Display the current hand on the screen
	void drawHand();

	// Return the lowest value contained by the hand
	// (returns INT_MAX if hand is empty)
	int handValueLow();

	// Return the highest value contained by the hand
	// (returns -1 if hand is empty)
	int handValueHigh();

private:
	// Vector to hold the cards currently contained by this hand obect
	std::vector<card> currentHand;
};
