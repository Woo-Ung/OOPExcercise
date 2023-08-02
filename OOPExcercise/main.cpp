#include <iostream>

//����ȯ(type - cast)
//up - cast							down - cast
//child->parent					parent->child
//�Ͻ��� ����(����)				��������� Ȯ��
//Compile - time					Run - tine
//����							����
//Character * p = new Warrior;	(Warrior*)p
//
//Runtime Type Check : RTC
//	RunTime Type Information : RTTI
//
//C++ typecast operators
//
//	static_cast<>()
//	dynamic_cast<>() -Ŭ������ ������ Ȥ�� ������
//
//	reinterpreter_cast<>()
//	const_cast<>()

//���� ���� �Լ�(pure virtual function)
//	���->��Ģ
//	���ǰ� ����!
//
//	function-declaration = 0;
//
//	int x = 0;
//	void f() = 0;
//
//�߻� Ŭ����(Abstract Class)
//	- **���� �����Լ��� ����
//	- �ν��Ͻ� �Ұ� (����Լ��� ���ǰ� ����)
//	- �߻� �θ� Ŭ���� (Abstract Parent Class)

//�������̽�(Interface)
//	��Ģ
//	���������Լ��θ� �̷��� �߻� Ŭ����
//class HDMI
//{
//public:
//	void Power() = 0;
//	void Display() = 0;
//};


class Character
{
protected:
	int mHP;

public:
	Character() : mHP{ 100 }
	{
		std::cout << "[+] Character Created!" << std::endl;
	}
	virtual ~Character()
	{
		std::cout << "[-] Character Destroyed!" << std::endl;
	}

public:
	virtual void Attack() const = 0;
	virtual void Dead() const = 0;
};

class Warrior : public Character
{
public:
	Warrior()
	{
		std::cout << "[+] Warrior Created!" << std::endl;
	}
	~Warrior()
	{
		std::cout << "[-] Warrior Destroyed!" << std::endl;
	}

public:
	void Attack() const override
	{
		std::cout << "����� Į�� �ֵѷ���" << std::endl;
	}

	void Dead() const override
	{
		std::cout << "���簡 ����ߴ�" << std::endl;
	}

	void DoubleSlash() const
	{
		std::cout << "����� ���ϰ� �ι� �ֵѷ���" << std::endl;
	}
};

class Wolf : public Character
{
public:
	void Attack() const override
	{

	}
	void Dead() const override
	{

	}
};

class MyClass
{
public:
	int mVal {10};
};

void Print(char* input)
{
	std::cout << input << std::endl;
}

int main()
{
	const char string[]{ "Hello" };
	Print(const_cast<char*>(string));
	Print(const_cast<char*>("Hello"));

	/*int x;
	MyClass c;

	x = *reinterpret_cast<int*>(&c);
	std::cout << x << std::endl;*/

	//Character* p = new Warrior;
	//p->Attack();
	////((Warrior*)p)->DoubleSlash();
	//Warrior* wp = dynamic_cast<Warrior*>(p);
	//if (wp)
	//{
	//	wp->DoubleSlash();
	//}
	//else
	//{
	//	std::cerr << "Warrior type expected" << std::endl;
	//}

	//delete p;
}
