#include "Information.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define MAX 1000

struct vip
{
	long int id, score = 0;
	unsigned long long int phonenum = 0;
	char name[10];
	char sex[10];
}vip[1000];

int i = 0;
//����ȫ�ֱ���i

//�������ݴ洢�ļ�
void fileset(void)
{
	FILE *fp = NULL;
	FILE *fq = NULL;
	fopen_s(&fq, "exist.data", "rb+");
	if (fq == NULL)
	{
		fopen_s(&fq, "exist.data", "wb");
		fopen_s(&fp, "vip.data", "wb");
		menu();
	}
}

//**********************
//**********************
//**********************

//���˵�
void menu(void)
{
	fileset();
	//�������ݴ洢�ļ�

	fileread();
	//��ȡ����

	for (;;)
	{
		system("cls");

		char a;

		printf("\t***   �q���T�T�T�T���������T�T�r ***\n");
		printf("\t*    ��   ��Ա����Ϣ����ϵͳ   ��  *\n");
		printf("\t*    �t�T���������T�T�T�T�T�T���s  *\n");
		printf("\t*    ��������������������������    *\n");
		printf("\t*    ��1.�����Ϣ  2.�޸���Ϣ��    *\n");
		printf("\t*    ��                      ��    *\n");
		printf("\t*    ��3.��ѯ��Ϣ  4.ɾ����Ϣ��    *\n");
		printf("\t*    ��                      ��    *\n");
		printf("\t*    ��5.��Ϣ����  6.�������ݩ�    *\n");
		printf("\t*    ��                      ��    *\n");
		printf("\t*    ��7.�˳�ϵͳ            ��    *\n");
		printf("\t*    ��������������������������    *\n");
		printf("\t************************************\n");
		printf("\t���������ѡ��(1~7):");

		a = _getch();

		while (a<'1' || a>'7')
		{
			a = _getch();
		}
		//�ų����벻Ϊ1��7ʱ�����

		if (a == '1')
			ID();
		//�����Ϣ

		if (a == '2')
			change();
		//�޸���Ϣ

		if (a == '3')
			search();
		//��ѯ��Ϣ

		if (a == '4')
			del();
		//ɾ����Ϣ

		if (a == '5')
			order();
		//��Ϣ����

		if (a == '6')
			filewrite();
		//

		if (a == '7')
		{
			printf("\n\t\t\t\t�˳�ϵͳ��...");
			Sleep(3000);
			//�ӳ�

			exit(0);
		}
	}
	//��ʾ���˵�����Ӧѡ��
}

//**********************
//**********************
//**********************

//�����Ϣ
void ID(void) 
{
	for (;;)
	{
		system("cls");
		fflush(stdin);

		char a;
		int list[1000] = { 0 }, c, d, x = 0;

		srand((unsigned int)time(NULL));
		for (int b = 0; b < MAX; b++)
		{
			while (1)
			{
				d = rand() % 1000 + 1;
				for (c = 0; c < b; c++)
				{
					if (list[c] == d)
						break;
				}
				if (c == b)
				{
					list[b] = d;
					break;
				}
			}
		}
		//������������洢��list������

		do
		{
			printf("\n----------------------------------------------------\n");
			printf("\t      �����������Ϣ������\n\n");

			printf("��Ա����:%ld\n", list[x] + 100000);
			vip[i].id = list[x] + 100000;
			x++;
			//���ɵ����������������Ϊ��Ա����

			printf("����:");
			gets_s(vip[i].name);

			printf("�Ա�:");
			gets_s(vip[i].sex);
			while (strcmp(vip[i].sex, "��") != 0 && strcmp(vip[i].sex, "Ů") != 0)
			{
				printf("�Ա�ֻ����Ů:");
				gets_s(vip[i].sex);
			}

			printf("�ֻ�����:");
			scanf_s("%llu", &vip[i].phonenum);
			while (vip[i].phonenum <= 13000000000 || vip[i].phonenum >= 19000000000)
			{
				printf("��������ȷ���ֻ�����:");
				scanf_s("%llu", &vip[i].phonenum);
			}

			i++;
			//ȫ�ֱ���i�ڴ���һ�����ݺ���м�һ����

			printf("\n������!  Ŀǰ����%d����Ա!\n��1�ص�������!��2���������Ϣ!\n", i);

			a = _getch();

			while (a != '1' && a != '2')
			{
				a = _getch();
			}
			//�ų����벻Ϊ1��2�����

		} while (a == '2');
		//�ظ���ǰ�����Ϣ����

		if (a == '1')
			break;
		//�������˵�
	}
}

