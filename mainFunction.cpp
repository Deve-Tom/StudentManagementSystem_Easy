#include<iostream>
#include"studentIn.h"
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

# define list cout<<"ѧ��        ����   �Ա�   |���ĳɼ�    ��ѧ�ɼ�    Ӣ��ɼ�    �����ܳɼ�    �ܷ�"<<endl;
# define EOR cout<<"����\a";

/*����Ϊ���ú���*/
int start();//��ʼ�˵�
student* menuFunction(student* head);//1.���ܲ˵�
void explanation();//2.���˵��
void exitSoft(student* head);//3.�˳�������
bool printStudent(student* head);//a.�������ѧ����Ϣ
student* studentFunctionb(student* head);//b.ѧ������
void outStudentIn(student* head);//4.����ѧ����Ϣ���ļ���
void findStuentMenu(student* head);//1.����ѧ��
int deleteStudentMenu();//2.ɾ��ѧ��
student* deleteStudentID(student* head, int ID);//2.1��ѧ��ɾ��ѧ��
student* deleteStudentName(student* head, char name[]);//2.2������ɾ��ѧ��
int createNewStudentMenu();//3.����ѧ�����ܲ˵�
student* createNewStudent(student* head);//3.1�ӿ���̨����ѧ����Ϣ
void findStudentP(student* head, int place);//1.1��λ�ò���ѧ��
int findStudentMenu();//1.2����Ϣ����ѧ���Ӳ˵�
void findStudentMenu(student* head, int ID);//1.2.1��ѧ�Ų���
void findStudentMenu(student* head, const char name[], const char sex[]);//1.2.2���������Ա����
void findStudentMenu(student* head, const char sex[]);//1.2.3��ѧ���Ա����
void outStudentIn(student* head);//4.����ѧ����Ϣ���ļ���
student* reversStudent(student* head);//6.����ѧ����Ϣ����������
student* cut(student*& head);
void mergesort(student*& head);
student* merge(student*& head, student*& mid);//�鲢�㷨
int insertmenu();//7.����˵�
student* insert(student* head, int place);//7.1��λ�ò���
student* insertID(student* head, int ID);//7.2��ѧ����Ϣ����
void ALLnumber(student* head);//ͳ����������
void deletedAlldata(student* head);//�����������

/*����Ϊ��������*/
int start()//��ʼ�˵�
{
	system("CLS");
	system("color 7C");
	int function{ 0 };
	cout << "��ӭʹ�á�����������ѧ������ϵͳ��" << endl;
	cout << ">>1.���ܲ˵�" << endl;
	cout << ">>2.���˵��" << endl;
	cout << ">>3.�˳�������" << endl;
	cout << ">>";
	cin >> function;
	return function;
}

student* menuFunction(student* head)//1.���ܲ˵�
{
	system("CLS");
	char function;
	//���⣺�ظ�������������ѧ�����ݶ�ʧ(�Ѿ����)
	bool selct{ true };
	cout << ">>a.�������ѧ����Ϣ" << endl;
	cout << ">>b.ѧ������" << endl;
	cout << ">>c.����ѧ��" << endl;
	cout << ">>d.����" << endl;
	cout << ">>";
	cin >> function;
	switch (function)
	{
	case 'A':
	case 'a': {
		selct = printStudent(head);
		break;
	}
	case 'B':
	case 'b': {
		head = studentFunctionb(head);
		break;
	}
	case'C':
	case'c': {
		outStudentIn(head);
		break;
	}
	case 'd':
	case 'D': {
		return head;
	}
	default: {
		cout << "�������Ϣ��������������" << endl;
		system("PAUSE");
		system("CLS");
		break;
	}
	}
	return head;
}

void explanation()//2.���˵��
{
	system("CLS");
	string explan;
	ifstream state;
	int function{ 0 };
	state.open("ʹ��˵��.hs");
	while (!state.eof())
	{
		state >> explan;
		cout << explan;
		cout << endl;
	}
	state.close();
	cout << endl;
	system("PAUSE");
}

