#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//迪米特原则又叫知识最少原则
//个人理解：其核心思想类似于中介，比如我想租房，那么我并不需要直接找到很多个房东
//我也不需要了解很多关于楼房的知识，我只需要找一个租房中介，并且我将我的需求告诉给他，具体工作由他来完成
//降低了用户和具体楼房的耦合性

class AbstructBuilding
{
public:
	AbstructBuilding()
	{

	}
	virtual void sale() = 0;//楼房售卖
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
		cout << "楼房A已售卖" << " 品质" << quality << endl;
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
		cout << "楼房B已售卖" << " 品质" << quality << endl;
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

//该类用于维护和管理楼盘
class Agency
{
public:
	Agency()
	{

	}

	void putBuilding(AbstructBuilding* building)//从房东处找房子
	{
		TotalBuilding.push_back(building);
	}

	AbstructBuilding* rentBuilding(string quality)//将房子租给客户
	{
		if (TotalBuilding.size() > 0)
		{
			for (vector<AbstructBuilding*>::iterator it = TotalBuilding.begin(); it != TotalBuilding.end(); it++)
			{
				if ((*it)->getQuality() == quality)
				{
					cout << "成功给用户找到房子" << endl;
					return *it;
				}
				else
				{
					cout << "房子不符合用户的需求" << endl;
					return NULL;
				}
			}
		}
		else
		{
			cout << "抱歉，没房了" << endl;
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


	//delete buildingA; 此处不需要析构，否者会释放两次空间
	//delete buildingB;
	delete agent;
}

int main()
{

	test();
	while (1);
	return 0;
}