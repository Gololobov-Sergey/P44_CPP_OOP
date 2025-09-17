#include <iostream>

#include "Student.h"
#include "Array.h"
#include"String.h"

using namespace std;

inline void func()
{
	cout << "**********************" << endl;
}

void printArray(Array a)
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
	srand(time(0));


	// 17.09.2025

	String s1;
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
	f("mama");

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