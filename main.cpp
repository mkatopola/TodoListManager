#include <iostream>
#include <string>
#include <vector>

// ==================== Task Class ====================
class Task {
private:
    std::string description;
    bool completed;

public:
    Task(const std::string& desc) {
        description = desc;
        completed = false;
    }

    void markComplete() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    std::string getDescription() const {
        return description;
    }

    void display(int index) const {
        std::cout << index << ". ";
        if (completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << description << std::endl;
    }
};

// ==================== Function Prototypes ====================
void showMenu();
void listTasks(const std::vector<Task>& tasks);
void addTask(std::vector<Task>& tasks);
void completeTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);

// ==================== Main ====================
int main() {
    std::vector<Task> tasks;
    int choice = 0;

    while (true) {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(10000, '\n');   // clear input buffer

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
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << std::endl;
    }

    return 0;
}

// ==================== Functions ====================

void showMenu() {
    std::cout << "===== To-Do List Manager =====\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. List Tasks\n";
    std::cout << "3. Mark Task as Complete\n";
    std::cout << "4. Delete Task\n";
    std::cout << "5. Exit\n";
}

void listTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks yet.\n";
        return;
    }

    std::cout << "\n----- Your Tasks -----\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        tasks[i].display(i + 1);
    }
}

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);

    if (description.empty()) {
        std::cout << "Task description cannot be empty.\n";
        return;
    }

    tasks.push_back(Task(description));
    std::cout << "Task added successfully!\n";
}

void completeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to complete.\n";
        return;
    }

    listTasks(tasks);

    int index;
    std::cout << "Enter the number of the task to mark as complete: ";
    std::cin >> index;
    std::cin.ignore(10000, '\n');

    // Convert to 0-based index and check validity
    if (index < 1 || index > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].markComplete();
    std::cout << "Task marked as complete!\n";
}

void deleteTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }

    listTasks(tasks);

    int index;
    std::cout << "Enter the number of the task to delete: ";
    std::cin >> index;
    std::cin.ignore(10000, '\n');

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));
    std::cout << "Task deleted successfully!\n";
}