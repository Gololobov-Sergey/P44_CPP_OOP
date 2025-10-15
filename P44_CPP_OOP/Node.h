#pragma once

template<class T, class TPri = int>
struct Node
{
	T value;
	TPri priority;
	Node* next;
	Node* prev;

	Node(T val) : value(val), next(nullptr), prev(nullptr) {}
	Node(T val, TPri pri) : value(val), priority(pri), next(nullptr), prev(nullptr) {}
 };