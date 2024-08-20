// Template_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

template<class T>
class ArrayHard
{
private:
	T** arr;
	
	size_t size;
	
public:
	ArrayHard(int a, int b)
	{
		arr = new T*[a];
		for (int i = 0; i < a; i++)
		{
			arr[i] = new T[b];
		}
		size = a * b;
	}
	~ArrayHard()
	{
		for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	
	
	T* operator [](unsigned index)
	{

		return arr[index];
	}
	const T* operator [](unsigned index) const
	{
		return arr[index];
	}
	
	int Size()
	{
		return size;
	}

};
template<class T>
void print_arr(T& arr)
{
	std::cout << "Table: " << std::endl;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		std::cout << "Row " << i << ": ";
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int main()
{
	auto table = ArrayHard <int>(2, 2);


	for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		for (int j = 0; j < sizeof(table[0]) / sizeof(table[0][0]); j++)
		{
			table[i][j] = i + j;
		}
	}
	print_arr(table);
	table[1][1] = 15;
	print_arr(table);
	
}
