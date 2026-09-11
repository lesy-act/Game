#include<iostream>
using namespace std;    

class Person {
    public:
        string name;
        int age;
        Person(string n, int a) {
            name = n;
            age = a;
        }
};

class Student : public Person {
    public:
        string school;
        Student(string n, int a, string s) : Person(n, a) {
            school = s;
        }
        void showInfo() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "School: " << school << endl;
        }
};

int main() {
    Student s("Alice", 20, "MIT");
    s.showInfo();
    return 0;
}