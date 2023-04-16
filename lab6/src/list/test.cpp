#include "test.hpp"

#include <iostream>

#include "list.hpp"

using namespace std;

void list_test()
{
     cout << "LIST TEST: " << endl
          << endl;

     cout << "Test List.save_load: " << endl;
     test_list_save_load();
     cout << endl;

     cout << "Test List.recursive_insert: " << endl;
     test_list_recursive_insert();
     cout << endl;

     cout << "Test List.queue_insert: " << endl;
     test_list_queue_insert();
     cout << endl;

     cout << "Test List.recursive_insert with K nodes: " << endl;
     test_list_recursive_insert_K();
     cout << endl;

     cout << "Test List.queue_insert with K nodes: " << endl;
     test_list_queue_insert_K();
     cout << endl;

     cout << "Test List.recursive_remove: " << endl;
     test_list_recursive_remove();
     cout << endl;

     cout << "Test List.queue_remove: " << endl;
     test_list_queue_remove();
     cout << endl;

     cout << "Test List iterator and [] op: " << endl;
     test_list_iterator();
     cout << endl;

     cout << "Test lists multiplication: " << endl;
     test_list_multiplication();
     cout << endl;

     cout << "LIST TEST END." << endl
          << endl;
}

void test_list_save_load()
{
     const string filename = "lab6list.dat";

     Node<string> *A_e1 = new Node<string>("A_e11");
     Node<string> *A_e2 = new Node<string>("A_e22");
     Node<string> *A_e3 = new Node<string>("A_e33");
     List<string> *A = new List<string>();
     List<string> *B = new List<string>();

     A->push_back(A_e1);
     A->push_back(A_e2);
     A->push_back(A_e3);

     cout << "List A with " << A->get_size() << " nodes: ";
     A->print();
     cout << endl;

     cout << "Empty list B: ";
     B->print();
     cout << endl;

     cout << "Save list A to file (\"" << filename << "\"): " << A->save(filename) << endl;

     delete A;

     cout << "Load list B from file (\"" << filename << "\"): " << B->load(filename) << endl;

     cout << "List B with " << B->get_size() << " nodes: ";
     B->print();
     cout << endl;

     delete B;
}

void test_list_recursive_insert()
{
     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     Node<string> *e4 = new Node<string>("e44");
     Node<string> *e5 = new Node<string>("e55");
     Node<string> *e6 = new Node<string>("e66");
     List<string> *list = new List<string>();

     cout << "Empty list: ";
     list->print();
     cout << endl;

     cout << "Insert node to empty list with invalid (\"invalid key\") key: "
          << list->recursive_insert(e1, "invalid key") << endl;

     cout << "Empty list: ";
     list->print();
     cout << endl;

     cout << "Add 1 node after list.";
     list->push_back(e1);
     cout << endl;

     cout << "List with 1 node: ";
     list->print();
     cout << endl;

     cout << "Insert node to list with invalid (\"invalid key\") key: "
          << list->recursive_insert(e2, "invalid key") << endl;
     cout << "Insert node to list with valid (\"" << e1->get_key() << "\") key: "
          << list->recursive_insert(e2, e1->get_key()) << endl;

     cout << "List with 2 nodes: ";
     list->print();
     cout << endl;

     cout << "Add 1 node after list.";
     list->push_back(e3);
     cout << endl;

     cout << "List with 3 nodes: ";
     list->print();
     cout << endl;

     cout << "Add 1 node before list.";
     list->push_front(e4);
     cout << endl;

     cout << "List with 4 nodes: ";
     list->print();
     cout << endl;

     cout << "Insert node to list with valid (\"" << e3->get_key() << "\") key: "
          << list->recursive_insert(e5, e3->get_key()) << endl;

     cout << "List with 5 nodes: ";
     list->print();
     cout << endl;

     cout << "Insert node to list with valid (\"" << e4->get_key() << "\") key: "
          << list->recursive_insert(e6, e4->get_key()) << endl;

     cout << "List with 6 nodes: ";
     list->print();
     cout << endl;

     delete list;
}

