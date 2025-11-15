#include <iostream>

#include "functions.h"
#include "Student.h"
#include "Array.h"
#include "String.h"
#include "Reservoir.h"
#include "Fraction.h"
#include <set>
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "ForwardList.h"
#include "PrintServer.h"
#include "List.h"
#include "BTree.h"
#include "Relation.h"
#include "Inherit.h"
#include "Animal.h"
#include "WorldWar.h"
#include "MyException.h"
#include "DateTime.h"
#include "SmartPointer.h"
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>
#include <random>

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


Student f(String s)
{
	Student st;
	return st;
}

void mult2(int& a)
{
	a *= 2;
}


double division(double a, double b, ILogError& log)
{
	if (b == 0)
	{
		log.saveError("Div by zero!");
		return 0;
	}

	//
	return a / b;
}


void print_flying(List<IFly*>& fly)
{
	for (size_t i = 0; i < fly.length(); i++)
	{
		fly[i]->fly();
	}
}


void func666()
{
	SmartPointer<Cat> c(new Cat("Tom", 3));



	///

	int a;
	cin >> a;
	if (a == 0)
		return;
	//
	//

	//delete an;
}


bool big10(int a)
{
	return a > 10;
}

template<class Container>
void print(Container& c)
{
	for (auto el : c)
	{
		cout << el << " ";
	}
	cout << endl;
}



class Random {
public:
	template<typename T>
	static T get(T from, T to) {
		static thread_local std::mt19937 generator(std::random_device{}());

		if constexpr (std::is_integral<T>::value) {
			std::uniform_int_distribution<T> dist(from, to);
			return dist(generator);
		}
		else if constexpr (std::is_floating_point<T>::value) {
			std::uniform_real_distribution<T> dist(from, to);
			return dist(generator);
		}
	}
};

void gen(vector<int>& v)
{
	generate(v.begin(), v.end(), []() { return Random::get(0, 100); });
}