void exitSoft(student* head)//3.�˳�������
{
	system("CLS");
	cout << "��������˳�";
	for (int i{ 0 }; i < 5; i++)
	{
		Sleep(200);
		cout << "*";
	}
	deletedAlldata(head);
	Sleep(100);
	system("CLS");
	cout << "��ӭ�ٴ�ʹ�ñ�����^_^";
	system("PAUSE");
	exit(0);
}

bool printStudent(student* head)//a.���ѧ����Ϣ
{
	system("CLS");
	if (!head)
	{
		cout << "��ѧ����Ϣ�����Ƚ��е������\a" << endl;
		system("PAUSE");
		return false;
	}
	list;
	student* move{ head };
	{
		ALLnumber(head);
		while (move->next)
		{
			if (move->next->flag == 0 && !move->next->next)
				break;
			cout << "|" << move->next->ID << "  " << move->next->name << "     " << move->next->SEX
				<< "     " << move->next->studentsc.Chinese << "        " << move->next->studentsc.Math << "          "
				<< move->next->studentsc.English << "         " << move->next->studentsc.Others << "          "
				<< move->next->studentsc.all;
			if (move->next->flag == -1)
				cout << endl;
			move = move->next;
		}
		cout << endl << "�ܼƣ�" << head->flag << endl;
		system("PAUSE");
		return true;
	}
}

/*��ʼ�����²˵��еĸ���ܣ���û��߬д�����㷨10.1*/

student* studentFunctionb(student* head)//b.ѧ������
{
	system("CLS");
	cout << "1.����ѧ�� | 2.ɾ��ѧ�� | 3.����ѧ�� | 4.����ѧ�� | 5.����(���ܳɼ����� | 6.����ѧ����Ϣ | 7.����ѧ����Ϣ" << endl;
	cout << "___________________________________________________________________________________________________________" << endl;
	list;
	student* move{ head };
	if (head && move->next)
	{
		while (move->next)
		{
			if (move->next->flag == 0 && !move->next->next)
			{
				break;
			}
			cout << "|" << move->next->ID << "  " << move->next->name << "     " << move->next->SEX
				<< "     " << move->next->studentsc.Chinese << "        " << move->next->studentsc.Math << "          "
				<< move->next->studentsc.English << "         " << move->next->studentsc.Others << "          "
				<< move->next->studentsc.all;
			if (move->next->flag == -1)
				cout << endl;
			move = move->next;
		}
		ALLnumber(head);
		cout << endl << "�ܼƣ�" << head->flag << endl;
	}
	else
	{
		cout << "\n��\n";
		cout << "___________________________________________________________________________________________________________" << endl;
		cout << "\a\n��ѧ����Ϣ,���ȵ���ѧ����Ϣ" << endl;
	}
	{
		cout << "___________________________________________________________________________________________________________" << endl;
		int function{ 0 };
		cout << ">>";
		cin >> function;
		switch (function)
		{
		case 1:findStuentMenu(head); break;
		case 2:
		{
			switch (deleteStudentMenu())
			{
			case 1:
			{
				cout << "�����·���������Ҫɾ����ѧ�ţ�" << endl;
				int ID{ 0 };
				cin >> ID;
				head = deleteStudentID(head, ID);
				break;
			}
			case 2:
			{
				cout << "�����·�����������Ҫɾ��ѧ����������" << endl;
				char name[6];
				cin >> name;
				head = deleteStudentName(head, name);
				break;
			}
			case 3:
			{
				break;
			}
			default:
			{
				cout << "�������Ϣ��������������\a" << endl;
				system("PAUSE");
				break;
			}
			}
			break;
		}
		case 3:
		{
			int i{ 0 };
			i = createNewStudentMenu();
			switch (i)
			{
			case 1:
			{
				head = createNewStudent(head);
				cin.get();
				break;
			}
			case 2:
			{
				system("CLS");
				cout << "�˹��ܻ�δ����\a" << endl;
				system("PAUSE");
				break;
			}
			case 3:break;
			default:
			{
				cout << "�������Ϣ��������������" << endl;
				system("PAUSE");
				break;
			}
			}
			break;
		}
		case 4:
		{
			outStudentIn(head);
			break;
		}
		case 5:
		{
			if (head)
				mergesort(head->next);
			break;
		}
		case 6:
		{
			head = reversStudent(head);
			break;
		}
		case 7:
		{
			switch (insertmenu())
			{
			case 1:
			{
				cout << "������������λ��:" << endl;
				cout << ">>";
				int place{ 0 };
				cin >> place;
				head = insert(head, place);
				if (head)
				{
					cout << "����ɹ�!\a\n";
					system("PAUSE");
				}
				break;
			}
			case 2:
			{
				cout << "������������ѧ����ѧ��:" << endl;
				cout << ">>";
				int ID{ 0 };
				cin >> ID;
				head = insertID(head, ID);
				if (head)
					cout << "����ɹ�!\a";
				system("PAUSE");
				break;
			}
			}//7.����˵�
			break;
		}//����ѧ������
		default:
		{
			cout << "�������Ϣ��������������\a" << endl;
			system("PAUSE");
			break;
		}
		}
	}
	return head;
}