void test_list_queue_insert()
{
     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     Node<string> *e4 = new Node<string>("e44");
     Node<string> *e5 = new Node<string>("e55");
     Node<string> *e6 = new Node<string>("e66");
     List<string> *list = new List<string>();

     cout << "Empty list: ";
     list->print();
     cout << endl;

     cout << "Insert node to empty list with invalid (\"invalid key\") key: "
          << list->recursive_insert(e1, "invalid key") << endl;

     cout << "Empty list: ";
     list->print();
     cout << endl;

     cout << "Add 1 node after list.";
     list->push_back(e1);
     cout << endl;

     cout << "List with 1 node: ";
     list->print();
     cout << endl;

     cout << "Insert node to list with invalid (\"invalid key\") key: "
          << list->recursive_insert(e2, "invalid key") << endl;
     cout << "Insert node to list with valid (\"" << e1->get_key() << "\") key: "
          << list->recursive_insert(e2, e1->get_key()) << endl;

     cout << "List with 2 nodes: ";
     list->print();
     cout << endl;

     cout << "Add 1 node after list.";
     list->push_back(e3);
     cout << endl;

     cout << "List with 3 nodes: ";
     list->print();
     cout << endl;

     cout << "Add 1 node before list.";
     list->push_front(e4);
     cout << endl;

     cout << "List with 4 nodes: ";
     list->print();
     cout << endl;

     cout << "Insert node to list with valid (\"" << e3->get_key() << "\") key: "
          << list->recursive_insert(e5, e3->get_key()) << endl;

     cout << "List with 5 nodes: ";
     list->print();
     cout << endl;

     cout << "Insert node to list with valid (\"" << e4->get_key() << "\") key: "
          << list->recursive_insert(e6, e4->get_key()) << endl;

     cout << "List with 6 nodes: ";
     list->print();
     cout << endl;

     delete list;
}

void test_list_recursive_remove()
{
     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     List<string> *list = new List<string>();

     cout << "Empty list: ";
     list->print();
     cout << endl;

     cout << "Remove node of empty list wiht valid (\"" << e2->get_key() << "\") key (result == nullptr): "
          << (list->recursive_remove(e2->get_key()) == nullptr) << endl;

     cout << "Add 3 nodes to empty list.";
     list->push_back(e1);
     list->push_back(e2);
     list->push_back(e3);
     cout << endl;

     cout << "List with 3 nodes: ";
     list->print();
     cout << endl;

     cout << "Remove node of empty list wiht valid (\"" << e2->get_key() << "\") key (key): "
          << list->recursive_remove(e2->get_key())->get_key() << endl;

     cout << "List with 2 nodes: ";
     list->print();
     cout << endl;

     cout << "Remove node of empty list wiht valid (\"" << e1->get_key() << "\") key (key): "
          << list->recursive_remove(e1->get_key())->get_key() << endl;

     cout << "List with 1 node: ";
     list->print();
     cout << endl;

     cout << "Remove node of empty list wiht valid (\"" << e3->get_key() << "\") key (key): "
          << list->recursive_remove(e3->get_key())->get_key() << endl;

     cout << "Empty list: ";
     list->print();
     cout << endl;

     delete list, e1, e2, e3;
}

void test_list_queue_remove()
{

     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     List<string> *list = new List<string>();

     cout << "Remove node of empty list with valid (\"" << e1->get_key() << "\") key (result == nullptr): "
          << (list->queue_remove(e1->get_key()) == nullptr) << endl;

     cout << "Add 3 nodes to empty list.";
     list->push_back(e1);
     list->push_back(e2);
     list->push_back(e3);
     cout << endl;

     cout << "List with 3 nodes: ";
     list->print();
     cout << endl;

     cout << "Remove node of empty list with valid (\"" << e2->get_key() << "\") key (key): "
          << list->queue_remove(e2->get_key())->get_key() << endl;

     cout << "List with 2 nodes: ";
     list->print();
     cout << endl;

     cout << "Remove node of empty list with valid (\"" << e1->get_key() << "\") key (key): "
          << list->queue_remove(e1->get_key())->get_key() << endl;

     cout << "List with 1 node: ";
     list->print();
     cout << endl;

     cout << "Remove node of empty list with valid (\"" << e3->get_key() << "\") key (key): "
          << list->queue_remove(e3->get_key())->get_key() << endl;

     cout << "Empty list: ";
     list->print();
     cout << endl;

     delete list, e1, e2, e3;
}

void test_list_recursive_insert_K()
{

     Node<string> *A_e1 = new Node<string>("A_e11");
     Node<string> *A_e2 = new Node<string>("A_e22");
     Node<string> *A_e3 = new Node<string>("A_e33");
     List<string> *A = new List<string>();
     A->push_back(A_e1);
     A->push_back(A_e2);
     A->push_back(A_e3);

     cout << "List A with 3 nodes: ";
     A->print();
     cout << endl;

     Node<string> *B_e1 = new Node<string>("B_e11");
     Node<string> *B_e2 = new Node<string>("B_e22");
     Node<string> *B_e3 = new Node<string>("B_e33");
     Node<string> *B_e4 = new Node<string>("B_e44");
     List<string> *B = new List<string>();
     B->push_back(B_e1);
     B->push_back(B_e2);
     B->push_back(B_e3);
     B->push_back(B_e4);

     cout << "List B with 4 nodes: ";
     B->print();
     cout << endl;

     Node<string> *C_e1 = new Node<string>("C_e11");
     List<string> *C = new List<string>();

     cout << "Empty list C: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " nodes to empty list with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "this is very invalid key") << endl;

     cout << "Empty list C: ";
     C->print();
     cout << endl;

     cout << "Add 1 node after list.";
     C->push_back(C_e1);
     cout << endl;

     cout << "List C with 1 node: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " node to list with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "invalid key") << endl;

     cout << "Insert " << A->get_size() << " node to list with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(A, C_e1->get_key()) << endl;

     cout << "List C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     cout << "Insert " << B->get_size() << " node to list with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(B, C_e1->get_key()) << endl;

     cout << "List C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     delete A, B, C;
}

