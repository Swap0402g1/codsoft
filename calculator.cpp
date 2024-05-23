#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\nCalculator Menu:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    double num1, num2;
    int choice;
    bool exit = false;

    while (!exit) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between 1 and 5." << std::endl;
            continue;
        }

        if (choice == 5) {
            std::cout << "Exiting..." << std::endl;
            break;
        }

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter valid numbers." << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;
            case 2:
                std::cout << "Result: " << num1 - num2 << std::endl;
                break;
            case 3:
                std::cout << "Result: " << num1 * num2 << std::endl;
                break;
            case 4:
                if (num2 != 0) {
                    std::cout << "Result: " << num1 / num2 << std::endl;
                } else {
                    std::cout << "Error: Division by zero!" << std::endl;
                }
                break;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 5." << std::endl;
                break;
        }
    }

    return 0;
}
