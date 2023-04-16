#include "test.hpp"

#include <iostream>

#include "stack.hpp"

using namespace std;

void stack_test()
{
     cout << "STACK TEST: " << endl
          << endl;

     cout << "Test Stack.save_load: " << endl;
     test_stack_save_load();
     cout << endl;

     cout << "Test Stack.recursive_insert: " << endl;
     test_stack_recursive_insert();
     cout << endl;

     cout << "Test Stack.queue_insert: " << endl;
     test_stack_queue_insert();
     cout << endl;

     cout << "Test Stack.recursive_insert with K nodes: " << endl;
     test_stack_recursive_insert_K();
     cout << endl;

     cout << "Test Stack.queue_insert with K nodes: " << endl;
     test_stack_queue_insert_K();
     cout << endl;

     cout << "Test Stack.recursive_remove: " << endl;
     test_stack_recursive_remove();
     cout << endl;

     cout << "Test Stack.queue_remove: " << endl;
     test_stack_queue_remove();
     cout << endl;

     cout << "Test Stack iterator and [] op: " << endl;
     test_stack_iterator();
     cout << endl;

     cout << "Test stacks multiplication: " << endl;
     test_stack_multiplication();
     cout << endl;

     cout << "STACK TEST END." << endl
          << endl;
}


void test_stack_save_load()
{
     const string filename = "lab6stack.dat";

     Node<string> *A_e1 = new Node<string>("A_e11");
     Node<string> *A_e2 = new Node<string>("A_e22");
     Node<string> *A_e3 = new Node<string>("A_e33");
     Stack<string> *A = new Stack<string>();
     Stack<string> *B = new Stack<string>();

     A->push(A_e1);
     A->push(A_e2);
     A->push(A_e3);

     cout << "Stack A with " << A->get_size() << " nodes: ";
     A->print();
     cout << endl;

     cout << "Empty stack B: ";
     B->print();
     cout << endl;

     cout << "Save stack A to file (\"" << filename << "\"): " << A->save(filename) << endl;

     delete A;

     cout << "Load stack B from file (\"" << filename << "\"): " << B->load(filename) << endl;

     cout << "Stack B with " << B->get_size() << " nodes: ";
     B->print();
     cout << endl;

     delete B;
}


