#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class TV
{
public:
	void turnOnTV()
	{
		cout << "打开电视" << endl;
	}

	void turnOffTV()
	{
		cout << "关闭电视" << endl;
	}
};

class Microphone
{
public:
	void turnOnMicrophone()
	{
		cout << "打开麦克风" << endl;
	}

	void turnOffMicrophone()
	{
		cout << "关闭麦克风" << endl;
	}
};

class Light
{
public:
	void turnOnLight()
	{
		cout << "打开电灯" << endl;
	}

	void turnOffLight()
	{
		cout << "关闭电灯" << endl;
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