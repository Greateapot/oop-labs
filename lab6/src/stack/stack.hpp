#pragma once

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Stack;

template <class T>
class Iterator;

template <class T>
class Node
{
    T key;
    Node<T> *next;

    friend class Stack<T>;
    friend class Iterator<T>;

public:
    Node(T key, Node<T> *next = nullptr)
        : key(key), next(next){};

    ~Node()
    {
        if (next != nullptr)
            delete next;
    }

    T get_key() const { return key; }
    void set_key(const T v) { key = v; }
};


template <class T>
class Iterator
{
    Node<T> *node;

    friend class Stack<T>;

public:
    Iterator() : node(nullptr){};
    Iterator(Node<T> *node) : node(node){};
    Iterator(const Iterator<T> &other) : node(other.node){};
    ~Iterator(){};

    bool operator==(const Iterator<T> &other) { return node->key == other.node->key; }
    bool operator!=(const Iterator<T> &other) { return node->key != other.node->key; }
    void operator++(int) { node = node->next; }
    void operator++() { node = node->next; }
    void operator--() { node = node->previous; }
    Node<T> &operator*() { return *node; }
    Iterator<T> &operator+(int count)
    {
        for (int i = 0; i < count && node->next != nullptr; i++)
            node = node->next;
        return *this;
    }
};

template <class T>
class Stack
{
    size_t size;
    Node<T> *head;

public:
    Stack() : size(0), head(nullptr){};
    Stack(const size_t size) : size(size), head(nullptr){};
    /// TODO:
    Stack(const Stack &){};
    ~Stack<T>()
    {
        if (head != nullptr)
            delete head;
    }

    size_t get_size() const { return size; }
    void set_size(const size_t v) { size = v; }

    void push(Node<T> *node);
    Node<T> *pop();

    Node<T> *_recursive_remove(Stack<T> *to, const T key);
    Node<T> *recursive_remove(const T key);
    Node<T> *queue_remove(const T key);

    bool _recursive_insert(Stack<T> *to, Node<T> *node, const T key);
    bool recursive_insert(Node<T> *node, const T key);
    bool queue_insert(Node<T> *node, const T key);

    bool _recursive_insert(Stack<T> *to, Stack<T> *nodes, const T key);
    bool recursive_insert(Stack<T> *nodes, const T key);
    bool queue_insert(Stack<T> *nodes, const T key);

    bool save(const string filename) const;
    bool load(const string filename);

    void print() const;

    
    Iterator<T> first() const { return Iterator(head); }
    Iterator<T> last() const { return Iterator(nullptr); } // зачем оно вообще в списке

    Node<T> *operator[](int index)
    {
        if (size < index + 1)
            return nullptr;
        Node<T> *node = head;
        for (int i = 1; i <= index; i++)
            node = node->next;
        return node;
    }
    int operator()() const
    {
        return size;
    }
    Stack<T> *operator*(Stack<T> &other)
    {
        Stack<T> *new_stack = new Stack<T>();
        for (int i = 0; i < min(size, other.size); i++)
            new_stack->push(new Node<T>(((*this)[i])->key * ((other)[i])->key));
        return new_stack;
    }
};

template <class T>
void Stack<T>::print() const
{
    if (head == nullptr) // список пуст
        return;
    Node<T> *node = head;
    for (int i = 2; i <= size; i++)
    {
        cout << node->key << ", ";
        node = node->next;
    }
    cout << node->key;
}

template <class T>
void Stack<T>::push(Node<T> *node)
{
    node->next = head;
    head = node;
    size++;
}

template <class T>
Node<T> *Stack<T>::pop()
{
    Node<T> *node = head;
    head = node->next;
    size--;
    return node;
}

template <class T>
Node<T> *Stack<T>::_recursive_remove(Stack<T> *to, const T key)
{
    if (head == nullptr)
        return nullptr;
    if (head->key == key)
    {
        Node<T> *node = pop();
        _recursive_remove(to, key);
        return node;
    }
    to->push(pop());
    return _recursive_remove(to, key);
}

