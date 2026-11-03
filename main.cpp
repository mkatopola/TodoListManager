#include <iostream>
#include <string>
#include <vector>
#include <fstream>   // for file operations

using namespace std;

// ==================== Task Class ====================
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

// ==================== Function Prototypes ====================
void showMenu();
void listTasks(const vector<Task>& tasks);
void addTask(vector<Task>& tasks);
void completeTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks);
void loadTasks(vector<Task>& tasks);

// ==================== Main ====================
int main() {
    vector<Task> tasks;

    // Load existing tasks at startup
    loadTasks(tasks);

    int choice = 0;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');

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
            saveTasks(tasks);          // Save before exiting
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

// ==================== Functions ====================

void showMenu() {
    cout << "===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. List Tasks\n";
    cout << "3. Mark Task as Complete\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
}

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

// ---------- File Operations ----------

void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");

    if (!file.is_open()) {
        cout << "Error: Could not save tasks.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        // Format: 0 or 1 (completed) followed by the description
        file << (tasks[i].isCompleted() ? "1" : "0") << " "
             << tasks[i].getDescription() << endl;
    }

    file.close();
}

void loadTasks(vector<Task>& tasks) {
    ifstream file("tasks.txt");

    if (!file.is_open()) {
        // No file yet – that's fine for the first run
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        // First character is 0 or 1
        bool isCompleted = (line[0] == '1');
        // The rest after the space is the description
        string description = line.substr(2);

        tasks.push_back(Task(description, isCompleted));
    }

    file.close();
    cout << "Loaded " << tasks.size() << " task(s) from file.\n\n";
}