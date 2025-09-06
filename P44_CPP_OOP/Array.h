#pragma once


class Array
{
	int* arr = nullptr;
	size_t size = 0;

public:

	Array(size_t s);

	~Array();

	void fill(int number);

	void randomFill(int min, int max);

	void print();

	void resize(int newSize);

	void sort();

	int minValue();

	int maxValue();

	void add(int value);

	void set(int index, int value);
};


Array::Array(size_t s)
{
	size = s;
	arr = new int[size];
}

Array::~Array()
{
	delete arr;
}

void Array::fill(int number)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = number;
	}
}

void Array::randomFill(int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void Array::print()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array::resize(int newSize)
{
	if (newSize == size)
	{
		return;
	}

	int* temp = new int[newSize] {0};

	int s = (newSize > size) ? size : newSize;

	for (size_t i = 0; i < s; i++)
	{
		temp[i] = arr[i];
	}
	size = newSize;
	delete arr;
	arr = temp;
}

void Array::sort()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int Array::minValue()
{
	int min = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

inline int Array::maxValue()
{
	int max = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void Array::add(int value)
{
	int* arr2 = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	arr2[size] = value;
	size++;
	delete arr;
	arr = arr2;
}

void Array::set(int index, int value)
{
	if (index >= 0 && index < size)
	{
		arr[index] = value;
	}
}
