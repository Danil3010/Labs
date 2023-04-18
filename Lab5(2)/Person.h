#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual ~Person() {}
    virtual void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class ArticleAuthor : public Person {
protected:
    int numArticles;
public:
    ArticleAuthor(string n, int a, int num) : Person(n, a), numArticles(num) {}
    double calculateSalary(int numChars) {
        return numChars * 0.01 * numArticles;
    }
    void printInfo() override {
        cout << "Article Author" << endl;
        Person::printInfo();
        cout << "Number of Articles: " << numArticles << endl;
    }
};

class Scientist : public Person {
protected:
    string position;
    double salaryRate;
    int experience;
    vector<string> researchGroups;
    vector<int> workHours;
public:
    Scientist(string n, int a, string pos, double rate, int hours, int exp) :
        Person(n, a), position(pos), salaryRate(rate), experience(exp) {}


    double calculateSalary(int hours, int years) {
        double positionRate = Position(position);
        return (salaryRate * hours / years) * positionRate;
    }

    double Position(string position) {
        if (position == "High") {
            return 1.5;
        }
        else if (position == "Middle") {
            return 1.0;
        }
        else if (position == "Low") {
            return 0.5;
        }
        else {
            return 0.0;
        }
    }

    void addResearchGroup(string group, int hours) {
        researchGroups.push_back(group);
        workHours.push_back(hours);
    }

    bool removeResearchGroup(string groupName) {
        auto it = find(researchGroups.begin(), researchGroups.end(), groupName);
        if (it != researchGroups.end()) {
            researchGroups.erase(it);
            return true;
        }
        return false;
    }

    void setWorkHours(string group, int hours) {
        for (int i = 0; i < researchGroups.size(); i++) {
            if (researchGroups[i] == group) {
                workHours[i] = hours;
                break;
            }
        }
    }
    int getWorkHours(string group) {
        for (int i = 0; i < researchGroups.size(); i++) {
            if (researchGroups[i] == group) {
                return workHours[i];
            }
        }
        return -1;
    }
    vector<string> getResearchGroups() {
        return researchGroups;
    }
    void printInfo() override {
        cout << "Scientist" << endl;
        Person::printInfo();
        cout << "Position: " << position << endl;
        cout << "Salary Rate: " << salaryRate << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Research Groups: " << endl;
        for (string group : researchGroups) {
            cout << "- " << group << endl;
        }
    }
};