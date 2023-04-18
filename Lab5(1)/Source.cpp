#include <iostream>
#include <cmath>

using namespace std;

class Figures {
protected:
    double x1, y1, x2, y2;
public:
    Figures(double x1, double y1, double x2, double y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    double length() {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
};

class Trapezium : public Figures {
private:
    double x3, y3, x4, y4;

public:
    Trapezium(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        : Figures(x1, y1, x2, y2) {
        this->x3 = x3;
        this->y3 = y3;
        this->x4 = x4;
        this->y4 = y4;
    }

    double base1() {
        return Figures::length();
    }

    double base2() {
        return sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    }

    double height() {
        double s = (base1() - base2()) / 2;
        return sqrt(pow(base2(), 2) - pow(2 * s, 2)) * 2 / base1();
    }

    double perimeter() {
        return base1() + base2() + 2 * sqrt(pow(height(), 2) + pow((base1() - base2()) / 2, 2));
    }

    double area() {
        return (base1() + base2()) * height() / 2;
    }

    void printData() {
        cout << "Trapezium coordinates: (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), (" << x3 << "," << y3 << "), (" << x4 << "," << y4 << ")" << endl;
        cout << "Base 1: " << base1() << endl;
        cout << "Base 2: " << base2() << endl;
        cout << "Height: " << height() << endl;
        cout << "Perimeter: " << perimeter() << endl;
        cout << "Area: " << area() << endl;
    }
};

bool isTrapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double length12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double length34 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));

    if (length12 == length34) {
        return false;
    }

    double length23 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double length41 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

    if (length23 != length41) {
        return false;
    }

    return true;
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    bool isInvalidInput = true;

    while (isInvalidInput) {
        cout << "Enter coordinates of the first point: ";
        cin >> x1 >> y1;
        cout << "Enter coordinates of the second point: ";
        cin >> x2 >> y2;
        cout << "Enter coordinates of the third point: ";
        cin >> x3 >> y3;
        cout << "Enter coordinates of the fourth point: ";
        cin >> x4 >> y4;

        if (!isTrapezoid(x1, y1, x2, y2, x3, y3, x4, y4)) {
            cout << "Entered coordinates do not form a trapezoid." << endl;
        }
        else {
            isInvalidInput = false;
        }
    }

    Trapezium trapezium(x1, y1, x2, y2, x3, y3, x4, y4);

    trapezium.printData();

    return 0;
}