#include <iostream>
#include <random>
#include <ctime>

// STL
#include <algorithm>
#include <list>  // list
#include <queue> // priority_queue
#include <map>   // map

#include "pair/pair.hpp"

using namespace std;

const size_t kSize = 10;

template <class T>
void print(list<T> &ls)
{
  for (T v : ls)
    cout << v << ",";
  cout << endl;
}

template <class T>
void print(priority_queue<T> &pq)
{
  priority_queue<T> temp;
  while (!pq.empty())
  {
    cout << pq.top() << ", ";
    temp.push(pq.top());
    pq.pop();
  }

  cout << endl;

  while (!temp.empty())
  {
    pq.push(pq.top());
    temp.pop();
  }
}

template <class K, class V>
void print(map<K, V> &m)
{
  for (const pair<const K, V> &x : m)
    cout << x.first << " : " << x.second << ",";
  cout << endl;
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
list<T> Q2L(priority_queue<T> &pq)
{
  priority_queue<T> pqCopy = _Q_copy(pq);
  list<T> ls = list<T>();
  while (!pqCopy.empty())
  {
    ls.push_back(pqCopy.top());
    pqCopy.pop();
  }
  return ls;
}

template <typename T>
priority_queue<T> L2Q(list<T> &ls)
{
  priority_queue<T> pq = priority_queue<T>();
  for (T v : ls)
    pq.push(v);

  return pq;
}

void ex1()
{
  list<Pair> ls;

  // init
  {
    for (int i = 0; i < kSize; i++)
    {
      const int v = rand() % 1000000;
      ls.push_back(Pair(v / 1000, v % 1000 * 0.001));
    }

    print(ls);
  }

  // 1
  {
    const Pair sum = accumulate(ls.begin(), ls.end(), Pair());
    const Pair avg = Pair(
        sum.get_a() / ls.size(),
        sum.get_b() / (double)ls.size());

    cout << "Sum: " << sum << "; Avg: " << avg << ';' << endl;

    ls.push_back(avg);
    print(ls);
  }

  // 2
  {
    Pair a, b;
    cout << "A:" << endl, cin >> a;
    cout << "B:" << endl, cin >> b;

    remove_if(ls.begin(), ls.end(), [&a, &b](Pair &p)
              { return (p >= a && p <= b); });

    print(ls);
  }

  // 3
  {
    Pair min = *min_element(ls.begin(), ls.end());
    Pair max = *max_element(ls.begin(), ls.end());
    const Pair sum = min + max;

    cout << "Sum: " << sum << endl;

    for_each(ls.begin(), ls.end(), [&sum](Pair &p)
             { p += sum; });

    print(ls);
  }
}

void ex2()
{
  priority_queue<Pair> pq;

  // init
  {
    for (int i = 0; i < kSize; i++)
    {
      const int v = rand() % 1000000;
      pq.push(Pair(v / 1000, v % 1000 * 0.001));
    }

    print(pq);
  }

  // 1
  {
    list<Pair> ls = Q2L(pq);
    const Pair sum = accumulate(ls.begin(), ls.end(), Pair());
    const Pair avg = Pair(
        sum.get_a() / ls.size(),
        sum.get_b() / (double)ls.size());

    cout << "Sum: " << sum << "; Avg: " << avg << ';' << endl;

    ls.push_back(avg);

    pq = L2Q(ls);
    print(pq);
  }

  // 2
  {
    list<Pair> ls = Q2L(pq);
    Pair a, b;
    cout << "A:" << endl, cin >> a;
    cout << "B:" << endl, cin >> b;

    remove_if(ls.begin(), ls.end(), [&a, &b](Pair &p)
              { return (p >= a && p <= b); });

    pq = L2Q(ls);
    print(pq);
  }

  // 3
  {
    list<Pair> ls = Q2L(pq);
    Pair min = *min_element(ls.begin(), ls.end());
    Pair max = *max_element(ls.begin(), ls.end());
    const Pair sum = min + max;

    cout << "Sum: " << sum << endl;

    for_each(ls.begin(), ls.end(), [&sum](Pair &p)
             { p += sum; });

    pq = L2Q(ls);
    print(pq);
  }
}

void ex3()
{
  map<int, Pair> m;

  // init
  {
    for (int i = 0; i < kSize; i++)
    {
      const int v = rand() % 1000000;
      m[i] = (Pair(v / 1000, v % 1000 * 0.001));
    }

    print(m);
  }

  // 1
  {
    Pair sum;
    for (const pair<const int, Pair> &x : m)
      sum += x.second;
    const Pair avg = Pair(
        sum.get_a() / m.size(),
        sum.get_b() / (double)m.size());

    cout << "Sum: " << sum << "; Avg: " << avg << ';' << endl;

    m[m.size()] = avg;
    print(m);
  }

  // // 2
  {
    Pair a, b;
    cout << "A:" << endl, cin >> a;
    cout << "B:" << endl, cin >> b;

    for (pair<const int, Pair> &x : m)
      if (x.second >= a && x.second <= b)
        m.erase(x.first);

    print(m);
  }

  // 3
  {
    Pair min = (*min_element(m.begin(), m.end())).second;
    Pair max = (*max_element(m.begin(), m.end())).second;
    const Pair sum = min + max;

    cout << "Sum: " << sum << endl;

    for_each(m.begin(), m.end(), [&sum](pair<const int, Pair> &x)
             { x.second += sum; });

    print(m);
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