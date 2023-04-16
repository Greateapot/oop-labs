#include "test.hpp"

#include <iostream>

#include "list.hpp"
#include "../error.hpp"

using namespace std;

void list_test()
{
     cout << "LIST TEST: " << endl
          << endl;

     cout << "Test List.recursive_insert: " << endl;
     test_list_recursive_insert();
     cout << endl;

     cout << "Test List.recursive_remove: " << endl;
     test_list_recursive_remove();
     cout << endl;

     cout << "Test List [] op: " << endl;
     test_list_operator();
     cout << endl;

     cout << "LIST TEST END." << endl
          << endl;
}

// 1
void test_list_recursive_insert()
{
     auto *list = new List<int>();

     for (int i = 0; i < LIST_MAX_SIZE; i++)
          list->push_back(new Node<int>(i));

     cout << "Filled list: ";
     list->print();
     cout << endl;

     auto *t = new Node<int>(99);

     try
     {
          cout << "Trying to add 1 more node to list..." << endl;
          list->recursive_insert(t, 10);
     }
     catch (const int &v)
     {
          cout << "Error!" << endl;
     }

     delete t, list;
}

// 3
void test_list_recursive_remove()
{
     List<int> *list = new List<int>();

     cout << "Empty list: ";
     list->print();
     cout << endl;

     try
     {
          cout << "Trying to remove 1 node from list..." << endl;
          list->recursive_remove(1);
     }
     catch (const EmptySizeError &e)
     {
          cout << e.what() << endl;
     }

     delete list;
}

// 2
void test_list_operator()
{
     List<int> *list = new List<int>();

     cout << "Empty list: ";
     list->print();
     cout << endl;

     try
     {
          cout << "Trying to get 1 node with index -1 from list..." << endl;
          auto _ = (*list)[-1];
     }
     catch (const logic_error &e)
     {
          cout << e.what() << endl;
     }

     delete list;
}
