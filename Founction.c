#include"Founction.h"




void Menu()
{
	printf("\t\t\t\t\t\t\t *****************************************\n");

	printf("\t\t\t\t\t\t\t *********    ��ӭ����ͨѶ¼    **********\n");

	printf("\t\t\t\t\t\t\t ********   �����Խ������²���   *********\n");

	printf("\t\t\t\t\t\t\t***1.������ϵ��             2.������ϵ��***\n");

	printf("\t\t\t\t\t\t\t***3.�޸���ϵ��             4.ɾ����ϵ��***\n");

	printf("\t\t\t\t\t\t\t***5.��ʾ��ϵ��             6.�����ϵ��***\n");

	printf("\t\t\t\t\t\t\t***7.�½���ϵ��Ⱥ��         8.��Ⱥ����ʾ***\n");

	printf("\t\t\t\t\t\t\t**9.����������ĸ˳���ӡ   10.�������Ⱥ��**\n");

	printf("\t\t\t\t\t\t\t***           0.�˳�����             ****\n");

}

Pcontacts Creat_Contact(Pcontacts Ph, P_group Pg)
{
	int num;
	char m[4] = { 0 };
	char n[4] = { 0 };
	char c;
	int i=0;
	do {
		Pcontacts p = (Pcontacts)malloc(sizeof(struct Contacts));
		Pcontacts tail;
		if (p == NULL)
			return NULL;
		//p->Next = NULL;
		printf("\t\t\t\t\t\t\t������������");
		scanf_s("%s", p->Name, 1024);
		printf("\t\t\t\t\t\t\t�������Ա�");
		scanf_s("%s", p->Sex, 3);
		while ((c = getchar()) != '\n' && c != EOF);
		while (strcmp(p->Sex, "��") != 0 && strcmp(p->Sex, "Ů") != 0)
		{
			printf("\t\t\t\t\t\t\t\033[31;47m��������Ա�ֻ��Ϊ���С���Ů�������������룺\033[0m");
			
			scanf_s("%s", p->Sex, 3);
			while ((c = getchar()) != '\n' && c != EOF);
			if (strcmp(p->Sex, "��") == 0 || strcmp(p->Sex, "Ů") == 0)
				break;
		}
		
		printf("\t\t\t\t\t\t\t������סַ��");
		scanf_s("%s", p->Adress, 1024);
		printf("\t\t\t\t\t\t\t������绰���룺");
		scanf_s("%s", p->Phon_num, 1024);
		
		while ((strlen(p->Phon_num) > 11 || strlen(p->Phon_num) < 4)|| !Determing_Input(p->Phon_num))
		{
			
			printf("\t\t\t\t\t\t\t\033[31;47m������󣬵绰����ֻ�������ֶ��ұ�����С�ڻ����11λ�ģ��Ҵ���3λ�����������룺\033[0m");
			scanf_s("%s", p->Phon_num, 1024);
			if ((strlen(p->Phon_num) <= 12 && strlen(p->Phon_num) >= 4)&& Determing_Input(p->Phon_num))
				break;
		}
		
		printf("\t\t\t\t\t\t\t������QQ���룺");
		scanf_s("%s", p->QQ_num, 20);
		while (strlen(p->QQ_num) !=10|| !Determing_Input(p->QQ_num))
		{
			printf("\t\t\t\t\t\t\t\033[31;47m�������QQ����ֻ�������ֶ���λ��Ϊʮλ�����������룺\033[0m");
			scanf_s("%s", p->QQ_num, 20);
			if (strlen(p->QQ_num) == 10&& Determing_Input(p->QQ_num))
				break;
		}

		printf("\t\t\t\t\t\t\t�Ƿ񽫸���ϵ�˼��뵽Ⱥ��(Y/N):");
		scanf_s("%s", m, 4);
		while (strcmp(m, "Y") != 0 && strcmp(m, "N") != 0)
		{
			printf("\t\t\t\t\t\t\t\033[32;47m�������Ӧ����Y/N�����������룺\033[0m");
			scanf_s("%s", m, 4);
			if (strcmp(m, "Y") == 0 || strcmp(m, "N") == 0)
				break;
		}
		if (strcmp(m, "N") == 0) {
			strcpy(p->Contact_Group, "��Ⱥ��");
		}
		else {
			num = Group_longth(Pg);
			if (num == 0)
			{
				printf("\t\t\t\t\t\t\t��ǰϵͳû��Ⱥ�飬���½�Ⱥ��\n");
				Creat_Group(Pg);
			}
			show_Group(Pg, Ph);
			printf("\t\t\t\t\t\t\t��ѡ����Ҫ�����Ⱥ�飨����Ⱥ��������");
			scanf_s("%s", p->Contact_Group, 24);
		}
		
		
		//Show_Con_Group(Con_Group_Arr);
		printf("\t\t\t\t\t\t\t�Ƿ񱣴棬������(Y/N): ");
		scanf_s("%s", n,4);
		
		if (strcmp(n, "Y") == 0)
		{
			tail = Ph;
			while (tail->Next != NULL) {
				tail = tail->Next;
			}
				tail->Next = p;
				p->Next = NULL;
				printf("\t\t\t\t\t\t\t\t\t\033[32;47m�����ɹ�\033[0m\n");

			/*if (Ph->Next == NULL)
			{
				Ph->Next = p;
				p->Next = NULL;
				printf("\t\t\t\t\t\t\t\t\t\033[32;47m�����ɹ�\033[0m\n");
			}
			else
			{
				p->Next = Ph->Next;
				Ph->Next = p;
				printf("\t\t\t\t\t\t\t\t\t\033[32;47m�����ɹ�\033[0m\n");
			}*/
		}
		
		
		printf("\t\t\t\t\t\t\t�Ƿ��������(����Y/N): ");
		scanf_s("%s", m,4);
		while(strcmp(m, "Y") != 0&&strcmp(m, "N") != 0)
		{
			printf("\t\t\t\t\t\t\t\033[32;47m�������Ӧ����Y/N�����������룺\033[0m");
			scanf_s("%s", m,4);
			if (strcmp(m, "Y") == 0 || strcmp(m, "N") == 0)
				break;
		}
		if (strcmp(m, "Y") == 0)
			i = 1;
		if (strcmp(m, "N") == 0)
			i = 0;
		puts("\n\n");
	} while (i);

	    return Ph;
}

