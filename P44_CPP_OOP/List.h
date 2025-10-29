#pragma once
#include <iostream>
#include <initializer_list>

#include "functions.h"
#include "Node.h"

using namespace std;


template<class T>
class List
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t   size  = 0;

	Node<T>* getNode(int index) const;

public:
	List();
	List(initializer_list<T> list);
	~List();
	List(const List& list);
	List& operator=(const List& list);

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, int index);

	void pop_front();
	void pop_back();
	void remove(int index);

	T& front();
	T& back();
	T& at(int index);

	T& operator[](int index) const;

	void clear();
	void print() const;

	size_t length() const;

	List operator+(const List& list);
	void operator+=(const List& list);

	int find(const T& value);

	void for_each(void(*method)(T& value));


	List splice(int index1, int index2);

};

template<class T>
size_t List<T>::length() const
{
	return size;
}


template<class T>
Node<T>* List<T>::getNode(int index) const
{
	Node<T>* pos;
	if (index < size / 2)
	{
		pos = first;
		for (int i = 0; i < index; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (int i = 0; i < size - 1 - index; i++)
		{
			pos = pos->prev;
		}
	}
	return pos;
}



template<class T>
List<T>::List()
{
}

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (T elem : list)
	{
		push_back(elem);
	}
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
List<T>::List(const List& list)
{
}

template<class T>
List<T>& List<T>::operator=(const List<T>& list)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
	size++;
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last->next->prev = last;
		last = last->next;
	}
	size++;
}

template<class T>
void List<T>::insert(const T& value, int index)
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
		Node<T>* pos = getNode(index);
		Node<T>* newNode = new Node<T>(value);
		newNode->next = pos->next;
		pos->next->prev = newNode;
		pos->next = newNode;
		newNode->prev = pos;
		size++;
	}
}

template<class T>
void List<T>::clear()
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
void List<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		//cout << temp->value << " ";
		cout << temp->value;
		temp = temp->next;
	}
	cout << endl;
}


template<class T>
void List<T>::pop_front()
{
	if (size > 0)
	{
		Node<T>* temp = first->next;
		delete first;
		first = temp;
		size--;
		if(first != nullptr)
			first->prev = nullptr;
		
	}
}


template<typename T>
void List<T>::pop_back()
{
	if (size > 0) 
	{
		if (size == 1) 
		{
			delete first;
			first = last = nullptr;
			size = 0;
		}
		else 
		{
			last = last->prev;
			delete last->next;
			last->next = nullptr;
		}
		size--;
	}
}

template<typename T>
void List<T>::remove(int index)
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
		pos->next->prev = pos;
		delete temp;
		size--;
	}

}


template<class T>
void List<T>::for_each(void(*method)(T& value))
{
	Node<T>* temp = first;
	while (temp)
	{
		method(temp->value);
		temp = temp->next;
	}
}

template<class T>
T& List<T>::operator[](int index) const
{
	return getNode(index)->value;
}