//*********************
//*********************
//*********************

//�޸���Ϣ
void change(void)       
{
	for (;;)
	{
		system("cls");

		char a;

		printf("\n----------------------------------------------------\n");
		printf("\t      �������޸���Ϣ������\n\n");
		printf("\t        ����������������\n");
		printf("\t        ��1.���ֻ����멦\n");
		printf("\t        ��  �޸�      ��\n");
		printf("\t        ��2.�������޸ĩ�\n");
		printf("\t        ��            ��\n");
		printf("\t        ��3.����      ��\n");
		printf("\t        ����������������\n");
		printf("\t  ��ѡ���޸ķ�ʽ:");

		a = _getch();

		while (a<'1' || a>'3')
		{
			a = _getch();
		}

		if (a == '1')
			phonechange();   
		//���ֻ������޸�   

		if (a == '2')
			namechange();   
		//�������޸�   

		if (a == '3')
			break;
		//�������˵�
	}
}

//**************************
//**************************
//**************************

//���ֻ������޸�
void phonechange(void)
{
	for (;;)
	{
		system("cls");

		int j = 0;
		unsigned long long int a;

		printf("\t  ��������Ҫ�޸ĵ���Ϣ��Ӧ���ֻ�����:");
		scanf_s("%llu", &a);
		while (a >= 19000000000 && a <= 13000000000)
		{
			printf("\t  ��������ȷ���ֻ�����:");
			scanf_s("%llu", &a);
		}

		for (int i = 0; i < MAX; i++)
		{
			if (a == vip[i].phonenum)
			{
				j = 1;
				//�ڵ�

				printf("�������޸ĺ��µ���Ϣ:\n");
				printf("����:");
				getchar();
				gets_s(vip[i].name);

				printf("�Ա�:");
				gets_s(vip[i].sex);
				while (strcmp(vip[i].sex, "��") != 0 && strcmp(vip[i].sex, "Ů") != 0)
				{
					printf("�Ա�ֻ����Ů:");
					gets_s(vip[i].sex);
				}

				printf("�ֻ�����:");
				scanf_s("%llu", &vip[i].phonenum);
				while (vip[i].phonenum <= 13000000000 || vip[i].phonenum >= 19000000000)
				{
					printf("��������ȷ���ֻ�����:");
					scanf_s("%llu", &vip[i].phonenum);
				}

				printf("\n�޸����!\n\n��1������һ��!  ");
			}
		}
		if (j == 0)
		{
			printf("\t  �Բ���,��¼��û�д���!");
			printf("\n\n��1������һ��!  ");
		}
		//�ڵ�û��˵��û�в�ѯ�����

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//�ų�����Ϊ1�����

		if (a == '1')
			break;
		//������һ��
	}
}

//**************************
//**************************
//**************************

//�������޸�
void namechange(void)
{
	for (;;)
	{
		system("cls");

		int j = 0;
		char a;
		char name[10];

		printf("\t  ��������Ҫ�޸ĵ�������Ϣ:");
		scanf_s("%s", name);

		for (int i = 0; i < MAX; i++)
		{
			if (strcmp(name, vip[i].name) == 0)
			{
				j = 1;
				//�ڵ�

				printf("�������޸ĺ��µ���Ϣ:\n");
				printf("����:");
				getchar();
				gets_s(vip[i].name);

				printf("�Ա�:");
				gets_s(vip[i].sex);
				while (strcmp(vip[i].sex, "��") != 0 && strcmp(vip[i].sex, "Ů") != 0)
				{
					printf("�Ա�ֻ����Ů:");
					gets_s(vip[i].sex);
				}

				printf("�ֻ�����:");
				scanf_s("%llu", &vip[i].phonenum);
				while (vip[i].phonenum <= 13000000000 || vip[i].phonenum >= 19000000000)
				{
					printf("��������ȷ���ֻ�����:");
					scanf_s("%llu", &vip[i].phonenum);
				}

				printf("�޸ĳɹ�!\n��1������һ��!  ");
				break;
			}
		}
		if (j == 0)
		{
			printf("\t  �Բ���,��¼��û�д���!");
			printf("\n\n��1������һ��!  ");
		}
		//�ڵ�û��˵��û�в�ѯ�����

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//�ų�����Ϊ1�Ľ��

		if (a == '1')
			break;
		//������һ��
	}
}

