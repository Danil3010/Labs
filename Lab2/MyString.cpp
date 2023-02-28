#include "MyString.h"
#include <iostream>

MyString::MyString() : str("") {}
MyString::MyString( int* s) {}
MyString::MyString( string& s) : str(s) {}
MyString::MyString(MyString& other) : str(other.str) {}
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
void MyString::Add(string add){
    str += add;
}