void findStuentMenu(student* head)//1.����ѧ��
{
	system("CLS");
	int function{ 0 };
	cout << ">>1.��λ�ò���<<" << endl;
	cout << ">>2.����Ϣ����<<" << endl;
	cout << ">>";
	cin >> function;
	switch (function)
	{
	case 1:
	{
		int place{ 0 };
		cout << "��������Ҫ����ѧ�������λ�ã�" << endl;
		cout << ">>";
		cin >> place;
		findStudentP(head, place);
		break;
	}
	case 2:
	{
		switch (findStudentMenu())
		{
		case 1:
		{
			cout << "�����·�������Ҫ����ѧ����ѧ��:" << endl;
			int ID{ 0 };
			cin >> ID;
			findStudentMenu(head, ID);
			cin.get();//���ñ��
			break;
		}
		case 2:
		{
			cout << "�����·�������Ҫ����ѧ���������Լ��Ա�" << endl;
			char name[10];
			char sex[3];
			cin >> name >> sex;
			findStudentMenu(head, name, sex);
			break;
		}
		case 3:
		{
			cout << "�����·�������Ҫ����ѧ�����Ա�" << endl;
			char sex[3];
			cin >> sex;
			findStudentMenu(head, sex);
			break;
		}
		}
		break;
	}
	}
}

void findStudentP(student* head, int place)//1.1��λ�ò���ѧ��
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "���ܶԿձ���в���\a" << endl;
		system("PAUSE");
		return;
	}
	int i{ 0 };
	while (move->next && i < place)
	{
		move = move->next;
		i++;
	}
	if (i == place)
	{
		list;
		cout << "|" << move->ID << "   " << move->name << "   " << move->SEX
			<< "   " << move->studentsc.Chinese << "   " << move->studentsc.Math << "   "
			<< move->studentsc.English << "   " << move->studentsc.Others << "   " << move->studentsc.all
			<< endl;
	}
	else
	{
		cout << "����ʧ�ܣ�";
	}
	system("PAUSE");
}

int findStudentMenu()//1.2����Ϣ����ѧ���Ӳ˵�
{
	system("CLS");
	int function{ 0 };
	cout << ">>1.��ѧ�Ų���<<" << endl;
	cout << ">>2.���������Ա����<<" << endl;
	cout << ">>3.���Ա����<<" << endl;
	cin >> function;
	return function;
}

void findStudentMenu(student* head, int ID)//1.2.1��ѧ�Ų���
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "���ܶԿձ���в���\a" << endl;
		system("PAUSE");
		return;
	}
	{
		cout << "������";
		for (int i{ 0 }; i < 5; i++)
		{
			Sleep(2000);
			cout << "*";
		}
		system("CLS");
	}//���Ҷ���
	while (move->next && move->next->ID != ID)
	{
		move = move->next;
	}
	if (move->next && move->next->ID == ID)
	{
		list;
		cout << "|" << move->next->ID << "   " << move->next->name << "   " << move->next->SEX
			<< "   " << move->next->studentsc.Chinese << "   " << move->next->studentsc.Math << "   "
			<< move->next->studentsc.English << "   " << move->next->studentsc.Others << "   "
			<< move->next->studentsc.all << endl;
		system("PAUSE");
	}
	else
	{
		cout << "δ�ҵ�\a" << endl;
		system("PAUSE");
	}
}

