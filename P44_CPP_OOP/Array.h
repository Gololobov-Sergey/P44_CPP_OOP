#pragma once

template <class T>
class Array
{
	T* arr = nullptr;
	size_t size = 0;

public:

	explicit Array(size_t size);

	Array(const Array& obj);

	~Array();

	void fill(T number) const;

	void randomFill(int min, int max) const;

	void print() const;

	void resize(int newSize);

	void sort() const;

	int minValue() const;

	int maxValue() const;

	void add(T value);

	void set(int index, T value) const;
};

template <class T>
Array<T>::Array(size_t size)
{
	this->size = size;
	this->arr = new T[size];
	cout << "Constructor Array" << endl;
}

template <class T>
Array<T>::Array(const Array& obj)
{
	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	cout << "Copy Constructor Array" << endl;
}

template <class T>
Array<T>::~Array()
{
	delete arr;
	cout << "Destructor Array" << endl;
}

template <class T>
void Array<T>::fill(T number) const
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = number;
	}
}

template <class T>
void Array<T>::randomFill(int min, int max) const
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

template <class T>
void Array<T>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class T>
void Array<T>::resize(int newSize)
{
	if (newSize == size)
	{
		return;
	}

	int* temp = new T[newSize] {0};

	int s = (newSize > size) ? size : newSize;

	for (size_t i = 0; i < s; i++)
	{
		temp[i] = arr[i];
	}
	size = newSize;
	delete arr;
	arr = temp;
}

template <class T>
void Array<T>::sort() const
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

template <class T>
int Array<T>::minValue() const
{
	T min = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

template <class T>
inline int Array<T>::maxValue() const
{
	T max = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template <class T>
void Array<T>::add(T value)
{
	T* arr2 = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	arr2[size] = value;
	size++;
	delete arr;
	arr = arr2;
}

template <class T>
void Array<T>::set(int index, T value) const
{
	if (index >= 0 && index < size)
	{
		arr[index] = value;
	}
}
