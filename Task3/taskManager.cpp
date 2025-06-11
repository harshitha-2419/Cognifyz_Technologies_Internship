#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <regex>
#include <ctime>

using namespace std;

struct Task {
    int id;
    string title;
    string description;
    string priority; // Low, Medium, High
    string dueDate;  // YYYY-MM-DD
    string status;   // Pending, Completed
};

vector<Task> tasks;
int nextId = 1;

// Improved Date Validation
bool isValidDate(const string& date) {
    regex dateRegex(R"(\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");
    if (!regex_match(date, dateRegex)) {
        return false;
    }

    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    
    if (isLeap && month == 2) {
        if (day > 29) return false;
    } else if (month == 2) {
        if (day > 28) return false;
    }

    if (day > daysInMonth[month - 1]) return false;

    time_t now = time(0);
    tm* localtm = localtime(&now);
    int currentYear = localtm->tm_year + 1900;
    int currentMonth = localtm->tm_mon + 1;
    int currentDay = localtm->tm_mday;

    if (year < currentYear || 
        (year == currentYear && month < currentMonth) || 
        (year == currentYear && month == currentMonth && day < currentDay)) {
        return false;
    }

    return true;
}

bool isValidPriority(const string& priority) {
    string p = priority;
    transform(p.begin(), p.end(), p.begin(), ::tolower);
    return (p == "low" || p == "medium" || p == "high");
}

string toTitleCase(const string& str) {
    if (str.empty()) return str;
    string result = str;
    result[0] = toupper(result[0]);
    for (size_t i = 1; i < result.size(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

// CREATE Operation
void createTask() {
    string title, description, priority, dueDate;
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter description: ";
    getline(cin, description);

    while (true) {
        cout << "Enter priority (Low, Medium, High): ";
        getline(cin, priority);
        if (!isValidPriority(priority)) {
            cout << "Invalid priority. Please enter Low, Medium, or High." << endl;
        } else {
            priority = toTitleCase(priority);
            break;
        }
    }

    while (true) {
        cout << "Enter due date (YYYY-MM-DD): ";
        getline(cin, dueDate);
        if (!isValidDate(dueDate)) {
            cout << "Invalid date format or past date. Please enter a valid future date." << endl;
        } else {
            break;
        }
    }

    Task task = {nextId++, title, description, priority, dueDate, "Pending"};
    tasks.push_back(task);
    cout << "Task created successfully!" << endl;
}

// READ Operation
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
    } else {
        cout << "\nTasks:\n";
        for (const auto& task : tasks) {
            cout << "ID: " << task.id << "\nTitle: " << task.title << "\nPriority: " << task.priority
                 << "\nDue: " << task.dueDate << "\nStatus: " << task.status << "\nDescription: " << task.description 
                 << "\n-------------------------" << endl;
        }
    }
}

Task* findTaskById(int id) {
    for (auto& task : tasks) {
        if (task.id == id) {
            return &task;
        }
    }
    return nullptr;
}

// UPDATE Operation
void updateTask() {
    cout << "Enter task ID to update: ";
    string idStr;
    getline(cin, idStr);
    int id = stoi(idStr);
    Task* task = findTaskById(id);
    if (!task) {
        cout << "Task not found." << endl;
        return;
    }

    string input;
    cout << "Enter new title (" << task->title << "): ";
    getline(cin, input);
    if (!input.empty()) task->title = input;

    cout << "Enter new description (" << task->description << "): ";
    getline(cin, input);
    if (!input.empty()) task->description = input;

    while (true) {
        cout << "Enter new priority (" << task->priority << "): ";
        getline(cin, input);
        if (input.empty()) break;
        if (!isValidPriority(input)) {
            cout << "Invalid priority. Please enter Low, Medium, or High." << endl;
        } else {
            task->priority = toTitleCase(input);
            break;
        }
    }

    while (true) {
        cout << "Enter new due date (" << task->dueDate << "): ";
        getline(cin, input);
        if (input.empty()) break;
        if (!isValidDate(input)) {
            cout << "Invalid date format or past date. Please enter a valid future date." << endl;
        } else {
            task->dueDate = input;
            break;
        }
    }

    cout << "Enter new status (" << task->status << "): ";
    getline(cin, input);
    if (!input.empty()) task->status = toTitleCase(input);

    cout << "Task updated successfully!" << endl;
}

// DELETE Operation
void deleteTask() {
    cout << "Enter task ID to delete: ";
    string idStr;
    getline(cin, idStr);
    int id = stoi(idStr);
    auto it = remove_if(tasks.begin(), tasks.end(), [id](const Task& t) { return t.id == id; });
    if (it == tasks.end()) {
        cout << "Task not found." << endl;
    } else {
        tasks.erase(it, tasks.end());
        cout << "Task deleted successfully!" << endl;
        if (tasks.empty()) {
            nextId = 1;
        }
    }
}

// Main Menu
void mainMenu() {
    while (true) {
        cout << "\nTask Manager\n1. Create Task\n2. View Tasks\n3. Update Task\n4. Delete Task\n5. Exit\nChoose an option: ";
        string choiceStr;
        getline(cin, choiceStr);
        if (choiceStr == "1") {
            createTask();
        } else if (choiceStr == "2") {
            viewTasks();
        } else if (choiceStr == "3") {
            updateTask();
        } else if (choiceStr == "4") {
            deleteTask();
        } else if (choiceStr == "5") {
            cout << "Exiting Task Manager. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid option. Try again." << endl;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}