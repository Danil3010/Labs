#include "MyString.h"
#include <iostream>

int main() {

	bool run_again = true;

	while (run_again) {
	string a;
	cout << "Enter a string of numeric values: ";
	cin >> a;
	MyString s(a);
	if (!s.Check()) {
		cout << "Error: string contains non-digit characters." << endl;
		cout << "" << endl;
		continue;
	}
	cout << "Original string: ";
	s.print();
	cout << "Length of string: " << s.length() << endl;
	s.removeFive();
	cout << "String after removing 5: ";
	s.print();
	cout << "Length of string after removing 5: " << s.length() << endl;
	s.length2();

	cout << ""<< endl;

	cout << "Continue? (Yes/No): ";
	string answer;
	cin >> answer;
	cout << "" << endl;
		if (answer == "No") {
			run_again = false;
		}
	}
	return 0;
}
