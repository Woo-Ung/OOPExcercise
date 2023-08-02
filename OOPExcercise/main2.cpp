#include <iostream>

//using FunctionPtr = int (*)(float, int);	//C++
//typedef int (*FPtr)(float, int);			//C
//
//int MyFunction(float arg1, int arg2)
//{
//	std::cout << arg1 << ", " << arg2 << std::endl;
//	return 0;
//}
//
//int main()
//{
//	int (*p)(float, int);
//	p = &MyFunction;
//	(*p)(1.1f, 1);
//
//	FunctionPtr p2;
//	p2 = MyFunction;
//	p2(1.1f, 1);
//
//	FPtr p3;
//	p3 = MyFunction;
//	p3(1.1f, 1);
//}


//------------------------------------------------

//Ŭ������ ������
//�Լ� ������
//	float (*)(int)
//	float (myClass::*)(int)

//namespace
//	�ĺ���(Identifier)

class MyClass
{
public:
	int MyMemberFunction(float x)
	{
		std::cout << "����Լ� ȣ��" << std::endl;
		return 0;
	}

	static float MyStaticFunction(int x)
	{
		std::cout << "�����Լ� ȣ��" << std::endl;
		return 0.0f;
	}
};

using FPtr1 = int (MyClass::*)(float);
using FPtr2 = float (*)(int);

int main()
{
	MyClass c;

	FPtr1 p = &MyClass::MyMemberFunction;
	(c.*p)(1.1f);

	FPtr2 p2 = &MyClass::MyStaticFunction;
	(*p2)(1);
}