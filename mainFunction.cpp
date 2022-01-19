#include<iostream>
#include"studentIn.h"
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

# define list cout<<"学号        姓名   性别   |语文成绩    数学成绩    英语成绩    其它总成绩    总分"<<endl;
# define EOR cout<<"错误\a";

/*以下为调用函数*/
int start();//开始菜单
student* menuFunction(student* head);//1.功能菜单
void explanation();//2.软件说明
void exitSoft(student* head);//3.退出本程序
bool printStudent(student* head);//a.输出所有学生信息
student* studentFunctionb(student* head);//b.学生操作
void outStudentIn(student* head);//4.导出学生信息到文件中
void findStuentMenu(student* head);//1.查找学生
int deleteStudentMenu();//2.删除学生
student* deleteStudentID(student* head, int ID);//2.1按学号删除学生
student* deleteStudentName(student* head, char name[]);//2.2按姓名删除学生
int createNewStudentMenu();//3.导入学生功能菜单
student* createNewStudent(student* head);//3.1从控制台导入学生信息
void findStudentP(student* head, int place);//1.1按位置查找学生
int findStudentMenu();//1.2按信息查找学生子菜单
void findStudentMenu(student* head, int ID);//1.2.1按学号查找
void findStudentMenu(student* head, const char name[], const char sex[]);//1.2.2按姓名和性别查找
void findStudentMenu(student* head, const char sex[]);//1.2.3按学生性别查找
void outStudentIn(student* head);//4.导出学生信息到文件中
student* reversStudent(student* head);//6.倒置学生信息（倒置链表）
student* cut(student*& head);
void mergesort(student*& head);
student* merge(student*& head, student*& mid);//归并算法
int insertmenu();//7.插入菜单
student* insert(student* head, int place);//7.1按位置插入
student* insertID(student* head, int ID);//7.2按学号信息插入
void ALLnumber(student* head);//统计人数函数
void deletedAlldata(student* head);//清除所有数据

/*以下为函数主体*/
int start()//开始菜单
{
	system("CLS");
	system("color 7C");
	int function{ 0 };
	cout << "欢迎使用【东拉西扯】学生管理系统！" << endl;
	cout << ">>1.功能菜单" << endl;
	cout << ">>2.软件说明" << endl;
	cout << ">>3.退出本程序" << endl;
	cout << ">>";
	cin >> function;
	return function;
}

student* menuFunction(student* head)//1.功能菜单
{
	system("CLS");
	char function;
	//问题：重复建立了链表导致学生数据丢失(已经解决)
	bool selct{ true };
	cout << ">>a.输出所有学生信息" << endl;
	cout << ">>b.学生操作" << endl;
	cout << ">>c.导出学生" << endl;
	cout << ">>d.返回" << endl;
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
		cout << "输入的信息有误，请重新输入" << endl;
		system("PAUSE");
		system("CLS");
		break;
	}
	}
	return head;
}

void explanation()//2.软件说明
{
	system("CLS");
	string explan;
	ifstream state;
	int function{ 0 };
	state.open("使用说明.hs");
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

void exitSoft(student* head)//3.退出本程序
{
	system("CLS");
	cout << "软件正在退出";
	for (int i{ 0 }; i < 5; i++)
	{
		Sleep(200);
		cout << "*";
	}
	deletedAlldata(head);
	Sleep(100);
	system("CLS");
	cout << "欢迎再次使用本程序^_^";
	system("PAUSE");
	exit(0);
}

bool printStudent(student* head)//a.输出学生信息
{
	system("CLS");
	if (!head)
	{
		cout << "无学生信息，请先进行导入操作\a" << endl;
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
		cout << endl << "总计：" << head->flag << endl;
		system("PAUSE");
		return true;
	}
}

/*开始链接下菜单中的各项功能，还没有攥写排序算法10.1*/

student* studentFunctionb(student* head)//b.学生操作
{
	system("CLS");
	cout << "1.查找学生 | 2.删除学生 | 3.导入学生 | 4.导出学生 | 5.排序(按总成绩升序） | 6.倒置学生信息 | 7.插入学生信息" << endl;
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
		cout << endl << "总计：" << head->flag << endl;
	}
	else
	{
		cout << "\n空\n";
		cout << "___________________________________________________________________________________________________________" << endl;
		cout << "\a\n无学生信息,请先导入学生信息" << endl;
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
				cout << "请再下方输入您想要删除的学号：" << endl;
				int ID{ 0 };
				cin >> ID;
				head = deleteStudentID(head, ID);
				break;
			}
			case 2:
			{
				cout << "请再下方依次输入所要删除学生的姓名：" << endl;
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
				cout << "输入的信息有误，请重新输入\a" << endl;
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
				cout << "此功能还未开发\a" << endl;
				system("PAUSE");
				break;
			}
			case 3:break;
			default:
			{
				cout << "输入的信息有误，请重新输入" << endl;
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
				cout << "请输入所插如位置:" << endl;
				cout << ">>";
				int place{ 0 };
				cin >> place;
				head = insert(head, place);
				if (head)
				{
					cout << "插入成功!\a\n";
					system("PAUSE");
				}
				break;
			}
			case 2:
			{
				cout << "请输入所插如学生的学号:" << endl;
				cout << ">>";
				int ID{ 0 };
				cin >> ID;
				head = insertID(head, ID);
				if (head)
					cout << "插入成功!\a";
				system("PAUSE");
				break;
			}
			}//7.插入菜单
			break;
		}//插入学生功能
		default:
		{
			cout << "输入的信息有误，请重新输入\a" << endl;
			system("PAUSE");
			break;
		}
		}
	}
	return head;
}

