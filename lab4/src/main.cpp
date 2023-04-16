/*
Базовый класс:
ЧЕЛОВЕК (PERSON)
Имя (name) – string
Возраст (age) – int

Определить методы изменения полей.

Создать производный класс STUDENT, имеющий поля Предмет – string и Оценка – int.
Определить методы изменения полей и метод, выдающий сообщение о неуд. оценке.
*/

#include <iostream>

#include "person.hpp"
#include "student.hpp"

using namespace std;

void f1(Person &person)
{
    person.set_age(99);
    cout << person << endl; // <<
}

Person f2()
{
    Student student("Student", 19, "Math", 2);
    return student;
}

int main()
{
    Person p1 = make_person(); // =
    cout << p1 << endl;        // <<

    Person p2;          // empty
    cin >> p2;          // >>
    cout << p2 << endl; // <<

    Person p3 = p1;     // =
    cout << p3 << endl; // <<

    Student s1 = make_student(); // =
    cout << s1 << endl;          // <<

    Student s2;         // empty
    cin >> s2;          // >>
    cout << s2 << endl; // <<

    Student s3 = s1;    // =
    cout << s3 << endl; // <<

    f1(s3);

    // принцип подстановки (фигня бесполезная, студента обрезали)
    p2 = f2();          // =
    cout << p2 << endl; // <<

    // сообщение о плохой оценке
    s3.bad_rating();

    return 0;
}