#include "Person.h"

int main() {
	string name;
	int age;
	int yearsOfExperience;
	string position;
	double hourlyRate;
	int hoursWorked;
	int numberOfGroups;
	// Getting input for ArticleAuthor

	cout << "Enter name of the article author: ";
	getline(cin, name);
	cout << "Enter age of the article author: ";
	cin >> age;
	cout << "Enter years of experience of the article author: ";
	cin >> yearsOfExperience;

	ArticleAuthor author(name, age, yearsOfExperience);
	int numChars;
	cout << "Enter number of characters in the article: ";
	cin >> numChars;
	double salary = author.calculateSalary(numChars);
	cout << "Author's salary: " << salary << endl;

	// Getting input for Scientist
	cin.ignore();
	
	cout << "\nEnter name of the scientist: ";
	getline(cin, name);
	cout << "Enter age of the scientist: ";
	cin >> age;
	cin.ignore();
	cout << "Enter position of the scientist: ";
	getline(cin, position);
	cout << "Enter hourly rate of the scientist: ";
	cin >> hourlyRate;
	cout << "Enter hours worked by the scientist: ";
	cin >> hoursWorked;
	cout << "Enter years of experience of the scientist: ";
	cin >> yearsOfExperience;

	Scientist scientist(name, age, position, hourlyRate, hoursWorked, yearsOfExperience);
	cout << "Scientist's salary: " << scientist.calculateSalary(hoursWorked, yearsOfExperience) << endl;

	// Adding research groups
	cout << "\nHow many research groups does the scientist work with? ";
cin >> numberOfGroups;
cin.ignore();

int hours1;
for (int i = 0; i < numberOfGroups; i++) {
    string groupName;
    
    cout << "Enter name of research group " << i + 1 << ": ";
    getline(cin, groupName);
    cout << "Enter hours of work for group " << groupName << ": ";
    cin >> hours1;
    cin.ignore();

    scientist.addResearchGroup(groupName, hours1);
}

// Displaying work hours for each project before deletion
cout << "Research groups before to be deleted:\n";
vector<string> groups1 = scientist.getResearchGroups();

for (string group : groups1) {
	int hours = scientist.getWorkHours(group);
	cout << "Group " << group << ": " << hours << " hours\n";
}

// Deleting research group
cout << "\nEnter the name of the research group to be deleted: ";
string groupName;
getline(cin, groupName);
bool success = scientist.removeResearchGroup(groupName);
if (success) {
	cout << "Research group " << groupName << " deleted successfully.\n";
}
else {
	cout << "Research group " << groupName << " not found.\n";
}

// Displaying work hours for each project after deletion
cout << "\n Research groups after deletion:\n";
vector<string> remainingGroups = scientist.getResearchGroups();
for (string group : remainingGroups) {
	int hours = scientist.getWorkHours(group);
	cout << "Group " << group << ": " << hours << " hours\n";
}
	return 0;
}