/*
	Nicholas Cutlip
	CS 361
	Assignment #7
	deck.h
	Header file for the declarations of the deck class.
*/

#pragma once

#include "card.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class deck {
public:
	// Construct 
	deck();

	// Return a random card from the deck (removes card from deck)
	card dealCard();

	// Returns the current size of the deck.
	int deckSize();

private:
	// Vector of card objects to hold the cards in the deck
	std::vector<card> deckVec;
};
