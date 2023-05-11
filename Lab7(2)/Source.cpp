#include <iostream>

template<typename T>
class Point {
private:
    T x;
    T y;

public:
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}

    void setX(T x) {
        this->x = x;
    }

    void setY(T y) {
        this->y = y;
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }
};

template<typename T>
class Rectangle {
private:
    Point<T> p1, p2, p3, p4, intersectionPoint;
    T side1, side2;

public:
    Rectangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
        // ��������, ��� ���������� ����� �������� ����������� ���������
        T dx1 = p2.getX() - p1.getX();
        T dx2 = p3.getX() - p1.getX();
        T dy1 = p2.getY() - p1.getY();
        T dy2 = p3.getY() - p1.getY();

        if ((dx1 * dx2 + dy1 * dy2) != 0) {
            std::cout << "�������: ������ ����� �� ��������� ����������� ���������." << std::endl;
            exit(1);
        }

        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;

        // ����������� ������ �����
        this->p4.setX(p2.getX() + p3.getX() - p1.getX());
        this->p4.setY(p2.getY() + p3.getY() - p1.getY());

        // ���������� ������� �����
        side1 = distance(p1, p2);
        side2 = distance(p1, p3);

        // ���������� ����� �������� ���������
        T intersectionX = (p1.getX() + p3.getX()) / 2;
        T intersectionY = (p1.getY() + p3.getY()) / 2;
        intersectionPoint.setX(intersectionX);
        intersectionPoint.setY(intersectionY);
    }

    T getSide1() const {
        return side1;
    }

    T getSide2() const {
        return side2;
    }

    T getPerimeter() const {
        return 2 * (side1 + side2);
    }

    T getArea() const {
        return side1 * side2;
    }

    void changeRectangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
        Rectangle<T> newRectangle(p1, p2, p3);
        *this = newRectangle;
    }

    static T distance(const Point<T>& p1, const Point<T>& p2) {
        T dx = p2.getX() - p1.getX();
        T dy = p2.getY() - p1.getY();
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main() {

    setlocale(LC_CTYPE, "ukr");

    // �������� ��������� ����� � ���������
    float x1, y1, x2, y2, x3, y3;
    std::cout << "������ ���������� ����� ����� (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "������ ���������� ����� ����� (x2, y2): ";
    std::cin >> x2 >> y2;
    std::cout << "������ ���������� ������ ����� (x3, y3): ";
    std::cin >> x3 >> y3;

    // ��������� ��'���� ����� Rectangle � ��������� �������
    Point<float> point1(x1, y1);
    Point<float> point2(x2, y2);
    Point<float> point3(x3, y3);

    Rectangle<float> rectangle(point1, point2, point3);

    // ��������� ����� ��� ��������� ��'���
    std::cout << "�����������:" << std::endl;
    std::cout << "������� 1: " << rectangle.getSide1() << std::endl;
    std::cout << "������� 2: " << rectangle.getSide2() << std::endl;
    std::cout << "��������: " << rectangle.getPerimeter() << std::endl;
    std::cout << "�����: " << rectangle.getArea() << std::endl;

    // ���� ������������ �� ������ ������������ �����
    float newX1, newY1, newX2, newY2, newX3, newY3;
    std::cout << "������ ��� ���������� ����� ����� (newX1, newY1): ";
    std::cin >> newX1 >> newY1;
    std::cout << "������ ��� ���������� ����� ����� (newX2, newY2): ";
    std::cin >> newX2 >> newY2;
    std::cout << "������ ��� ���������� ������ ����� (newX3, newY3): ";
    std::cin >> newX3 >> newY3;

    Point<float> newPoint1(newX1, newY1);
    Point<float> newPoint2(newX2, newY2);
    Point<float> newPoint3(newX3, newY3);

    rectangle.changeRectangle(newPoint1, newPoint2, newPoint3);

    // ��������� ����� ��� ������� �����������
    std::cout << "������� �����������:" << std::endl;
    std::cout << "������� 1: " << rectangle.getSide1() << std::endl;
    std::cout << "������� 2: " << rectangle.getSide2() << std::endl;
    std::cout << "��������: " << rectangle.getPerimeter() << std::endl;
    std::cout << "�����: " << rectangle.getArea() << std::endl;

    return 0;
}