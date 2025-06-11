#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <set>
#include <limits>  // Added to fix numeric_limits error

using namespace std;

const int maxTrials = 5;
const int boxCount = 9;
const vector<string> contents = {"prize", "trap", "empty"};

vector<string> getRandomContents() {
    vector<string> boxContents;
    srand(time(0));
    while (boxContents.size() < boxCount) {
        int choice = rand() % contents.size();
        boxContents.push_back(contents[choice]);
    }
    return boxContents;
}

void printRules() {
    cout << "Welcome to the Mystery Box Guessing Game!" << endl;
    cout << "Rules & Logic:" << endl;
    cout << "- There are 9 mystery boxes." << endl;
    cout << "- You have 5 trials to select boxes." << endl;
    cout << "- Each box may contain a prize, a trap, or be empty." << endl;
    cout << "- Finding a prize gives you 10 points." << endl;
    cout << "- Finding a trap adds to your losses." << endl;
    cout << "- Empty boxes give no points or losses." << endl;
    cout << "- Try to score 30 or more points to win the game." << endl;
    cout << "- The game ends after 5 trials, and the winner is announced." << endl;
    cout << "- You can play again anytime after the game ends." << endl << endl;
}

int main() {
    bool playAgain = true;
    while (playAgain) {
        vector<string> boxContents = getRandomContents();
        int points = 0;
        int losses = 0;
        int trials = 0;
        set<int> chosenBoxes;

        printRules();

        while (trials < maxTrials) {
            cout << "Trial " << (trials + 1) << " of " << maxTrials << endl;
            cout << "Choose a box number (1-" << boxCount << "): ";
            int boxNumber;
            cin >> boxNumber;

            if (cin.fail() || boxNumber < 1 || boxNumber > boxCount) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and " << boxCount << ".\n" << endl;
                continue;
            }
            if (chosenBoxes.find(boxNumber) != chosenBoxes.end()) {
                cout << "You already chose that box. Please select a different box.\n" << endl;
                continue;
            }

            chosenBoxes.insert(boxNumber);
            string content = boxContents[boxNumber - 1];

            if (content == "prize") {
                points += 10;
                cout << "Congratulations! You found the prize!\n" << endl;
            } else if (content == "trap") {
                losses += 1;
                cout << "Oh no! You found a trap! You lose!\n" << endl;
            } else {
                cout << "The box is empty. Try again!\n" << endl;
            }

            trials++;
            cout << "Current points: " << points << endl;
            cout << "Trials used: " << trials << "\n" << endl;
        }

        if (points >= 30) {
            cout << "Hurray! You are the overall winner!" << endl;
        } else {
            cout << "Oh no! The computer wins overall!" << endl;
        }

        string response;
        while (true) {
            cout << "Do you want to play again? (yes/no): ";
            cin >> response;
            for (size_t i = 0; i < response.size(); ++i) {
                response[i] = tolower(response[i]);
            }
            if (response == "yes" || response == "y") {
                cout << "\nStarting a new game...\n" << endl;
                break;
            } else if (response == "no" || response == "n") {
                playAgain = false;
                cout << "Thanks for playing! Goodbye!" << endl;
                break;
            } else {
                cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
            }
        }
    }
    return 0;
}
