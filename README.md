# 2048 Game - C++ Implementation

## Description
This project is a C++ implementation of the popular 2048 game. The game allows players to merge numbered tiles by shifting them in different directions until they reach the winning tile (2048) or run out of moves.

## Features
- Fully functional 2048 game mechanics
- Random tile generation
- Score tracking and leaderboard management
- User-friendly interface using `cppgraphics.hpp`
- Sound effects for different game events

## Requirements
- C++ compiler (e.g., MinGW, MSVC)
- Windows OS (for `Windows.h` and `PlaySound` functionality)
- `cppgraphics.hpp` library

## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/2048-game.git
   ```
2. Navigate to the project folder:
   ```bash
   cd 2048-game
   ```
3. Compile the source code:
   ```bash
   g++ -o 2048 Source1.cpp -lwinmm
   ```
4. Run the executable:
   ```bash
   ./2048
   ```
   OR

   **Install the executable folder and enjoy it :)

## How to Play
- Use the arrow keys to shift tiles:
  - `Right Arrow` → Move tiles right
  - `Left Arrow` → Move tiles left
  - `Up Arrow` → Move tiles up
  - `Down Arrow` → Move tiles down
- Merge tiles of the same number to combine them
- Reach 2048 to win the game
- If no moves are possible, the game ends

## Game Structure
- `start_game()`: Initializes the game loop
- `StartGame()`: Generates initial tiles and manages gameplay
- `shiftright()`, `shiftleft()`, `shiftup()`, `shiftdown()`: Handle tile movements
- `checkhorizontal()`, `checkvertical()`: Check available moves
- `generateRandomTile()`: Adds a new tile after each move
- `draw()`: Renders the game board
- `gameover()`, `win()`: Handle endgame scenarios



