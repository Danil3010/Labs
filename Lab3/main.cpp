#include "MyString.h"
#include <iostream>

int main() {

	bool run_again = true;

    while (run_again) {
        std::string input;
        std::cout << "Enter a string of numeric values: ";
        std::cin >> input;

        MyString s(input);

        if (!s.Check()) {
            std::cout << "Error: string contains non-digit characters." << std::endl << std::endl;
            continue;
        }

        std::cout << "Original string: ";
        s.print();
        std::cout << "Length of string: " << s.length() << std::endl;

        s.removeFive();
        std::cout << "String after removing 5: ";
        s.print();
        std::cout << "Length of string after removing 5: " << s.length() << std::endl;

        s.length2();
        std::cout << std::endl;

        std::cout << "String after doubling: ";
        s * 2;
        s.print();

        MyString str("Hello");
        MyString repeated_str = str * 3;
        std::cout << "String after tripling: ";
        repeated_str.print();

        MyString result3 = s + s;
        std::cout << "String after concatenation: ";
        result3.print();

        std::string input1, input2;
        std::cout << "Enter the first string: ";
        std::cin >> input1;
        std::cout << "Enter the second string: ";
        std::cin >> input2;

        MyString str1(input1);
        MyString str2(input2);

        std::cout << std::endl;

        if (str1 != str2) {
            std::cout << "The two strings are not equal" << std::endl;
        }
        else {
            std::cout << "The two strings are equal" << std::endl;
        }

        std::cout << std::endl;

        s++; // apply overloaded operator "++"
        std::cout << "String after increment: ";
        s.print(); // print "Hello5"

        std::string input6;
        std::cout << "Enter the string: ";
        std::cin >> input6;

        MyString str6(input6);

        std::cout << std::endl;

        if (!str6) {
            std::cout << "The string does not contain uppercase letters\n";
        }
        else {
            std::cout << "The string contains uppercase letters\n";
        }

        std::cout << std::endl;

        std::string answer;
        std::cout << "Continue? (Yes/No): ";
        std::cin >> answer;
        std::cout << std::endl;

        if (answer == "No") {
            run_again = false;
        }
    }
    return 0;
}