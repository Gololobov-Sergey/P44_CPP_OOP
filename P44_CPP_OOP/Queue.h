#pragma once
#include <iostream>
#include <initializer_list>

using namespace std;


#include "Node.h"


template<class T>
class Queue
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t   size  = 0;


public:
	Queue();
	
	Queue(initializer_list<T> list);
	
	~Queue();
	
	Queue(const Queue& obj);
	
	Queue& operator=(const Queue& obj);
	
	void enqueue(const T& value);
	
	void dequeue();
	
	T* front();
	
	bool isEmpty() const;
	
	size_t length() const;
	
	void print() const;
	
	void clear();

	void loop();
};

template<class T>
Queue<T>::Queue() { }

template<class T>
Queue<T>::Queue(initializer_list<T> list)
{
	for (const T& item : list) 
	{
		enqueue(item);
	}
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}

template<class T>
Queue<T>::Queue(const Queue& obj)
{
	Node<T>* temp = obj.first;
	while (temp)
	{
		this->enqueue(temp->value);
		temp = temp->next;
	}
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& obj)
{
	if (this == &obj)
		return *this;

	this->clear();

	Node<T>* temp = obj.first;
	while (temp)
	{
		this->enqueue(temp->value);
		temp = temp->next;
	}

	return *this;
}

template<class T>
void Queue<T>::enqueue(const T& value)
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
void Queue<T>::dequeue()
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
T* Queue<T>::front()
{
	return &first->value;
}

template<class T>
bool Queue<T>::isEmpty()const
{
	return size == 0;
}


template<class T>
size_t Queue<T>::length() const
{
	return size;
}

template<class T>
void Queue<T>::print() const
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
void Queue<T>::clear()
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
void Queue<T>::loop()
{
	if (size > 1)
	{
		last->next = first;
		first = first->next;
		last = last->next;
		last->next = nullptr;
	}
}
