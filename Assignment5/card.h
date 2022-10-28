/*
    Nicholas Cutlip
    CS 361
    Assignment #6
    card.h
    Header file for the declarations of the card class.
*/


#pragma once

#include <iostream>

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
        Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
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
}

// A card object as a value and a suit associated with it
class card {
private:
    cards::cardValue val;
    cards::cardSuit suit;

    // Draw value for DrawCard
    void DrawValue(cards::cardValue val) {
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
    void DrawSuit(cards::cardSuit suit) {
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

public:
    // Initialize card with given value and suit
    card(cards::cardValue val, cards::cardSuit suit)
    {
        this->val = val;
        this->suit = suit;
    }

    // Default constructor
    card() = default;

    // Set the value of this card object
    void setCardValue(cards::cardValue val)
    {
        this->val = val;
    }

    // Set the suit of this card object
    void setCardSuit(cards::cardSuit suit)
    {
        this->suit = suit;
    }

    // Prints a visual representation of the card object to the console
    void drawCard()
    {
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
    }
};