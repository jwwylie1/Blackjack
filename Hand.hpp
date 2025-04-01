#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Hand {
    public:
        //Hand();
        Hand(Card card1, Card card2, sf::RenderWindow& window, sf::Text& playerText,
        sf::Text& dealerText);

        bool isSplittable();
        bool hasAce();
        void printPlayer(std::string blackjackStatus);
        void printDealer(bool show, std::string blackjackStatus);

        Card &operator[](int index) {
            if (index >= hole.size()) {
                std::cout << "Index out of range";
            }
            return hole[index];
        }

        int size();
        int total();
        void reset();
        void addCard(Card add);
        void show();
        std::string randomSuit();
    
    private:
        std::vector<Card> hole;
        bool test = false;
        sf::RenderWindow& window;
        sf::Text& playerText;
        sf::Text& dealerText;
};
