#pragma once
#include <iostream>

using namespace std;

//ģ�⿪��ԭ�������µĹ��ܲ��ı�Դ���룬ֻ��Ҫ�����µĴ��뼴��
//�����˼���ʹ�ö�̬

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
//�ӷ�����
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
//��������
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

//�˷�����
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

//��������
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