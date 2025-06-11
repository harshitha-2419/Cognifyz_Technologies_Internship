# Task3: Task Manager (CRUD)

## Description
This is a console-based task manager implemented in C++. It supports creating, reading, updating, and deleting tasks. Each task has the following fields:
- ID
- Title
- Description
- Priority (Low, Medium, High)
- Due Date (YYYY-MM-DD)
- Status (Pending, Completed)

## Main File
- `taskManager.cpp`

## How to Run
1. Compile the C++ file using a C++ compiler, for example:
   ```
   g++ taskManager.cpp -o taskmanager
   ```
2. Run the executable:
   ```
   ./taskmanager
   ```
3. Use the menu-driven interface to manage tasks.

## Notes
- Input validation is included for priority and due date.
- The program ensures due dates are valid and not in the past.
- Tasks are stored in memory during runtime (no file persistence).
