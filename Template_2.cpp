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
	size_t row;
	size_t cols;
	
public:
	ArrayHard(int a, int b)
	{
		arr = new T*[a];
		for (int i = 0; i < a; i++)
		{
			arr[i] = new T[b];
		}
		row = a;
		cols = b;
		size = a * b;
	}
	~ArrayHard()
	{
		for (int i = 0; i < row; i++)
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
void print_arr(T& arr, unsigned rows_, unsigned cols_)
{
	std::cout << "Table: " << std::endl;
	for (int i = 0; i < rows_; i++)
	{
		std::cout << "Row " << i << ": ";
		for (int j = 0; j < cols_; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int main()
{
	
		int a = 2;
		int b = 2;
		auto table = ArrayHard <int>(a, b);


		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				table[i][j] = i + j;
			}
		}
		print_arr(table, a, b);
		table[1][1] = 15;
		print_arr(table, a, b);
	
	
}
