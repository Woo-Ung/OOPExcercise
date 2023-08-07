#include <iostream>

//Template

//Generic Prigramming - template ����
//
//template <typename T1,typenamet2,...>

// ���ǻ���
//1. Ÿ�Կ� ������ �� �ƴմϴ�. �� ��ŭ�� �ڵ尡 �߰��Ǵ� ��!
//	�����Ϸ��� ������ �ð��� �ڵ� ����
//
//
//2. ����� ���Ǵ� ���� ���Ͽ� �����ؾ� �մϴ�.


//template <typename T>
//T Sum(T x, T y)											//�Ϲ�ȭ generalization
//{
//	T sum;
//	sum = x + y;
//
//	return sum;
//}
//
//int main()
//{
//	//�Ͻ��� ǥ���
//	std::cout << Sum(1, 2) << std::endl;
//	std::cout << Sum('A', 'B') <<std::endl;
//
//	//����� ǥ�⺱
//	std::cout << Sum<int>(1, 2) << std::endl;			//Ư��ȭ int�� Ư��ȭ�� �Լ�
//	std::cout << Sum<float>(1.1f, 1.2f) << std::endl;
//	std::cout << Sum<char>(65, 1) << std::endl;
//}
//
//// Compiler
//
//int Sum(int x, int y)
//{
//	int sum;
//	sum = x + y;
//
//	return sum;
//}



template <typename T>
void Sort(T x[], T y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (x[i] < x[j])
			{
				T temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	
}

template <typename R>
void Print(R x[], R y)
{
	for (int i = 0;i < y;i++)
	{
		std::cout << x[i] << " ";
	} std::cout << std::endl;
	
};

// non-type template parameter
template <typename R, int y>
void Print2(R x[])
{
	for (int i = 0;i < y;i++)
	{
		std::cout << x[i] << " ";
	} std::cout << std::endl;

};

int main()
{
	int array1[5]{ 1,2,3,5,4 };
	Sort<int>(array1, 5);
	Print<int>(array1, 5);
	Print2<int, 5>(array1);

	float array[5]{ 1.1f, 2.5f, 3.1f, 5.0f, 4.2f };
	Sort<float>(array, 5);
	Print<float>(array, 5);
}



//////////////////////////////////////////////////
template <typename T>
class MyClass
{
	T mValue;

public:
	void Function(T arg);
};

int main()
{
	MyClass<int> c1; // c1 -> MyClass<int>

	c1.Function(10); // c2 -> MyClass<int>::Function()
}

template <typename T>
void MyClass<T>::Function(T arg)
{
	T temp = arg;
	temp += arg;
}