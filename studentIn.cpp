struct score
{
	double Chinese;
	double Math;
	double English;
	double Others;
	double all;
};
struct student
{
	int ID;
	char name[6];
	char SEX[2];
	score studentsc;
	int flag;
	student* next;
};
