#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

double toCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double toFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double askTemperature() {
    double temp;
    while (true) {
        cout << "Enter the temperature value: ";
        cin >> temp;
        if (cin.fail()) {
            cout << "Invalid temperature. Please enter a numeric value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
            return temp;
        }
    }
}

int askConversionDirection() {
    int choice;
    while (true) {
        cout << "Choose conversion direction:" << endl;
        cout << "1. Fahrenheit to Celsius" << endl;
        cout << "2. Celsius to Fahrenheit" << endl;
        cout << "Enter 1 or 2: ";
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2)) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
            return choice;
        }
    }
}

int main() {
    double temp = askTemperature();
    int choice = askConversionDirection();

    cout << fixed << setprecision(2);
    if (choice == 1) {
        double celsius = toCelsius(temp);
        cout << temp << "°F is " << celsius << "°C" << endl;
    } else {
        double fahrenheit = toFahrenheit(temp);
        cout << temp << "°C is " << fahrenheit << "°F" << endl;
    }

    cout << "Goodbye!" << endl;
    return 0;
}
