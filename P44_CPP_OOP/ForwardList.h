#pragma once
#include <iostream>
#include <initializer_list>

using namespace std;


#include "Node.h"


template<class T>
class ForwardList
{
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t   size = 0;

	Node<T>* getNode(int index);

public:
	ForwardList();
	ForwardList(initializer_list<T> list);
	~ForwardList();
	ForwardList(const ForwardList& obj);
	ForwardList& operator= (const ForwardList& obj);

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, int index);

	void pop_front();
	void pop_back();
	void remove(int index);

	void clear();
	void print();
	size_t length() const;

	T& operator[](int index);

	//TODO
	ForwardList& operator+(const ForwardList& obj);
	void operator+=(const ForwardList& obj);
	int find(const T& value);
};

template<class T>
Node<T>* ForwardList<T>::getNode(int index)
{
	Node<T>* pos = first;
	for (size_t i = 0; i < index; i++)
	{
		pos = pos->next;
	}
	return pos;
}

template<class T>
ForwardList<T>::ForwardList()
{
}

template<class T>
ForwardList<T>::ForwardList(initializer_list<T> list)
{
	for (T elem : list)
	{
		push_back(elem);
	}
}

template<class T>
ForwardList<T>::~ForwardList()
{
	clear();
}

template<class T>
ForwardList<T>::ForwardList(const ForwardList& obj)
{
}

template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& obj)
{
	// TODO: вставьте здесь оператор return
}


template<class T>
void ForwardList<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}
	size++;
}

template<class T>
void ForwardList<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T>
void ForwardList<T>::insert(const T& value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else if (index == size)
	{
		push_back(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* pos = getNode(index - 1);
		newNode->next = pos->next;
		pos->next = newNode;
		size++;
	}
}


template<class T>
void ForwardList<T>::pop_front()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T>
void ForwardList<T>::pop_back()
{
	if (size > 0)
	{
		last = getNode(size - 2);
		delete last->next;
		last->next = nullptr;
		size--;
	}
}

template<class T>
void ForwardList<T>::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}

	if (index == 0)
	{
		pop_front();
	}
	else if (index == size - 1)
	{
		pop_back();
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* temp = pos->next;
		pos->next = pos->next->next;
		delete temp;
		size--;
	}
}


template<class T>
void ForwardList<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T>
void ForwardList<T>::print()
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}


template<class T>
size_t ForwardList<T>::length() const
{
	return size;
}

template<class T>
T& ForwardList<T>::operator[](int index)
{
	return getNode(index);
}

template<class T>
int ForwardList<T>::find(const T& value)
{
	Node<T>* temp = first;
	for (size_t i = 0; i < size; i++)
	{
		if (temp->value == value)
		{
			return i;
		}
		temp = temp->next;
	}
	return -1;
}