int main()
{
	SetColor(Color::White, Color::Blue);
	cout.setf(ios::boolalpha);
	system("cls");
	srand(time(0));


	vector<int> v = { 1,2,4,2,98,0 };
	vector<string> s(6);
	//print(v);
	//for_each(v.begin(), v.end(), [](int& a) {a *= 2; });
	print(v);
	//cout << all_of(v.begin(), v.end(), [](int& a) { return a > 0; }) << endl;

	//auto it = find(v.begin(), v.end(), 120);
	//auto it = find_if(v.begin(), v.end(), [](int& a) { return a > 1000; });
	/*auto it = find_if(v.begin(), v.end(), [](int& a) { return a > 1000; });
	if(it != v.end())
		cout << *it << endl;*/

	//cout << count_if(v.begin(), v.end(), [](int& a) { return a < 10; }) << endl;

	//copy_if(v.begin(), v.end(), ostream_iterator<int>(cout, " "), [](int a) {return a % 2 == 0; });

	//replace(v.begin(), v.end(), 2, 100);
	//replace_if(v.begin(), v.end(), [](int a) {return a % 2 == 0; }, 100);
	//print(v);

	//transform(v.cbegin(), v.cend(), s.begin(), [](int val) { return to_string(val); });
	//print(s);

	vector<int> vv(10);
	//generate(vv.begin(), vv.end(), rand);
	gen(vv);
	print(vv);
	sort(vv.begin(), vv.end());
	print(vv);
	std::random_device rd;
	std::mt19937 g(rd());
	shuffle(vv.begin(), vv.end(), g);
	print(vv);

	// 08.11.2025


	/*vector<int> v = { 1,2,4,6,98,0 };
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	auto it = v.begin() + 3;
	cout << *it << endl;

	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << v.max_size() << endl;
	cout << v.capacity() << endl;
	v.push_back(99);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	v.shrink_to_fit();
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	int a = 999;
	v.insert(v.begin() + 4, a);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;*/

	/*erase(v, 999);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	erase_if(v, [](int a) {return a < 10; });
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;*/


	/*list<int> l = { 8,7,7,8,9,6,7,8 };

	auto i = l.begin();
	advance(i, 2);

	i = next(i, 2);

	l.insert(next(l.begin(), 2), v.begin() + 2, v.begin() + 5);
	for (int el : l)
	{
		cout << el << " ";
	}
	cout << endl;*/



	/*int b = 100, c = 888;
	auto f = [&](int a) -> int
		{ 
			if (a == b)
				return 100;
			else
				return 100.0;
		};
	f(100);*/


	//list<Student> vs;
	//vs.insert(vs.begin(), Student("Vasya", 24, 10));
	//vs.emplace_back("Petya", 14, 6);
	//vs.emplace_back("Kolya", 34, 6);
	//vs.emplace_back("Anna", 4, 6);

	////vs.sort([](const Student& s1, const Student& s2) { return strcmp(s1.getName(), s2.getName()) < 0; });
	//vs.sort([](const Student& s1, const Student& s2) { return s1.getAge() < s2.getAge(); });

	//for (Student& s : vs)
	//{
	//	cout << s.getName() << endl;
	//}


	/*DateTime d(2025, 11, 8);
	cout << DateTime::now() << endl;*/


	// 05.11.2025





	/*func666();

	int a = 9, b = 10;

	swap(a, b);

	int&& r = 10;

	List<Cat> l;
	Cat c("Tom", 3);
	l.push_back(c);
	l.push_back(Cat("sss", 10));


	unique_ptr<Cat> uc = make_unique<Cat>("Tom", 3);
	unique_ptr<Cat> uc1 = move(uc);*/

	/*{
		shared_ptr<Cat> sh = make_shared<Cat>("Tom", 3);
		{
			shared_ptr<Cat> sh1(sh);
		}
	}*/

	//// 01.11.2025

	//int a, b;
	//cin >> a >> b;
	//try
	//{
	//	List<int> l;


	//	if (b == 0)
	//		//throw MyException(DateTime::now().to_longDateTime(), __FILE__, __LINE__, "Div by zero (b = 0)");
	//		throw invalid_argument("Div by zero (b = 0)");
	//	cout << a / b << endl;
	//}
	//catch (int ex)
	//{
	//	cout << ex << endl;
	//}
	//catch (const char* ex)
	//{
	//	cout << ex << endl;
	//}
	//catch (MyException& ex)
	//{
	//	ex.saveError();
	//	cout << ex.getError() << endl;
	//}
	//catch (exception& ex)
	//{
	//	cout << ex.what() << endl;
	//}
	//catch (...)
	//{
	//	cout << "Fatal error" << endl;
	//}



	/*Animal* ad = new Cat("Tom", 5);
	Cat* cat = dynamic_cast<Cat*>(ad);
	if (cat)
	{
		cat->catch_mouse();
		cout << cat->getType() << endl;
	}*/


	//cout << ad.getType() << endl;



	//Animal* p_dog = new Dog("Spike", 5);


	/*hash<string> h;
	cout << h("mama") << endl;*/



	// 29.10.2025

	/*try
	{
		WorldWar w(5);
		w.game();
	}
	catch (...)
	{
		cout << "Fatal error" << endl;
	}*/



	// 28.10.2025

	/*FileLogError f_log("log.txt");

	ConsoleLogError c_log;

	cout << division(8, 0, c_log) << endl;

	List<IFly*> fly = { new Sparrow("Gorobec", 1), new Parrot("Kesha", 2)};
	print_flying(fly);*/



	//{
	//	Animal* cat = new Cat("Tom", 3);

	//	cout << cat->Animal::getType() << endl;

	//	//
	//	delete cat;
	//}


	// 25.10.2025


	///*Animal a("No name", 0);
	//cout <<a.getType() << endl;
	//a.print();
	//cout << a.getVoice() << endl;*/

	//Cat cat("Tom", 3);
	//
	///*cout << cat.getType() << endl;
	//cat.print();
	//cout << endl;*/


	//Animal& r_cat = cat;
	///*cout << r_cat.getType() << endl;
	//r_cat.print();*/
	////cout << endl;


	//Animal* p_cat = &cat;
	////cout << p_cat->getType() << endl;
	////p_cat->print();
	////cout << endl;

	//Animal* p_dog = new Dog("Spike", 5);
	////cout << p_dog->getType() << endl;
	////p_dog->print();


	//List<Animal*> zoo = { p_cat, p_dog, new SiamCat("Murzik", 4), new Ravlik("Roma", 1)};
	//for (size_t i = 0; i < 4; i++)
	//{
	//	cout << zoo[i]->getType() << endl;
	//	zoo[i]->print();
	//	cout << zoo[i]->getVoice() << endl;
	//	cout << endl;
	//}


	/*Router r(123, 345, 456, 678);
	cout << r.WiFi::Device::id << endl;
	cout << r.LAN::Device::id << endl;*/


	// 22.10.2025

	//Human h("Vasya", 20);
	//h.print();
	//

	//cout << endl;
	//Worker w("Petya", 30, 5);
	///*w.name = "Petya";
	//w.age = 30;*/
	////w.workTime = 5;
	//w.print();


	/*Director d;

	int val = 22;
	printf("%s = %d%%", "Value", val);*/



	/*A a;
	B b;*/



	/*Engine* en = new Engine;
	{
		Car c(en);
		c.move();
	}
	STO sto;
	sto.setEngine(en);
	sto.upgrade();*/

	// 18.10.2025

	/*BTree<int, int> b;
	b.push_r(20, 20);
	b.push_r(2, 2);
	b.push_r(22, 22);
	b.push_r(15, 15);
	b.push_r(10, 10);
	cout << b.push_r(8, 8) << endl;
	cout << b.push_r(8, 8) << endl;
	b.print();

	cout << *b.getValue(10) << endl;*/

	//BTree<string, List<Protocol>> base;


	// 15.10.2025

	/*List<int> l = { 1,2,3,4,5 };
	l.print();
	l.insert(99, 4);
	l.print();
	l.pop_front();
	l.print();
	l.remove(3);
	l.print();
	l.for_each(mult2);
	l.print();*/


	// 11.10.2025


	/*string fName[] = { "file1.doc", "file2.xls", "file3.txt", "file4.pdf", "file5.ppt" };

	PrintServer ps("10.6.6.58");

	int i = 0;
	while (true)
	{
		if (i % 5 == 0)
		{
			ps.addTask(TaskPrint(fName[rand() % 5], rand() % 3 + 5, (DEPARTMENT)(rand() % 4)));
		}
		ps.work();
		i++;
		Sleep(100);
	}*/



	// 08.10.2025

	/*ForwardList<int> list = { 1,2,34,5,6,7 };
	list.print();*/



	// 04.10.2025


	/*int i = 0;
	while (true)
	{
		cout << ++i << endl;
		if (i % 4 == 0)
			cout << "add passenger" << endl;
		Sleep(1000);
	}*/




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


	// 01.10.2025

	//Stack<int, 10> s;
	////s.push(10);
	//int* a = s.peek();
	//if(a)
	//	cout << *a << endl;

	/*s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);*/
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