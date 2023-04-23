
#include"Founction.h"

int main()
{
	/*Pcontacts Ph = (Pcontacts)malloc(sizeof(struct Contacts));
	if (Ph == NULL)
		return;*/
	Pcontacts Ph=init_Link2();
	P_group Pg = init_Link1();
	int i;
	do {
		Menu();
		printf("\t\t\t\t\t\t\t请选择：");
		scanf_s("%d", &i);
		
			switch (i)
			{
			case 1:
				puts("\n");
				Creat_Contact(Ph,Pg);
				break;
			case 2:
				puts("\n");
				Serach_Contact(Ph);
				break;
			case 3:
				puts("\n");
				Modify_Contact(Ph);
				break;
			case 4:
				puts("\n");
				Delet_Contact(Ph);
				break;
			case 5:
				puts("\n");
				Show_Contact(Ph);
				break;
			case 6:
				puts("\n");
				Empty_Contact(Ph);
				break;
			case 7:
				puts("\n");				
				Creat_Group(Pg);
				break;
			case 8:
				puts("\n");
				show_Group(Pg,Ph);
				break;
			case 9:
				puts("\n");
				Sort_By_Alphabet(Ph);
				Show_Contact(Ph);
				break;
			case 10:
				puts("\n");
				Empty_Group(Pg, Ph);
				break;
			case 0:
				puts("\n");
				Save_File1(Ph);
				Save_Group(Pg);
				printf("\t\t\t\t\t\t\t正在退出，请稍后。。。\n");
				exit(EXIT_SUCCESS);
			default:
				printf("\t\t\t\t\t\t\t输入错误，请重新输入\n");
				break;
			}

	} while (-1);
	return 0;
}