void findStudentMenu(student* head, const char name[], const char sex[])//1.2.2���������Ա����
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "���ܶԿձ���в���\a" << endl;
		system("PAUSE");
		return;
	}
	while (move->next && strcmp(name, move->next->name) && strcmp(sex, move->next->SEX))
	{
		move = move->next;
	}
	if (move->next && !strcmp(name, move->next->name) && !strcmp(sex, move->next->SEX))
	{
		list;
		cout << "|" << move->next->ID << "   " << move->next->name << "   " << move->next->SEX
			<< "   " << move->next->studentsc.Chinese << "   " << move->next->studentsc.Math << "   "
			<< move->next->studentsc.English << "   " << move->next->studentsc.Others << "   "
			<< move->next->studentsc.all << endl;
		system("PAUSE");
	}
	else
	{
		cout << "δ�ҵ�\a" << endl;
		system("PAUSE");
	}
}

void findStudentMenu(student* head, const char sex[])//1.2.2���Ա����
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "���ܶԿձ���в���\a" << endl;
		system("PAUSE");
		return;
	}
	list;
	while (move->next)
	{
		if (!strcmp(sex, move->next->SEX))
		{
			cout << "|" << move->next->ID << "   " << move->next->name << "   " << move->next->SEX
				<< "   " << move->next->studentsc.Chinese << "   " << move->next->studentsc.Math << "   "
				<< move->next->studentsc.English << "   " << move->next->studentsc.Others << "   "
				<< move->next->studentsc.all << endl;
		}
		move = move->next;
	}
	cout << "�������......" << endl;
	system("PAUSE");
}

int deleteStudentMenu()//2.ɾ��ѧ��
{
	system("CLS");
	int function{ 0 };
	cout << ">>��ѡ��ɾ����ʽ" << endl;
	cout << ">>1.��ѧ��ɾ��" << endl;
	cout << ">>2.������ɾ��" << endl;
	cout << ">>3.����" << endl;
	cin >> function;
	return function;
}

student* deleteStudentID(student* head, int ID)//2.1��ѧ��ɾ��ѧ��
{
	student* move{ head };
	if (!move)
	{
		cout << "��ϵͳ��û�д洢�κ�ѧ����Ϣ���뵼��ѧ�����ٽ��б�����\a" << endl;
		system("PAUSE");
		return head;
	}

	while (move->next && move->next->ID != ID)
	{
		move = move->next;
	}

	if (move->next)
	{
		student* s = move->next;
		move->next = s->next;
		delete s;
	}
	else
	{
		EOR;
		system("PAUSE");
	}
	return head;
}

student* deleteStudentName(student* head, char name[])//2.2������ɾ��ѧ��
{
	student* move{ head };
	if (!head)
	{
		cout << "��ϵͳ��û�д洢�κ�ѧ������Ϣ���뵼��ѧ�����ݺ��ٽ��в���" << endl;
		system("PAUSE");
		return head;
	}

	while (move->next && strcmp(name, move->next->name))
	{
		move = move->next;
	}

	if (move->next)
	{
		student* s = move->next;
		move->next = s->next;
		delete s;
	}
	else EOR;
	return head;
}

int createNewStudentMenu()//3.����ѧ�����ܲ˵�
{
	system("CLS");
	int function{ 0 };
	cout << ">>��ѡ���뷽ʽ" << endl;
	cout << ">>1.�ӿ���̨����<<" << endl;
	cout << ">>2.�������ļ�����<<" << endl;
	cout << ">>3.����<<" << endl;
	cout << ">>";
	cin >> function;
	return function;
}

