#include <iostream>
#include <random>
#include <ctime>
#include <set>

#include "pair/pair.hpp"
#include "list.hpp"

using namespace std;

const size_t kSize = 10;

template <typename T>
List<T> MS2L(multiset<T> &ms)
{
  List<T> L = List<T>();
  for (auto it = ms.begin(); it != ms.end(); it++)
    L.push_back(new Node<T>(*it));
  return L;
}

template <typename T>
multiset<T> L2MS(List<T> &L)
{
  multiset<T> ms = multiset<T>();
  for (Iterator<T> it = L.first(); it != L.last(); it++)
    ms.insert((*it).get_key());
  return ms;
}

template <class T>
void print(multiset<T> &ms)
{
  for (T v : ms)
    cout << v << ", ";
  cout << endl;
}

void ex1()
{
  multiset<double> ms;

  for (int i = 0; i < kSize; i++)
    ms.insert(rand() % 10000 * .001);

  print(ms);

  // 1
  {
    double sum = 0;
    for (double v : ms)
      sum += v;

    const double avg = sum / (double)(ms.size());

    cout << "Sum: " << sum << "Avg: " << avg << endl;

    ms.insert(avg);

    print(ms);
  }

  // 2
  {
    multiset<double> temp;
    double a, b;

    cout << "A: ";
    cin >> a;

    cout << "B: ";
    cin >> b;

    for (double v : ms)
      if (v < a || v > b)
        temp.insert(v);

    ms.clear();

    for (double v : temp)
      ms.insert(v);

    print(ms);
  }

  // 3
  {
    double min = *(ms.begin()), max = min;
    bool first = 1;
    multiset<double> temp;

    for (double v : ms)
    {
      temp.insert(v);
      if (first)
        first = 0;
      else if (v < min)
        min = v;
      else if (v > max)
        max = v;
    }

    const double sum = max + min;

    cout << "Sum: " << sum << endl;

    ms.clear();

    for (double v : temp)
      ms.insert(v + sum);

    print(ms);
  }
}

void ex2()
{
  multiset<Pair> ms;

  for (int i = 0; i < kSize; i++)
  {
    const int v = rand() % 1000000;
    ms.insert(Pair(v / 1000, v % 1000 * 0.001));
  }

  print(ms);

  // 1
  {
    Pair sum;
    for (Pair v : ms)
      sum += v;

    ms.insert(Pair(sum.get_a() / ms.size(), sum.get_b() / (double)ms.size()));

    print(ms);
  }

  // 2
  {
    multiset<Pair> temp;
    Pair a, b;

    cout << "A: ";
    cin >> a;

    cout << "B: ";
    cin >> b;

    for (Pair v : ms)
      if (v < a || v > b)
        temp.insert(v);

    ms.clear();

    for (Pair v : temp)
      ms.insert(v);

    print(ms);
  }

  // 3
  {
    Pair min = *(ms.begin()), max = min;
    bool first = 1;
    multiset<Pair> temp;

    for (Pair v : ms)
    {
      temp.insert(v);
      if (first)
        first = 0;
      else if (v < min)
        min = v;
      else if (v > max)
        max = v;
    }

    const Pair sum = max + min;

    cout << "Sum: " << sum << endl;

    ms.clear();

    for (Pair v : temp)
      ms.insert(v + sum);

    print(ms);
  }
}

void ex3()
{
  multiset<Pair> ms;

  {
    List<Pair> ls = MS2L(ms);
    for (int i = 0; i < kSize; i++)
    {
      const int v = rand() % 1000000;
      ls.push_back(new Node<Pair>(Pair(v / 1000, v % 1000 * 0.001)));
    }

    ls.print();
    ms = L2MS(ls);
  }

  // 1
  {
    List<Pair> ls = MS2L(ms);
    Pair sum;
    for (Iterator<Pair> it = ls.first(); it != ls.last(); it++)
      sum += (*it).get_key();

    ls.push_back(new Node<Pair>(Pair(sum.get_a() / ls.get_size(), sum.get_b() / (double)ls.get_size())));
    ls.print();
    ms = L2MS(ls);
  }

  // 2
  {
    List<Pair> ls = MS2L(ms);
    Pair a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    for (Iterator<Pair> it = ls.first(); it != ls.last(); it++)
    {
      Pair e = (*it).get_key();
      if (e < a || e > b)
        ls.queue_remove(e);
    }

    ls.print();
    ms = L2MS(ls);
  }

  // 3
  {
    List<Pair> ls = MS2L(ms);
    bool first = 1;
    Pair min = (*(ls.first())).get_key(), max = min;
    for (Iterator<Pair> it = ls.first(); it != ls.last(); it++)
    {
      Pair e = (*it).get_key();

      if (!first)
      {
        if (e < min)
          min = e;
        else if (e > max)
          max = e;
      }
      else
        first = 0;
    }

    const Pair sum = min + max;
    cout << "Sum: " << sum << endl;

    for (Iterator<Pair> it = ls.first(); it != ls.last(); it++)
      (*it).set_key((*it).get_key() + sum);

    ls.print();
    ms = L2MS(ls);
  }
}

int main()
{
  srand((int)time(0));
  ex1();
  ex2();
  ex3();
  return 0;
}