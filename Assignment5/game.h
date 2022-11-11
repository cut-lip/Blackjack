/*
    Nicholas Cutlip
    CS 361
    Assignment #7
    game.h
    Header file for the declarations of the deck class.
*/

#pragma once

#include "card.h"
#include "deck.h"
#include "hand.h"
#include <iostream>
#include <string>

class game {
public:

    // Constructor to set initial game state (with full deck and empty player hand)
    game();

    // Is this necessary?
    void stand()
    {

    }

private:

    // Main game loop (started by the class constructor)
    void mainLoop();

    // Display given hand with identifying message
    void displayHand(hand currHand, string who);

    // Determine if current hand is a bust
    bool isBust(hand currHand);

    // Present the winner
    void presentWinner(string winner);

    // A single player or dealer's turn
    // (for future use, not implemented yet in this simple version)
    // void turn();

    // Deal another card to the given hand
    void hit(hand& currHand);

    // --MEMBER VARIABLES--
    // Name of player
    string playerName = "";
    // Deck of cards for use in the game
    deck gameDeck;
    // Hands of cards for use in the game
    hand playerHand;
    hand dealerHand;
};
