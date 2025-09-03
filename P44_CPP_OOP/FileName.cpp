#include <iostream>

#include "Student.h"

using namespace std;

int main()
{
	Student st("Vasya", 15);
	Student st2;
	//st.age = 1500000000;
	//st.setAge(14);
	//st.setName("Vasya");
	st.print();

	int a = st.getAge();
}