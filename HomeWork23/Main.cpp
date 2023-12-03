#include<iostream>

// Функция Задачи 1:
void three_max(int& a, int& b, int& c) {
	int max = a;				// первую ссылку присвоим к переменной max.
	max = max > b ? max : b;	// сравним max с второй переменной b.
	max = max > c ? max : c;	// сравним max с третьей переменной c.
	// присвоим всем ссылкам на переменные в блоке main значения переменной max:
	a = max;
	b = max;
	c = max;
}
// Функция Задачи 2:
int& neg(int arr[], const int length) {
	for (int i = 0; i < length; i++)	// переберем все элементы массива.
		if (arr[i] < 0)					// если элемент массива меньше нуля,
			return *(arr + i);			// то возвращаем его значение в блок main в виде указателя,
	return *(arr);						// иначе (если не найдем отрицательные элементы) возвращаем значение первого элемента массива.
}
// Функция Задачи 3:
void zero_second_arr(int arr1[], const int length1, int arr2[], const int length2) {
	for (int i = 0; i < length1; i++)			// переберем каждый элемент в массиве 1.
		for (int j = 0; j < length2; j++)		// переберем все элементы массива 2.
			if (*(arr1 + i) == *(arr2 + j))		// сравним элементы массива 1 с элементами массива 2,
				*(arr2 + j) = 0;				// при равенстве элементов, обнулим элемент массива 2.
}
// шаблонная функция по выводу массива в консоль:
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << *(arr + i) << ", ";	// вывод указателя в консоль.
	std::cout << "\b\b }" << std::endl;
}

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	
	// Задача 1. 
	std::cout << "Задача 1.\n";
	int A = 3, B = 5, C = 4;
	std::cout << A << ' ' << B << ' ' << C << std::endl;
	std::cout << "-----\n";
	three_max(A, B, C);
	std::cout << A << ' ' << B << ' ' << C << std::endl;
	std::cout << std::endl;

	// Задача 2.
	std::cout << "Задача 2.\n";
	const int size2 = 5;
	int arr2[size2]{ 10, 20, 0, -5, 7 };	// создадим массив с одним отрицательным элементом.
	std::cout << "Массив 1:\n";
	print_arr(arr2, size2);
	if (neg(arr2, size2) > 0)				// если в массиве отсутствуют отрицательные числа, то переход к строке 55, иначе переход к строке 57.
		std::cout << "В массиве отсутствуют отрицательные элементы.\n\n";
	else
		std::cout << "Первым отрицательным элементом в массиве является " << neg(arr2, size2) << '.' << std::endl;

	int arr2_1[size2]{ 10, -20, 0, -5, 7 };	// создадим массив с двумя отрицательными элементами.
	std::cout << "Массив 2:\n";
	print_arr(arr2_1, size2);
	if (neg(arr2_1, size2) > 0)
		std::cout << "В массиве отсутствуют отрицательные элементы.\n\n";
	else
		std::cout << "Первым отрицательным элементом в массиве является " << neg(arr2_1, size2) << '.' << std::endl;

	int arr2_2[size2]{ 10, 20, 0, 5, 7 };	// создадим массив без отрицательных элементов.
	std::cout << "Массив 3:\n";
	print_arr(arr2_2, size2);
	if (neg(arr2_2, size2) > 0)
		std::cout << "В массиве отсутствуют отрицательные элементы.\n\n";
	else
		std::cout << "Первым отрицательным элементом в массиве является " << neg(arr2_2, size2) << '.' << std::endl;
	
	// Задача 3.
	std::cout << "Задача 3.\n";
	const int size3_1 = 7;
	int arr3_1[size3_1]{ 3, 6, 4, 1, 4, 8, 2 };
	const int size3_2 = 6;
	int arr3_2[size3_2]{ 5, 3, 1, 5, 10, 8 };
	std::cout << "Массив 1:\n";
	print_arr(arr3_1, size3_1);
	std::cout << "Массив 2:\n";
	print_arr(arr3_2, size3_2);
	// Вызовем функцию по обнулению тех элементов во втором массиве, которые встречаются в первом:
	zero_second_arr(arr3_1, size3_1, arr3_2, size3_2);
	std::cout << "Массив 2 после вызова функции:\n";
	print_arr(arr3_2, size3_2);

	return 0;
}