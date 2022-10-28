/*
	Nicholas Cutlip
	CS 361
	Assignment #6
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
	// deck constructor
	deck() {
		// Initialize empty vector with 54 elements

		// Populate vector with cards of each suit and value
		for (cards::cardValue val : cards::allVals) {
			for (cards::cardSuit suit : cards::allSuits) {
				deckVec.push_back(card::card(val, suit));
			}
		}
	}
	
	// Return a random card from the deck (removes card from deck)
	card dealCard() {
		// Provide random number generator seed based off clock
		srand(static_cast<unsigned int> (time(0)));

		// Randomly select an index from the deck, and retrieve the card from that index
		int index = (rand() % deckVec.size());
		card selection = deckVec.at((size_t)index);

		// Remove selected card from the deck, and return selected card
		deckVec.erase(deckVec.begin() + index);
		return selection;
	}

	// Returns the current size of the deck.
	int deckSize() {
		return (int)deckVec.size();
	}

private:
	// Vector of card objects to hold the cards in the deck
	std::vector<card> deckVec;
};