//**************************
//**************************
//**************************

//��ѯ��Ϣ
void search(void)
{
	for (;;)
	{
		system("cls");

		char a;

		printf("----------------------------------------------------\n");
		printf("\t      ��������ѯ��Ϣ������\n");
		printf("\t  ������������������������������ \n");
		printf("\t  ��1.���ֻ�����  2.��������ѯ�� \n");
		printf("\t  ��  ��ѯ                    �� \n");
		printf("\t  ��3.ȫ����ʾ    4.����      �� \n");
		printf("\t  ������������������������������ \n");
		printf("\t  ���������ѡ��:");

		a = _getch();

		while (a<'1' || a>'4')
		{
			a = _getch();
		}
		//�ų�����Ϊ1��4�����

		if (a == '1')
			phonesearch();    
		//���ֻ������ѯ  

		if (a == '2')
			namesearch();  
		//��������ѯ   

		if (a == '3')
			show();  
		//ȫ����ʾ   

		if (a == '4')
			break;
		//�������˵�
	}
}

//******************************
//******************************
//******************************

//���ֻ������ѯ
void phonesearch(void)    
{
	for (;;)
	{
		system("cls");
		fflush(stdin);

		int i, j = 0;
		unsigned long long int a;
		char b;

		printf("\t  ��������Ҫ��ѯ���ֻ�����:");
		scanf_s("%llu", &a);

		for (i = 0; i < MAX; i++)
		{
			if (vip[i].phonenum == a)
			{
				j = 1;        
				//�ڵ�

				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf(" ��Ա����\t����\t�Ա�\t  �ֻ�����\t����\n");
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("  %ld\t %s\t %s\t %llu\t %ld\n", vip[i].id, vip[i].name, vip[i].sex, vip[i].phonenum, vip[i].score);
				printf("\n\n   ����1������һ���� ");
				break;
			}
		}
		//�ж������ֵ���Ա���ֻ������Ƿ�һ�²���ӡ��Ա��Ϣ

		if (j == 0) 
		{
			printf("\t  �Բ���,��¼��û�д���!\n");
			printf("\n\n   ����1������һ���� ");
		}
		//�ڵ�û��˵��û�в�ѯ����� 

		getchar();
		b = _getch();

		while (b != '1')
		{
			b = _getch();
		}
		//�ų����벻Ϊ1�����

		if (b == '1')
			break;
		//������һ��
	}
}

//******************************
//******************************
//******************************

//��������ѯ
void namesearch(void)  
{
	for (;;)
	{
		system("cls");
		fflush(stdin);

		char num[10];
		int j = 0;
		char a;

		printf("\t  ��������Ҫ��ѯ������:");
		scanf_s("%s", num);

		for (int i = 0; i < MAX; i++)
		{
			if (strcmp(num, vip[i].name) == 0)
			{
				j = 1;
				//�ڵ�

				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf(" ��Ա����\t����\t�Ա�\t  �ֻ�����\t����\n");
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("  %ld\t %s\t %s\t %llu\t %ld\n", vip[i].id, vip[i].name, vip[i].sex, vip[i].phonenum, vip[i].score);
				printf("\n\n   ����1���������棡 ");
				break;
			}
		}
		//�ж������ֵ���Ա�������Ƿ�һ�²���ӡ��Ա��Ϣ
		if (j == 0)
		{
			printf("\t  �Բ���,��¼��û�д���!");
			printf("\n\n  ����1������һ���� ");
		}
		//�ڵ�û��˵��û�в�ѯ�����

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//�ų����벻Ϊ1�����

		if (a == '1')
			break;
		//������һ��
	}
}

//******************************
//******************************
//******************************

