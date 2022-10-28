/*
	Nicholas Cutlip
	CS 361
	Assignment #6
	deck.cpp
	Cpp file for the definitions of the deck class.
*/

#include "deck.h"

// !!!!!!!!!!!!!!!!!!!!
// Why do I have to use name qualifier here but not in card.cpp????????????????????
// I THINK BECAUSE its only for public methods and these are all public


deck::deck() {
	// Initialize empty vector with 54 elements
		// Populate vector with cards of each suit and value
	for (cards::cardValue val : cards::allVals) {
		for (cards::cardSuit suit : cards::allSuits) {
			deckVec.push_back(card::card(val, suit));
		}
	}
}

// Return a random card from the deck (removes card from deck)
card deck::dealCard() {
	// Provide random number generator seed based off clock
	srand(static_cast<unsigned int> (time(0)));

		// Randomly select an index from the deck, and retrieve the card from that index
	int index = (rand() % deckVec.size());
	card selection = deckVec.at((size_t)index);

		// Remove selected card from the deck, and return selected card
	deck::deckVec.erase(deckVec.begin() + index);
	return selection;
}

// Returns the current size of the deck.
int deck::deckSize() {
	return (int)deckVec.size();
}

