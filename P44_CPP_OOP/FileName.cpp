#include <iostream>

#include "Student.h"
#include "Array.h"

using namespace std;

inline void func()
{
	cout << "**********************" << endl;
}


int main()
{
	srand(time(0));

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

	
	Array b(10);
	//b.fill(5);
	b.randomFill(5, 15);
	b.print();
	b.resize(15);
	b.print();
	b.sort();
	b.print();
	b.add(99);
	b.print();

	
}