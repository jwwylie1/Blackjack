# 🃏 Blackjack Decision Trainer  
*A C++/SFML simulator that teaches data-driven Blackjack strategy and card-counting through real-time statistical feedback.*  

![Blackjack Demo Screenshot](./assets/demo.gif) *(Upload a GIF/screenshot later!)*  

## ✨ Key Features  
- **Optimal Move Feedback**: Evaluates each decision (Hit/Stand/Double/etc.) against statistically correct play.  
- **True Count Tracking**: Practice card-counting with live true count updates.  
- **Monte Carlo Simulations**: Calculates *player edge* by running 100,000 sims per hand (adjusted for remaining deck composition).  
- **SFML Visualization**: Intuitive UI with cards, chips, and real-time stats.  

## 🚀 Installation  
### Prerequisites  
- C++17 compiler (GCC/Clang/MSVC)  
- [SFML 2.5+](https://www.sfml-dev.org/download.php)  

### Steps  
```bash
git clone https://github.com/jwwylie1/Blackjack.git  
cd Blackjack
./blackjack-trainer \[number_of_decks\] \[initial_bet\]
```
### ⚙️ Command Line Arguments

| Argument          | Type   | Valid Range  | Default | Description                     |
|-------------------|--------|--------------|---------|---------------------------------|
| `number_of_decks` | int    | 1-10         | 6       | Number of decks in the shoe      |
| `initial_bet`     | int    | 100-10000    | 1000    | Starting bet       |

**Example:**
```bash
./blackjack-trainer         # 6 decks, $1000 starting bet
./blackjack-trainer 8       # 8 decks, $1000 starting bet
./blackjack-trainer 4 500   # 4 decks, $500 starting bet