void Show_Contact(Pcontacts Ph)
{
	int num;
	Pcontacts p = Ph->Next;
	if (Ph->Next == NULL)
	{
		printf("\t\t\t\t\t\t\t����ϵ����Ϣ\n");
	}
	printf("\t\t\t\t\t\t\t1.�������ӡ    2.������ӡ\n");
	printf("\t\t\t\t\t\t\t��ѡ��1/2����");
	scanf_s("%d", &num);
	puts("\n\n");
	if (num == 2)
	{
		//printf("\033[34;47m");
		printf("\t\t\t\t\033[34;47m|--------------------------------------------------------------------------------------------------------------------|\033[0m\n");
		printf("\t\t\t\t\033[34;47m|                                                   ��ϵ�˱�                                                       |\033[0m\n");
		printf("\t\t\t\t\033[34;47m|--------------------------------------------------------------------------------------------------------------------|\033[0m\n");
		printf("\t\t\t\t\033[34;47m| �� ��    �� ��     �� ַ                                    �� ��                       QQ                  Ⱥ��   |\033[0m\n");
		printf("\t\t\t\t\033[34;47m|--------------------------------------------------------------------------------------------------------------------|\033[0m\n");
	}

	while (p!= NULL)
	{
		if (num == 1)
		{
			printf("\t\t\t\t\t\t\t������%s\n", p->Name);
			printf("\t\t\t\t\t\t\t�Ա�%s\n", p->Sex);
			printf("\t\t\t\t\t\t\t��ַ��%s\n", p->Adress);
			printf("\t\t\t\t\t\t\t�绰���룺%s\n", p->Phon_num);
			printf("\t\t\t\t\t\t\tQQ���룺%s\n", p->QQ_num);
			printf("\t\t\t\t\t\t\tȺ�飺%s\n", p->Contact_Group);
			puts("\n\n");
		}


		if (num == 2)
		{
					
			printf("\t\t\t\t\033[34;47m| %-6s      %-2s     %-42s%-11s                  %-10s         %-3s|\033[0m\n", p->Name, p->Sex, p->Adress, p->Phon_num, p->QQ_num, p->Contact_Group);
			printf("\t\t\t\t\033[34;47m|--------------------------------------------------------------------------------------------------------------------|\033[0m\n");

		}
		p = p->Next;
	}
	//printf("\033[0m");
	puts("\n\n");
	free(p);

}

