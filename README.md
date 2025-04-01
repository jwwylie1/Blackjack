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
- CMake (recommended)  

### Steps  
```bash
git clone https://github.com/yourusername/blackjack-trainer.git  
cd blackjack-trainer  
mkdir build && cd build  
cmake .. && make  
./BlackjackTrainer  