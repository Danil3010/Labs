#include "MyString.h"
#include <iostream>

MyString::MyString(string s) {
    str = s;
}

bool MyString::Check() {

    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int MyString::length() {
    return str.length();
}

void MyString::removeFive() {
    size_t pos = str.find("5");
    while (pos != string::npos) {
        str.erase(pos, 1);
        pos = str.find("5");
    }
}

int MyString::length2() {
    return str.length();
}

void MyString::print() {
    cout << str << endl;
}

MyString MyString::operator+(const MyString& other) const{
    MyString result = *this;
    result.str += other.str;
    return result;
}

bool MyString::operator!=(const MyString& other)
{
    return str != other.str;
}

MyString MyString::operator++(int)
{
    MyString temp = *this;
    str += "5";
    return temp;
}

bool MyString::operator!() const
{
    for (char c : str) {
        if (isupper(c)) { // перевірка на верхній регістр
            return false;
        }
    }
    return true;
}

MyString& MyString::operator*(const int n)
{
    if (n <= 0) {
        return *this;
    }
    string newStr = "";
    int len = str.length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len && j < n; j++) {
            newStr += str[j];
        }
    }
    str += newStr;
    return *this;
}

MyString MyString::operator*(const int n) const
{
    string repeated_str;
    for (int i = 0; i < n; i++) {
        repeated_str += str;
    }
    return MyString(repeated_str);
}



