#pragma once
#include <iostream>

using namespace std;

//模拟开闭原则，增加新的功能不改变源代码，只需要增加新的代码即可
//其核心思想就使用多态

class AbstructCalculator
{
public:
	AbstructCalculator(double a, double b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	void setNum(double a,double b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	virtual double calculator() = 0;

	virtual ~AbstructCalculator()
	{
	}
public:
	double m_a;
	double m_b;
};
//加法运算
class Add : public AbstructCalculator
{
public:
	Add(double a, double b) :AbstructCalculator(a,b)
	{
	}
	virtual double calculator()
	{
		return m_a + m_b;
	}

};
//减法运算
class Minus : public AbstructCalculator
{
public:
	Minus(double a, double b) :AbstructCalculator(a, b)
	{
	}
	virtual double calculator()
	{
		return m_a - m_b;
	}

};

//乘法运算
class Multi : public AbstructCalculator
{
public:
	Multi(double a, double b) :AbstructCalculator(a, b)
	{
	}
	virtual double calculator()
	{
		return m_a * m_b;
	}

};

//除法运算
class Divide : public AbstructCalculator
{
public:
	Divide(double a, double b) :AbstructCalculator(a, b)
	{
	}
	virtual double calculator()
	{
		return m_a / m_b;
	}

};

#if 0
int main()
{
	AbstructCalculator *calculator = new Add(11,22);
	//calculator->setNum(10,20);
	cout << calculator->calculator() << endl;

	delete calculator;

	AbstructCalculator *calculator1 = new Minus(10, 20);
	cout << calculator1->calculator() << endl;

	delete calculator1;

	system("pause");
	return 0;
}
#endif