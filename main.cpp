#include <iostream>
#include <string>
#include <vector>

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

    // Displaying the tasks
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
    // Creating a vector that will hold Task objects
    std::vector<Task> tasks;

    // Adding my tasks for this week
    tasks.push_back(Task("Complete Week 2 Soft Skills Assignment"));
    tasks.push_back(Task("Practice using vectors in C++"));
    tasks.push_back(Task("Attend Institute class on Thursday"));

    // Display all tasks using a for loop and expression indexing
    std::cout << "===== My To-Do List =====\n";
    for ( int i = 0; i < tasks.size(); i++) {
        tasks[i].display(i + 1);
    }

    // Mark the second task as complete
    std::cout << "\nMarking task 2 as complete...\n";
    tasks[1].markComplete();

    // Display again
    std::cout << "\n===== Updated List =====\n";
    for (int i = 0; i < tasks.size(); i++) {
        tasks[i].display(i + 1);
    }

    return 0;
}