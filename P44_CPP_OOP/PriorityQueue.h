#pragma once
#include <iostream>
#include <initializer_list>

using namespace std;


#include "Node.h"


template<class T, class TPri = int>
class PriorityQueue
{
	Node<T, TPri>* first = nullptr;
	Node<T, TPri>* last = nullptr;
	size_t   size = 0;


public:
	PriorityQueue();

	PriorityQueue(initializer_list<T> list);

	~PriorityQueue();

	PriorityQueue(const PriorityQueue& obj);

	PriorityQueue& operator=(const PriorityQueue& obj);

	void enqueue(const T& value, TPri priority);

	void dequeue();

	T* front();

	bool isEmpty() const;

	size_t length() const;

	void print() const;

	void clear();

	void loop();
};


template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue()
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(initializer_list<T> list)
{
	for (const T& item : list)
	{
		enqueue(item);
	}
}

template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
	clear();
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(const PriorityQueue& obj)
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>& PriorityQueue<T, TPri>::operator=(const PriorityQueue& obj)
{
	// TODO: вставьте здесь оператор return
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, TPri priority)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);

	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (priority > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else if (priority <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else
	{
		Node<T, TPri>* pos = first;
		while (priority <= pos->next->priority)
		{
			pos = pos->next;
		}

		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	if (size > 0)
	{
		Node<T, TPri>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, class TPri>
T* PriorityQueue<T, TPri>::front()
{
	return &first->value;
}

template<class T, class TPri>
bool PriorityQueue<T, TPri>::isEmpty()const
{
	return size == 0;
}


template<class T, class TPri>
size_t PriorityQueue<T, TPri>::length() const
{
	return size;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::print() const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		//cout << "(" << temp->priority << ")-" << temp->value << "   ";
		cout << temp->value;
		temp = temp->next;
	}
	cout << endl;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}