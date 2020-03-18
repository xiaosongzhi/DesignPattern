#include <iostream>
#include <string>

using namespace std;

//���Ƚ���һЩ���
//��Ʒ�� ��ͬһ���ػ���ͬһ���̣����ܲ�ͬ
//��Ʒ�ȼ� ��������ͬ�����ػ��߳��̲�ͬ
//���󹤳�����Բ�Ʒ�壬��������Բ�Ʒ�ȼ�

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
		cout << "�й�ƻ��" << endl;
	}
};

class AmericaApple : public AbstructApple
{
public:
	virtual void show_name()
	{
		cout << "����ƻ��" << endl;
	}
};

class JapaneseApple : public AbstructApple
{
public:
	virtual void show_name()
	{
		cout << "�ձ�ƻ��" << endl;
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
		cout << "�й��㽶" << endl;
	}
};

class AmericaBanana : public AbstructBanana
{
public:
	virtual void show_name()
	{
		cout << "�����㽶" << endl;
	}
};

class JapaneseBanana : public AbstructBanana
{
public:
	virtual void show_name()
	{
		cout << "�ձ��㽶" << endl;
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
		cout << "�й�Ѽ��" << endl;
	}
};

class AmericaPear : public AbstructPear
{
public:
	virtual void show_name()
	{
		cout << "����Ѽ��" << endl;
	}
};

class JapanesePear : public AbstructPear
{
public:
	virtual void show_name()
	{
		cout << "�ձ�Ѽ��" << endl;
	}
};

//���󹤳�
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

//���󹤳�ģʽ����
//ǰ����Ҫд�ܶ���࣬���Ǻ���������������ҵĻ��ͱȽϼ���
//�������ˮ�������࣬�ͻ��漰���ܴ�ĸĶ�
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