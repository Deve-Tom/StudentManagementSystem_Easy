#include<iostream>
#include"studentIn.cpp"
using namespace std;

int start();//��ʼ�˵�
student* menuFunction(student* head);//1.���ܲ˵�
void explanation();//2.���˵��
void exitSoft(student* head);//3.�˳�������
void deletedAlldata(student* head);//�����������

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
			cout << "�������Ϣ��������������" << endl;
			system("PAUSE");
			system("CLS");
			break;
		}
		}
		system("CLS");
	}
	return 0;
}