template <class T>
Node<T> *Stack<T>::recursive_remove(const T key)
{
    Stack<T> *temp = new Stack<T>();
    Node<T> *node = _recursive_remove(temp, key);
    for (int i = 1, size = temp->size; i <= size; i++)
        push(temp->pop());
    delete temp;
    return node;
}

template <class T>
bool Stack<T>::_recursive_insert(Stack<T> *to, Node<T> *node, const T key)
{
    if (head == nullptr)
        return false;
    if (head->key == key)
    {
        if (node->next == nullptr) // Чтоб дважды не вставило
            to->push(node);
        to->push(pop());
        _recursive_insert(to, node, key);
        return true;
    }
    to->push(pop());
    return _recursive_insert(to, node, key);
}

template <class T>
bool Stack<T>::recursive_insert(Node<T> *node, const T key)
{
    Stack<T> *temp = new Stack<T>();
    bool result = _recursive_insert(temp, node, key);
    for (int i = 1, size = temp->size; i <= size; i++)
        push(temp->pop());
    delete temp;
    return result;
}

template <class T>
bool Stack<T>::_recursive_insert(Stack<T> *to, Stack<T> *nodes, const T key)
{
    if (head == nullptr)
        return false;
    if (head->key == key)
    {
        {
            Stack<T> *temp = new Stack<T>();
            for (int i = 1, size = nodes->size; i <= size; i++)
                temp->push(nodes->pop());
            for (int i = 1, size = temp->size; i <= size; i++)
                to->push(temp->pop());
            delete temp;
        }
        to->push(pop());
        _recursive_insert(to, nodes, key);
        return true;
    }
    to->push(pop());
    return _recursive_insert(to, nodes, key);
}

template <class T>
bool Stack<T>::recursive_insert(Stack<T> *nodes, const T key)
{
    Stack<T> *temp = new Stack<T>();
    bool result = _recursive_insert(temp, nodes, key);
    for (int i = 1, size = temp->size; i <= size; i++)
        push(temp->pop());
    delete temp;
    return result;
}

template <class T>
Node<T> *Stack<T>::queue_remove(const T key)
{
    Stack<T> *temp = new Stack<T>();
    Node<T> *node = nullptr, *v;
    for (int i = 1, size = this->size; i <= size; i++)
        if (head->key == key)
            node = pop();
        else
            temp->push(pop());
    for (int i = 1, size = temp->size; i <= size; i++)
        push(temp->pop());
    delete temp;
    return node;
}

template <class T>
bool Stack<T>::queue_insert(Node<T> *node, const T key)
{
    Stack<T> *temp = new Stack<T>();
    const size_t size = size;
    for (int i = 1; i <= size; i++)
    {
        Node<T> *v = pop();
        temp->push(v);
        if (v->key == key && node->next == nullptr)
            temp->push(node);
    }
    for (int i = 1, size = temp->size; i <= size; i++)
        push(temp->pop());
    delete temp;
    return (size > size);
}

template <class T>
bool Stack<T>::queue_insert(Stack<T> *nodes, const T key)
{
    Stack<T> *temp = new Stack<T>();
    const size_t size = size;
    for (int i = 1; i <= size; i++)
    {
        Node<T> *v = pop();
        temp->push(v);
        if (v->key == key)
            for (int j = 1, _size = nodes->size; j <= _size; j++)
                temp->push(nodes->pop());
    }
    for (int i = 1, size = temp->size; i <= size; i++)
        push(temp->pop());
    delete temp;
    return (size > size);
}

template <class T>
bool Stack<T>::save(const string filename) const
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    Node<T> *node = head;
    for (int i = 1; i <= size; i++, node = node->next)
        file << node->key << '\0';
    file.close();
    return true;
}

template <class T>
bool Stack<T>::load(const string filename)
{
    Stack<T> *temp = new Stack<T>();
    ifstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    T key;
    while (getline(file, key, '\0'))
    {
        temp->push(new Node<T>(key));
    }
    file.close();
    for (int i = 1, size = temp->size; i <= size; i++)
        push(temp->pop());
    delete temp;
    return true;
}