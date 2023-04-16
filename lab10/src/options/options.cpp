#include <iostream>

#include "../utils/utils.hpp"
#include "../pair/pair.hpp"
#include "../consts.hpp"
#include "../list.hpp"

using namespace std;

void op1(List<Pair> *list)
{
    int H;
    do
    {
        H = input_int_number("Input H: ");

        if (H < 0)
            cout << "H must be greater than 0" << endl;
    } while (H < 0);

    for (int i = 0; i < H; i++)
        list->push_back(new Node(get_rand_pair()));
}

void op5(List<Pair> *list)
{
    const int Ma = input_int_number("Input Ma: ");
    const int Mb = input_double_number("Input Mb: ");
    const Pair M(Ma, Mb);

    for (Iterator<Pair> it = list->first(); it != list->last();)
    {
        Pair key = (*it).get_key();
        it++;
        if (key < M)
        {
            Node<Pair> *todl = list->recursive_remove(key);
            delete todl;
        }
    }
}

void _op6_int(List<Pair> *list)
{
    int L = input_int_number("Input int: ");
    for (Iterator<Pair> it = list->first(); it != list->last(); it++)
        (*it).set_key((*it).get_key() + L);
}

void _op6_double(List<Pair> *list)
{
    double L = input_double_number("Input double: ");
    for (Iterator<Pair> it = list->first(); it != list->last(); it++)
        (*it).set_key((*it).get_key() + L);
}

void op6(List<Pair> *list)
{
    bool stop = 0;
    do
    {

        cout << SUB_MENU;
        cout << "--> ";

        const unsigned short int option = input_option_number();

        switch (option)
        {
        case 1:
            _op6_int(list);
            stop = 1;
            break;
        case 2:
            _op6_double(list);
            stop = 1;
            break;
        case 0:
            stop = 1;
            break;
        default:
            cout << "Некорректный ввод!" << endl;
            break;
        }
    } while (!stop);
}

void op7(List<Pair> *list)
{
    int P;
    do
    {
        P = input_int_number("Input P: ");
        if (P < 0)
            cout << "P must be greater than 0" << endl;
    } while (P < 0);

    int K;
    do
    {
        K = input_int_number("Input K: ");
        if (K < 0)
            cout << "K must be greater than 0" << endl;
    } while (K < 0);

    Iterator<Pair> it = list->first();
    for (int i = 0; i < P; i++)
        it++;

    List<Pair> *temp = new List<Pair>();

    for (int i = 0; i < K; i++)
        temp->push_back(new Node<Pair>(get_rand_pair()));

    list->recursive_insert(temp, (*it).get_key());

    delete temp;
}

bool process(List<Pair> *list)
{
    cout << "--> ";
    const unsigned short int option = input_option_number();
    switch (option)
    {
    case 0:
        return 1;
    case 1:
        op1(list);
        break;
    case 2:
        list->save(FILENAME);
        break;
    case 3:
        list->load(FILENAME);
        break;
    case 4:
        list->print();
        cout << endl;
        break;
    case 5:
        op5(list);
        break;
    case 6:
        op6(list);
        break;
    case 7:
        op7(list);
        break;
    case 8:
        delete list;
        list = new List<Pair>();
        break;
    case 9:
        cout << MENU;
        break;
    }
    return 0;
}
