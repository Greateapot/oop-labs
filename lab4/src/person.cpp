#include "person.hpp"

#include <iostream>

using namespace std;

Person::Person()
{
    this->name = "";
    this->age = 0;
}
Person::Person(string name, int age) : name(name), age(age) {}
Person::Person(const Person &other) : name(other.name), age(other.age) {}
Person::~Person() {}

void Person::set_name(string name)
{
    this->name = name;
}
string Person::get_name()
{
    return this->name;
}

void Person::set_age(int age)
{
    this->age = age;
}
int Person::get_age()
{
    return this->age;
}

Person &Person::operator=(const Person &other)
{
    this->name = other.name;
    this->age = other.age;
    return *this;
}

ostream &operator<<(ostream &out, const Person &person)
{
    return (out << "Person(\"" << person.name << "\", " << person.age << ")");
}

istream &operator>>(istream &in, Person &person)
{
    in.sync();
    // cout может не оказаться
    cout << "Input person name: ";
    getline(in, person.name, '\n');

    cout << "Input person age: ";
    in >> person.age;

    return in;
}

Person make_person()
{
    cin.sync();
    
    string name;
    int age;

    cout << "Input person name: ";
    getline(cin, name, '\n');

    cout << "Input person age: ";
    cin >> age;

    return Person(name, age);
}