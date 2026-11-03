// ============================================================
//  To-Do List Manager
//  CSE 310 - Applied Programming (Module 1: C++)
//  Author: Moffat Katopola
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// ------------------------------------------------------------
// Task class
// ------------------------------------------------------------
class Task {
private:
    string description;
    bool completed;

public:
    Task(const string& desc, bool isCompleted = false) {
        description = desc;
        completed = isCompleted;
    }

    void markComplete() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }

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
// Function prototypes
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
    int choice = 0;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Protect against non-numeric input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 1) {
            addTask(tasks);
        }
        else if (choice == 2) {
            loadTasks(tasks);
        }
        else if (choice == 3) {
            listTasks(tasks);
        }
        else if (choice == 4) {
            completeTask(tasks);
        }
        else if (choice == 5) {
            deleteTask(tasks);
        }
        else if (choice == 6) {
            saveTasks(tasks);
        }
        else if (choice == 7) {
            cout << "Goodbye!\n";
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
// Menu
// ------------------------------------------------------------
void showMenu() {
    cout << "===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. Load Tasks\n";
    cout << "3. List Tasks\n";
    cout << "4. Mark Task as Complete\n";
    cout << "5. Delete Task\n";
    cout << "6. Save Tasks to File\n";
    cout << "7. Exit\n";
}

// ------------------------------------------------------------
// List all tasks
// ------------------------------------------------------------
void listTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet.\n";
        return;
    }

    cout << "\n----- Your Tasks -----\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        tasks[i].display(i + 1);
    }
}

// ------------------------------------------------------------
// Add a new task
// ------------------------------------------------------------
void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);

    if (description.empty()) {
        cout << "Task description cannot be empty.\n";
        return;
    }

    tasks.push_back(Task(description));
    cout << "Task added successfully!\n";
}

// ------------------------------------------------------------
// Mark a task as complete
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

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].markComplete();
    cout << "Task marked as complete!\n";
}

// ------------------------------------------------------------
// Delete a task
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

    tasks.erase(tasks.begin() + (index - 1));
    cout << "Task deleted successfully!\n";
}

// ------------------------------------------------------------
// Save tasks to a file (user provides the name)
// ------------------------------------------------------------
void saveTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to save.\n";
        return;
    }

    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);

    if (filename.empty()) {
        cout << "Filename cannot be empty.\n";
        return;
    }

    // Add .txt extension automatically
    filename += ".txt";

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not create the file.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        file << (tasks[i].isCompleted() ? "1" : "0") << " "
             << tasks[i].getDescription() << endl;
    }

    file.close();
    cout << "Tasks saved successfully to \"" << filename << "\".\n";
}

// ------------------------------------------------------------
// Load tasks from a file (user provides the name)
// ------------------------------------------------------------
void loadTasks(vector<Task>& tasks) {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);

    if (filename.empty()) {
        cout << "Filename cannot be empty.\n";
        return;
    }

    filename += ".txt";

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open the file \"" << filename << "\".\n";
        return;
    }

    // Clear current tasks before loading new ones
    tasks.clear();

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        bool isCompleted = (line[0] == '1');
        string description = line.substr(2);

        tasks.push_back(Task(description, isCompleted));
    }

    file.close();
    cout << "Successfully loaded " << tasks.size() << " task(s) from \"" << filename << "\".\n";
}