void Serach_Contact(Pcontacts Ph)
{
	Show_Name(Ph);
	int i = 0;
	printf("\t\t\t\t\t\t\t��������Ҫ��ѯ����ϵ�˵�������");
	char m[4] = { 0 };
	char name[1024] = {0};
	scanf_s("%s", name, 1024);
	do {
		Pcontacts p = Ph;
		
		while (p != NULL)
		{
			if (strcmp(p->Name, name) == 0)
			{
				printf("\t\t\t\t\t\t\t������%s\n", p->Name);
				printf("\t\t\t\t\t\t\t�Ա�%s\n", p->Sex);
				printf("\t\t\t\t\t\t\t��ַ��%s\n", p->Adress);
				printf("\t\t\t\t\t\t\t�绰���룺%s\n", p->Phon_num);
				printf("\t\t\t\t\t\t\tQQ���룺%s\n", p->QQ_num);
				printf("\t\t\t\t\t\t\tȺ�飺%s\n", p->Contact_Group);
				printf("\t\t\t\t\t\t\t\n\n");
				i = 1;
				break;
			}
			else
			{
				p = p->Next;
			}
		}
		if (!i)
		{
			printf("\t\t\t\t\t\t\t��ϵ���в�û�и���ϵ�˵���Ϣ��\n");
		}
		printf("\t\t\t\t\t\t\t�Ƿ��������(����Yes/No): ");
		scanf_s("%s", m,4);
		if (strcmp(m, "No") == 0)
			break;
		printf("\t\t\t\t\t\t\t��������Ҫ��ѯ����ϵ�˵�������");
		char name[1024] = { 0 };
		scanf_s("%s", name, 1024);

	} while (1);
	
}

void Modify_Contact(Pcontacts Ph)
{
	Show_Name(Ph);
	printf("\t\t\t\t\t\t\t��������Ҫ�޸ĵ���ϵ�˵�������");
	char arr[6][1024] = { "����","�Ա�","סַ","�绰����","QQ����","Ⱥ��"};
	char nam[1024] = { 0 };
	scanf_s("%s", nam, 1024);

	
	Pcontacts p = Ph;
	int i = 0;

	while (p != NULL)
	{
		if (strcmp(p->Name, nam) == 0)
		{
			printf("\t\t\t\t\t\t\t������%s\n", p->Name);
			printf("\t\t\t\t\t\t\t�Ա�%s\n", p->Sex);
			printf("\t\t\t\t\t\t\t��ַ��%s\n", p->Adress);
			printf("\t\t\t\t\t\t\t�绰���룺%s\n", p->Phon_num);
			printf("\t\t\t\t\t\t\tQQ���룺%s\n", p->QQ_num);
			printf("\t\t\t\t\t\t\tȺ�飺%s\n", p->Contact_Group);
			printf("\t\t\t\t\t\t\t\n\n");
			int num;
			Menu_Contact();
			do {
				printf("\t\t\t\t\t\t\t��������Ҫ�޸ĵ����ݴ���(����0�˳�): ");
				scanf_s("%d", &num);
				if (num == 0)
					break;
					for (int j = 1; j <= 6; j++)
					{
						if (j == num)
						{
							printf("\t\t\t\t\t\t\t��������Ҫ�޸ĵ�%s:", arr[j-1]);
							if (j == 1)
								scanf_s("%s", p->Name,1023);
							if (j == 2)
								scanf_s("%s", p->Sex,1024);
							if (j == 3)
								scanf_s("%s", p->Adress,1024);
							if (j == 4)
								scanf_s("%s", p->Phon_num,1024);
							if (j == 5)
								scanf_s("%s", p->QQ_num,1024);
							if(j==6)
								scanf_s("%s", p->Contact_Group,24);
						}
					}
			} while (-1);			
			i = 1;
			break;
		}
		else
		{
			p = p->Next;
		}
		printf("\t\t\t\t\t\t\t\t\t\033[32;47m�޸ĳɹ�\033[0m\n");
	}
	if (!i)
	{
		printf("\t\t\t\t\t\t\t��ϵ���в�û�и���ϵ�˵���Ϣ��\n");
	}
	
	
}

