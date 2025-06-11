#include <iostream>
#include <string>
#include <limits>

using namespace std;

void generateSimplePyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        cout << string(rows - i, ' ');
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void generateRightAngledTriangle(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void generateInvertedPyramid(int rows) {
    for (int i = rows; i >= 1; i--) {
        cout << string(rows - i, ' ');
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void generateDiamondPattern(int rows) {
    // Upper pyramid
    for (int i = 1; i <= rows; i++) {
        cout << string(rows - i, ' ');
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    // Lower inverted pyramid
    for (int i = rows - 1; i >= 1; i--) {
        cout << string(rows - i, ' ');
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void generatePascalsTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        cout << string(rows - i, ' ');
        int val = 1;
        for (int j = 0; j <= i; j++) {
            cout << val << " ";
            val = val * (i - j) / (j + 1);
        }
        cout << endl;
    }
}

int main() {
    int choice;
    int rows;
    char cont = 'y';

    cout << "Number Patterns Generator" << endl;

    while (cont == 'y' || cont == 'Y') {
        cout << "Select Pattern:" << endl;
        cout << "1. Simple Pyramid" << endl;
        cout << "2. Right-Angled Triangle" << endl;
        cout << "3. Inverted Pyramid" << endl;
        cout << "4. Diamond Pattern" << endl;
        cout << "5. Pascal's Triangle" << endl;

        while (true) {
            cout << "Enter your choice (1-5): ";
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 5) {
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter number of rows (1-20): ";
            cin >> rows;
            if (cin.fail() || rows < 1 || rows > 20) {
                cout << "Invalid number of rows. Please enter a number between 1 and 20." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cout << endl;

        switch (choice) {
            case 1:
                generateSimplePyramid(rows);
                break;
            case 2:
                generateRightAngledTriangle(rows);
                break;
            case 3:
                generateInvertedPyramid(rows);
                break;
            case 4:
                generateDiamondPattern(rows);
                break;
            case 5:
                generatePascalsTriangle(rows);
                break;
            default:
                cout << "Unknown pattern selected." << endl;
        }

        cout << endl << "Do you want to generate another pattern? (y/n): ";
        cin >> cont;
        cout << endl;
    }

    cout << "Thank you for using Number Patterns Generator." << endl;

    return 0;
}
