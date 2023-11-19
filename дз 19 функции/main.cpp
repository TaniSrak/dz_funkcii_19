#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

	//task1
	int min(int num1, int num2)
	{
		int min_num = num1;
		if (min_num < num2)
			min_num = num2;
		for (int i = min_num; i > 0; i--)
		{
			if (num1 % i == 0 && num2 % i == 0)
				return i;
		}
	}

	//Task2
	int mirror_number(int num, int result = 0, int poisk = 0)
	{
		while (num > 0)
		{
			poisk = num % 10;
			result = result * 10 + poisk;
			num /= 10;
		}
		return result;
	}

	//Task3
	int searth_index(int arr[], const int length, int begin)
	{
		int index = 0;
		for (int i = 0; i < length; i++)
		{
			if (arr[i] == begin)
			{
				index = i;
				break;
			}
		}
		int a = 0;
		for (int j = index + 1; j < length - 1; j++)
		{
			for (int i = index + 1; i < length - 1; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					a = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = a;
				}
			}
		}
		return index;
	}
	//вывод массива
	template <typename T>
	void print_arr(T arr[], const int length)
	{
		std::cout << "{ ";
		for (int i = 0; i < length; i++)
			std::cout << arr[i] << ", ";
		std::cout << "\b\b }\n";
	}
	//Task4
	void fill_arr(int arr[], const int length, int num1, int num2)
	{
		for (int i = 0; i < length; i++)
		{
			arr[i] = rand() % (num2 - num1) + num1;
		}
	}


	int main() {
		setlocale(LC_ALL, "Russian");
		int n;
		srand(time(NULL));

		//task1
		int num1 = 12;
		int num2 = 9;
		std::cout << "Наибольший делитель 12 и 9 -> " << min(num1, num2) << "\n\n";

		//task2
		std::cout << "Введите число -> ";
		std::cin >> n;

		int mirror = mirror_number(n);
		std::cout << "Отраженное число -> " << mirror << "\n\n";

		//Task3
		std::cout << "Изначальный массив:\n";
		const int size = 15;
		int arr[size]{};
			for (int i = 0; i < size; i++)
			{
				arr[i] = rand() % 10;
			}
		print_arr(arr, size);

		std::cout << "Введите число с которого начнется сортировка -> ";
		std::cin >> n;
		searth_index(arr, size, n);
		std::cout << "Отсортированный массив:\n";
		print_arr(arr, size);

		//Task4
		int arr2[size]{};
		fill_arr(arr2, size, 12, 32);
		std::cout << "Массив:\n";
		print_arr(arr2, size);

		return 0;
	}