//ȫ����ʾ
void show(void)  
{
	for (;;)
	{
		system("cls");

		char a;

		printf("\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" ��Ա����\t����\t�Ա�\t  �ֻ�����\t����\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

		for (int j = 0; j < i; j++)
		{
			if (vip[j].phonenum != 0)
				printf("  %ld\t %s\t %s\t %llu\t %ld\n", vip[j].id, vip[j].name, vip[j].sex, vip[j].phonenum, vip[j].score);
		}
		//��ӡ�Ѵ���Ļ�Ա��Ϣ

		printf("\n\n   ����1������һ���� ");

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//�ų����벻Ϊ1�����

		if (a == '1')
			break;
		//������һ��
	}
}

//**************************
//**************************
//**************************

//ɾ����Ϣ
void del(void)       
{
	for (;;)
	{
		system("cls");

		char a;

		printf("----------------------------------------------------\n");
		printf("\t      ������ɾ����Ϣ������\n");
		printf("\t        ����������������\n");
		printf("\t        ��1.���ֻ����멦\n");
		printf("\t        ��  ɾ��      ��\n");
		printf("\t        ��2.������ɾ����\n");
		printf("\t        ��            ��\n");
		printf("\t        ��3.����      ��\n");
		printf("\t        ����������������\n");
		printf("\t      ���������ѡ��:");

		a = _getch();

		while (a<'1' || a>'3')
		{
			printf("\t      ���������ѡ��:");
			a = _getch();
		}
		//�ų����벻Ϊ1��3�����

		if (a == '1')
			phonedel();    
		//���ֻ�����ɾ��   

		if (a == '2')
			namedel();  
		//������ɾ��   

		if (a == '3')
			break;
		//�������˵�
	}
}

//*************************
//*************************
//*************************

//���ֻ�����ɾ��
void phonedel(void)
{
	for (;;)
	{
		system("cls");

		int j, x, k;
		unsigned long long int a;

		printf("\t      ��������Ҫɾ������Ϣ��Ӧ���ֻ�����:");
		scanf_s("%llu", &a);

		k = 0;
		//�ڵ�

		for (j = 0; j <= i; j++)
		{
			if (a == vip[j].phonenum)
			{
				k = 1;
				for (x = j; x <= i; x++)
				{
					vip[x] = vip[x + 1];
				}
				i--;
				//ɾ��ѧ����Ϣ�󣬼���ѧ������  

				break;
			}
		}
		if (k == 0)
		{
			printf("\t      �Բ���,��¼��û�д���...");
			_getch();
			break;
		}
		//�ڵ�û��˵��û�в�ѯ�����

		printf("\n\t      ɾ���ɹ�!");
		_getch();
		break;
	}
}

//************************
//************************
//************************

//������ɾ�� 
void namedel(void)
{
	for (;;)
	{
		system("cls");

		int j, x, k;
		char name[10];

		printf("\t      ��������Ҫɾ������Ϣ��Ӧ������:");
		scanf_s("%s", name);
		k = 0;
		//�ڵ�

		for (j = 0; j <= i; j++)
		{
			if (strcmp(name, vip[j].name) == 0)
			{
				k = 1;
				for (x = j; x <= i; x++)
				{
					vip[x] = vip[x + 1];
				}
				i--;
				//ɾ����Ϣ��,����ѧ������

				break;
			}
		}
		if (k == 0)
		{
			printf("\t      �Բ���,��¼��û�д���...");
			_getch();
			break;
			//�������������һ��
		}
		//�ڵ�û��˵��û�в�ѯ�����

		printf("\n\t      ɾ���ɹ�!");
		_getch();
		break;
		//�������������һ��
	}
}

//************************
//************************
//************************

//��Ϣ����
void order(void)  
{
	for (;;)
	{
		system("cls");

		char a;

		printf("----------------------------------------------------\n");
		printf("\t      ��������Ϣ���򩤩���\n");
		printf("\t        ����������������\n");
		printf("\t        ��1.����Ա���ũ�\n");
		printf("\t        ��  ����      ��\n");
		printf("\t        ��2.����������\n");
		printf("\t        ��            ��\n");
		printf("\t        ��3.����      ��\n");
		printf("\t        ����������������\n");
		printf("\t      ���������ѡ��:");

		a = _getch();

		while (a<'1' || a>'3')
		{
			printf("\t      ���������ѡ��:");
			a = _getch();
		}
		//�ų����벻Ϊ1��3�����

		if (a == '1')
			idorder();
		//����Ա��������

		if (a == '2')
			scoreorder();
		//����������

		if (a == '3')
			break;
		//�������˵�
	}
}

//************************
//************************
//************************

//���ջ�Ա��������
void idorder(void)           
{
	for (;;)
	{
		system("cls");

		struct vip a;

		int x, y, one;

		for (x = 0; x<i - 1; x++)
		{
			one = 0;
			for (y = 0; y<i - 1 - x; y++)
			{
				if (vip[y].id>vip[y + 1].id)
				{
					a = vip[y];
					vip[y] = vip[y + 1];
					vip[y + 1] = a;
					one = 1;
				}
			}
			if (one == 0)
				break;
		}
		if (one == 0)
		{
			printf("\t      ����ʧ�ܻ����������...");
			_getch();
			break;
			//�������������һ��
		}
		else
		{
			printf("\t      ����ɹ�...");
			_getch();
			break;
			//�������������һ��
		}
	}
}

//************************
//************************
//************************

//���ջ�������
void scoreorder(void)      
{
	for (;;)
	{
		system("cls");

		struct vip a;

		int x, y, one;

		for (x = 0; x<i; x++)
		{
			one = 0;
			for (y = 0; y<i - x; y++)
			if (vip[y].score<vip[y + 1].score)
			{	
				a = vip[y];
				vip[y] = vip[y + 1];
				vip[y + 1] = a;
				one = 1;
			}
			if (one == 0)
				break;
		}
		if (one == 0)
		{
			printf("\t      ����ʧ�ܻ����������...");
			_getch();
			break;
			//�������������һ��
		}
		else
		{
			printf("\t      ����ɹ�...");
			_getch();
			break;
			//�������������һ��
		}
	}
}

//************************
//************************
//************************

//���ݱ���
void filewrite(void)
{
	for (;;)
	{
		system("cls");

		FILE *fp=NULL;

		int x, a = 0;

		fopen_s(&fp, "vip.data", "wb");

		if (fp == NULL)
		{
			printf("\t      ���ļ�ʧ��...");
			_getch();
			break;
		}
		for (x = 0; x<i; x++)
		{
			fwrite(&vip[x], sizeof(struct vip), 1, fp);
		}
		if (x == i)
		{
			a = 1;
		}
		fclose(fp);
		printf("\n\t      ���ݱ�����...");
		printf("\n\t      ");
		for (int y = 1; y <= 5; y++)
		{
			printf("����");
			Sleep(800);
		}
		//�ӳ�

		if (a == 1)
		{
			printf("\n\t      ���ݱ���ɹ�...");
			_getch();
			break;
		}
		//��ӡ��Ϣ���������˵�

		else
		{
			printf("\n\t      ���ݱ���ʧ��...");
			_getch();
			break;
		}
		//��ӡ��Ϣ���������˵�
	}
}

//***********************
//***********************
//***********************

//���ݶ�ȡ
void fileread(void)
{
	FILE *fp = NULL;

	int y, a = 0;

	fopen_s(&fp, "vip.data", "rb+");

	if (fp == NULL)
	{
		printf("\t      ���ļ�ʧ��...");
		_getch();
	}
	i = 0;
	while (!feof(fp))
	{
		fread(&vip[i], sizeof(struct vip), 1, fp);
		i++;
		a = 1;
	}
	i--;
	fclose(fp);
	printf("\n\t      ���ݶ�ȡ��...");
	printf("\n\t      ");
	for (y = 1; y <= 5; y++)
	{
		printf("����");
		Sleep(800);
	}
	if (a == 1)
	{
		printf("\n\t      ���ݶ�ȡ�ɹ�!���ι���ȡ%d������...", i);
		_getch();
	}
	else
	{
		printf("\n\t      ���ݶ�ȡʧ��!");
		_getch();
	}
}

//***********************
//***********************
//***********************

//��½����
int main(void)       
{
	system("color f0");

	printf("\n\n\n\t\t\t     ��Ա����Ϣ����ϵͳ\n\n");
	printf("\t\t\t                          Loading...\n\n");
	printf("\t\t\t                          ");

	for (int i = 1; i <= 5; i++)
	{
		printf("����");
		Sleep(800);
		//�ӳ�
	}

	system("cls");

	menu();

	return 0;
}
