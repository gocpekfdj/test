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
//�˵�����
void Menu();            
//������ϵ��
Pcontacts Creat_Contact(Pcontacts Ph, P_group Pg);  
//չʾ��ϵ��
void Show_Contact(Pcontacts Ph);  
//������ϵ��
void Serach_Contact(Pcontacts Ph);  
//�޸���ϵ����Ϣ
void Modify_Contact(Pcontacts Ph);  
//�޸���ϵ���Ӳ˵�
void Menu_Contact();               
//ɾ����ϵ��
void Delet_Contact(Pcontacts Ph);  
//�����ϵ��
void Empty_Contact(Pcontacts Ph);  
//չʾ��ϵ������
void Show_Name(Pcontacts Ph);
//��������
int Num_Link(Pcontacts Ph);        
//���浽�ļ���
void Save_File(Pcontacts Ph);      

void Save_File1(Pcontacts Ph);

void Save_File2(Pcontacts Ph);

int compute(Pcontacts Ph); 
//����ĸ˳������
void Sort_By_Alphabet(Pcontacts Ph);
Pcontacts init_Link2();
//��ʼ��Ⱥ��
P_group init_Link1();         
//�½�Ⱥ��
P_group Creat_Group(P_group Pg);        
//����Ⱥ�鳤��
int Group_longth(P_group Pg);           
//չʾȺ��
void show_Group(P_group Pg, Pcontacts Ph);			
//����Ⱥ�鵽�ļ���ȥ
void Save_Group(P_group Pg);
//�ж������Ƿ�Ϸ�
int Determing_Input(char arr[]);
//���Ⱥ��
void Empty_Group(P_group Pg, Pcontacts Ph);


