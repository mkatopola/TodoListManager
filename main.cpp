// ============================================================
//  To-Do List Manager
//  CSE 310 - Applied Programming (Module 1: C++)
//  Author: Moffat Katopola
// ============================================================
//  This program demonstrates:
//  - Variables, expressions, conditionals, loops
//  - Functions and classes
//  - STL vector
//  - Reading from and writing to a file
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// ------------------------------------------------------------
// Task class
// Represents a single to-do item with a description and status
// ------------------------------------------------------------
class Task {
private:
    string description;   
    bool completed;       

public:
    // Constructor – creates a new task
    // isCompleted defaults to false so new tasks start incomplete
    Task(const string& desc, bool isCompleted = false) {
        description = desc;
        completed = isCompleted;
    }

    // Mark this task as completed
    void markComplete() {
        completed = true;
    }

    // Return whether the task is completed
    bool isCompleted() const {
        return completed;
    }

    // Return the task description
    string getDescription() const {
        return description;
    }

    // Display the task with its number and status
    void display(int index) const {
        cout << index << ". ";
        if (completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << description << endl;
    }
};

// ------------------------------------------------------------
// Function declarations
// ------------------------------------------------------------
void showMenu();
void listTasks(const vector<Task>& tasks);
void addTask(vector<Task>& tasks);
void completeTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks);
void loadTasks(vector<Task>& tasks);

// ------------------------------------------------------------
// main
// ------------------------------------------------------------
int main() {
    vector<Task> tasks;

    // Load any previously saved tasks when the program starts
    loadTasks(tasks);

    int choice = 0;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle non-numeric input (prevents infinite loop)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        cin.ignore(10000, '\n');   // clear the leftover newline

        if (choice == 1) {
            addTask(tasks);
        }
        else if (choice == 2) {
            listTasks(tasks);
        }
        else if (choice == 3) {
            completeTask(tasks);
        }
        else if (choice == 4) {
            deleteTask(tasks);
        }
        else if (choice == 5) {
            saveTasks(tasks);
            cout << "Tasks saved. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    }

    return 0;
}
// ------------------------------------------------------------
// Displays the main menu
// ------------------------------------------------------------
void showMenu() {
    cout << "===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. List Tasks\n";
    cout << "3. Mark Task as Complete\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
}

// ------------------------------------------------------------
// Lists all tasks currently in the vector
// ------------------------------------------------------------
void listTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet.\n";
        return;
    }

    cout << "\n----- Your Tasks -----\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        tasks[i].display(i + 1);   // Show 1-based numbers
    }
}

// ------------------------------------------------------------
// Adds a new task to the list
// ------------------------------------------------------------
void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);

    // Simple validation
    if (description.empty()) {
        cout << "Task description cannot be empty.\n";
        return;
    }

    tasks.push_back(Task(description));
    cout << "Task added successfully!\n";
}

// ------------------------------------------------------------
// Marks a chosen task as complete
// ------------------------------------------------------------
void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to complete.\n";
        return;
    }

    listTasks(tasks);

    int index;
    cout << "Enter the number of the task to mark as complete: ";
    cin >> index;
    cin.ignore(10000, '\n');

    // Check that the number is valid
    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].markComplete();
    cout << "Task marked as complete!\n";
}

// ------------------------------------------------------------
// Deletes a chosen task from the list
// ------------------------------------------------------------
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    listTasks(tasks);

    int index;
    cout << "Enter the number of the task to delete: ";
    cin >> index;
    cin.ignore(10000, '\n');

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
        return;
    }

    // Erase the task from the vector
    tasks.erase(tasks.begin() + (index - 1));
    cout << "Task deleted successfully!\n";
}

// ------------------------------------------------------------
// Saves all tasks to a text file
// ------------------------------------------------------------
void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");

    if (!file.is_open()) {
        cout << "Error: Could not save tasks.\n";
        return;
    }

    // Write each task on its own line: 0/1 + description
    for (size_t i = 0; i < tasks.size(); i++) {
        file << (tasks[i].isCompleted() ? "1" : "0") << " "
             << tasks[i].getDescription() << endl;
    }

    file.close();
}

// ------------------------------------------------------------
// Loads tasks from the text file (if it exists)
// ------------------------------------------------------------
void loadTasks(vector<Task>& tasks) {
    ifstream file("tasks.txt");

    // If the file doesn't exist yet, just return
    if (!file.is_open()) {
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        // First character tells us if the task is completed
        bool isCompleted = (line[0] == '1');
        // Everything after the first two characters is the description
        string description = line.substr(2);

        tasks.push_back(Task(description, isCompleted));
    }

    file.close();
    cout << "Loaded " << tasks.size() << " task(s) from file.\n\n";
}