/*
    Nicholas Cutlip
    CS 361
    Assignment #7
    deck.cpp
    Cpp file for the definitions of the deck class.
*/

#include "deck.h"

deck::deck() {
    // Provide random number generator seed based off clock
    srand(static_cast<unsigned int> (time(0)));

    // Populate vector with cards of each suit and value
    for (cards::cardValue val : cards::allVals) {
        for (cards::cardSuit suit : cards::allSuits) {
            deckVec.push_back(card::card(suit, val));
        }
    }
}

// Return a random card from the deck (removes card from deck)
card deck::dealCard() {

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

