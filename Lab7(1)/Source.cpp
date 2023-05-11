#include <iostream>
#include <cmath>

template<typename T>
class Point {
private:
    T x;
    T y;

public:
    Point() : x(0), y(0) {}

    Point(T x, T y) : x(x), y(y) {}

    void setX(T newX) {
        x = newX;
    }

    void setY(T newY) {
        y = newY;
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }
};

template<typename T>
class Triangular {
private:
    Point<T> vertex1;
    Point<T> vertex2;
    Point<T> vertex3;

public:
    Triangular(const Point<T>& v1, const Point<T>& v2, const Point<T>& v3)
        : vertex1(v1), vertex2(v2), vertex3(v3) {}

    void setVertex1(const Point<T>& v) {
        vertex1 = v;
    }

    void setVertex2(const Point<T>& v) {
        vertex2 = v;
    }

    void setVertex3(const Point<T>& v) {
        vertex3 = v;
    }

    double calculateDistance(const Point<T>& p1, const Point<T>& p2) const {
        double dx = p1.getX() - p2.getX();
        double dy = p1.getY() - p2.getY();
        return std::sqrt(dx * dx + dy * dy);
    }

    double getSide1Length() const {
        return calculateDistance(vertex1, vertex2);
    }

    double getSide2Length() const {
        return calculateDistance(vertex2, vertex3);
    }

    double getSide3Length() const {
        return calculateDistance(vertex3, vertex1);
    }

    double getPerimeter() const {
        return getSide1Length() + getSide2Length() + getSide3Length();
    }

    double getArea() const {
        double p = getPerimeter() / 2.0;
        double a = getSide1Length();
        double b = getSide2Length();
        double c = getSide3Length();
        return std::sqrt(p * (p - a) * (p - b) * (p - c));
    }

    std::string getType() const {
        double a = getSide1Length();
        double b = getSide2Length();
        double c = getSide3Length();

        if (a == b && b == c) {
            return "Equilateral";
        }
        else if (a == b || b == c || c == a) {
            return "Isosceles";
        }
        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            return "Right";
        }
        else {
            return "Scalene";
        }
    }
};

int main() {
    double x, y;

    std::cout << "Enter coordinates for Point 1 (x y): ";
    std::cin >> x >> y;
    Point<double> p1(x, y);

    std::cout << "Enter coordinates for Point 2 (x y): ";
    std::cin >> x >> y;
    Point<double> p2(x, y);

    std::cout << "Enter coordinates for Point 3 (x y): ";
    std::cin >> x >> y;
    Point<double> p3(x, y);

    Triangular<double> triangle(p1, p2, p3);

    std::cout << "Triangle Perimeter: " << triangle.getPerimeter() << std::endl;
    std::cout << "Triangle Area: " << triangle.getArea() << std::endl;
    std::cout << "Triangle Type: " << triangle.getType() << std::endl;

    // Changing the vertices of the triangle
    std::cout << "Enter new coordinates for Point 1 (x y): ";
    std::cin >> x >> y;
    Point<double> newP1(x, y);
    triangle.setVertex1(newP1);

    std::cout << "Enter new coordinates for Point 2 (x y): ";
    std::cin >> x >> y;
    Point<double> newP2(x, y);
    triangle.setVertex2(newP2);

    std::cout << "Enter new coordinates for Point 3 (x y): ";
    std::cin >> x >> y;
    Point<double> newP3(x, y);
    triangle.setVertex3(newP3);

    std::cout << "Triangle Perimeter (After changing vertices): " << triangle.getPerimeter() << std::endl;
    std::cout << "Triangle Area (After changing vertices): " << triangle.getArea() << std::endl;
    std::cout << "Triangle Type (After changing vertices): " << triangle.getType() << std::endl;

    return 0;
}