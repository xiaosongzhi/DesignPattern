#include <iostream>
#include <string>

using namespace std;

//������תԭ�� ������������˼�������ԭ���Ĵ��ϵ��µ�������ϵ
//ת��ɾ���ʵ�ֲ�͸߲�ҵ��㶼�����ڳ����
//ʵ�ֲ��ҵ��㲻����ֱ�ӵ���ϵ�����Ӵ���Ŀ���չ��


class AbstructBankWorker
{
public:
	virtual void do_business() = 0;
};


/******����ҵ��ʵ�ֲ�********/
//��Ǯҵ��
class SaveBankWorker : public AbstructBankWorker
{
public:
	virtual void do_business()
	{
		cout << "��Ǯҵ��" << endl;
	}
};

//����ҵ��
class BorrowBankWorker : public AbstructBankWorker
{
public:
	virtual void do_business()
	{
		cout << "����ҵ��" << endl;
	}
};

//�в�����

void doNewBusiness(AbstructBankWorker *worker)
{
	worker->do_business();
}


//����ҵ�������ڳ����
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