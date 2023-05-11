#include <iostream>
#include <cmath>
#include <vector>

class Expression {
private:
    double a, b, c, d;

public:
    Expression(double a_val, double b_val, double c_val, double d_val) {
        a = a_val;
        b = b_val;
        c = c_val;
        d = d_val;
    }

    void setValues(double a_val, double b_val, double c_val, double d_val) {
        a = a_val;
        b = b_val;
        c = c_val;
        d = d_val;
    }

    double calculate() {
        try {
            double result = (log10(4 * b - c) * a) / (b + c / d - 1);
            return result;
        }
        catch (const std::exception& e) {
            std::cout << "Exception occurred: " << e.what() << std::endl;
            return 0.0;
        }
    }

    double getValue() {
        return calculate();
    }
};

int main() {
    const int ARRAY_SIZE = 3;  // Розмір масиву об'єктів

    // Створення масиву об'єктів
    std::vector<Expression> expressions;
    expressions.reserve(ARRAY_SIZE);

    // Введення значень для об'єктів і обчислення виразу
    for (int i = 0; i < ARRAY_SIZE; i++) {
        double a, b, c, d;
        std::cout << "Enter values for expression " << i + 1 << ":" << std::endl;
        std::cout << "a: ";
        std::cin >> a;
        std::cout << "b: ";
        std::cin >> b;
        std::cout << "c: ";
        std::cin >> c;
        std::cout << "d: ";
        std::cin >> d;

        Expression expression(a, b, c, d);
        expressions.push_back(expression);
    }

    // Виведення результату для кожного об'єкта
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Result for expression " << i + 1 << ": " << expressions[i].getValue() << std::endl;
    }

    return 0;
}
