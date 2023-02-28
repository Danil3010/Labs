#include <string>

using namespace std;

class MyString {
private:
    string str; // Значення рядка
public:
    MyString(); // Конструктор за замовчуванням
    MyString( int* s); // Конструктор зі значенням C-style рядка
    MyString( string& s); // Конструктор зі значенням рядка типу string
    MyString( MyString& other); // Конструктор копіювання

    bool Check() ; // Перевірка елементів
    int length() ; // Метод обчислення довжини рядка
    int length2() ; // Метод обчислення довжини рядка після видалення
    void removeFive(); // Метод видалення символу '5'
    void print(); // Метод виведення рядка на екран
    void Add(string a);// Метод додавання символу
};
