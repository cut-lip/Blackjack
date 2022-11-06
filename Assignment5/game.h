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

class game {
public:
	game()
	{

	}

private:
	// Deck of cards for use in the game
	deck gameDeck;

	// Player hand of cards
	hand player;
};
