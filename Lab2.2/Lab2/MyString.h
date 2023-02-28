#include <string>

using namespace std;

class MyString {
private:
    string str; // �������� �����
public:
    MyString(); // ����������� �� �������������
    MyString( int* s); // ����������� � ��������� C-style �����
    MyString( string& s); // ����������� � ��������� ����� ���� string
    MyString( MyString& other); // ����������� ���������

    bool Check() ; // �������� ��������
    int length() ; // ����� ���������� ������� �����
    int length2() ; // ����� ���������� ������� ����� ���� ���������
    void removeFive(); // ����� ��������� ������� '5'
    void print(); // ����� ��������� ����� �� �����
    void Add(string a);// ����� ��������� �������
};