void Menu_Contact()
{
	printf("\t\t\t\t\t\t\t1.����       2.�Ա�\n");
	printf("\t\t\t\t\t\t\t3.��ַ       4.�绰����\n");
	printf("\t\t\t\t\t\t\t5.QQ����     6.Ⱥ��\n");
	printf("\t\t\t\t\t\t\t     0.�˳�\n");
}

void Sort_By_Alphabet(Pcontacts Ph)
{
	int count = Num_Link(Ph);
	int i, num;
	int flag = 0;
	Pcontacts p1, p2, p;
	for (i = 0; i < count - 1; i++)
	{
		p1 = Ph->Next;
		p2 = p1->Next;
		p = Ph;
		num = count - 1 - i;
		while (num--)
		{
			if (strcmp(p1, p2) > 0)
			{
				p->Next = p2;
				p1->Next = p2->Next;
				p2->Next = p1;
				flag = 1;

			}
			p = p->Next;
			p1 = p->Next;
			p2 = p1->Next;
		}
		if (!flag)
			break;
	}




}

void Delet_Contact(Pcontacts Ph)
{
	Show_Name(Ph);
	printf("\t\t\t\t\t\t\t��������Ҫɾ������ϵ��������");
	char name[1024] = { 0 };
	scanf_s("%s", name,1023);
	Pcontacts p = Ph;
	Pcontacts p1;
	int i = 0;
	while (p->Next != NULL)
	{
		if (strcmp(p->Next->Name, name) == 0)
		{
			p1 = p->Next;
			p->Next = p1->Next;
			free(p1);
			i = 1;
		}
		else
			p = p->Next;
		printf("\t\t\t\t\t\t\t\t\t\033[32;47mɾ���ɹ�\033[0m\n");
	}
	if (!i)
		printf("\t\t\t\t\t\t\t��ϵ���в��޴���");


}

void Empty_Contact(Pcontacts Ph)
{
	Pcontacts p = NULL;
	
	printf("\t\t\t\t\t\t\t�Ƿ�ɾ��������ϵ����Ϣ��Yes/No)");
	char name[1024] = { 0 };
	scanf_s("%s", name, 1024);
	if (strcmp(name, "Yes")==0)
	{
		Pcontacts p1 = Ph->Next;
		while (p1)
		{
			p = p1;
			p1 = p1->Next;
			free(p);
			p = NULL;
		}
		free(p);
		//free(Ph);
		Ph->Next=NULL;
		printf("\t\t\t\t\t\t\t\033[32;47m������\033[0m\n");
	}
	else
	{
		return;
	}
}


int Num_Link(Pcontacts Ph)
{
	Pcontacts p = Ph;
	int num=0;
	while (p->Next!=NULL)
	{
		num++;
		p = p->Next;
	}
	return num;
}

void Save_File(Pcontacts Ph)
{
	Pcontacts p =Ph;
	FILE* fp = NULL;
	fp = fopen("F:\\������è1\\Contact.txt", "wb");
	if (fp == NULL)
	{
		printf("\t\t\t\t\t\t\t����ʧ��!�ļ���ʧ�ܣ�\n");
		return;
	}
	//
	while (p != NULL)
	{
		fwrite(p, sizeof(struct Contacts), 1, fp);
		p = p->Next;
	}
	
	printf("\t\t\t\t\t\t\t����ɹ���\n");
	fclose(fp);
	fp = NULL;
}

