#include<stdio.h>
#include<string.h>
#define MAX 100
int size = 0;//�ܹ���¼����Ϣ��ְ������
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
struct Staffs* p;//���ڱ�ʾ¼����Ϣʱ����ʼ��ַ
void menu(void)
{
	printf("\n��ӭʹ��ְ����Ϣ����ϵͳ\n");
	printf("***********************************\n");
	printf("1.¼��ְ����Ϣ\n2.���ְ����Ϣ\n3.��ѯְ����Ϣ\n4.�޸�ְ����Ϣ\n5.ɾ��ְ����Ϣ\n6.�˳�\n");
	printf("***********************************\n");
	printf("�밴�������:");
}
struct Staffs* input(struct Staffs* ps)
{
	int sz = 0;//������¼������¼���ְ������
	int i = 1;
	struct Staffs* p = ps;
	do
	{
		printf("\n������ְ����:");
		scanf("%d", &p->number);
		printf("����������:");
		scanf("%s", p->name);
		printf("�������Ա�<Ů/��>:");
		scanf("%s", p->sex);
		printf("����������:");
		scanf("%d", &p->age);
		printf("������ѧ��:");
		scanf("%s", p->education);
		printf("�����빤��:");
		scanf("%d", &p->galary);
		printf("������סַ:");
		scanf("%s", p->address);
		printf("������绰:");
		scanf("%d", &p->tele);
		p++;//psָ��������һ��Ԫ��
		size++;//ÿ¼��һ����������һ
		sz++;//ÿ¼��һ������¼��������һ
		printf("¼��ɹ����ܹ�����%d��ְ����Ϣ��\n", size);
		printf("����¼���밴1���˳�¼���밴0:");
		scanf("%d", &i);
	} while (i);//���û�����0����ѭ��ֹͣ¼����Ϣ
	printf("\n����¼������������ѳɹ�¼��%d�ˡ�\n", sz);
	return p;
}
void display(struct Staffs* ps)
{
	int i;
	printf("ְ����\t����\t�Ա�\t����\tѧ��\t����\tסַ\t�绰\n");
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
	scanf("%d", &num);//����Ҫ��ѯ��ְ����
	for (i = 0; i < size; i++)//�����ṹ������sta�е�����Ԫ�ص��ҵ�����������ְԱ��Ϣ���ʹ�ӡ����
	{
		if (ps[i].number == num)
		{
			printf("\n��ѯ�ɹ�,��ѯ���Ϊ:\n");
			printf("%d\t%-s\t%-s\t%-d\t%-s\t%-d\t%-s\t%-d\n",
				ps[i].number,
				ps[i].name,
				ps[i].sex,
				ps[i].age,
				ps[i].education,
				ps[i].galary,
				ps[i].address,
				ps[i].tele);
			return i;//��ѯ�ɹ��㷵��i����������
		}
	}
	printf("\n�Բ���,���޴���\n");
	return -1;//��ѯʧ�ܣ��������������²�ѯ
}
void search_education(struct Staffs* ps)
{
	char edu[5];
	int i;
	int count = 0;//����ͳ�Ʋ�ѯ�������	
	scanf("%s", edu);//����Ҫ��ѯ��ѧ��
	for (i = 0; i < size; i++)//�����ṹ������sta�е�����Ԫ��,���ҵ�����������ְԱ��Ϣ���ʹ�ӡ����
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
			count++;//ÿ�ҵ�һ��������һ
		}
	}
	printf("\n�ܹ��ҵ�%d���й�\"%s\"��ְ����Ϣ���\n", count, edu);
}
void search_h(struct Staffs* ps)
{
	int choice;
	do
	{

		printf("\n��ѯ��ʽ:\n1.��ְ���Ų�ѯ\n2.��ѧ����ѯ\n3.�������˵�\n��ѡ��:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n������Ҫ��ѯ��ְ���ţ�");
			search_number(ps);
			break;
		case 2:
			printf("\n������Ҫ��ѯ��ѧ����");
			search_education(ps);
			break;
		case 3:
			break;
		default:
			printf("\nѡ�����,������ѡ��:\n");
		}
	} while (choice != 3);//��ѡ��3ʱ����ѭ�����������˵�
}
void correct(struct Staffs* ps)
{
	int i;
	printf("\n������Ҫ�޸ĵ�ְ���ţ�");
	i = search_number(ps);
	if (i != -1)
	{
		printf("\n������޸�:\n");//�޸���ѡ��ְ��
		printf("\n������ְ����:");
		scanf("%d", &ps[i].number);
		printf("����������:");
		scanf("%s", ps[i].name);
		printf("�������Ա�<Ů/��>:");
		scanf("%s", ps[i].sex);
		printf("����������:");
		scanf("%d", &ps[i].age);
		printf("������ѧ��:");
		scanf("%s", ps[i].education);
		printf("�����빤��:");
		scanf("%d", &ps[i].galary);
		printf("������סַ:");
		scanf("%s", ps[i].address);
		printf("������绰:");
		scanf("%d", &ps[i].tele);
		printf("\n�޸ĳɹ�\n");
	}
}
void del(struct Staffs* ps)
{
	int i;
	printf("\n������Ҫɾ����ְ���ţ�");
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
		p--;//ɾ��һ��ְ����Ϣ��¼�����ʼ��ַҲ��һ
		printf("\nɾ���ɹ���\n");

	}
}
int main()
{
	int choice;
	struct Staffs sta[MAX], * ps = sta;
	p = sta;//���ó�ʼ¼���ַΪ�����׵�ַ
	do
	{
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			p = input(p);//��ÿ��¼�����p��ָ�������Ԫ���еĵ�ַ���ظ�p�������´�¼�����ʼ��ַ
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
			printf("����������������ѡ��:\n");
		}
	} while (choice != 6);
	return 0;
}
