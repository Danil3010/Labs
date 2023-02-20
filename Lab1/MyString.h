#include <string>

using namespace std;

class MyString {
private:
    string str; // Значення рядка

public:
    MyString(string s); // Конструктор з параметрами
    bool Check();//Перевірка елементів
    int length(); // Метод обчислення довжини рядка
    int length2(); // Метод обчислення довжини рядка після видалення
    void removeFive(); // Метод видалення символу '5'
    void print(); // Метод виведення рядка на екран
};

