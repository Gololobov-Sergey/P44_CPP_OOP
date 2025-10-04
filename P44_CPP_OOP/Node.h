#pragma once

template<class T, class TPri = int>
struct Node
{
	T value;
	TPri priority;
	Node* next;

	Node(T val) : value(val), next(nullptr) {}
	Node(T val, TPri pri) : value(val), priority(pri), next(nullptr) {}
 };