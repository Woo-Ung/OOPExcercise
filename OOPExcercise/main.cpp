#include <iostream>

//형변환(type - cast)
//up - cast							down - cast
//child->parent					parent->child
//암시적 가능(안전)				명시적으로 확인
//Compile - time					Run - tine
//빠름							느림
//Character * p = new Warrior;	(Warrior*)p
//
//Runtime Type Check : RTC
//	RunTime Type Information : RTTI
//
//C++ typecast operators
//
//	static_cast<>()
//	dynamic_cast<>() -클래스의 참조형 혹은 포인터
//
//	reinterpreter_cast<>()
//	const_cast<>()

//순수 가상 함수(pure virtual function)
//	약속->규칙
//	정의가 없음!
//
//	function-declaration = 0;
//
//	int x = 0;
//	void f() = 0;
//
//추상 클래스(Abstract Class)
//	- **순수 가상함수가 존재
//	- 인스턴스 불가 (멤버함수의 정의가 없음)
//	- 추상 부모 클래스 (Abstract Parent Class)

//인터페이스(Interface)
//	규칙
//	순수가상함수로만 이뤄진 추상 클래스
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
		std::cout << "전사는 칼을 휘둘렀다" << std::endl;
	}

	void Dead() const override
	{
		std::cout << "전사가 사망했다" << std::endl;
	}

	void DoubleSlash() const
	{
		std::cout << "전사는 강하게 두번 휘둘렀다" << std::endl;
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
