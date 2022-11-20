/*
    Nicholas Cutlip
    CS 361
    Assignment #8
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

    // Overload less than operator ( < )
    friend bool operator < (const hand& hand1, const hand& hand2);

    // Overload greater than operator ( > )
    friend bool operator > (const hand& hand1, const hand& hand2);

    // Overload equality operator ( == )
    friend bool operator == (const hand& hand1, const hand& hand2);

    // Evaluate current best hand value based off of handValueHigh() and handValueLow()
    int handValue(hand currHand);

    // Add card to hand
    void addCardToHand(card newCard);

    // Display the current hand on the screen
    void drawHand();

    // Return the minimum value of the hand
    // (Ace is valued as 1)
    int handValueLow() const;
    
    // Return the maximum value of the hand
    // (Ace is valued as 11)
    int handValueHigh() const;

private:
    // Vector to hold the cards currently contained by this hand obect
    std::vector<card> currentHand;
};