student* createNewStudent(student* head)//3.1�ӿ���̨����ѧ����Ϣ
{
	//���⣺���ڴ���ʱ�ж�����(�Ѿ������
	system("CLS");
	cout << "  >>�����·�����ѧ����Ϣ<<" << endl;
	cout << "  ��Ϣ�ֱ��ǣ�\n  ѧ�� ���� �Ա� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ� �����ɼ���ÿһ����һ���ո������" << endl;
	if (!head)
	{
		head = new student;
		head->next = NULL;
	}
	student* move{ head }, * tool{ head };
	while (move->next)
	{
		move = move->next;
	}
	while (!cin.eof())
	{
		cout << ">>";
		tool = new student;
		tool->next = move->next;
		move->next = tool;
		move = move->next;
		(cin >> tool->ID).get();
		cin >> tool->name;
		cin >> tool->SEX;
		(cin >> tool->studentsc.Chinese).get();
		(cin >> tool->studentsc.Math).get();
		(cin >> tool->studentsc.English).get();
		cin >> tool->studentsc.Others;
		tool->studentsc.all = tool->studentsc.Chinese + tool->studentsc.Math + tool->studentsc.English + tool->studentsc.Others;
		tool->flag = -1;
	}
	tool->flag = 0;
	move = head;
	while (move->next && move->next->flag != 0)
	{
		move = move->next;
	}
	delete move->next;
	move->next = NULL;
	cin.clear();
	return head;
}

//3.2���ļ��е���ѧ�����ݣ���ʱ������߬д
void outStudentIn(student* head)//4.����ѧ����Ϣ���ļ���
{
	system("CLS");
	if (!head)
	{
		cout << "��ѧ����Ϣ���޷����е�������\a" << endl;
		system("PAUSE");
		system("CLS");
		return;
	}
	ofstream outStudent;
	cout << "�����·����뵼�����ļ������ļ����ͣ��ļ���.�ļ����ͣ���" << endl;
	string filename;
	student* move{ head };
	cin >> filename;
	outStudent.open(filename);
	outStudent << "ѧ�� ���� �Ա�  ���ĳɼ�  ��ѧ�ɼ�  Ӣ��ɼ�  �����ܳɼ�  �ܷ�" << endl;
	while (move->next)
	{
		outStudent << move->next->ID << "   " << move->next->name << "   " << move->next->SEX
			<< "   " << move->next->studentsc.Chinese << "   " << move->next->studentsc.Math << "   "
			<< move->next->studentsc.English << "   " << move->next->studentsc.Others << "   "
			<< move->next->studentsc.all << endl;
		move = move->next;
	}
	cout << "�����ɹ�\a��";
	outStudent.close();
	system("PAUSE");
	system("CLS");
}

//5.��ѧ����Ϣ���������ܷ�����������ù鲢����ķ�ʽ
void mergesort(student*& head) /*�鲢����*/
{
	if (head->next)
	{
		student* mid = cut(head);
		mergesort(head);
		mergesort(mid);
		head = merge(head, mid);
	}
}

student* cut(student*& head) /*�ж�����*/
{
	if (head)
	{
		student* p{ head };
		student* q{ head };
		student* second_head{ NULL };
		while (q && q->next)
		{
			q = q->next;
			if (q->next) {
				p = p->next;
				q = q->next;
			}
		}
		second_head = p->next;
		p->next = NULL;
		return second_head;
	}
	else return head;
}

student* merge(student*& head, student*& mid) /*�鲢�㷨*/
{
	student tmp;
	student* p{ &tmp }, * q{ head }, * t{ mid };
	while (q && t) {
		if (q->studentsc.all >= t->studentsc.all)
		{
			p->next = q;
			p = p->next;
			q = q->next;
		}
		else {
			p->next = t;
			p = p->next;
			t = t->next;
		}
	}
	if (q)
		p->next = q;
	else
		p->next = t;
	return tmp.next;
}

student* reversStudent(student* head)//6.����ѧ����Ϣ����������
{
	system("CLS");
	if (!head)
	{
		cout << "���ܶԿձ���е���\a" << endl;
		system("PAUSE");
		return head;
	}
	student* NewNode = new student;
	NewNode->next = NULL;
	student* move{ head->next };
	int num{ 0 };
	while (move)//��whileѭ��Ϊ�����㷨
	{
		head->next = move->next;
		move->next = NewNode->next;
		NewNode->next = move;
		move = head->next;
	}
	cout << "���ý�����·���ʾ��" << endl;
	move = NewNode;
	list;
	while (move->next)
	{
		if (move->next->flag == 0)
			break;
		cout << "|" << move->next->ID << "   " << move->next->name << "   " << move->next->SEX
			<< "   " << move->next->studentsc.Chinese << "   " << move->next->studentsc.Math << "   "
			<< move->next->studentsc.English << "   " << move->next->studentsc.Others << "   "
			<< move->next->studentsc.all;
		if (move->next->flag == -1)
			cout << endl;
		move = move->next;
		num++;//������ͳ��
	}
	system("PAUSE");
	return NewNode;
}

