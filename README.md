# Project Tasks Overview

This repository contains multiple programming tasks organized into separate folders. Each task demonstrates different programming concepts and implementations primarily in C++, with one Node.js web server task.

---

## Task1: Mystery Box Guessing Game

- **Description:** A console-based game where the player selects from 9 mystery boxes containing prizes, traps, or empty boxes. The player has 5 trials to score points by finding prizes while avoiding traps.
- **Main File:** `Task1/consoleApp.cpp`
- **How to Run:** Compile and run the C++ file using a C++ compiler. The game runs in the console with interactive input.

---

## Task2: Number Patterns Generator

- **Description:** Generates various number patterns such as pyramids, triangles, diamonds, and Pascal's triangle based on user input.
- **Main File:** `Task2/number-pattern.cpp`
- **How to Run:** Compile and run the C++ file. Select the desired pattern and number of rows when prompted.

---

## Task3: Task Manager (CRUD)

- **Description:** A console-based task manager supporting create, read, update, and delete operations on tasks with fields like title, description, priority, due date, and status.
- **Main File:** `Task3/taskManager.cpp`
- **How to Run:** Compile and run the C++ file. Use the menu-driven interface to manage tasks.

---

## Task4: Temperature Converter

- **Description:** Converts temperatures between Fahrenheit and Celsius with input validation and formatted output.
- **Main File:** `Task4/temperatureConverter.cpp`
- **How to Run:** Compile and run the C++ file. Enter the temperature and select the conversion direction when prompted.

---

## Task5: Task Manager with File Persistence

- **Description:** A console-based task manager that stores tasks persistently in a text file (`tasks.txt`). Supports listing, adding, updating, and deleting tasks.
- **Main File:** `Task5/TaskData.cpp`
- **How to Run:** Compile and run the C++ file. Tasks are saved and loaded automatically from `tasks.txt`.

---

## Task6: Web Scraper Server

- **Description:** A Node.js Express server that serves static web files and provides an endpoint to scrape paragraph texts from a given URL.
- **Main File:** `Task6/server.js`
- **How to Run:** 
  1. Install dependencies with `npm install` inside the `Task6` folder.
  2. Start the server with `node server.js`.
  3. Access the web interface via `http://localhost:3000` and use the scraper functionality.

---

# General Notes

- C++ tasks require a C++ compiler to build and run.
- Task6 requires Node.js and npm installed.
- Each task is self-contained within its folder.
