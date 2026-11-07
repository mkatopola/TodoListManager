# Overview

This project is a console-based To-Do List Manager built in C++.  

The goal was to deepen my understanding of core C++ features by creating a practical tool that manages tasks, supports persistent storage, and provides a clean interactive experience.

The software allows users to:
- Add new tasks
- Load previously saved task lists
- View all current tasks
- Mark tasks as complete
- Delete tasks
- Save the current list to a .txt file

It demonstrates key C++ concepts including classes, the Standard Template Library (`std::vector`), file input/output, conditionals, loops, and functions.


# Software Demo Video

[Software Demo Video](https://youtu.be/Zt5mctaNXv4)


# Source Code GitHub Link

[GitHub Link](https://github.com/mkatopola/TodoListManager)


# Development Environment

- **Editor / IDE**: Visual Studio Code  
- **Compiler**: g++ (GNU Compiler Collection)  
- **Language Standard**: C++17 (required for `<filesystem>`)  
- **Operating System**: Windows / Linux / macOS (cross-platform console application)

# Libraries / Headers used:
- `<iostream>`
- `<string>`
- `<vector>`
- `<fstream>`
- `<filesystem>`


# Useful Websites Resources

- [C++ Reference – std::vector](https://en.cppreference.com/w/cpp/container/vector)
- [C++ Reference – File Input/Output](https://en.cppreference.com/w/cpp/io/basic_fstream)
- [C++ Reference – std::filesystem](https://en.cppreference.com/w/cpp/filesystem)
- [learncpp.com – Classes](https://www.learncpp.com/cpp-tutorial/classes-and-class-members/)
- [cplusplus.com – string](https://cplusplus.com/reference/string/string/)

# Future Work

- Add the ability to edit an existing task description
- Support task priorities or due dates
- Allow loading multiple files and merging them
- Make the program modular and use inheritance to make everything work together