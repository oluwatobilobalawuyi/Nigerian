#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Nigerian class (inherits from Person)
class Nigerian : public Person {
private:
    string tribe;
public:
    Nigerian(string n, int a, string t) : Person(n, a), tribe(t) {}
    void printDetails() override {
        cout << "--- Nigerian Details ---" << endl;
        Person::printDetails();
        cout << "Tribe: " << tribe << endl;
    }
};

// Foreigner class (inherits from Person)
class Foreigner : public Person {
private:
    bool passport;
public:
    Foreigner(string n, int a, bool p) : Person(n, a), passport(p) {}
    void printDetails() override {
        cout << "--- Foreigner Details ---" << endl;
        Person::printDetails();
        if (passport)
            cout << "Has passport" << endl;
        else
            cout << "Does not have passport" << endl;
    }
};

// main function
int main() {
    Person* people[4];

    people[0] = new Nigerian("John Doe", 25, "Yoruba");
    people[1] = new Foreigner("Jane Smith", 30, true);
    people[2] = new Nigerian("Ali Baba", 35, "Hausa");
    people[3] = new Person("Tom Smith", 40);

    for (int i = 0; i < 4; i++) {
        people[i]->printDetails(); // polymorphic function call
        cout << endl;
    }

    // free memory
    for (int i = 0; i < 4; i++) {
        delete people[i];
    }
    return 0;
}
