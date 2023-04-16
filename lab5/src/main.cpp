#include <iostream>

#include "object.hpp"
#include "person.hpp"
#include "student.hpp"
#include "Vector.hpp"

using namespace std;

int main()
{
    Vector v(3);
    cout << v << endl;
    Object* o;

    Person p = make_person();
    cout << p << endl;
    o = &p;
    v.add(o);

    Student s = make_student();
    cout << s << endl;
    o = &s;
    v.add(o);

    cout << v << endl;

    return 0;
}