void findStuentMenu(student* head)//1.查找学生
{
	system("CLS");
	int function{ 0 };
	cout << ">>1.按位置查找<<" << endl;
	cout << ">>2.按信息查找<<" << endl;
	cout << ">>";
	cin >> function;
	switch (function)
	{
	case 1:
	{
		int place{ 0 };
		cout << "请输入所要查找学生的序号位置：" << endl;
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
			cout << "请在下方输入所要查找学生的学号:" << endl;
			int ID{ 0 };
			cin >> ID;
			findStudentMenu(head, ID);
			cin.get();//做好标记
			break;
		}
		case 2:
		{
			cout << "请在下方输入所要查找学生的姓名以及性别：" << endl;
			char name[10];
			char sex[3];
			cin >> name >> sex;
			findStudentMenu(head, name, sex);
			break;
		}
		case 3:
		{
			cout << "请在下方输入所要查找学生的性别：" << endl;
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

void findStudentP(student* head, int place)//1.1按位置查找学生
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "不能对空表进行查找\a" << endl;
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
		cout << "查找失败！";
	}
	system("PAUSE");
}

int findStudentMenu()//1.2按信息查找学生子菜单
{
	system("CLS");
	int function{ 0 };
	cout << ">>1.按学号查找<<" << endl;
	cout << ">>2.按姓名和性别查找<<" << endl;
	cout << ">>3.按性别查找<<" << endl;
	cin >> function;
	return function;
}

void findStudentMenu(student* head, int ID)//1.2.1按学号查找
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "不能对空表进行查找\a" << endl;
		system("PAUSE");
		return;
	}
	{
		cout << "查找中";
		for (int i{ 0 }; i < 5; i++)
		{
			Sleep(2000);
			cout << "*";
		}
		system("CLS");
	}//查找动画
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
		cout << "未找到\a" << endl;
		system("PAUSE");
	}
}

void findStudentMenu(student* head, const char name[], const char sex[])//1.2.2按姓名和性别查找
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "不能对空表进行查找\a" << endl;
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
		cout << "未找到\a" << endl;
		system("PAUSE");
	}
}

