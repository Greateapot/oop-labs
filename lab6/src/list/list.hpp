#pragma once

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class List;

template <class T>
class Iterator;

template <class T>
class Node
{
    T key;
    Node<T> *next, *previous;

    friend class List<T>;
    friend class Iterator<T>;

public:
    Node() : next(nullptr), previous(nullptr){};
    Node(const T key, Node<T> *next = nullptr, Node<T> *previous = nullptr)
        : key(key), next(next), previous(previous){};

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

    friend class List<T>;

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
class List
{

    size_t size;
    Node<T> *head, *tail;

public:
    /// @brief идиотизм, след. конструктор тоже можно вызвать без аргументов, если добавить значение по умолчанию
    List() : size(0), head(nullptr), tail(nullptr){};
    List(const size_t size) : size(size), head(nullptr), tail(nullptr){};

    /// TODO:
    List(const List &) {}
    ~List()
    {
        if (head != nullptr)
            delete head;
    }

    size_t get_size() const { return size; }
    void set_size(const size_t v) { size = v; }

    void push_back(Node<T> *);
    void push_front(Node<T> *);

    Node<T> *pop_last();
    Node<T> *pop_first();

    Node<T> *_recursive_search(Node<T> *, const T);

    Node<T> *recursive_remove(const T);
    Node<T> *queue_remove(const T);

    bool recursive_insert(Node<T> *, const T);
    bool queue_insert(Node<T> *, const T);

    bool recursive_insert(List<T> *, const T);
    bool queue_insert(List<T> *, const T);

    bool save(const string) const;
    bool load(const string);

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
    List<T> *operator*(List<T> &other)
    {
        List<T> *new_list = new List<T>();
        for (int i = 0; i < min(size, other.size); i++)
            new_list->push_back(new Node<T>(((*this)[i])->key * ((other)[i])->key));
        return new_list;
    }
};

template <class T>
void List<T>::print() const
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
void List<T>::push_front(Node<T> *node)
{
    node->next = head;
    if (size == 0)   // список пуст
        tail = node; // новый элемент и первый и последний
    else
        head->previous = node;
    head = node;
    size++;
}

template <class T>
void List<T>::push_back(Node<T> *node)
{
    if (tail == nullptr) // список пуст
        push_front(node);
    else
    {
        tail->next = node;
        node->previous = tail;
        tail = node;
        size++;
    }
}

template <class T>
Node<T> *List<T>::pop_first()
{
    if (head == nullptr) // список пуст
        return nullptr;
    Node<T> *node = head;
    head = node->next;
    if (head == nullptr) // Это был единственный элемент
        tail = nullptr;
    else // если бы он был последним, то ему не пришлось бы ставить nullptr
    {
        node->next->previous = nullptr;
        node->next = nullptr;
    }
    size--;
    return node;
}

template <class T>
Node<T> *List<T>::pop_last()
{
    if (tail == nullptr) // список пуст
        return nullptr;
    Node<T> *node = tail;
    if (head == tail) // это был единственный элемент
    {
        head = nullptr;
        tail = nullptr;
    }
    else // это был не единственный элемент
    {
        node->previous->next = nullptr;
        tail = node->previous;
        node->previous = nullptr;
    }
    size--;
    return node;
}

template <class T>
Node<T> *List<T>::_recursive_search(Node<T> *node, const T key)
{
    if (node->key == key)
        return node;
    if (node->next == nullptr)
        return nullptr;
    return _recursive_search(node->next, key);
}

template <class T>
Node<T> *List<T>::recursive_remove(const T key)
{
    if (head == nullptr) // список пуст
        return nullptr;
    if (head->key == key)   // первый элемент подходит
        return pop_first(); // значит его и удаляем
    if (head == tail)       // он не подошел и оказался единственным
        return nullptr;
    // он не подошел, но он не единственный
    Node<T> *node = _recursive_search(head, key);
    if (node != nullptr) // не нашлось элемента с таким ключом
    {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        size--;
    }
    return node;
}

template <class T>
Node<T> *List<T>::queue_remove(const T key)
{
    if (head == nullptr) // список пуст
        return nullptr;
    int _size = size; // храним, иначе забудем сделать один оборот при наличии элемента с заданным ключом
    Node<T> *node = nullptr;
    for (int i = 1; i <= _size; i++)
    {
        Node<T> *temp = pop_first();
        if (temp->key == key)
            node = temp;
        else
            push_back(temp);
    }
    return node;
}

template <class T>
bool List<T>::recursive_insert(Node<T> *node, const T key)
{
    if (head == nullptr) // список пуст
        return false;
    if (head->key == key) // первый элемент подходит
    {
        push_front(node); // значит добавляем в начало
        return true;
    }
    if (head == tail) // он не подошел и оказался единственным
        return false;
    // он не подошел, но он не единственный
    Node<T> *temp = _recursive_search(head, key);
    if (temp == nullptr) // не нашлось элемента с таким ключом
        return false;
    temp->previous->next = node;
    node->next = temp;
    node->previous = temp->previous;
    temp->previous = node;
    size++;
    return true;
}

template <class T>
bool List<T>::queue_insert(Node<T> *node, const T key)
{
    if (head == nullptr) // список пуст
        return false;
    int _size = size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= _size; i++)
    {
        Node<T> *temp = pop_first();
        if (temp->key == key)
            push_back(node);
        push_back(temp);
    }
    return (size > _size);
}

template <class T>
bool List<T>::recursive_insert(List<T> *nodes, const T key)
{
    if (head == nullptr) // список пуст
        return false;
    if (head->key == key) // первый элемент подходит
    {
        int _size = nodes->size;
        for (int i = 1; i <= _size; i++)
            push_front(nodes->pop_last());
        return true;
    }
    if (head == tail) // он не подошел и оказался единственным
        return false;
    // он не подошел, но он не единственный
    Node<T> *node = _recursive_search(head, key);
    if (node == nullptr) // не нашлось элемента с таким ключом
        return false;
    node->previous->next = nodes->head;
    nodes->head->previous = node->previous;
    node->previous = nodes->tail;
    nodes->tail->next = node;
    size += nodes->size;
    nodes->head = nullptr;
    nodes->tail = nullptr;
    nodes->size = 0;
    return true;
}

template <class T>
bool List<T>::queue_insert(List<T> *nodes, const T key)
{
    if (head == nullptr) // список пуст
        return false;
    int _size = size; // храним, иначе сделаем лишний оборот при наличии элемента с заданным ключом
    for (int i = 1; i <= _size; i++)
    {
        Node<T> *node = pop_first();
        if (node->key == key)
        {
            int __size = nodes->size;
            for (int i = 1; i <= __size; i++)
                push_back(pop_first());
        }
        push_back(node);
    }
    return (size > _size);
}

template <class T>
bool List<T>::save(const string filename) const
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
bool List<T>::load(const string filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        file.close();
        return false;
    }
    string key;
    while (getline(file, key, '\0'))
        push_back(new Node<T>(key));
    file.close();
    return true;
}
