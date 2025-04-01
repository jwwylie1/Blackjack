#include "Hand.hpp"
#include "graphics.hpp"
#include <SFML/Graphics.hpp>

/* Hand::Hand() {
    hole.resize(2);
} */

Hand::Hand(Card card1, Card card2, sf::RenderWindow& window, sf::Text& playerText, sf::Text& dealerText)
        : window(window), playerText(playerText), dealerText(dealerText) {
    hole.push_back(card1);
    hole.push_back(card2);
} 

void Hand::printPlayer(std::string blackjackStatus)
{
    for (int i=0; i<hole.size(); ++i) { // show all player cards
        sf::Texture card = createCardTexture(std::to_string(hole[i]) + "_of_" + randomSuit());
        window.draw(createPlayerSprite(card, i));
    }

    playerText.setString(std::to_string(total()));
    
    updateArea(window, playerText, 260);
}

void Hand::printDealer(bool show, std::string blackjackStatus)
{
    if (blackjackStatus != "none") {
        sf::Texture card = createCardTexture(std::to_string(hole[0]) + "_of_" + randomSuit());
        window.draw(createDealerSprite(card, 0));
        show = true; // show all cards on blackjack
    }

    if (show) {
        for (int i=1; i<hole.size(); ++i) { // display all cards
            sf::Texture card = createCardTexture(std::to_string(hole[i]) + "_of_" + randomSuit());
            window.draw(createDealerSprite(card, i));
            window.display();
        }

        dealerText.setString(std::to_string(total())); // sum all cards
    } else {
        sf::Texture card = createCardTexture(std::to_string(hole[0]) + "_of_" + randomSuit());
        sf::Texture back = createCardTexture("back");
        window.draw(createDealerSprite(card, 0));
        window.draw(createDealerSprite(back, 1));
        dealerText.setString(std::to_string(hole[0])); // only one card shown, display value
    }

    updateArea(window, dealerText, 250);
    
}

int Hand::size() {
    return hole.size();
}

int Hand::total() {
    int sum=0;
    int aces = 0;
    for (int i=0; i<size(); ++i) {
        if (hole[i] == 11) {
            sum += 11;
            ++aces;
        } else {
            sum += hole[i];
        }
    }

    while (sum > 21 && aces > 0) {
        sum -= 10; // Treat Ace as 1 instead of 11
        aces--;
    }

    return sum;
}

bool Hand::hasAce() {
    for (int i=0; i<size(); ++i) {
        if (hole[i] == ACE)
            return true;
    }
    return false;
}

bool Hand::isSplittable() {
    if (hole[0] == hole[1]) {
        return true;
    } else {
        return false;
    }
}

void Hand::reset() {
    hole.resize(2);
}

void Hand::addCard(Card add) {
    hole.push_back(add);
}

std::string Hand::randomSuit() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    int rand = dis(gen);
    
    if (rand==0) {return "spades";}
    else if (rand==1) {return "hearts";}
    else if (rand==2) {return "clubs";}
    else {return "diamonds";}
}