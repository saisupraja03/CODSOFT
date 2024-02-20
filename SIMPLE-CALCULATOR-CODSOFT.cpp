#include <iostream>

int main() {
    double a,b;
    char calculation;

    std::cout << "Basic calculator\n";
    std::cout << "Enter first number(a): ";
    std::cin >> a;

    std::cout << "Enter second number(b): ";
    std::cin >> b;

    std::cout << "Choose operation (+, -, *, /): ";
    std::cin >> calculation;

    switch (calculation) {
        case '+':
            std::cout << a << " + " << b << " = " << a + b << "\n";
            break;
        case '-':
            std::cout << a << " - " << b << " = " << a - b << "\n";
            break;
        case '*':
            std::cout << a << " * " << b << " = " << a * b << "\n";
            break;
        case '/':
            if (b != 0) {
                std::cout << a << " / " << b << " = " << a / b << "\n";
            } else {
                std::cout << "Error!Division by zero is not possible.\n";
            }
            break;
        default:
            std::cout << "Invalid!!,Please choose +, -, *, or /.\n";
    }

    return 0;
}
