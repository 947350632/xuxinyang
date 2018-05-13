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
//定义全局变量i

//创建数据存储文件
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

//主菜单
void menu(void)
{
	fileset();
	//创建数据存储文件

	fileread();
	//读取数据

	for (;;)
	{
		system("cls");

		char a;

		printf("\t***   ╭□════■□■□══╮ ***\n");
		printf("\t*    │   会员卡信息管理系统   │  *\n");
		printf("\t*    ╰═■□■□══════■╯  *\n");
		printf("\t*    ┌───────────┐    *\n");
		printf("\t*    │1.添加信息  2.修改信息│    *\n");
		printf("\t*    │                      │    *\n");
		printf("\t*    │3.查询信息  4.删除信息│    *\n");
		printf("\t*    │                      │    *\n");
		printf("\t*    │5.信息排序  6.保存数据│    *\n");
		printf("\t*    │                      │    *\n");
		printf("\t*    │7.退出系统            │    *\n");
		printf("\t*    └───────────┘    *\n");
		printf("\t************************************\n");
		printf("\t请输入你的选择(1~7):");

		a = _getch();

		while (a<'1' || a>'7')
		{
			a = _getch();
		}
		//排除输入不为1到7时的情况

		if (a == '1')
			ID();
		//添加信息

		if (a == '2')
			change();
		//修改信息

		if (a == '3')
			search();
		//查询信息

		if (a == '4')
			del();
		//删除信息

		if (a == '5')
			order();
		//信息排序

		if (a == '6')
			filewrite();
		//

		if (a == '7')
		{
			printf("\n\t\t\t\t退出系统中...");
			Sleep(3000);
			//延迟

			exit(0);
		}
	}
	//显示主菜单及相应选项
}

//**********************
//**********************
//**********************

//添加信息
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
		//生成随机数并存储到list数组中

		do
		{
			printf("\n----------------------------------------------------\n");
			printf("\t      ———添加信息———\n\n");

			printf("会员卡号:%ld\n", list[x] + 100000);
			vip[i].id = list[x] + 100000;
			x++;
			//生成的随机数经过处理作为会员卡号

			printf("姓名:");
			gets_s(vip[i].name);

			printf("性别:");
			gets_s(vip[i].sex);
			while (strcmp(vip[i].sex, "男") != 0 && strcmp(vip[i].sex, "女") != 0)
			{
				printf("性别只限男女:");
				gets_s(vip[i].sex);
			}

			printf("手机号码:");
			scanf_s("%llu", &vip[i].phonenum);
			while (vip[i].phonenum <= 13000000000 || vip[i].phonenum >= 19000000000)
			{
				printf("请输入正确的手机号码:");
				scanf_s("%llu", &vip[i].phonenum);
			}

			i++;
			//全局变量i在存入一次数据后进行加一处理

			printf("\n添加完毕!  目前共有%d名会员!\n按1回到主界面!按2继续添加信息!\n", i);

			a = _getch();

			while (a != '1' && a != '2')
			{
				a = _getch();
			}
			//排除输入不为1和2的情况

		} while (a == '2');
		//重复当前添加信息操作

		if (a == '1')
			break;
		//返回主菜单
	}
}

//*********************
//*********************
//*********************

//修改信息
void change(void)       
{
	for (;;)
	{
		system("cls");

		char a;

		printf("\n----------------------------------------------------\n");
		printf("\t      ───修改信息───\n\n");
		printf("\t        ┌──────┐\n");
		printf("\t        │1.按手机号码│\n");
		printf("\t        │  修改      │\n");
		printf("\t        │2.按姓名修改│\n");
		printf("\t        │            │\n");
		printf("\t        │3.返回      │\n");
		printf("\t        └──────┘\n");
		printf("\t  请选择修改方式:");

		a = _getch();

		while (a<'1' || a>'3')
		{
			a = _getch();
		}

		if (a == '1')
			phonechange();   
		//按手机号码修改   

		if (a == '2')
			namechange();   
		//按姓名修改   

		if (a == '3')
			break;
		//返回主菜单
	}
}

//**************************
//**************************
//**************************

