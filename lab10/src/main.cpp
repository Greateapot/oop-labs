#include <iostream>
#include <ctime>

#include "options/options.hpp"
#include "pair/pair.hpp"
#include "consts.hpp"
#include "list.hpp"

using namespace std;

int main()
{
  srand((int)time(0));

  List<Pair> *list = new List<Pair>();

  bool stop = 0;
  cout << MENU;
  do
  {
    stop = process(list);
  } while (!stop);
  delete list;
  return 0;
}
