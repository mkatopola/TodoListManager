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

// ==================== Function Definitions ====================
void showMenu();
void listTasks(const std::vector<Task>& tasks);

// ==================== Main ====================
int main() {
    std::vector<Task> tasks;
    int choice = 0;

    // Main program loop
    while (true) {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear the input buffer after reading a number
        std::cin.ignore(10000, '\n');

        if (choice == 1) {
            // Feature to be implemented later
            std::cout << "The feature for adding tasks is coming soon...\n";
        }
        else if (choice == 2) {
            listTasks(tasks);
        }
        else if (choice == 3) {
            // Feature to be implemented later
            std::cout << "The feature for marking tasks as complete is coming soon...\n";
        }
        else if (choice == 4) {
            // Feature to be implemented later
            std::cout << "The feature for deleting tasks is coming soon...\n";
        }
        else if (choice == 5) {
            std::cout << "Goodbye!\n";
            // Exiting the program
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

/// Displays the main menu options to the user.
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
    for (int i = 0; i < tasks.size(); i++) {
        tasks[i].display(i + 1);
    }
}