#include <iostream>
#include <string>

// ==================== Task Class ====================
class Task {
private:
    std::string description;
    bool completed;

public:
    // Constructor
    Task(const std::string& desc) {
        description = desc;
        completed = false;
    }

    // Marking the task as complete
    void markComplete() {
        completed = true;
    }

    // Checking if the task is completed
    bool isCompleted() const {
        return completed;
    }

    // Getting the description
    std::string getDescription() const {
        return description;
    }

    // Displaying the task
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

// ==================== Main ====================
int main() {
    // Just testing the class for now
    Task task1("Learn C++ classes");
    Task task2("Build a to-do list");

    std::cout << "\nT0-Do List Manager" << std::endl;

    task1.display(1);
    task2.display(2);

    std::cout << "\nMarking first task as complete...\n";
    task1.markComplete();

    task1.display(1);
    task2.display(2);

    return 0;
}