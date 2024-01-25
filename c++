#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.push_back({description, false});
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as completed: " << tasks[index].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void displayTasks() const {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;

    char choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Mark Task as Completed" << std::endl;
        std::cout << "3. Display Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter task description: ";
                {
                    std::string description;
                    std::cin.ignore();
                    std::getline(std::cin, description);
                    todoList.addTask(description);
                }
                break;

            case '2':
                std::cout << "Enter task index to mark as completed: ";
                {
                    int index;
                    std::cin >> index;
                    todoList.markTaskAsCompleted(index - 1);
                }
                break;

            case '3':
                todoList.displayTasks();
                break;

            case '4':
                std::cout << "Exiting program." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != '4');

    return 0;
}