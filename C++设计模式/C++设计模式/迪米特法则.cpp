#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������ԭ���ֽ�֪ʶ����ԭ��
//������⣺�����˼���������н飬���������ⷿ����ô�Ҳ�����Ҫֱ���ҵ��ܶ������
//��Ҳ����Ҫ�˽�ܶ����¥����֪ʶ����ֻ��Ҫ��һ���ⷿ�н飬�����ҽ��ҵ�������߸��������幤�����������
//�������û��;���¥���������

class AbstructBuilding
{
public:
	AbstructBuilding()
	{

	}
	virtual void sale() = 0;//¥������
	virtual string getQuality() = 0;
	virtual ~AbstructBuilding()
	{

	}
};

class BuildingA : public AbstructBuilding
{
public:
	BuildingA() :quality("good")
	{

	}
	virtual void sale()
	{
		cout << "¥��A������" << " Ʒ��" << quality << endl;
	}
	virtual string getQuality()
	{
		return quality;
	}
	~BuildingA()
	{

	}
private:
	string quality;
};

class BuildingB : public AbstructBuilding
{
public:
	BuildingB() :quality("bad")
	{

	}
	virtual void sale()
	{
		cout << "¥��B������" << " Ʒ��" << quality << endl;
	}
	virtual string getQuality()
	{
		return quality;
	}
	~BuildingB()
	{

	}
private:
	string quality;
};

//��������ά���͹���¥��
class Agency
{
public:
	Agency()
	{

	}

	void putBuilding(AbstructBuilding* building)//�ӷ������ҷ���
	{
		TotalBuilding.push_back(building);
	}

	AbstructBuilding* rentBuilding(string quality)//����������ͻ�
	{
		if (TotalBuilding.size() > 0)
		{
			for (vector<AbstructBuilding*>::iterator it = TotalBuilding.begin(); it != TotalBuilding.end(); it++)
			{
				if ((*it)->getQuality() == quality)
				{
					cout << "�ɹ����û��ҵ�����" << endl;
					return *it;
				}
				else
				{
					cout << "���Ӳ������û�������" << endl;
					return NULL;
				}
			}
		}
		else
		{
			cout << "��Ǹ��û����" << endl;
			return NULL;
		}
	}
	~Agency()
	{
		if(TotalBuilding.size()>0)
		for (vector<AbstructBuilding*>::iterator it = TotalBuilding.begin(); it != TotalBuilding.end(); it++)
		{
			if (TotalBuilding.size() > 0)
				if ((*it) != NULL)
					delete *it;
		}
	}
private:
	vector<AbstructBuilding*> TotalBuilding;

};

void test()
{
	Agency *agent = new Agency;

	AbstructBuilding *buildingA = new BuildingA;
	AbstructBuilding *buildingB = new BuildingB;

	agent->putBuilding(buildingA);
	agent->putBuilding(buildingB);

	agent->rentBuilding("good");


	//delete buildingA; �˴�����Ҫ���������߻��ͷ����οռ�
	//delete buildingB;
	delete agent;
}

int main()
{

	test();
	while (1);
	return 0;
}