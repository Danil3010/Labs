#include "MyString.h"
#include <iostream>

int main() {
    bool run_again = true;
    while (run_again) {
        cout << "Enter a string of numeric values: ";
        string input;
        cin >> input;

        MyString s1;
        MyString s2(input);
        MyString s3(s2);
        MyString s6 = s3;
        char arr[4];

        if (!s3.Check()) {
            cout << "Error: string contains non-digit characters." << endl;
            cout << "" << endl;
            continue;
        }
        cout << "Original string: ";
        s6.print();
        cout << "Length of string: " << s3.length() << endl;
        s3.removeFive();
        cout << "String after removing 5: ";
        s3.print();
        cout << "Length of string after removing 5: " << s3.length() << endl;
        s3.length2();
        cout << "" << endl;
        
        arr[0] = input.at(0);
        arr[1] = input.at(1);
        for (int i = 0; i < 2; i++) {
            arr[3 - i] = arr[i];
        }

        cout << "Array:";
        for (int i = 0; i < 4; i++) {
            arr[i];
            cout << arr[i] << " ";
        }
        cout << "" << endl;
        
        cout << "Do you want to add a character to a string? (Yes / No):" << endl;
        string answer1;
        cin >> answer1;
        cout << "" << endl;
        if (answer1 == "Yes") {
            cout << "Enter an additional character:" << endl;
            string add;
            cin >> add;
            s3.Add(add);
            s3.print();
        }
        else if(answer1 == "No") {
            goto contin;// продовжуємо виконання циклу
        }
        contin:// продовжуємо виконання циклу

        cout << "Continue? (Yes/No): ";
        string answer2;
        cin >> answer2;
        cout << "" << endl;
        if (answer2 == "No") {
            run_again = false;
        }
    }
    return 0;
}