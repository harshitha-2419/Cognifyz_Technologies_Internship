# Task1: Mystery Box Guessing Game

## Description
This is a console-based game implemented in C++. The player selects from 9 mystery boxes, each containing either a prize, a trap, or being empty. The player has 5 trials to select boxes and tries to score 30 or more points by finding prizes while avoiding traps.

## Main File
- `consoleApp.cpp`

## How to Run
1. Compile the C++ file using a C++ compiler, for example:
   ```
   g++ consoleApp.cpp -o mysterybox
   ```
2. Run the executable:
   ```
   ./mysterybox
   ```
3. Follow the on-screen instructions to play the game.

## Notes
- The game uses randomization to assign contents to boxes each time.
- Input validation is included to ensure valid box selections.
- The game can be replayed multiple times without restarting the program.