void test_list_queue_insert_K()
{

     Node<string> *A_e1 = new Node<string>("A_e11");
     Node<string> *A_e2 = new Node<string>("A_e22");
     Node<string> *A_e3 = new Node<string>("A_e33");
     List<string> *A = new List<string>();
     A->push_back(A_e1);
     A->push_back(A_e2);
     A->push_back(A_e3);

     cout << "List A with 3 nodes: ";
     A->print();
     cout << endl;

     Node<string> *B_e1 = new Node<string>("B_e11");
     Node<string> *B_e2 = new Node<string>("B_e22");
     Node<string> *B_e3 = new Node<string>("B_e33");
     Node<string> *B_e4 = new Node<string>("B_e44");
     List<string> *B = new List<string>();
     B->push_back(B_e1);
     B->push_back(B_e2);
     B->push_back(B_e3);
     B->push_back(B_e4);

     cout << "List B with 4 nodes: ";
     B->print();
     cout << endl;

     Node<string> *C_e1 = new Node<string>("C_e11");
     List<string> *C = new List<string>();

     cout << "Empty list C: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " nodes to empty list with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "invalid key") << endl;

     cout << "Empty list C: ";
     C->print();
     cout << endl;

     cout << "Add 1 node after list.";
     C->push_back(C_e1);
     cout << endl;

     cout << "List C with 1 node: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " node to list with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "invalid key") << endl;

     cout << "Insert " << A->get_size() << " node to list with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(A, C_e1->get_key()) << endl;

     cout << "List C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     cout << "Insert " << B->get_size() << " node to list with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(B, C_e1->get_key()) << endl;

     cout << "List C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     cout << "List A with " << A->get_size() << " nodes: ";
     A->print();
     cout << endl;

     cout << "List B with " << B->get_size() << " nodes: ";
     B->print();
     cout << endl;

     delete A, B, C;
}

void test_list_iterator()
{
     Node<int> *A_e1 = new Node<int>(1);
     Node<int> *A_e2 = new Node<int>(2);
     Node<int> *A_e3 = new Node<int>(3);
     Node<int> *A_e4 = new Node<int>(4);
     Node<int> *A_e5 = new Node<int>(5);
     Node<int> *A_e6 = new Node<int>(6);
     Node<int> *A_e7 = new Node<int>(7);
     Node<int> *A_e8 = new Node<int>(8);
     Node<int> *A_e9 = new Node<int>(9);
     List<int> *A = new List<int>();
     A->push_back(A_e1);
     A->push_back(A_e2);
     A->push_back(A_e3);
     A->push_back(A_e4);
     A->push_back(A_e5);
     A->push_back(A_e6);
     A->push_back(A_e7);
     A->push_back(A_e8);
     A->push_back(A_e9);

     Iterator it = A->first();
     cout << "First A node key: " << (*it).get_key() << endl;

     it++;
     cout << "Second A node key: " << (*it).get_key() << endl;

     it + 3;
     cout << "Fifth A node key: " << (*it).get_key() << endl;

     cout << "Third A node key: " << (*A)[2]->get_key() << endl;

     delete A;
}

void test_list_multiplication()
{
     Node<int> *A_e1 = new Node<int>(1);
     Node<int> *A_e2 = new Node<int>(3);
     Node<int> *A_e3 = new Node<int>(5);
     List<int> *A = new List<int>();
     A->push_back(A_e1);
     A->push_back(A_e2);
     A->push_back(A_e3);

     cout << "List A with 3 nodes: ";
     A->print();
     cout << endl;

     Node<int> *B_e1 = new Node<int>(0);
     Node<int> *B_e2 = new Node<int>(4);
     Node<int> *B_e3 = new Node<int>(6);
     Node<int> *B_e4 = new Node<int>(8);
     List<int> *B = new List<int>();
     B->push_back(B_e1);
     B->push_back(B_e2);
     B->push_back(B_e3);
     B->push_back(B_e4);

     cout << "List B with 4 nodes: ";
     B->print();
     cout << endl;

     List<int> *C = (*A) * (*B);

     cout << "List C with 3 nodes: ";
     C->print();
     cout << endl;

     delete A, B, C;
}