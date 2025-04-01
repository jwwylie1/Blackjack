#ifndef DECK_HPP
#define DECK_HPP

#include <vector>

enum Card {
    TWO     = 2,
    THREE   = 3,
    FOUR    = 4,
    FIVE    = 5,
    SIX     = 6,
    SEVEN   = 7,
    EIGHT   = 8,
    NINE    = 9,
    TEN     = 10,
    JACK    = 10,
    QUEEN   = 10,
    KING    = 10,
    ACE     = 11,
};

class Deck
{
public:
    Deck();
    Deck(int decks);

    // REQUIRES: index < size
    // EFFECTS: returns [index] of cards
    Card &operator[](int index) {
        if (index >= cards.size()) {
            std::cout << "Index out of range";
        }
        return cards[index];
    }

    Deck &operator=(Deck &copyThis) {
        resize(copyThis.size());
        for (int i=0; i<copyThis.size(); ++i) {
            cards[i] = copyThis[i];
        }
        return *this;
    }

    void shuffle();
    Card next();
    int size();
    void resize(int newSize);


private:
    int numDecks;
    std::vector<Card> cards;

    int place = 0;

    const std::vector<Card> STANDARD_DECK = {TWO,TWO,TWO,TWO,THREE,THREE,THREE,THREE,FOUR,FOUR,FOUR,FOUR,
    FIVE,FIVE,FIVE,FIVE,SIX,SIX,SIX,SIX,SEVEN,SEVEN,SEVEN,SEVEN,EIGHT,EIGHT,EIGHT,EIGHT,NINE,NINE,NINE,NINE,TEN,TEN,TEN,TEN,
    JACK,JACK,JACK,JACK,QUEEN,QUEEN,QUEEN,QUEEN,KING,KING,KING,KING,ACE,ACE,ACE,ACE};
};

#endif // DECK_HPP