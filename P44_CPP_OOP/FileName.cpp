#include <iostream>

#include "functions.h"
#include "Student.h"
#include "Array.h"
#include"String.h"
#include "Reservoir.h"
#include "Fraction.h"
#include<set>
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

inline void func()
{
	cout << "**********************" << endl;
}

template<typename T>
void printArray(Array<T> a)
{
	a.print();
}

void printStudent(Student a)
{
	a.print();
}


void f(String s)
{

}


int main()
{
	SetColor(Color::White, Color::Blue);
	system("cls");
	srand(time(0));


	// 04.01.2025


	int i = 0;
	while (true)
	{
		cout << ++i << endl;
		if (i % 4 == 0)
			cout << "add passenger" << endl;
		Sleep(1000);
	}




	/*PriorityQueue<int> pq;
	pq.enqueue(10, 4);
	pq.enqueue(40, 1);
	pq.enqueue(30, 3);
	pq.enqueue(20, 3);
	pq.enqueue(10, 1);

	pq.print();*/


	/*Queue<int> q = { 1 };
	q.print();
	q.loop();
	q.print();*/
	/*q.enqueue(10);
	q.print();
	q.dequeue();
	q.print();
	q.clear();
	q.print();*/

	/*Queue<int> q2(q);
	q2.print();*/


	// 01.01.2025

	//Stack<int, 10> s;
	////s.push(10);
	//int* a = s.peek();
	//if(a)
	//	cout << *a << endl;

	/*s.push(10);
	s.push(20);
	s.push(30);
	s.push(40)*/;
	//s.print();

	//Stack<int, 10> s2 = s;

	//s2 = s;

	//s2.print();

	/*String s1("mama");
	String s2("mama");
	cout << (s1 == s2) << endl;

	cout << (void*)s1.getStr() << endl;
	cout << (void*)s2.getStr() << endl;*/


	// >0 0 <0

	// 24.09.2025

	// :: ?: * -> sizeof


	// Operator overloading
	// ++ -- - +
	// + - * / % = += -= *= /= %=
	// !
	// == != > < >= <=

	// && ||

	// []

	// ()


	/*Fraction f1(3, 4);	
	Fraction f2(5, 40);*/
	//Fraction f3 = f1.add(f2);
	//Fraction f3 = -f1; // f1.operator-();
	//f3.print();
	//(++f1).print();
	//(f1++).print();
	//f1.print();
	//Fraction f3 = f1 + f2;
	//f3.print();

	//f2 += f1 += f1; // f2 = f2 + f1; // f2.operator+=(f1);

	//Fraction f4 = f1 + 10;
	//Fraction f5 = 10 + f1; // Error // 10.operator+(f1);
	
	/*if (f1 == f2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;

	}*/


	//float ff = f1;


	//Array<int> a1(5);
	//a1.randomFill(1, 10);
	//Array<int> a2 = a1;
	////
	//a2 = a1;
	//a1.print();

	//a1[1] = 99;

	//cout << a1[1] << endl;

	//

	//String s("mama");
	//cout << s << endl;
	//cin >> s;
	//cout << s << endl;

	/*Array<double> a2(5);
	a2.randomFill(1, 10);*/



	/*ReservoirType rt = ReservoirType::OCEAN;
	ReservoirType rt1 = ReservoirType::POND;
	Color c = Color::RED;
	if (rt == rt1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}*/


	/*String n;
	cout << sizeof(String) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(size_t) << endl;

	Array<int> a(5);
	Array<double> a1(5);
	Array<String> a2(5);
	Array<Student> a3(5);*/


	// 17.09.2025

	/*String s1;
	String s2(20);
	String s3("mama");
	String s4(s3);

	s1.print();
	s2.print();
	s3.print();

	cout << s1.length() << endl;
	cout << s2.length() << endl;
	cout << s3.length() << endl;


	s3.set();
	s3.set("papa");


	f(20);
	f("mama");*/

	// 10.09.2025


	//const Array a(5);
	//a.randomFill(1, 10);
	//a.print();
	////a.add(99);
	//

	////Student st("Vasya", 15, 99);
	////st.print();

	//printArray(a);
	//a.print();


	//Student st("Vasya", 15, 99);
	//st.print(); // print(st);
	//printStudent(st);
	//st.print();

	//char* n;

	//{
	//	Student st("Vasya", 15);
	//	Student st2;
	//	//st.age = 1500000000;
	//	//st.setAge(14);
	//	//st.setName("Vasya");
	//	st.print();
	//	n = st.getName();
	//	int a = st.getAge();
	//}
	//
	//cout << n << endl;


	/*const int t = 5;
	
	int a = 10.55;
	int b(10.55);
	int c{ 10 };

	

	cout << "Count : " << Student::getCount() << endl;
	{
		Student st("Vasya", 15, 99);
		Student st2;

		st.print();
		cout << "Count : " << st.getCount() << endl;

	}
	cout << "Count : " << Student::getCount() << endl;

	func();*/

	
	//Array b(10);
	////b.fill(5);
	//b.randomFill(5, 15);
	//b.print();
	//b.resize(15);
	//b.print();
	//b.sort();
	//b.print();
	//b.add(99);
	//b.print();

	
}