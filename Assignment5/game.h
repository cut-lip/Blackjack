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
	game() : playerDeck(), playerHand()
	{
		cout << "Welcome to BlackJack\n\n" << "What is your name, player ?" << endl;
		cin >> playerName;		// Seeks input for player's name

		// Player should initially be dealt two cards
		cout << "\n" + playerName + " is dealt two cards.\n" << endl;
		playerHand.addCardToHand(playerDeck.dealCard());
		playerHand.addCardToHand(playerDeck.dealCard());

		// Display players initial hand
		cout << playerName << "'s hand:\n";
		playerHand.drawHand();
		cout << endl;
	}

private:
	// Deck of cards for use in the game
	deck playerDeck;

	// Name of player
	string playerName;
	// Player hand of cards
	hand playerHand;
};