void Save_File1(Pcontacts Ph)
{
	Pcontacts p = Ph->Next;
	FILE* fp = fopen("F:\\������è1\\Contact.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}

	while (p)
	{
		fprintf(fp, "%s %s %s %s %s %s ", p->Name, p->Sex, p->Adress, p->Phon_num, p->QQ_num,p->Contact_Group);
		p = p->Next;
	}
	fprintf(fp, "\n");
	fclose(fp);
	fp = NULL;
	return;
}

void Save_File2(Pcontacts Ph)
{
	printf("\n");
	int sz = compute(Ph);
	int i;
	Pcontacts p = Ph;
	FILE* fp = fopen("F:\\������è1\\Contact.txt", "wb");
	if (fp ==NULL||fp==0)
	{
		printf("\t\t\t\t\t\t\t�򲻿�");
	}
	for (i = 0; i < sz; i++)
	{
		if (fp == NULL)
			return;
		fwrite(p, sizeof(struct Contacts), 1, fp);
		p = p->Next;
	}
	if (fp == NULL)
		return;
	fclose(fp);
	printf("\t\t\t\t\t\t\t�������");
}

int compute(Pcontacts Ph)
{
	int count = 0;
	Pcontacts p = Ph;
	while (p != NULL)
	{
		p = p->Next;
		count++;

	}
	return count;

}
//--------------------------------------------------------------------
P_group init_Link1()
{
	FILE* fp = fopen("F:\\������è1\\C_Group.txt", "r");
	if (!fp)
	{
		fp = fopen("F:\\������è1\\C_Group.txt", "w+");
		if (!fp)
		{
			printf("\t\t\t\t\t\t\t�ļ�����ʧ��");
			return NULL;
		}
		{
			printf("\t\t\t\t\t\t\t�����ɹ�\n");
			P_group ph = (P_group)malloc(sizeof(struct C_Group));
			if (ph == NULL)
				return NULL;
			ph->next = NULL;
			return ph;
		}
	}

	int num = 0;
	P_group Ph = (P_group)malloc(sizeof(struct C_Group));
	if (Ph == NULL)
		return NULL;
	Ph->next = NULL;
	
	while (!feof(fp))
	{
		P_group tail;
		P_group p1 = calloc(1, sizeof(struct C_Group));
		if (p1 == NULL)
			return NULL;
		int ret = fscanf(fp, "%d %s",&p1->num, p1->group);
		
		if (ret != 2)
		{
			free(p1);
			break;
		}
		tail = Ph;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = p1;
		p1->next = NULL;
		/*p1->next = Ph->next;
		Ph->next = p1;
		num++;*/
	}
	fclose(fp);
	if (Ph == NULL)
	{
		return NULL;
	}
	
	return Ph;
}

P_group Creat_Group(P_group Pg)
{
	
	P_group p = (P_group)malloc(sizeof(struct C_Group));
	if (p == NULL) 
	{
		return NULL;
	}
	P_group p1;
	p->num = Group_longth(Pg)+1;
	printf("\t\t\t\t\t\t\t�������½�Ⱥ������");
	scanf_s("%s", p->group,24);
	p1 = Pg;
	while (p1->next != NULL) {
		p1 = p1->next;
	}
	p1->next = p;
	p->next = NULL;
	/*if (Pg->next == NULL)
	{
		Pg->next = p;
		p->next = NULL;
		printf("\t\t\t\t\t\t\tȺ��%s�����ɹ�\n",p->group);
	}
	else
	{
		p->next = Pg->next;
		Pg->next = p;
		printf("\t\t\t\t\t\t\tȺ��%s�����ɹ�\n", p->group);
	}*/
	return Pg;

}

int Group_longth(P_group Pg)
{
	int count = 0;
	P_group p = Pg;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	return count;

}

void show_Group(P_group Pg, Pcontacts Ph)
{
	Pcontacts p1;
	P_group p = Pg->next;
	while (p != NULL)
	{
		if (p->num == 0)
		{
			p = p->next;
			continue;
		}
		printf("\t\t\t\t\t\t\t\033[34;47mȺ��%d��\033[0m  \033[35;47m%s\033[0m\n", p->num, p->group);
		p1 = Ph;
		int count = 1;
		while (p1!= NULL)
		{
			if (strcmp(p1->Contact_Group, p->group) == 0)
			{
				printf("\t\t\t\t\t\t\t��ϵ��%d:   %s\n", count, p1->Name);
				count++;
			}
			
			p1 = p1->Next;
		}
		free(p1);
		if (count == 1)
			printf("\t\t\t\t\t\t\t��Ⱥ������ϵ��\n");
		printf("\n");
		p = p->next;
	}

}

void Save_Group(P_group Pg)
{
	P_group p = Pg->next;
	FILE* fp = fopen("F:\\������è1\\C_Group.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
		return;
	}

	while (p)
	{
		fprintf(fp, "%d %s ", p->num, p->group);
		p = p->next;
	}
	fprintf(fp, "\n");
	fclose(fp);
	fp = NULL;
	return;
}

void Empty_Group(P_group Pg, Pcontacts Ph)
{
	P_group p = NULL;

	printf("\t\t\t\t\t\t\t�Ƿ��������Ⱥ����Ϣ��Y/N)");
	char name[1024] = { 0 };
	scanf_s("%s", name, 1024);
	if (strcmp(name, "Y") == 0)
	{
		P_group p1 = Pg->next;
		while (p1)
		{
			p = p1;
			p1 = p1->next;
			free(p);
			p = NULL;
		}
		free(p);
		//free(Ph);
		Pg->next = NULL;
		printf("\t\t\t\t\t\t\t\033[32;47m������\033[0m\n");


		Pcontacts p3;
		p3 = Ph->Next;
		while (p3)
		{
			memset(p3->Contact_Group, 0, 12);
			strcpy(p3->Contact_Group, "��Ⱥ��");
			
			p3 = p3->Next;
		}
	}
	else
	{
		return;
	}

}
//--------------------------------------------------------------------
Pcontacts init_Link2()
{

	FILE* fp = fopen("F:\\������è1\\Contact.txt", "r");


	if (!fp)
	{
		//printf("\t\t\t\t123456\n");

		fp = fopen("F:\\������è1\\Contact.txt", "w+");
		if (!fp)
		{
			printf("\t\t\t\t�ļ�����ʧ��");
			return NULL;
		}
		{
			printf("\t\t\t\t\t\t\t�����ɹ�\n");
			Pcontacts ph = (Pcontacts)malloc(sizeof(struct Contacts));
					if (ph == NULL)
						return NULL;
					ph->Next = NULL;
			return ph;
		}
	}
	int num = 0;
	Pcontacts Ph = (Pcontacts)malloc(sizeof(struct Contacts));
	if (Ph == NULL)
		return NULL;
	Ph->Next = NULL;
	
	while (!feof(fp))
	{
		Pcontacts p;
		Pcontacts p1 = calloc(1, sizeof(struct Contacts));
		if (p1 == NULL)
			return NULL;
		int ret = fscanf(fp, "%s %s %s %s %s %s", p1->Name, p1->Sex, p1->Adress, p1->Phon_num, p1->QQ_num,p1->Contact_Group);
		
		if (ret !=6)
		{
			free(p1);
			break;
		}
		p = Ph;
		while (p->Next != NULL)
		{
			p = p->Next;
		}
		p->Next = p1;
		p1->Next = NULL;
		
		num++;
	}

	
	fclose(fp);
	if (Ph == NULL)
	{
		
		return NULL;
	}
	
	return Ph;
}

int Determing_Input(char arr[])                //�жϵ绰�����Լ�QQ���������Ƿ���ȷ
{
	int i = 0;
	int m = strlen(arr);
	for (i = 0; i < m; i++)
	{
		if (arr[i] < '0' || arr[i]>'9')
		{
			return 0;
		}
	}
	return 1;
}

void Show_Name(Pcontacts Ph)
{
	Pcontacts p = Ph->Next;
	int count = 1;
	while (p!= NULL) {
		printf("\t\t\t\t\t\t\t\033[34;47m��ϵ��%d: \033[0m\033[35;47\033[0m%s\n", count, p->Name);
		p = p->Next;
	}

}





