#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>  
#include <crtdbg.h>
#include <iostream>
#include <string>
#include "Stack.h"

void test1()
{
	Stack s;
	s.Push(2);
	s.Push(8);
	if (s.Pop() == 8 && s.Pop() == 2 && s.Empty())
		std::cout << "    Test 1 passed!\n";
	else
		std::cout << "*** Test 1 failed!\n";
}

void test2()
{
	Stack s;
	s.Push(2);
	s.Push(80);
	s.Push(6);
	s.Push(-51);
	if (s.Size() == 4)
		std::cout << "    Test 2 passed!\n";
	else
		std::cout << "*** Test 2 failed!\n";
}

void test3()
{
	Stack s;
	s.Push(3);
	s.Push(5);
	s.Pop();
	s.Push(69);
	s.Push(420);
	s.Push(42);
	s.Push(21);
	s.Pop();
	s.Pop();
	s.Pop();
	if (s.Size() == 2)
		std::cout << "    Test 3 passed!\n";
	else
		std::cout << "*** Test 3 failed!\n";
}

void test4()
{
	Stack s;
	s.Push(2);
	s.Push(5);
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	if (s.Size() == 0)
		std::cout << "    Test 4 passed!\n";
	else
		std::cout << "*** Test 4 failed!\n";
}

void test5()
{
	Stack s;
	s.Push(7);
	s.Push(3);

	Stack s2 = s;
	s2.Pop();

	if (s.Size() == 2 && s2.Pop() == 7)
		std::cout << "    Test 5 passed!\n";
	else
		std::cout << "*** Test 5 failed!\n";
}

void test6()
{
	Stack s;
	s.Push(5);
	s.Push(8);

	{
		Stack s2 = s;
		s2.Pop();
	}

	if (s.Size() == 2 && s.Pop() == 8)
		std::cout << "    Test 6 passed!\n";
	else
		std::cout << "*** Test 6 failed!\n";
}

void test7()
{
	Stack s;
	s.Push(5);
	s.Push(8);

	Stack s2;
	s2 = s;
	s2.Pop();

	if (s.Size() == 2 && s2.Pop() == 5)
		std::cout << "    Test 7 passed!\n";
	else
		std::cout << "*** Test 7 failed!\n";
}

void test8()
{
	Stack s;
	s.Push(5);
	s.Push(8);

	{
		Stack s2;
		s2 = s;
		s2.Pop();
	}

	if (s.Size() == 2 && s.Pop() == 8)
		std::cout << "    Test 8 passed!\n";
	else
		std::cout << "*** Test 8 failed!\n";
}

void test9()
{
	Stack s;
	s.Push(5);
	s.Push(6);

	{
		Stack s2;
		s2.Push(3428756);
		s2.Push(432785);
		s2 = s;
		s2.Pop();
	}

	if (s.Size() == 2 && s.Pop() == 6)
		std::cout << "    Test 9 passed!\n";
	else
		std::cout << "*** Test 9 failed!\n";
}

//void test10()
//{
//	Stack s;
//	s.Push(350);
//	s.Push(743265);
//	s.Push(816);
//	s.Push(21);
//	for (auto& n : s)
//		n *= 10;
//	for (auto n : s)
//		std::cout << n << ", ";
//
//	std::cout << std::endl << "    Test 10 passed!\n";
//}
//
//void test11()
//{
//	Stack s;
//	s.Push(350);
//	s.Push(743265);
//	s.Push(816);
//	s.Push(21);
//
//	const Stack& cs = s;
//	for (auto& n : cs)
//		std::cout << n << ", ";
//
//	std::cout << std::endl << "    Test 10 passed!\n";
//}

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);

	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);

	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

	test1();
	test2();
	test3();
	test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	//test11();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