//按手机号码修改
void phonechange(void)
{
	for (;;)
	{
		system("cls");

		int j = 0;
		unsigned long long int a;

		printf("\t  请输入需要修改的信息对应的手机号码:");
		scanf_s("%llu", &a);
		while (a >= 19000000000 && a <= 13000000000)
		{
			printf("\t  请输入正确的手机号码:");
			scanf_s("%llu", &a);
		}

		for (int i = 0; i < MAX; i++)
		{
			if (a == vip[i].phonenum)
			{
				j = 1;
				//节点

				printf("请输入修改后新的信息:\n");
				printf("姓名:");
				getchar();
				gets_s(vip[i].name);

				printf("性别:");
				gets_s(vip[i].sex);
				while (strcmp(vip[i].sex, "男") != 0 && strcmp(vip[i].sex, "女") != 0)
				{
					printf("性别只限男女:");
					gets_s(vip[i].sex);
				}

				printf("手机号码:");
				scanf_s("%llu", &vip[i].phonenum);
				while (vip[i].phonenum <= 13000000000 || vip[i].phonenum >= 19000000000)
				{
					printf("请输入正确的手机号码:");
					scanf_s("%llu", &vip[i].phonenum);
				}

				printf("\n修改完毕!\n\n按1返回上一级!  ");
			}
		}
		if (j == 0)
		{
			printf("\t  对不起,记录中没有此人!");
			printf("\n\n按1返回上一级!  ");
		}
		//节点没变说明没有查询到结果

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//排除输入为1的情况

		if (a == '1')
			break;
		//返回上一级
	}
}

//**************************
//**************************
//**************************

//按姓名修改
void namechange(void)
{
	for (;;)
	{
		system("cls");

		int j = 0;
		char a;
		char name[10];

		printf("\t  请输入需要修改的名称信息:");
		scanf_s("%s", name);

		for (int i = 0; i < MAX; i++)
		{
			if (strcmp(name, vip[i].name) == 0)
			{
				j = 1;
				//节点

				printf("请输入修改后新的信息:\n");
				printf("姓名:");
				getchar();
				gets_s(vip[i].name);

				printf("性别:");
				gets_s(vip[i].sex);
				while (strcmp(vip[i].sex, "男") != 0 && strcmp(vip[i].sex, "女") != 0)
				{
					printf("性别只限男女:");
					gets_s(vip[i].sex);
				}

				printf("手机号码:");
				scanf_s("%llu", &vip[i].phonenum);
				while (vip[i].phonenum <= 13000000000 || vip[i].phonenum >= 19000000000)
				{
					printf("请输入正确的手机号码:");
					scanf_s("%llu", &vip[i].phonenum);
				}

				printf("修改成功!\n按1返回上一级!  ");
				break;
			}
		}
		if (j == 0)
		{
			printf("\t  对不起,记录中没有此人!");
			printf("\n\n按1返回上一级!  ");
		}
		//节点没变说明没有查询到结果

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//排除输入为1的结果

		if (a == '1')
			break;
		//返回上一级
	}
}

//**************************
//**************************
//**************************

//查询信息
void search(void)
{
	for (;;)
	{
		system("cls");

		char a;

		printf("----------------------------------------------------\n");
		printf("\t      ───查询信息───\n");
		printf("\t  ┌─────────────┐ \n");
		printf("\t  │1.按手机号码  2.按姓名查询│ \n");
		printf("\t  │  查询                    │ \n");
		printf("\t  │3.全部显示    4.返回      │ \n");
		printf("\t  └─────────────┘ \n");
		printf("\t  请输入你的选择:");

		a = _getch();

		while (a<'1' || a>'4')
		{
			a = _getch();
		}
		//排除输入为1到4的情况

		if (a == '1')
			phonesearch();    
		//按手机号码查询  

		if (a == '2')
			namesearch();  
		//按姓名查询   

		if (a == '3')
			show();  
		//全部显示   

		if (a == '4')
			break;
		//返回主菜单
	}
}

//******************************
//******************************
//******************************

