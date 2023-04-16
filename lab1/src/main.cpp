/*
Элемент арифметической прогрессии aj вычисляется по формуле: aj=a0·r^j.Поле first – дробное число,
первый элемент прогрессии a0, поле second – положительное целое число, постоянное отношение r.
Реализовать метод element(int j) –вычисление j-го элемента прогрессии.
*/

#include <iostream>

#include "progression.hpp"

using namespace std;

int main()
{
  Progression p1 = Progression();
  p1.read();
  p1.show();
  cout << p1.element(6) << endl;

  Progression *p2 = new Progression(1, 5);
  p2->show();
  cout << p2->element(3) << endl;

  Progression p3 = make_progression(.5, 3);
  p3.show();
  cout << p3.element(4) << endl;

  return 0;
}