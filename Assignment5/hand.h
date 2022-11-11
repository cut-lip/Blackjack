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

    // Return the minimum value of the hand
    // (Ace is valued as 1)
    int handValueLow();

    // Return the maximum value of the hand
    // (Ace is valued as 11)
    int handValueHigh();

private:
    // Vector to hold the cards currently contained by this hand obect
    std::vector<card> currentHand;

    // This causes a bunch of bugs...
    //std::unique_ptr<vector<card>> currentHand;
};
