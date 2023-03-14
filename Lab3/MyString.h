#include <string>

using namespace std;

class MyString {
private:
    string str; // �������� �����

public:
    MyString(string s); // ����������� � �����������
    bool Check();//�������� ��������
    int length(); // ����� ���������� ������� �����
    int length2(); // ����� ���������� ������� ����� ���� ���������
    void removeFive(); // ����� ��������� ������� '5'
    void print(); // ����� ��������� ����� �� �����

    MyString operator+(const MyString& other) const;
    bool operator!=(const MyString& other);
    MyString operator++(int);
    bool operator!() const;
    MyString& operator*(const int n);
    MyString operator*(const int n) const;
};