//按手机号码查询
void phonesearch(void)    
{
	for (;;)
	{
		system("cls");
		fflush(stdin);

		int i, j = 0;
		unsigned long long int a;
		char b;

		printf("\t  请输入需要查询的手机号码:");
		scanf_s("%llu", &a);

		for (i = 0; i < MAX; i++)
		{
			if (vip[i].phonenum == a)
			{
				j = 1;        
				//节点

				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf(" 会员卡号\t姓名\t性别\t  手机号码\t积分\n");
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("  %ld\t %s\t %s\t %llu\t %ld\n", vip[i].id, vip[i].name, vip[i].sex, vip[i].phonenum, vip[i].score);
				printf("\n\n   输入1返回上一级！ ");
				break;
			}
		}
		//判断输入的值与会员的手机号码是否一致并打印会员信息

		if (j == 0) 
		{
			printf("\t  对不起,记录中没有此人!\n");
			printf("\n\n   输入1返回上一级！ ");
		}
		//节点没变说明没有查询到结果 

		getchar();
		b = _getch();

		while (b != '1')
		{
			b = _getch();
		}
		//排除输入不为1的情况

		if (b == '1')
			break;
		//返回上一级
	}
}

//******************************
//******************************
//******************************

//按姓名查询
void namesearch(void)  
{
	for (;;)
	{
		system("cls");
		fflush(stdin);

		char num[10];
		int j = 0;
		char a;

		printf("\t  请输入需要查询的姓名:");
		scanf_s("%s", num);

		for (int i = 0; i < MAX; i++)
		{
			if (strcmp(num, vip[i].name) == 0)
			{
				j = 1;
				//节点

				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf(" 会员卡号\t姓名\t性别\t  手机号码\t积分\n");
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("  %ld\t %s\t %s\t %llu\t %ld\n", vip[i].id, vip[i].name, vip[i].sex, vip[i].phonenum, vip[i].score);
				printf("\n\n   输入1返回主界面！ ");
				break;
			}
		}
		//判断输入的值与会员的名字是否一致并打印会员信息
		if (j == 0)
		{
			printf("\t  对不起,记录中没有此人!");
			printf("\n\n  输入1返回上一级！ ");
		}
		//节点没变说明没有查询到结果

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//排除输入不为1的情况

		if (a == '1')
			break;
		//返回上一级
	}
}

//******************************
//******************************
//******************************

//全部显示
void show(void)  
{
	for (;;)
	{
		system("cls");

		char a;

		printf("\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" 会员卡号\t姓名\t性别\t  手机号码\t积分\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

		for (int j = 0; j < i; j++)
		{
			if (vip[j].phonenum != 0)
				printf("  %ld\t %s\t %s\t %llu\t %ld\n", vip[j].id, vip[j].name, vip[j].sex, vip[j].phonenum, vip[j].score);
		}
		//打印已存入的会员信息

		printf("\n\n   输入1返回上一级！ ");

		a = _getch();

		while (a != '1')
		{
			a = _getch();
		}
		//排除输入不为1的情况

		if (a == '1')
			break;
		//返回上一级
	}
}

//**************************
//**************************
//**************************

//删除信息
void del(void)       
{
	for (;;)
	{
		system("cls");

		char a;

		printf("----------------------------------------------------\n");
		printf("\t      ───删除信息───\n");
		printf("\t        ┌──────┐\n");
		printf("\t        │1.按手机号码│\n");
		printf("\t        │  删除      │\n");
		printf("\t        │2.按姓名删除│\n");
		printf("\t        │            │\n");
		printf("\t        │3.返回      │\n");
		printf("\t        └──────┘\n");
		printf("\t      请输入你的选择:");

		a = _getch();

		while (a<'1' || a>'3')
		{
			printf("\t      请输入你的选择:");
			a = _getch();
		}
		//排除输入不为1到3的情况

		if (a == '1')
			phonedel();    
		//按手机号码删除   

		if (a == '2')
			namedel();  
		//按姓名删除   

		if (a == '3')
			break;
		//返回主菜单
	}
}

//*************************
//*************************
//*************************

//按手机号码删除
void phonedel(void)
{
	for (;;)
	{
		system("cls");

		int j, x, k;
		unsigned long long int a;

		printf("\t      请输入需要删除的信息对应的手机号码:");
		scanf_s("%llu", &a);

		k = 0;
		//节点

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
				//删除学生信息后，减少学生人数  

				break;
			}
		}
		if (k == 0)
		{
			printf("\t      对不起,记录中没有此人...");
			_getch();
			break;
		}
		//节点没变说明没有查询到结果

		printf("\n\t      删除成功!");
		_getch();
		break;
	}
}