void test_stack_recursive_insert()
{
     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     Node<string> *e4 = new Node<string>("e44");
     Stack<string> *stack = new Stack<string>();

     cout << "Empty stack: ";
     stack->print();
     cout << endl;

     cout << "Insert node to empty stack with invalid (\"invalid key\") key: "
          << stack->recursive_insert(e1, "invalid key") << endl;

     cout << "Empty stack: ";
     stack->print();
     cout << endl;

     cout << "Add 1 node after stack.";
     stack->push(e1);
     cout << endl;

     cout << "Stack with 1 node: ";
     stack->print();
     cout << endl;

     cout << "Insert node to stack with invalid (\"invalid key\") key: "
          << stack->recursive_insert(e2, "invalid key") << endl;
     cout << "Insert node to stack with valid (\"" << e1->get_key() << "\") key: "
          << stack->recursive_insert(e2, e1->get_key()) << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Add 1 node after stack.";
     stack->push(e3);
     cout << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Insert node to stack with valid (\"" << e3->get_key() << "\") key: "
          << stack->recursive_insert(e4, e3->get_key()) << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     delete stack;
}


void test_stack_queue_insert()
{
     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     Node<string> *e4 = new Node<string>("e44");
     Stack<string> *stack = new Stack<string>();

     cout << "Empty stack: ";
     stack->print();
     cout << endl;

     cout << "Insert node to empty stack with invalid (\"invalid key\") key: "
          << stack->recursive_insert(e1, "invalid key") << endl;

     cout << "Empty stack: ";
     stack->print();
     cout << endl;

     cout << "Add 1 node after stack.";
     stack->push(e1);
     cout << endl;

     cout << "Stack with 1 node: ";
     stack->print();
     cout << endl;

     cout << "Insert node to stack with invalid (\"invalid key\") key: "
          << stack->recursive_insert(e2, "invalid key") << endl;
     cout << "Insert node to stack with valid (\"" << e1->get_key() << "\") key: "
          << stack->recursive_insert(e2, e1->get_key()) << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Add 1 node after stack.";
     stack->push(e3);
     cout << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Insert node to stack with valid (\"" << e3->get_key() << "\") key: "
          << stack->recursive_insert(e4, e3->get_key()) << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     delete stack;
}

void test_stack_recursive_remove()
{
     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     Stack<string> *stack = new Stack<string>();

     cout << "Empty stack: ";
     stack->print();
     cout << endl;

     cout << "Remove node of empty stack wiht valid (\"" << e2->get_key() << "\") key (result == nullptr): "
          << (stack->recursive_remove(e2->get_key()) == nullptr) << endl;

     cout << "Add 3 nodes to empty stack.";
     stack->push(e1);
     stack->push(e2);
     stack->push(e3);
     cout << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Remove node of empty stack wiht valid (\"" << e2->get_key() << "\") key (key): "
          << stack->recursive_remove(e2->get_key())->get_key() << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Remove node of empty stack wiht valid (\"" << e1->get_key() << "\") key (key): "
          << stack->recursive_remove(e1->get_key())->get_key() << endl;

     cout << "Stack with 1 node: ";
     stack->print();
     cout << endl;

     cout << "Remove node of empty stack wiht valid (\"" << e3->get_key() << "\") key (key): "
          << stack->recursive_remove(e3->get_key())->get_key() << endl;

     cout << "Empty stack: ";
     stack->print();
     cout << endl;

     delete stack, e1, e2, e3;
}

void test_stack_queue_remove()
{

     Node<string> *e1 = new Node<string>("e11");
     Node<string> *e2 = new Node<string>("e22");
     Node<string> *e3 = new Node<string>("e33");
     Stack<string> *stack = new Stack<string>();

     cout << "Remove node of empty stack with valid (\"" << e1->get_key() << "\") key (result == nullptr): "
          << (stack->queue_remove(e1->get_key()) == nullptr) << endl;

     cout << "Add 3 nodes to empty stack.";
     stack->push(e1);
     stack->push(e2);
     stack->push(e3);
     cout << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Remove node of empty stack with valid (\"" << e2->get_key() << "\") key (key): "
          << (stack->queue_remove(e2->get_key()))->get_key() << endl;

     cout << "Stack with " << stack->get_size() << " nodes: ";
     stack->print();
     cout << endl;

     cout << "Remove node of empty stack with valid (\"" << e1->get_key() << "\") key (key): "
          << stack->queue_remove(e1->get_key())->get_key() << endl;

     cout << "Stack with 1 node: ";
     stack->print();
     cout << endl;

     cout << "Remove node of empty stack with valid (\"" << e3->get_key() << "\") key (key): "
          << stack->queue_remove(e3->get_key())->get_key() << endl;

     cout << "Empty stack: ";
     stack->print();
     cout << endl;

     delete stack, e1, e2, e3;
}

void test_stack_recursive_insert_K()
{

     Node<string> *A_e1 = new Node<string>("A_e11");
     Node<string> *A_e2 = new Node<string>("A_e22");
     Node<string> *A_e3 = new Node<string>("A_e33");
     Stack<string> *A = new Stack<string>();
     A->push(A_e1);
     A->push(A_e2);
     A->push(A_e3);

     cout << "Stack A with 3 nodes: ";
     A->print();
     cout << endl;

     Node<string> *B_e1 = new Node<string>("B_e11");
     Node<string> *B_e2 = new Node<string>("B_e22");
     Node<string> *B_e3 = new Node<string>("B_e33");
     Node<string> *B_e4 = new Node<string>("B_e44");
     Stack<string> *B = new Stack<string>();
     B->push(B_e1);
     B->push(B_e2);
     B->push(B_e3);
     B->push(B_e4);

     cout << "Stack B with 4 nodes: ";
     B->print();
     cout << endl;

     Node<string> *C_e1 = new Node<string>("C_e11");
     Stack<string> *C = new Stack<string>();

     cout << "Empty stack C: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " nodes to empty stack with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "invalid key") << endl;

     cout << "Empty stack C: ";
     C->print();
     cout << endl;

     cout << "Add 1 node after stack.";
     C->push(C_e1);
     cout << endl;

     cout << "Stack C with 1 node: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " node to stack with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "invalid key") << endl;

     cout << "Insert " << A->get_size() << " node to stack with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(A, C_e1->get_key()) << endl;

     cout << "Stack C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     cout << "Insert " << B->get_size() << " node to stack with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(B, C_e1->get_key()) << endl;

     cout << "Stack C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     delete A, B, C;
}

void test_stack_queue_insert_K()
{

     Node<string> *A_e1 = new Node<string>("A_e11");
     Node<string> *A_e2 = new Node<string>("A_e22");
     Node<string> *A_e3 = new Node<string>("A_e33");
     Stack<string> *A = new Stack<string>();
     A->push(A_e1);
     A->push(A_e2);
     A->push(A_e3);

     cout << "Stack A with 3 nodes: ";
     A->print();
     cout << endl;

     Node<string> *B_e1 = new Node<string>("B_e11");
     Node<string> *B_e2 = new Node<string>("B_e22");
     Node<string> *B_e3 = new Node<string>("B_e33");
     Node<string> *B_e4 = new Node<string>("B_e44");
     Stack<string> *B = new Stack<string>();
     B->push(B_e1);
     B->push(B_e2);
     B->push(B_e3);
     B->push(B_e4);

     cout << "Stack B with 4 nodes: ";
     B->print();
     cout << endl;

     Node<string> *C_e1 = new Node<string>("C_e11");
     Stack<string> *C = new Stack<string>();

     cout << "Empty stack C: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " nodes to empty stack with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "invalid key") << endl;

     cout << "Empty stack C: ";
     C->print();
     cout << endl;

     cout << "Add 1 node after stack.";
     C->push(C_e1);
     cout << endl;

     cout << "Stack C with 1 node: ";
     C->print();
     cout << endl;

     cout << "Insert " << A->get_size() << " node to stack with invalid (\"invalid key\") key: "
          << C->recursive_insert(A, "invalid key") << endl;

     cout << "Insert " << A->get_size() << " node to stack with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(A, C_e1->get_key()) << endl;

     cout << "Stack C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     cout << "Insert " << B->get_size() << " node to stack with valid (\"" << C_e1->get_key() << "\") key: "
          << C->recursive_insert(B, C_e1->get_key()) << endl;

     cout << "Stack C with " << C->get_size() << " nodes: ";
     C->print();
     cout << endl;

     delete A, B, C;
}


void test_stack_iterator()
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
     Stack<int> *A = new Stack<int>();
     A->push(A_e1);
     A->push(A_e2);
     A->push(A_e3);
     A->push(A_e4);
     A->push(A_e5);
     A->push(A_e6);
     A->push(A_e7);
     A->push(A_e8);
     A->push(A_e9);

     Iterator it = A->first();
     cout << "First A node key: " << (*it).get_key() << endl;

     it++;
     cout << "Second A node key: " << (*it).get_key() << endl;

     it + 3;
     cout << "Fifth A node key: " << (*it).get_key() << endl;

     cout << "Third A node key: " << (*A)[2]->get_key() << endl;

     delete A;
}

void test_stack_multiplication()
{
     Node<int> *A_e1 = new Node<int>(1);
     Node<int> *A_e2 = new Node<int>(3);
     Node<int> *A_e3 = new Node<int>(5);
     Stack<int> *A = new Stack<int>();
     A->push(A_e1);
     A->push(A_e2);
     A->push(A_e3);

     cout << "Stack A with 3 nodes: ";
     A->print();
     cout << endl;

     Node<int> *B_e1 = new Node<int>(0);
     Node<int> *B_e2 = new Node<int>(4);
     Node<int> *B_e3 = new Node<int>(6);
     Node<int> *B_e4 = new Node<int>(8);
     Stack<int> *B = new Stack<int>();
     B->push(B_e1);
     B->push(B_e2);
     B->push(B_e3);
     B->push(B_e4);

     cout << "Stack B with 4 nodes: ";
     B->print();
     cout << endl;

     Stack<int> *C = (*A) * (*B);

     cout << "Stack C with 3 nodes: ";
     C->print();
     cout << endl;

     delete A, B, C;
}