#define _CRT_SECURE_NO_WARNINGS
#define MAX 20

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Contacts {
	char Name[1024];
	char Sex[1024];
	char Adress[1024];
	char Phon_num[1024];
	char QQ_num[1024];
	char Contact_Group[12];

	struct Contacts* Next;
};
typedef struct Contacts* Pcontacts;

struct C_Group {
	int num;
	char group[12];
	struct C_Group* next;
};
typedef struct C_Group* P_group;
//菜单函数
void Menu();            
//创建联系人
Pcontacts Creat_Contact(Pcontacts Ph, P_group Pg);  
//展示联系人
void Show_Contact(Pcontacts Ph);  
//搜索联系人
void Serach_Contact(Pcontacts Ph);  
//修改联系人信息
void Modify_Contact(Pcontacts Ph);  
//修改联系人子菜单
void Menu_Contact();               
//删除联系人
void Delet_Contact(Pcontacts Ph);  
//清空联系人
void Empty_Contact(Pcontacts Ph);  
//展示联系人姓名
void Show_Name(Pcontacts Ph);
//计算人数
int Num_Link(Pcontacts Ph);        
//保存到文件中
void Save_File(Pcontacts Ph);      

void Save_File1(Pcontacts Ph);

void Save_File2(Pcontacts Ph);

int compute(Pcontacts Ph); 
//按字母顺序排序
void Sort_By_Alphabet(Pcontacts Ph);
Pcontacts init_Link2();
//初始化群组
P_group init_Link1();         
//新建群组
P_group Creat_Group(P_group Pg);        
//计算群组长度
int Group_longth(P_group Pg);           
//展示群组
void show_Group(P_group Pg, Pcontacts Ph);			
//保存群组到文件中去
void Save_Group(P_group Pg);
//判断输入是否合法
int Determing_Input(char arr[]);
//清空群组
void Empty_Group(P_group Pg, Pcontacts Ph);


