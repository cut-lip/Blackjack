/*
	Nicholas Cutlip
	CS 361
	Assignment #7
	main.cpp
	Main driver method for blackjack package.
*/

#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "game.h"

using namespace std;
//TODO:
// switch params in card constructor
// implement tie case
// remove extra win messages from mainGameLoop


int main()
{
	card myCard = card(cards::cardValue::Ace, cards::cardSuit::Club);
	cout << myCard << endl;

	// Create an instance of the Blackjack game
	game myGame = game();

	// Do i need to delete the object?
}


