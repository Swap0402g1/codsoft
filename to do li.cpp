#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& desc) : description(desc), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    std::string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

private:
    std::string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
    }

    void viewTasks() const {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getDescription()
                      << " [" << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].markCompleted();
        } else {
            std::cerr << "Invalid task number.\n";
        }
    }

    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cerr << "Invalid task number.\n";
        }
    }

private:
    std::vector<Task> tasks;
};

void displayMenu() {
    std::cout << "\nTo-Do List Menu:\n"
              << "1. Add Task\n"
              << "2. View Tasks\n"
              << "3. Mark Task as Completed\n"
              << "4. Remove Task\n"
              << "5. Exit\n"
              << "Choose an option: ";
}

int main() {
    ToDoList toDoList;
    int choice;
    std::string description;
    size_t taskIndex;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter task description: ";
            std::cin.ignore();  // Clear the input buffer
            std::getline(std::cin, description);
            toDoList.addTask(description);
            break;
        case 2:
            toDoList.viewTasks();
            break;
        case 3:
            std::cout << "Enter task number to mark as completed: ";
            std::cin >> taskIndex;
            toDoList.markTaskCompleted(taskIndex);
            break;
        case 4:
            std::cout << "Enter task number to remove: ";
            std::cin >> taskIndex;
            toDoList.removeTask(taskIndex);
            break;
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cerr << "Invalid option. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