//************************
//************************
//************************

//按姓名删除 
void namedel(void)
{
	for (;;)
	{
		system("cls");

		int j, x, k;
		char name[10];

		printf("\t      请输入需要删除的信息对应的姓名:");
		scanf_s("%s", name);
		k = 0;
		//节点

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
				//删除信息后,减少学生人数

				break;
			}
		}
		if (k == 0)
		{
			printf("\t      对不起,记录中没有此人...");
			_getch();
			break;
			//按任意键返回上一级
		}
		//节点没变说明没有查询到结果

		printf("\n\t      删除成功!");
		_getch();
		break;
		//按任意键返回上一级
	}
}

//************************
//************************
//************************

//信息排序
void order(void)  
{
	for (;;)
	{
		system("cls");

		char a;

		printf("----------------------------------------------------\n");
		printf("\t      ───信息排序───\n");
		printf("\t        ┌──────┐\n");
		printf("\t        │1.按会员卡号│\n");
		printf("\t        │  排序      │\n");
		printf("\t        │2.按积分排序│\n");
		printf("\t        │            │\n");
		printf("\t        │3.返回      │\n");
		printf("\t        └──────┘\n");
		printf("\t      请输入你的选择:");

		a = _getch();

		while (a<'1' || a>'3')
		{
			printf("\t      请输入你的选择:");
			a = _getch();
		}
		//排除输入不为1到3的情况

		if (a == '1')
			idorder();
		//按会员卡号排序

		if (a == '2')
			scoreorder();
		//按积分排序

		if (a == '3')
			break;
		//返回主菜单
	}
}

//************************
//************************
//************************

//按照会员卡号排序
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
			printf("\t      排序失败或已完成排序...");
			_getch();
			break;
			//按任意键返回上一级
		}
		else
		{
			printf("\t      排序成功...");
			_getch();
			break;
			//按任意键返回上一级
		}
	}
}

//************************
//************************
//************************

//按照积分排序
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
			printf("\t      排序失败或已完成排序...");
			_getch();
			break;
			//按任意键返回上一级
		}
		else
		{
			printf("\t      排序成功...");
			_getch();
			break;
			//按任意键返回上一级
		}
	}
}

//************************
//************************
//************************

//数据保存
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
			printf("\t      打开文件失败...");
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
		printf("\n\t      数据保存中...");
		printf("\n\t      ");
		for (int y = 1; y <= 5; y++)
		{
			printf("▋▋");
			Sleep(800);
		}
		//延迟

		if (a == 1)
		{
			printf("\n\t      数据保存成功...");
			_getch();
			break;
		}
		//打印信息并返回主菜单

		else
		{
			printf("\n\t      数据保存失败...");
			_getch();
			break;
		}
		//打印信息并返回主菜单
	}
}

//***********************
//***********************
//***********************

//数据读取
void fileread(void)
{
	FILE *fp = NULL;

	int y, a = 0;

	fopen_s(&fp, "vip.data", "rb+");

	if (fp == NULL)
	{
		printf("\t      打开文件失败...");
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
	printf("\n\t      数据读取中...");
	printf("\n\t      ");
	for (y = 1; y <= 5; y++)
	{
		printf("▋▋");
		Sleep(800);
	}
	if (a == 1)
	{
		printf("\n\t      数据读取成功!本次共读取%d个数据...", i);
		_getch();
	}
	else
	{
		printf("\n\t      数据读取失败!");
		_getch();
	}
}

//***********************
//***********************
//***********************

//登陆函数
int main(void)       
{
	system("color f0");

	printf("\n\n\n\t\t\t     会员卡信息管理系统\n\n");
	printf("\t\t\t                          Loading...\n\n");
	printf("\t\t\t                          ");

	for (int i = 1; i <= 5; i++)
	{
		printf("▋▋");
		Sleep(800);
		//延迟
	}

	system("cls");

	menu();

	return 0;
}
