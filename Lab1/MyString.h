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
};

