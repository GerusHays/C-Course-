# C++ Coursework Portfolio

This repository contains my C++ assignments and three larger projects from a college course:
- **Grocery Store** — simple POS/inventory style exercises (files, structs/classes, totals, receipts).
- **Clock (12/24 hour)** — timekeeping utilities with input validation and dual-format display.
- **Banking Project** — accounts, deposits/withdrawals, interest calculations, and reporting.
- **Misc Calculators** — standalone programs used in labs/homework.

> Language: **C++** (g++/clang++/MSVC compatible).

---

## Folder Layout (example)
```
/GroceryStore/
/Clock12_24/
/Banking/
/Calculators/
/Homework/
```
If your local names differ, no worries—keep the same top-level folders you already have and commit them as-is.

---

## Build & Run (quick examples)

### g++ (single file)
```bash
g++ -std=c++17 -O2 -Wall -Wextra -o grocery ./GroceryStore/main.cpp
./grocery
```

### g++ (multiple sources)
```bash
g++ -std=c++17 -O2 -Wall -Wextra ./GroceryStore/src/*.cpp -I./GroceryStore/include -o grocery
./grocery
```

### CMake (if a CMakeLists.txt is present)
```bash
mkdir -p build && cd build
cmake ..
cmake --build . --config Release
./bin/your_program_name   # or just ./your_program_name on Linux/macOS
```

### Windows (MSVC, Developer Command Prompt)
```bat
cl /std:c++17 /EHsc /W4 /O2 /I .\GroceryStore\include .\GroceryStore\src\*.cpp /Fe:grocery.exe
grocery.exe
```

---

## Project Notes

### Grocery Store
- Typical topics: file I/O (CSV/JSON/text), classes for `Item`, `Cart`, and `Store`.
- Features may include: add/remove items, totals, tax, receipts, basic inventory.

### Clock (12/24 Hour)
- Input parsing/validation (HH:MM:SS).
- Conversions between 12-hour and 24-hour formats.
- Increment/decrement seconds, minutes, hours; display utilities.

### Banking
- `Account` class(es): balance, deposit, withdraw, monthly statements.
- Interest calculations (simple vs. compound), fees, and basic reporting.
- Optional: persistence via files.

### Misc Calculators
- Self-contained programs for labs/homework (areas, physics helpers, number utilities, etc.).

---

## Dev Conventions
- Standard: `-std=c++17` unless an assignment required otherwise.
- Warnings on: `-Wall -Wextra` (treat warnings as errors when polishing: `-Werror`).
- Keep each project buildable independently (local `README.md` or comments are great).
- Commit message style: present tense, short summary + context (e.g., `Add deposit/withdraw logic to Banking Account`).

---

## How to Run All Projects Quickly
Each top-level folder contains a program (or more). Open a terminal in that folder and use one of the build/run examples above. If a project includes its own `README.md` or `Makefile/CMakeLists.txt`, follow that.

---

## Requirements
- Any modern C++ compiler (g++ 10+, clang 10+, or MSVC 2019+).
- (Optional) CMake 3.16+ for multi-file builds.
- (Optional) VS Code with C/C++ extension for IntelliSense and easy builds.

---

## License
Personal coursework. Not licensed for commercial use. If you want to reuse a snippet, please ask first.
