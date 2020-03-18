#include <iostream>
#include <string>

using namespace std;

//����ģʽ �� ��Ķ���ֻ����һ��

class SignalA
{
private:	//���캯�����ó�private,������������޷�����ʵ������
	SignalA()
	{
	}
public:
	static SignalA *getInstance()
	{	
		if (A == NULL)
			A = new SignalA;
		return A;
	}
private:
	static SignalA* A;//��̬��Ա���ó�˽�еģ�������Ͳ���ͨ����������з���

};

SignalA* SignalA::A = NULL;//��̬��Ա�����ʼ��

//ʵ�ֵ�������
//1.���캯��˽�л�
//2.���Ӿ�̬˽�е�ǰ���ָ�����
//3.�ṩ��̬����ӿڣ����û���õ�������

//������Ϊ ����ʽ �� ����ʽ

//����ʽ
class LazySingleton
{
private:
	LazySingleton()
	{
		cout << "��������ʽ" << endl;
	}
	static LazySingleton* lazy;

public:

	static LazySingleton* getInstance()
	{
		if (lazy == NULL)
			lazy = new LazySingleton;
		return lazy;
	}
};
LazySingleton* LazySingleton::lazy = NULL;


//����ʽ
class HungerySingleton
{
private:
	static HungerySingleton* hungery;
	HungerySingleton()
	{
		cout << "���Ƕ���ʽ" << endl;
	}

public:
	static HungerySingleton* getInsatce()
	{
		return hungery;
	}

	static void freeSpace()
	{
		
	}

};
HungerySingleton* HungerySingleton::hungery = new HungerySingleton;	//��main����ִ��֮ǰ���Ѿ���ɴ�����.

int main()
{
	SignalA::getInstance();

	LazySingleton *pLazy = LazySingleton::getInstance();
	HungerySingleton *pHungry = HungerySingleton::getInsatce();

	system("pause");
	return 0;
}