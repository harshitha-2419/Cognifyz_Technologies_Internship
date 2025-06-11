# Task5: Task Manager with File Persistence

## Description
This is a console-based task manager implemented in C++. It manages a list of tasks stored persistently in a text file (`tasks.txt`). The user can list, add, update, and delete tasks.

## Main File
- `TaskData.cpp`

## How to Run
1. Compile the C++ file using a C++ compiler, for example:
   ```
   g++ TaskData.cpp -o taskdata
   ```
2. Run the executable:
   ```
   ./taskdata
   ```
3. Use the menu-driven interface to manage tasks. Tasks are saved automatically to `tasks.txt`.

## Notes
- Tasks are loaded from and saved to a text file for persistence.
- Input validation ensures valid task descriptions and task numbers.
- The program handles file read/write errors gracefully.
