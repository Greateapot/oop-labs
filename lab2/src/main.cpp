/*
Пользовательский класс ЗАРПЛАТА
ФИО – string
Оклад – double
Премия (% от оклада) – int
*/

#include <iostream>

#include "salary.hpp"

using namespace std;

void print_salary(Salary s)
{
  s.print(); // костыль же
}

int main()
{
  // empty
  Salary s1;
  s1.print();

  // params
  Salary s2("F I O", 13546, 24);
  s2.print();

  // copy 1
  Salary s3 = s2;
  s3.set_fio("O I F");
  s3.set_salary(153561);
  s3.set_award_percent(12);

  // copy 2
  print_salary(s3);
  
  // copy 3
  s1 = make_salary();
  s1.print();

  return 0;
}
