#include "salary.hpp"

#include <iostream>

using namespace std;

Salary::Salary()
{
    this->fio = "";
    this->salary = .0;
    this->award_percent = 0;
}

Salary::Salary(string fio, double salary, int award_percent) : fio(fio), salary(salary), award_percent(award_percent) {}

Salary::Salary(Salary &other) : fio(other.fio), salary(other.salary), award_percent(other.award_percent) {}

Salary::~Salary() {}

void Salary::set_fio(string fio) { this->fio = fio; }
void Salary::set_salary(double salary) { this->salary = salary; }
void Salary::set_award_percent(int award_percent) { this->award_percent = award_percent; }

string Salary::get_fio() { return this->fio; }
double Salary::get_salary() { return this->salary; }
int Salary::get_award_percent() { return this->award_percent; }

void Salary::print()
{
    cout << "Salary: " << endl
         << "fio: " << this->fio << endl
         << "salary: " << this->salary << endl
         << "award_percent: " << this->award_percent << endl
         << endl;
}

Salary make_salary()
{
    Salary s;

    string fio;
    double salary;
    int award_percent;

    cout << "Input fio: ";
    getline(cin, fio, '\n');

    cout << "Input salary: ";
    cin >> salary;

    cout << "Input award percent: ";
    cin >> award_percent;

    s.set_fio(fio);
    s.set_salary(salary);
    s.set_award_percent(award_percent);

    return s;
}