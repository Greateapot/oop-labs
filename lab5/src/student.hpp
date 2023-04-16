#pragma once
#include <iostream>
#include "person.hpp"

using namespace std;

class Student : public Person
{
protected:
    string subject;
    int rating;

public:
    Student();
    Student(string, int, string, int);
    Student(const Student &);
    ~Student();

    void set_subject(string);
    string get_subject();

    void set_rating(int);
    int get_rating();

    Student &operator=(const Student &);
    friend istream &operator>>(istream &, Student &);
    friend ostream &operator<<(ostream &, const Student &);

    // метод, выдающий сообщение о неуд. оценке.
    void bad_rating();

    void print();
};

Student make_student();
