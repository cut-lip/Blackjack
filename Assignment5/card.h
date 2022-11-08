/*
    Nicholas Cutlip
    CS 361
    Assignment #7
    card.h
    Header file for the declarations of the card class.
*/

// Do we leave enums and constants in header file???
#pragma once

#include <iostream>
#include <string>

using namespace std;

// Constants for unicode border and card symbls
const short spade = 6;
const short club = 5;
const short heart = 3;
const short diamond = 4;
const short verBorder = 186;
const short horBorder = 205;
const short topLBorder = 201;
const short topRBorder = 187;
const short botLBorder = 200;
const short botRBorder = 188;

namespace cards {

    // cardValue represents all of the potential values for cards in the deck
    enum class cardValue {
        Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
        Jack, Queen, King
    };

    // Array of all cardValue constants for iteration
    static const cardValue allVals[] = {
        cardValue::Ace,
        cardValue::Two,
        cardValue::Three,
        cardValue::Four,
        cardValue::Five,
        cardValue::Six,
        cardValue::Seven,
        cardValue::Eight,
        cardValue::Nine,
        cardValue::Ten,
        cardValue::Jack,
        cardValue::Queen,
        cardValue::King,
    };

    // cardSuit represents all of the potential suits a card can belong to
    enum class cardSuit {
        Spade, Club, Diamond, Heart
    };

    // Array of all cardSuit constants for iteration
    static const cardSuit allSuits[] = {
        cardSuit::Spade,
        cardSuit::Club,
        cardSuit::Diamond,
        cardSuit::Heart
    };
};

// A card object as a value and a suit associated with it
class card {
private:
    cards::cardValue val;
    cards::cardSuit suit;

    // Draw value for DrawCard
    void DrawValue(cards::cardValue val, ostream& os) const;

    // Draw suit for DrawCard
    void DrawSuit(cards::cardSuit suit, ostream& os) const;

public:
    // Default constructor
    card();
    
    // Initialize card with given value and suit
    card(cards::cardValue val, cards::cardSuit suit);

    // Overload extraction operator ( << ) to send visual representation of card to cout
    friend ostream& operator << (ostream& os, const card& card);

    // Set the value of this card object
    void setCardValue(cards::cardValue val);

    // Either implement these methods, or use protected access modifiers??
    cards::cardValue getCardValue();

    // Set the suit of this card object
    void setCardSuit(cards::cardSuit suit);

    // Either implement these methods, or use protected access modifiers??
    cards::cardSuit getCardSuit();
};