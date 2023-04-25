#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include <queue>

#include "list.hpp"
#include "pair/pair.hpp"

using namespace std;

const size_t SIZE = 10;

template <class T>
void print(list<T> &ls)
{
  for (T v : ls)
    cout << v << ", ";
  cout << endl;
}

template <class T>
void print(priority_queue<T> &ls)
{
  priority_queue<T> temp;
  while (!ls.empty())
  {
    cout << ls.top() << ", ";
    temp.push(ls.top());
    ls.pop();
  }

  cout << endl;

  while (!temp.empty())
  {
    ls.push(ls.top());
    temp.pop();
  }
}

template <typename T>
priority_queue<T> _Q_copy(priority_queue<T> &queueIn)
{
  priority_queue<T> temp = priority_queue<T>();
  priority_queue<T> queueOut = priority_queue<T>();
  while (!queueIn.empty())
  {
    temp.push(queueIn.top());
    queueOut.push(queueIn.top());
    queueIn.pop();
  }
  while (!temp.empty())
  {
    queueIn.push(temp.top());
    temp.pop();
  }
  return queueOut;
}

template <typename T>
List<T> Q2L(priority_queue<T> &queue)
{
  priority_queue<T> queueCopy = _Q_copy(queue);
  List<T> L = List<T>();
  while (!queueCopy.empty())
  {
    L.push_back(new Node<T>(queueCopy.top()));
    queueCopy.pop();
  }
  return L;
}

template <typename T>
priority_queue<T> L2Q(List<T> &L)
{
  priority_queue<T> queue = priority_queue<T>();
  for (Iterator<T> it = L.first(); it != L.last(); it++)
    queue.push((*it).get_key());

  return queue;
}

void ex1()
{
  list<double> ls;

  for (int i = 0; i < SIZE; i++)
    ls.push_back(rand() % 1000);

  print(ls);

  // 1
  {
    double sum = 0;
    for (double e : ls)
      sum += e;

    ls.push_back(sum / ls.size());
    print(ls);
  }

  // 2
  {
    list<double> temp = ls;
    ls.clear();

    double a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    for (double e : temp)
      if (e < a || e > b)
        ls.push_back(e);

    print(ls);
  }

  // 3
  {
    bool first = 1;
    double min = *(ls.begin()), max = min;
    for (double e : ls)
      if (!first)
      {
        if (e < min)
          min = e;
        else if (e > max)
          max = e;
      }
      else
        first = 0;

    const double sum = min + max;
    cout << "Sum: " << sum << endl;

    for (double &e : ls)
      e += sum;

    print(ls);
  }
}

void ex2()
{
  list<Pair> ls;

  for (int i = 0; i < SIZE; i++)
  {
    const int v = rand() % 1000000;
    ls.push_back(Pair(v / 1000, v % 1000 * 0.001));
  }

  print(ls);

  // 1
  {
    Pair sum;
    for (Pair e : ls)
      sum += e;

    ls.push_back(Pair(sum.get_a() / ls.size(), sum.get_b() / (double)ls.size()));
    print(ls);
  }

  // 2
  {
    list<Pair> temp = ls;
    ls.clear();

    Pair a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    for (Pair e : temp)
      if (e < a || e > b)
        ls.push_back(e);

    print(ls);
  }

  // 3
  {
    bool first = 1;
    Pair min = *(ls.begin()), max = min;
    for (Pair e : ls)
      if (!first)
      {
        if (e < min)
          min = e;
        else if (e > max)
          max = e;
      }
      else
        first = 0;

    const Pair sum = min + max;
    cout << "Sum: " << sum << endl;

    for (Pair &e : ls)
      e += sum;

    print(ls);
  }
}

void ex3()
{
  List<Pair> *ls = new List<Pair>();

  for (int i = 0; i < SIZE; i++)
  {
    const int v = rand() % 1000000;
    ls->push_back(new Node<Pair>(Pair(v / 1000, v % 1000 * 0.001)));
  }

  ls->print();

  // 1
  {
    Pair sum;
    for (Iterator<Pair> it = ls->first(); it != ls->last(); it++)
      sum += (*it).get_key();

    ls->push_back(new Node<Pair>(Pair(sum.get_a() / ls->get_size(), sum.get_b() / (double)ls->get_size())));
    ls->print();
  }

  // 2
  {
    Pair a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    for (Iterator<Pair> it = ls->first(); it != ls->last(); it++)
    {
      Pair e = (*it).get_key();
      if (e < a || e > b)
        ls->queue_remove(e);
    }

    ls->print();
  }

  // 3
  {
    bool first = 1;
    Pair min = (*(ls->first())).get_key(), max = min;
    for (Iterator<Pair> it = ls->first(); it != ls->last(); it++)
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

    for (Iterator<Pair> it = ls->first(); it != ls->last(); it++)
      (*it).set_key((*it).get_key() + sum);

    ls->print();
  }
}

void ex4()
{
  priority_queue<Pair> ls;

  for (int i = 0; i < SIZE; i++)
  {
    const int v = rand() % 1000000;
    ls.push(Pair(v / 1000, v % 1000 * 0.001));
  }

  print(ls);

  // 1
  {
    priority_queue<Pair> temp;

    Pair sum;
    while (!ls.empty())
    {
      sum += ls.top();
      temp.push(ls.top());
      ls.pop();
    }

    while (!temp.empty())
    {
      ls.push(temp.top());
      temp.pop();
    }

    ls.push(Pair(sum.get_a() / ls.size(), sum.get_b() / (double)ls.size()));
    print(ls);
  }

  // 2
  {
    priority_queue<Pair> temp;

    Pair a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    while (!ls.empty())
    {
      if (Pair(ls.top()) < a || Pair(ls.top()) > b)
        temp.push(ls.top());
      ls.pop();
    }

    while (!temp.empty())
    {
      ls.push(temp.top());
      temp.pop();
    }

    print(ls);
  }

  // 3
  {

    priority_queue<Pair> temp;
    bool first = 1;
    Pair min = ls.top(), max = min;

    while (!ls.empty())
    {
      Pair e = ls.top();
      if (!first)
      {
        if (e < min)
          min = e;
        else if (e > max)
          max = e;
      }
      else
        first = 0;

      temp.push(e);
      ls.pop();
    }

    const Pair sum = min + max;
    cout << "Sum: " << sum << endl;

    while (!temp.empty())
    {
      ls.push(Pair(temp.top()) + sum);
      temp.pop();
    }

    print(ls);
  }
}

void ex5()
{
  priority_queue<Pair> pq;
  {
    List<Pair> ls = Q2L(pq);
    for (int i = 0; i < SIZE; i++)
    {
      const int v = rand() % 1000000;
      ls.push_back(new Node<Pair>(Pair(v / 1000, v % 1000 * 0.001)));
    }

    ls.print();
    pq = L2Q(ls);
  }

  // 1
  {
    List<Pair> ls = Q2L(pq);
    Pair sum;
    for (Iterator<Pair> it = ls.first(); it != ls.last(); it++)
      sum += (*it).get_key();

    ls.push_back(new Node<Pair>(Pair(sum.get_a() / ls.get_size(), sum.get_b() / (double)ls.get_size())));
    ls.print();
    pq = L2Q(ls);
  }

  // 2
  {
    List<Pair> ls = Q2L(pq);
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
    pq = L2Q(ls);
  }

  // 3
  {
    List<Pair> ls = Q2L(pq);
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
    pq = L2Q(ls);
  }
}

int main()
{
  srand((int)time(0));
  // ex1();
  // ex2();
  // ex3();
  // ex4();
  ex5();
  return 0;
}