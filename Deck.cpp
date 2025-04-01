#include "Deck.hpp"
#include <algorithm>
#include <random>


Deck::Deck() {
    cards.reserve(0);
}

Deck::Deck(int decks) : numDecks(decks)
{                              
    for (int i=0; i<numDecks; ++i) {
        cards.reserve(52*decks);
        cards.insert(cards.end(), STANDARD_DECK.begin(), STANDARD_DECK.end());
    }
}

void Deck::shuffle() {
    // Shuffle the vector
    std::random_device rd;  // Seed for the random number generator
    std::mt19937 g(rd());   // Mersenne Twister engine
    std::shuffle(cards.begin(), cards.end(), g);
    place = 0;
    std::cout << "shuffled";
    /* for (int i : cards) {
        std::cout << i << " ";
    }
    std::cout << '\n'; */
}

Card Deck::next() {
    Card next = cards[place];
    ++place;
    return next;
}

int Deck::size() {
    return cards.size();
}

void Deck::resize(int newSize) {
    cards.resize(newSize);
}