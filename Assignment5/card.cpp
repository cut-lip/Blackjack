/*
    Nicholas Cutlip
    CS 361
    Assignment #8
    card.cpp
    Cpp file for the definitions of the card class.
*/

#include "card.h"

// Overload insertion operator ( << ) to send visual representation of card to cout
ostream& operator << (ostream& os, const card& c) {
    c.DrawValue(c.val, os);
    c.DrawSuit(c.suit, os);
    os << endl;

    // Return the ostream reference
    return os;
}

// Draw value for insertion operator overload
// Constant method as it does not change the data of its class
void card::DrawValue(cards::cardValue val, ostream& os) const {
    // Switch on all possible values of val (cardValue enum)
    // Print the given card's value
    switch (val) {
    case cards::cardValue::Ace:
        os << 'A';
        break;
    case cards::cardValue::Two:
        os << '2';
        break;
    case cards::cardValue::Three:
        os << '3';
        break;
    case cards::cardValue::Four:
        os << '4';
        break;
    case cards::cardValue::Five:
        os << '5';
        break;
    case cards::cardValue::Six:
        os << '6';
        break;
    case cards::cardValue::Seven:
        os << '7';
        break;
    case cards::cardValue::Eight:
        os << '8';
        break;
    case cards::cardValue::Nine:
        os << '9';
        break;
    case cards::cardValue::Ten:
        os << "10";
        break;
    case cards::cardValue::Jack:
        os << 'J';
        break;
    case cards::cardValue::Queen:
        os << 'Q';
        break;
    case cards::cardValue::King:
        os << 'K';
        break;
    }
}

// Draw suit for insertion operator overload
// Constant method as it does not change the data of its class
void card::DrawSuit(cards::cardSuit suit, ostream& os) const {
    // Switch on all possible values of suit
    // Print the given card's suit
    switch (suit) {
    case cards::cardSuit::Spade:
        os << char(spade);
        break;
    case cards::cardSuit::Club:
        os << char(club);
        break;
    case cards::cardSuit::Diamond:
        os << char(diamond);
        break;
    case cards::cardSuit::Heart:
        os << char(heart);
        break;
    }
}

// Default constructor
card::card() {}

// Construct card with given value and suit
card::card(cards::cardSuit suit, cards::cardValue val)
{
    this->val = val;
    this->suit = suit;
}

// Set the value of this card object
void card::setCardValue(cards::cardValue val) {
    this->val = val;
}

// Return the card value
cards::cardValue card::getCardValue() const {
    return val;
}

// Set the suit of this card object
void card::setCardSuit(cards::cardSuit suit) {
    this->suit = suit;
}

// Return the card suit
cards::cardSuit card::getCardSuit() {
    return suit;
}

