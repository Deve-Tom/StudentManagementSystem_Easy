#include<iostream>
#include"studentIn.cpp"
using namespace std;

int start();//开始菜单
student* menuFunction(student* head);//1.功能菜单
void explanation();//2.软件说明
void exitSoft(student* head);//3.退出本程序
void deletedAlldata(student* head);//清除所有数据

int main(int argc, char* argv[])
{
	student* head{ NULL };
	for (;;)
	{
		int function{ 0 };
		function = start();
		switch (function)
		{
		case 1:head = menuFunction(head); break;
		case 2:explanation(); break;
		case 3:exitSoft(head); break;
		default: {
			cout << "输入的信息有误，请重新输入" << endl;
			system("PAUSE");
			system("CLS");
			break;
		}
		}
		system("CLS");
	}
	return 0;
}
