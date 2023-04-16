#include <iostream>

#include "dialog.hpp"

using namespace std;

int main()
{
	cout << "Опции: " << endl
		 << "1. Создать вектор: (m6, где 6-размер)" << endl
		 << "2. Добавить элемент: +" << endl
		 << "3. Удалить элемент: -" << endl
		 << "4. Вывод полей элементов: s" << endl
		 << "5. Вывод названий элементов: z" << endl
		 << "6. Выход: q" << endl;

	Dialog().execute();

	return 0;
}