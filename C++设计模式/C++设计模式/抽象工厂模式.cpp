#include <iostream>
#include <string>

using namespace std;

//首先解释一些术语：
//产品族 ：同一产地或者同一厂商，功能不同
//产品等级 ：功能相同但产地或者厂商不同
//抽象工厂是针对产品族，而不是针对产品等级

class AbstructApple
{
public:
	virtual void show_name() = 0;
};

class ChineseApple : public AbstructApple
{
public:
	virtual void show_name()
	{
		cout << "中国苹果" << endl;
	}
};

class AmericaApple : public AbstructApple
{
public:
	virtual void show_name()
	{
		cout << "美国苹果" << endl;
	}
};

class JapaneseApple : public AbstructApple
{
public:
	virtual void show_name()
	{
		cout << "日本苹果" << endl;
	}
};
/***********************/
class AbstructBanana
{
public:
	virtual void show_name() = 0;
};

class ChineseBanana : public AbstructBanana
{
public:
	virtual void show_name()
	{
		cout << "中国香蕉" << endl;
	}
};

class AmericaBanana : public AbstructBanana
{
public:
	virtual void show_name()
	{
		cout << "美国香蕉" << endl;
	}
};

class JapaneseBanana : public AbstructBanana
{
public:
	virtual void show_name()
	{
		cout << "日本香蕉" << endl;
	}
};

/***********************/
class AbstructPear
{
public:
	virtual void show_name() = 0;
};

class ChinesePear : public AbstructPear
{
public:
	virtual void show_name()
	{
		cout << "中国鸭梨" << endl;
	}
};

class AmericaPear : public AbstructPear
{
public:
	virtual void show_name()
	{
		cout << "美国鸭梨" << endl;
	}
};

class JapanesePear : public AbstructPear
{
public:
	virtual void show_name()
	{
		cout << "日本鸭梨" << endl;
	}
};

//抽象工厂
class AbstructFactory
{
public:
	virtual AbstructApple* create_apple() = 0;
	virtual AbstructBanana* create_banana() = 0;
	virtual AbstructPear* create_pear() = 0;
};

class ChineseFactory:public AbstructFactory
{
public:
	virtual AbstructApple* create_apple()
	{
		return new ChineseApple;
	}
	virtual AbstructBanana* create_banana()
	{
		return new ChineseBanana;
	}

	virtual AbstructPear* create_pear()
	{
		return new ChinesePear;
	}
};

class AmericanFactory :public AbstructFactory
{
public:
	virtual AbstructApple* create_apple()
	{
		return new AmericaApple;
	}
	virtual AbstructBanana* create_banana()
	{
		return new AmericaBanana;
	}

	virtual AbstructPear* create_pear()
	{
		return new AmericaPear;
	}
};

class JapaneseFactory :public AbstructFactory
{
public:
	virtual AbstructApple* create_apple()
	{
		return new JapaneseApple;
	}
	virtual AbstructBanana* create_banana()
	{
		return new JapaneseBanana;
	}

	virtual AbstructPear* create_pear()
	{
		return new JapanesePear;
	}
};

//抽象工厂模式测试
//前期需要写很多个类，但是后期如果想新增国家的话就比较简单了
//但是想加水果的种类，就会涉及到很大的改动
void test05()
{	
	AbstructFactory *factory = NULL;
	AbstructApple *apple = NULL;
	AbstructBanana *banana = NULL;
	AbstructPear *pear = NULL;

	factory = new ChineseFactory;
	apple = factory->create_apple();
	apple->show_name();
	banana = factory->create_banana();
	banana->show_name();
	pear = factory->create_pear();
	pear->show_name();

	delete pear;
	delete banana;
	delete apple;
	delete factory;

	cout << "================================" << endl;

	factory = new AmericanFactory;
	apple = factory->create_apple();
	apple->show_name();
	banana = factory->create_banana();
	banana->show_name();
	pear = factory->create_pear();
	pear->show_name();

	delete pear;
	delete banana;
	delete apple;
	delete factory;

	cout << "================================" << endl;
	factory = new JapaneseFactory;
	apple = factory->create_apple();
	apple->show_name();
	banana = factory->create_banana();
	banana->show_name();
	pear = factory->create_pear();
	pear->show_name();

	delete pear;
	delete banana;
	delete apple;
	delete factory;
}

#if 0
int main()
{
	test05();
	system("pause");
	return 0;
}
#endif