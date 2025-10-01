#pragma once
#include <iostream>

using namespace std;


#include "Node.h"

template<class T, size_t maxSize = 100>
class Stack
{
	Node<T>* first = nullptr;
	size_t   size  = 0;

public:

	Stack();

	~Stack();

	Stack(const Stack& obj);

	Stack& operator=(const Stack& obj);

	void push(const T& value);

	void pop();

	T* peek();

	bool isEmpty() const;

	size_t lehgth() const;

	void print() const;

	void clear();
};


template<class T, size_t maxSize>
Stack<T, maxSize>::Stack()
{
}

template<class T, size_t maxSize>
Stack<T, maxSize>::~Stack()
{
	clear();
}

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack(const Stack& obj)
{
	Node<T>* temp1 = obj.first;
	this->first = new Node<T>(temp1->value);
	Node<T>* temp2 = first;

	while (temp1->next)
	{
		temp1 = temp1->next;
		temp2->next = new Node<T>(temp1->value);
		temp2 = temp2->next;
	}
	size = obj.size;
}

template<class T, size_t maxSize>
Stack<T, maxSize>& Stack<T, maxSize>::operator=(const Stack& obj)
{

}

template<class T, size_t maxSize>
void Stack<T, maxSize>::push(const T& value)
{
	if (size == maxSize)
	{
		return;
	}

	if (size == 0)
	{
		first = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}
	size++;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}


template<class T, size_t maxSize>
T* Stack<T, maxSize>::peek()
{
	return &first->value;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::isEmpty() const
{
	return size == 0;
}

template<class T, size_t maxSize>
size_t Stack<T, maxSize>::lehgth() const
{
	return size;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::print() const
{
	Node<T>* current = first;
	while (current != nullptr)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::clear()
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