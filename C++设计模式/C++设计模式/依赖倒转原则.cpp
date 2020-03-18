#include <iostream>
#include <string>

using namespace std;

//依赖倒转原则 个人理解其核心思想就是由原来的从上到下的依赖关系
//转变成具体实现层和高层业务层都依赖于抽象层
//实现层和业务层不存在直接的联系，增加代码的可扩展性


class AbstructBankWorker
{
public:
	virtual void do_business() = 0;
};


/******具体业务实现层********/
//存钱业务
class SaveBankWorker : public AbstructBankWorker
{
public:
	virtual void do_business()
	{
		cout << "存钱业务" << endl;
	}
};

//贷款业务
class BorrowBankWorker : public AbstructBankWorker
{
public:
	virtual void do_business()
	{
		cout << "贷款业务" << endl;
	}
};

//中层抽象层

void doNewBusiness(AbstructBankWorker *worker)
{
	worker->do_business();
}


//具体业务依赖于抽象层
void test04()
{
	AbstructBankWorker *newWorker1 = new BorrowBankWorker;
	doNewBusiness(newWorker1);
	AbstructBankWorker *newWorker2 = new SaveBankWorker;
	doNewBusiness(newWorker2);

	delete newWorker1;
	delete newWorker2;
}
#if 0
int main()
{
	test04();
	system("pause");
	return 0;
}
#endif