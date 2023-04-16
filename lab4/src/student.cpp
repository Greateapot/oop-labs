#include "student.hpp"

#include <iostream>

using namespace std;

Student::Student() : Person()
{
    this->subject = "";
    this->rating = 0;
}

Student::Student(string name, int age, string subject, int rating) : Person(name, age), subject(subject), rating(rating) {}
Student::Student(const Student &other) : Person(other.name, other.age), subject(other.subject), rating(other.rating) {}
Student::~Student() {}

void Student::set_subject(string subject)
{
    this->subject = subject;
}
string Student::get_subject()
{
    return this->subject;
}

void Student::set_rating(int rating)
{
    this->rating = rating;
}
int Student::get_rating()
{
    return this->rating;
}

Student &Student::operator=(const Student &other)
{
    this->name = other.name;
    this->age = other.age;
    this->subject = other.subject;
    this->rating = other.rating;
    return *this;
}

ostream &operator<<(ostream &out, const Student &student)
{
    return (out << "Student(\"" << student.name
                << "\", " << student.age
                << ", \"" << student.subject
                << "\", " << student.rating
                << ")");
}

istream &operator>>(istream &in, Student &student)
{
    in.sync();

    // cout может не оказаться
    cout << "Input student name: ";
    getline(in, student.name, '\n');

    cout << "Input student age: ";
    in >> student.age;

    in.sync();

    cout << "Input student subject: ";
    getline(in, student.subject, '\n');

    cout << "Input student rating: ";
    in >> student.rating;

    return in;
}

// не сказано как именно определить
void Student::bad_rating()
{
    cout << "Student has bad rating: " << this->rating << '!' << endl;
}

Student make_student()
{
    cin.sync();

    string name, subject;
    int age, rating;

    cout << "Input student name: ";
    getline(cin, name, '\n');

    cout << "Input student age: ";
    cin >> age;

    cin.sync();

    cout << "Input student subject: ";
    getline(cin, subject, '\n');

    cout << "Input student rating: ";
    cin >> rating;

    return Student(name, age, subject, rating);
}