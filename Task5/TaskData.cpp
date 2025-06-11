#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

const string TASKS_FILE = "tasks.txt";
vector<string> tasks;

void loadTasks() {
    tasks.clear();
    ifstream infile(TASKS_FILE);
    if (!infile.is_open()) {
        // File does not exist or cannot be opened, start with empty tasks
        return;
    }
    string line;
    while (getline(infile, line)) {
        if (!line.empty()) {
            tasks.push_back(line);
        }
    }
    infile.close();
}

void saveTasks() {
    ofstream outfile(TASKS_FILE);
    if (!outfile.is_open()) {
        cout << "Error writing tasks file." << endl;
        return;
    }
    for (const auto& task : tasks) {
        outfile << task << endl;
    }
    outfile.close();
}

void listTasks() {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". " << tasks[i] << endl;
        }
    }
}

void addTask() {
    string desc;
    cout << "Enter new task description: ";
    getline(cin, desc);
    if (desc.empty()) {
        cout << "Task description cannot be empty." << endl;
        addTask();
        return;
    }
    tasks.push_back(desc);
    saveTasks();
    cout << "Task added." << endl;
}

void updateTask() {
    listTasks();
    cout << "Enter task number to update: ";
    string numStr;
    getline(cin, numStr);
    int num = 0;
    try {
        num = stoi(numStr);
    } catch (...) {
        cout << "Invalid task number." << endl;
        updateTask();
        return;
    }
    if (num < 1 || num > (int)tasks.size()) {
        cout << "Invalid task number." << endl;
        updateTask();
        return;
    }
    cout << "Enter new description: ";
    string desc;
    getline(cin, desc);
    if (desc.empty()) {
        cout << "Task description cannot be empty." << endl;
        updateTask();
        return;
    }
    tasks[num - 1] = desc;
    saveTasks();
    cout << "Task updated." << endl;
}

void deleteTask() {
    listTasks();
    cout << "Enter task number to delete: ";
    string numStr;
    getline(cin, numStr);
    int num = 0;
    try {
        num = stoi(numStr);
    } catch (...) {
        cout << "Invalid task number." << endl;
        deleteTask();
        return;
    }
    if (num < 1 || num > (int)tasks.size()) {
        cout << "Invalid task number." << endl;
        deleteTask();
        return;
    }
    tasks.erase(tasks.begin() + num - 1);
    saveTasks();
    cout << "Task deleted." << endl;
}

void mainMenu() {
    while (true) {
        cout << "\nTask Manager" << endl;
        cout << "1. List tasks" << endl;
        cout << "2. Add task" << endl;
        cout << "3. Update task" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        string choice;
        getline(cin, choice);
        if (choice == "1") {
            listTasks();
        } else if (choice == "2") {
            addTask();
        } else if (choice == "3") {
            updateTask();
        } else if (choice == "4") {
            deleteTask();
        } else if (choice == "5") {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }
}

int main() {
    loadTasks();
    mainMenu();
    return 0;
}