int insertmenu()//7.����˵�
{
	system("CLS");
	cout << "��������뷽ʽ��\n";
	cout << ">>1.���뵽ĳλ��֮ǰ<<" << endl;
	cout << ">>2.���뵽ĳѧ��֮ǰ<<" << endl;
	cout << ">>";
	int function{ 0 };
	cin >> function;
	return function;
}

student* insert(student* head, int place)//7.1��λ�ò���
{
	int temp_place{ 0 };
	student* move{ head }, * move_1{ NULL };
	student* s{ NULL };
	if (!move)
	{
		cout << "���ܶԿձ���в���\a" << endl;
		system("PAUSE");
		return head;
	}
	while (temp_place < place - 1)
	{
		move = move->next;
		temp_place++;
	}
	cout << "��������Ҫ����ѧ��������:" << endl;
	int num{ 0 }, i{ 0 };
	cin >> num;
	cout << "�����·�������Ҫ�����ѧ������Ϣ��" << endl;
	while (i < num)
	{
		if (i == 0)
		{
			student* p = new student;
			s = p;
			move_1 = s;
			move_1->next = NULL;
		}
		student* p = new student;
		(cin >> p->ID).get();
		cin >> p->name;
		cin >> p->SEX;
		(cin >> p->studentsc.Chinese).get();
		(cin >> p->studentsc.Math).get();
		(cin >> p->studentsc.English).get();
		cin >> p->studentsc.Others;
		p->studentsc.all = p->studentsc.Chinese + p->studentsc.Math + p->studentsc.English + p->studentsc.Others;
		p->flag = -1;
		p->next = move_1->next;
		move_1->next = p;
		move_1 = move_1->next;
		i++;
	}
	if (s)
	{
		student* last{ s->next };
		while (last->next)
			last = last->next;
		last->next = move->next;
		move->next = s->next;
		delete s;
	}
	return head;
}

student* insertID(student* head, int ID)//7.2��ѧ����Ϣ����
{
	student* move{ head }, * move_1{ NULL };
	student* s{ NULL };
	if (!move)
	{
		cout << "���ܶԿձ���в���\a" << endl;
		system("PAUSE");
		return head;
	}
	while (move && move->next->ID != ID)
		move = move->next;
	cout << "��������Ҫ����ѧ��������:" << endl;
	int num{ 0 }, i{ 0 };
	cin >> num;
	cout << "�����·�������Ҫ�����ѧ������Ϣ��" << endl;
	while (i < num)
	{
		if (i == 0)
		{
			student* p = new student;
			s = p;
			move_1 = s;
			move_1->next = NULL;
		}
		student* p = new student;
		(cin >> p->ID).get();
		cin >> p->name;
		cin >> p->SEX;
		(cin >> p->studentsc.Chinese).get();
		(cin >> p->studentsc.Math).get();
		(cin >> p->studentsc.English).get();
		cin >> p->studentsc.Others;
		p->studentsc.all = p->studentsc.Chinese + p->studentsc.Math + p->studentsc.English + p->studentsc.Others;
		p->flag = -1;
		p->next = move_1->next;
		move_1->next = p;
		move_1 = move_1->next;
		i++;
	}
	if (s && move)
	{
		student* last{ s->next };
		while (last->next)
			last = last->next;
		last->next = move->next;
		move->next = s->next;
		delete s;
	}
	return head;
}

void ALLnumber(student* head)//ͳ����������
{
	int num{ 0 };
	if (head)
	{
		student* move{ head };
		while (move && move->next)
		{
			move = move->next;
			num++;
		}
		if (!move)
		{
			head->flag = 0;
		}
		else
			head->flag = num;
	}
	else return;
}

void deletedAlldata(student* head)//ɾ����������
{
	if (head)
	{
		student* move{ head->next };
		while (move)
		{
			head->next = move->next;
			delete move;
			move = head->next;
		}
		delete head;
	}
	else return;
}