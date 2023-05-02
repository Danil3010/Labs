#include <iostream>
#include <string>

using namespace std;

// ������� ���� "�����"
class Strings {
public:
    virtual int getLength() = 0; // ³�������� ������� ���������� ������� �����
    virtual void doubleString() = 0; // ³�������� ������� ��������� �����
};

// �������� ���� "�����"
class Digits : public Strings {
private:
    string value; // �������� �����
public:
    Digits(string val) {
        value = val;
    }

    int getLength() {
        return value.length();
    }

    void doubleString() {
        string newString = "";
        for (int i = 0; i < value.length(); i++) {
            newString += value[i];
            newString += value[i];
        }
        value = newString;
    }

    string getValue() {
        return value;
    }

    void setValue(string val) {
        value = val;
    }
};

// �������� ���� "�������"
class Symbols : public Strings {
private:
    string value; // �������� �����
public:
    Symbols(string val) {
        value = val;
    }

    int getLength() {
        return value.length();
    }

    void doubleString() {
        string newString = "";
        for (int i = 0; i < value.length(); i++) {
            if (value[i] == 'k') {
                newString += value[i];
            }
            newString += value[i];
        }
        value = newString;
    }

    string getValue() {
        return value;
    }

    void setValue(string val) {
        value = val;
    }
};

int main() {
    // ��������� ��'���� �����
    Strings* s1 = new Digits("12345");
    Strings* s2 = new Symbols("Hello, worldk!");

    // ������������ ����������� ��� ���������� ������� �� ��������� �����
    cout << "Length of s1: " << s1->getLength() << endl;
    s1->doubleString();
    cout << "New value of s1: " << dynamic_cast<Digits*>(s1)->getValue() << endl;

    cout << "Length of s2: " << s2->getLength() << endl;
    s2->doubleString();
    cout << "New value of s2: " << dynamic_cast<Symbols*>(s2)->getValue() << endl;

    delete s1;
    delete s2;

    return 0;
}
