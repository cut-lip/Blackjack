/*
	Nicholas Cutlip
	CS 361
	Assignment #7
	card.cpp
	Cpp file for the definitions of the card class.
*/

#include "card.h"

// Draw value for DrawCard
void card::DrawValue(cards::cardValue val) {
    // Switch on all possible values of val (cardValue enum)
    // Print the given card's value
    switch (val) {
    case cards::cardValue::Ace:
        cout << 'A';
        break;
    case cards::cardValue::Two:
        cout << '2';
        break;
    case cards::cardValue::Three:
        cout << '3';
        break;
    case cards::cardValue::Four:
        cout << '4';
        break;
    case cards::cardValue::Five:
        cout << '5';
        break;
    case cards::cardValue::Six:
        cout << '6';
        break;
    case cards::cardValue::Seven:
        cout << '7';
        break;
    case cards::cardValue::Eight:
        cout << '8';
        break;
    case cards::cardValue::Nine:
        cout << '9';
        break;
    case cards::cardValue::Ten:
        cout << "10";
        break;
    case cards::cardValue::Jack:
        cout << 'J';
        break;
    case cards::cardValue::Queen:
        cout << 'Q';
        break;
    case cards::cardValue::King:
        cout << 'K';
        break;
    }
}

// Draw suit for DrawCard
void card::DrawSuit(cards::cardSuit suit) {
    // Switch on all possible values of suit
    // Print the given card's suit
    switch (suit) {
    case cards::cardSuit::Spade:
        cout << char(spade);
        break;
    case cards::cardSuit::Club:
        cout << char(club);
        break;
    case cards::cardSuit::Diamond:
        cout << char(diamond);
        break;
    case cards::cardSuit::Heart:
        cout << char(heart);
        break;
    }
}

// Construct card with given value and suit
card::card(cards::cardValue val, cards::cardSuit suit)
{
    this->val = val;
    this->suit = suit;
}

// Set the value of this card object
void card::setCardValue(cards::cardValue val) {
    this->val = val;
}

// Return the card value
cards::cardValue card::getCardValue() {
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

// Returns a string representation of the card object to the ostream
string card::drawCard() {
    
    std::string s = "";

    // Draw top border of card
    cout << char(topLBorder);
    for (int i = 1; i < 11; i++) {
        cout << char(horBorder);
    }
    cout << char(topRBorder) << endl;

    // Draw second line, with value followed by suit adjacent to left border
    cout << char(verBorder);
    int spaces = 0;
    DrawValue(val);
    if (val != cards::cardValue::Ten) {
        spaces = 7;
    }
    else {
        spaces = 6;
    }
    DrawSuit(suit);
    for (int i = 0; i <= spaces; i++) {
        cout << " ";
    }
    cout << char(verBorder) << endl;

    // Draw inner lines of card
    for (int i = 0; i < 7; i++) {
        cout << char(verBorder);
        for (int i = 0; i < 10; i++) {
            cout << " ";
        }
        cout << char(verBorder) << endl;
    }

    // Draw second to last line, with value and suit printed adjacent to right border
    cout << char(verBorder);
    for (int i = 0; i <= spaces; i++) {
        cout << " ";
    }
    DrawSuit(suit);
    DrawValue(this->val);
    cout << char(verBorder) << endl;

    // Draw bottom border of card
    cout << char(botLBorder);
    for (int i = 0; i < 10; i++) {
        cout << char(horBorder);
    }
    cout << char(botRBorder) << endl;

    return s;
}

// Overload extraction operator ( << ) to send visual representation of card to cout
ostream& operator<<(ostream& os, const card& c)
{
    // Must return string from drawCard?
    //os << c.drawCard();

    return os;
}
