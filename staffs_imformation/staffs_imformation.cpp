#include<stdio.h>
#include<string.h>
#define MAX 100
int size = 0;//总共已录入信息的职工数量
struct Staffs
{
	int number;
	char name[10];
	char sex[5];
	int age;
	char education[5];
	int galary;
	char address[20];
	int tele;
};
struct Staffs* p;//用于表示录入信息时的起始地址
void menu(void)
{
	printf("\n欢迎使用职工信息管理系统\n");
	printf("***********************************\n");
	printf("1.录入职工信息\n2.浏览职工信息\n3.查询职工信息\n4.修改职工信息\n5.删除职工信息\n6.退出\n");
	printf("***********************************\n");
	printf("请按功能序号:");
}
struct Staffs* input(struct Staffs* ps)
{
	int sz = 0;//用来记录本次所录入的职工数量
	int i = 1;
	struct Staffs* p = ps;
	do
	{
		printf("\n请输入职工号:");
		scanf("%d", &p->number);
		printf("请输入姓名:");
		scanf("%s", p->name);
		printf("请输入性别<女/男>:");
		scanf("%s", p->sex);
		printf("请输入年龄:");
		scanf("%d", &p->age);
		printf("请输入学历:");
		scanf("%s", p->education);
		printf("请输入工资:");
		scanf("%d", &p->galary);
		printf("请输入住址:");
		scanf("%s", p->address);
		printf("请输入电话:");
		scanf("%d", &p->tele);
		p++;//ps指向数组下一个元素
		size++;//每录入一个总数量加一
		sz++;//每录入一个本次录入数量加一
		printf("录入成功，总共已有%d个职工信息。\n", size);
		printf("继续录入请按1，退出录入请按0:");
		scanf("%d", &i);
	} while (i);//当用户输入0结束循环停止录入信息
	printf("\n本次录入结束，本次已成功录入%d人。\n", sz);
	return p;
}
void display(struct Staffs* ps)
{
	int i;
	printf("职工号\t姓名\t性别\t年龄\t学历\t工资\t住址\t电话\n");
	for (i = 0; i < size; i++)
		printf("%d\t%-s\t%-s\t%-d\t%-s\t%-d\t%-s\t%-d\n",
			ps[i].number,
			ps[i].name,
			ps[i].sex,
			ps[i].age,
			ps[i].education,
			ps[i].galary,
			ps[i].address,
			ps[i].tele);
}
int search_number(struct Staffs* ps)
{
	int num;
	int i;
	scanf("%d", &num);//输入要查询的职工号
	for (i = 0; i < size; i++)//遍历结构体数组sta中的所有元素当找到满足条件的职员信息，就打印出来
	{
		if (ps[i].number == num)
		{
			printf("\n查询成功,查询结果为:\n");
			printf("%d\t%-s\t%-s\t%-d\t%-s\t%-d\t%-s\t%-d\n",
				ps[i].number,
				ps[i].name,
				ps[i].sex,
				ps[i].age,
				ps[i].education,
				ps[i].galary,
				ps[i].address,
				ps[i].tele);
			return i;//查询成功便返回i，函数结束
		}
	}
	printf("\n对不起,查无此人\n");
	return -1;//查询失败，函数结束，重新查询
}
void search_education(struct Staffs* ps)
{
	char edu[5];
	int i;
	int count = 0;//用于统计查询结果个数	
	scanf("%s", edu);//输入要查询的学历
	for (i = 0; i < size; i++)//遍历结构体数组sta中的所有元素,当找到满足条件的职员信息，就打印出来
	{
		if (strcmp(edu, ps[i].education) == 0)
		{
			printf("%d\t%-s\t%-s\t%-d\t%-s\t%-d\t%-s\t%-d\n",
				ps[i].number,
				ps[i].name,
				ps[i].sex,
				ps[i].age,
				ps[i].education,
				ps[i].galary,
				ps[i].address,
				ps[i].tele);
			count++;//每找到一个结果便加一
		}
	}
	printf("\n总共找到%d个有关\"%s\"的职工信息结果\n", count, edu);
}
void search_h(struct Staffs* ps)
{
	int choice;
	do
	{

		printf("\n查询方式:\n1.按职工号查询\n2.按学历查询\n3.返回主菜单\n请选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n请输入要查询的职工号：");
			search_number(ps);
			break;
		case 2:
			printf("\n请输入要查询的学历：");
			search_education(ps);
			break;
		case 3:
			break;
		default:
			printf("\n选择错误,请重新选择:\n");
		}
	} while (choice != 3);//当选择3时结束循环，返回主菜单
}
void correct(struct Staffs* ps)
{
	int i;
	printf("\n请输入要修改的职工号：");
	i = search_number(ps);
	if (i != -1)
	{
		printf("\n请进行修改:\n");//修改所选的职工
		printf("\n请输入职工号:");
		scanf("%d", &ps[i].number);
		printf("请输入姓名:");
		scanf("%s", ps[i].name);
		printf("请输入性别<女/男>:");
		scanf("%s", ps[i].sex);
		printf("请输入年龄:");
		scanf("%d", &ps[i].age);
		printf("请输入学历:");
		scanf("%s", ps[i].education);
		printf("请输入工资:");
		scanf("%d", &ps[i].galary);
		printf("请输入住址:");
		scanf("%s", ps[i].address);
		printf("请输入电话:");
		scanf("%d", &ps[i].tele);
		printf("\n修改成功\n");
	}
}
void del(struct Staffs* ps)
{
	int i;
	printf("\n请输入要删除的职工号：");
	i = search_number(ps);
	if (i != -1)
	{
		for (; i < size - 1; i++)
		{
			ps[i].number = ps[i + 1].number;
			strcpy(ps[i].name, ps[i + 1].name);
			strcpy(ps[i].sex, ps[i + 1].sex);
			ps[i].age = ps[i + 1].age;
			strcpy(ps[i].education, ps[i + 1].education);
			ps[i].galary = ps[i + 1].galary;
			strcpy(ps[i].address, ps[i + 1].address);
			ps[i].tele = ps[i + 1].tele;
		}
		size--;
		p--;//删除一个职工信息后录入的起始地址也减一
		printf("\n删除成功！\n");

	}
}
int main()
{
	int choice;
	struct Staffs sta[MAX], * ps = sta;
	p = sta;//设置初始录入地址为数组首地址
	do
	{
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			p = input(p);//将每次录入完后p所指向的数组元素中的地址传回给p，更新下次录入的起始地址
			break;
		case 2:
			display(ps);
			break;
		case 3:
			search_h(ps);
			break;
		case 4:
			correct(ps);
			break;
		case 5:
			del(ps);
			break;
		case 6:
			break;
		default:
			printf("序号输入错误，请重新选择:\n");
		}
	} while (choice != 6);
	return 0;
}