void findStudentMenu(student* head, const char sex[])//1.2.2按性别查找
{
	system("CLS");
	student* move{ head };
	if (!move)
	{
		cout << "不能对空表进行查找\a" << endl;
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
	cout << "查找完毕......" << endl;
	system("PAUSE");
}

int deleteStudentMenu()//2.删除学生
{
	system("CLS");
	int function{ 0 };
	cout << ">>请选择删除方式" << endl;
	cout << ">>1.按学号删除" << endl;
	cout << ">>2.按姓名删除" << endl;
	cout << ">>3.返回" << endl;
	cin >> function;
	return function;
}

student* deleteStudentID(student* head, int ID)//2.1按学号删除学生
{
	student* move{ head };
	if (!move)
	{
		cout << "本系统中没有存储任何学生信息，请导入学生后再进行本操作\a" << endl;
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

student* deleteStudentName(student* head, char name[])//2.2按姓名删除学生
{
	student* move{ head };
	if (!head)
	{
		cout << "本系统中没有存储任何学生的信息，请导入学生数据后再进行操作" << endl;
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

int createNewStudentMenu()//3.导入学生功能菜单
{
	system("CLS");
	int function{ 0 };
	cout << ">>请选择导入方式" << endl;
	cout << ">>1.从控制台导入<<" << endl;
	cout << ">>2.从已有文件导入<<" << endl;
	cout << ">>3.返回<<" << endl;
	cout << ">>";
	cin >> function;
	return function;
}

student* createNewStudent(student* head)//3.1从控制台导入学生信息
{
	//问题：存在创建时有多余结点(已经解决）
	system("CLS");
	cout << "  >>请在下方输入学生信息<<" << endl;
	cout << "  信息分别是：\n  学号 姓名 性别 语文成绩 数学成绩 英语成绩 其它成绩（每一项用一个空格隔开）" << endl;
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

//3.2从文件中导入学生数据，暂时不进行攥写
void outStudentIn(student* head)//4.导出学生信息到文件中
{
	system("CLS");
	if (!head)
	{
		cout << "无学生信息，无法进行导出操作\a" << endl;
		system("PAUSE");
		system("CLS");
		return;
	}
	ofstream outStudent;
	cout << "请在下方输入导出的文件名及文件类型（文件名.文件类型）：" << endl;
	string filename;
	student* move{ head };
	cin >> filename;
	outStudent.open(filename);
	outStudent << "学号 姓名 性别  语文成绩  数学成绩  英语成绩  其它总成绩  总分" << endl;
	while (move->next)
	{
		outStudent << move->next->ID << "   " << move->next->name << "   " << move->next->SEX
			<< "   " << move->next->studentsc.Chinese << "   " << move->next->studentsc.Math << "   "
			<< move->next->studentsc.English << "   " << move->next->studentsc.Others << "   "
			<< move->next->studentsc.all << endl;
		move = move->next;
	}
	cout << "导出成功\a！";
	outStudent.close();
	system("PAUSE");
	system("CLS");
}

//5.对学生信息进行排序，总分排序，这里采用归并排序的方式
void mergesort(student*& head) /*归并主体*/
{
	if (head->next)
	{
		student* mid = cut(head);
		mergesort(head);
		mergesort(mid);
		head = merge(head, mid);
	}
}

student* cut(student*& head) /*切断链表*/
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

student* merge(student*& head, student*& mid) /*归并算法*/
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

student* reversStudent(student* head)//6.倒置学生信息（倒置链表）
{
	system("CLS");
	if (!head)
	{
		cout << "不能对空表进行倒置\a" << endl;
		system("PAUSE");
		return head;
	}
	student* NewNode = new student;
	NewNode->next = NULL;
	student* move{ head->next };
	int num{ 0 };
	while (move)//本while循环为倒置算法
	{
		head->next = move->next;
		move->next = NewNode->next;
		NewNode->next = move;
		move = head->next;
	}
	cout << "倒置结果如下方所示：" << endl;
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
		num++;//总人数统计
	}
	system("PAUSE");
	return NewNode;
}

int insertmenu()//7.插入菜单
{
	system("CLS");
	cout << "请输入插入方式：\n";
	cout << ">>1.插入到某位置之前<<" << endl;
	cout << ">>2.插入到某学号之前<<" << endl;
	cout << ">>";
	int function{ 0 };
	cin >> function;
	return function;
}

student* insert(student* head, int place)//7.1按位置插入
{
	int temp_place{ 0 };
	student* move{ head }, * move_1{ NULL };
	student* s{ NULL };
	if (!move)
	{
		cout << "不能对空表进行插入\a" << endl;
		system("PAUSE");
		return head;
	}
	while (temp_place < place - 1)
	{
		move = move->next;
		temp_place++;
	}
	cout << "请输入您要插入学生的数量:" << endl;
	int num{ 0 }, i{ 0 };
	cin >> num;
	cout << "请在下方输入所要插入的学生的信息：" << endl;
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

student* insertID(student* head, int ID)//7.2按学号信息插入
{
	student* move{ head }, * move_1{ NULL };
	student* s{ NULL };
	if (!move)
	{
		cout << "不能对空表进行插入\a" << endl;
		system("PAUSE");
		return head;
	}
	while (move && move->next->ID != ID)
		move = move->next;
	cout << "请输入您要插入学生的数量:" << endl;
	int num{ 0 }, i{ 0 };
	cin >> num;
	cout << "请在下方输入所要插入的学生的信息：" << endl;
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

void ALLnumber(student* head)//统计人数函数
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

void deletedAlldata(student* head)//删除所有数据
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