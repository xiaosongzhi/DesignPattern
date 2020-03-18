#include <iostream>
#include <string>

using namespace std;

//单例模式 ： 类的对象只能有一个

class SignalA
{
private:	//构造函数设置成private,所以在类外就无法进行实例化。
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
	static SignalA* A;//静态成员设置成私有的，在类外就不能通过作用域进行访问

};

SignalA* SignalA::A = NULL;//静态成员类外初始化

//实现单例步骤
//1.构造函数私有化
//2.增加静态私有当前类的指针变量
//3.提供静态对外接口，让用户获得单例对象

//单例分为 懒汉式 和 饿汉式

//懒汉式
class LazySingleton
{
private:
	LazySingleton()
	{
		cout << "我是懒汉式" << endl;
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


//饿汉式
class HungerySingleton
{
private:
	static HungerySingleton* hungery;
	HungerySingleton()
	{
		cout << "我是饿汉式" << endl;
	}

public:
	static HungerySingleton* getInsatce()
	{
		return hungery;
	}
	//正常情况下单例不需要释放，当程序运行结束后会自动释放
#if 0
	static void freeSpace()
	{
		if (hungery != NULL)
			delete hungery;
	}
#endif
};
HungerySingleton* HungerySingleton::hungery = new HungerySingleton;	//在main函数执行之前就已经完成创建了.

int main()
{
	SignalA::getInstance();

	LazySingleton *pLazy1 = LazySingleton::getInstance();
	LazySingleton *pLazy2 = LazySingleton::getInstance();

	if (pLazy1 == pLazy2)
	{
		cout << "lazy 是单例" << endl;//被打印出来了
	}
	else
	{
		cout << "lazy 不是单例" << endl;
	}


	HungerySingleton *pHungry1 = HungerySingleton::getInsatce();
	HungerySingleton *pHungry2 = HungerySingleton::getInsatce();
	

	if (pHungry1 == pHungry2)
	{
		cout << "hungry 是单例" << endl;
	}
	else
	{
		cout << "hungry 不是单例" << endl;
	}

	system("pause");
	return 0;
}