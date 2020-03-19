#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class TV
{
public:
	void turnOnTV()
	{
		cout << "�򿪵���" << endl;
	}

	void turnOffTV()
	{
		cout << "�رյ���" << endl;
	}
};

class Microphone
{
public:
	void turnOnMicrophone()
	{
		cout << "����˷�" << endl;
	}

	void turnOffMicrophone()
	{
		cout << "�ر���˷�" << endl;
	}
};

class Light
{
public:
	void turnOnLight()
	{
		cout << "�򿪵��" << endl;
	}

	void turnOffLight()
	{
		cout << "�رյ��" << endl;
	}
};

class KTVMode
{

public:
	KTVMode()
	{
		light = new Light;
		microphone = new Microphone;
		tv = new TV;
	}

	~KTVMode()
	{
		delete tv;
		delete microphone;
		delete light;
	}

	void turnOnKTV()
	{
		light->turnOnLight();
		microphone->turnOnMicrophone();
		tv->turnOnTV();
	}


private:
	Light *light;
	Microphone *microphone;
	TV *tv;
};

int main()
{
	KTVMode *ktv = new KTVMode;
	ktv->turnOnKTV();

	delete ktv;
	system("pause");
	return 0;
}