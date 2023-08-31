#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


template <typename T> 
void fill_arr(T arr[], const int lenght, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (right - left) + left;
}
template <typename T>
void print_arr(T arr[], const int lenght) {
	std::cout << "{ ";
	for (int i = 0; i < lenght; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b}\n";
}


void type_of(int num) {	std::cout << "INT\n";}
void type_of(double num) { std::cout << "DOUBLE\n"; }
void type_of(char num) { std::cout << "CHAR\n"; }

int sum_AB(int A, int B); // Прототип функции sum_AB

template <typename T>
void middle_sort(T arr[], const int lenght);

template <typename T>
void move_arr(T arr[], const int length, int steps);


int main() {
	setlocale(LC_ALL, "RU");
	int n, m;

	




	// Задача 1. Тип данных

	/*std::cout << "Задача 1. \n";
	std::cout << "77 - "; type_of(77);
	std::cout << "5.1 - "; type_of(5.1);
	std::cout << "'A' - "; type_of('A');
	std::cout << std::endl;*/


	// Задача 2. Рекурсивная сумма

	/*std::cout << "Задача 2. \nВведите два числа -> ";
	std::cin >> n >> m;
	std::cout << "Сумма чисел от  " << n << " до " << m << " = " << sum_AB(n, m);*/

	// Задача 3.Сортитровка середины

/*std::cout << "Задача 3. \nИзначальный массив:\n ";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -10, 11);
	print_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);*/

	// Задача 4. Сдвиг по кругу

	std::cout << "Задача 4. \nИзначальный массив:\n ";
	const int size4 = 10;
	int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_arr(arr4, size4);
	std::cout << "Введите число -> ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	std::cout << "Итоговый массив:\n";
	print_arr(arr4, size4);
	return 0;
}

// Реализация функции sum_AB
int sum_AB(int A, int B) {
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;
}

template <typename T>
void middle_sort(T arr[], const int lenght) {
	int first_index = 0, last_index = 0;
	// Индекс первого отрицательного элемента
	for (int i = 0; i < lenght; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	// Индекс последнего отрицательного элемента
	for(int i = lenght -1; i >= first_index; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	// Пузырьковая сортировка
	/*for (int i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);*/

	// Быстрая сортировка
	std::sort(arr + first_index + 1, arr + last_index);

}

template <typename T>
void move_arr(T arr[], const int length, int steps) {
	if (steps >= 0)
		for (int i = 0; i < steps; i++) {
			T tmp = arr[length - 1];
			for (int i = length - 1; i >= 1; i--)
				arr[i] = arr[i - 1];
			arr[0] = tmp;
		}
	else
		for( int i = 0; i < -steps; i++)
			for(int i= 0; i< length -1; i++)
		std::swap(arr[i], arr[i + 1]);
}
