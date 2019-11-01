#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz1;
	int quiz2;
	struct personscore *link;
};
typedef struct personscore pscore;
pscore *ptr=NULL;
pscore *current=NULL;


void append()
{
	pscore *temp=(pscore*)malloc(sizeof(pscore));
 	 	
 	printf("�й��� �Է��Ͻÿ�: ");
	scanf("%d", &temp->number);
	printf("�̸��� �Է��Ͻÿ�: ");
	scanf("%s", temp->name);
	printf("����(�߰�)�� �Է��Ͻÿ�: ");
	scanf("%d", &temp->mid);
	printf("����(�⸻)�� �Է��Ͻÿ�: ");
	scanf("%d", &temp->final);
	printf("����(����1)�� �Է��Ͻÿ�: ");
	scanf("%d", &temp->quiz1);
	printf("����(����2)�� �Է��Ͻÿ�: ");
	scanf("%d", &temp->quiz2);
	
	temp->link=NULL;
	
 	if(ptr==NULL)
 	{
 		ptr=temp;
 		return;
	}
	
	current=ptr;
	
	while(current->link!=NULL)
		current=current->link;
	
	current->link=temp;

	printf("\n");
}

void Datasave(char *fname)
{
	FILE *fw;
	fw = fopen(fname, "w");

	fseek(fw, 0L, SEEK_END);	
	
	current = ptr;
	while (current != NULL)
	{

		fwrite(current, sizeof(pscore), 1, fw);
		current = current->link;
	}
}

void printscore()
{
	current=ptr;
	printf("\n������ ���� ������ >>\n");
	printf("%s\n", "  ____________________________________________________________");
	printf("%8s%15s%10s%8s%8s%8s\n", "��ȣ", "�̸�", "�߰�", "�⸻", "����1","����2");
	printf("%s\n", "  ------------------------------------------------------------");

	while (current != NULL) {
		printf("%6d%18s%8d%8d%8d%8d\n", current->number, current->name, current->mid, current->final, current->quiz1, current->quiz2);
		current = current->link;
		printf("\n");
	}
	printf("\n");
}

void fix()
{
	int hacb, choose,m;
	printf("������ �й��� �Է��Ͻÿ�:");
	scanf("%d", &hacb);
	current=ptr;
	do
	{
		if(current->number==hacb)
		{
			printf("� ������ �����ϰڽ��ϱ�?\n");
			printf("1.�߰�  2.�⸻  3.����1  4.����2\n");
			scanf("%d",&choose);
			
			switch(choose) {
				case 1 : 
					printf("�߰���� ������ �Է��ϼ���.: ");
					scanf("%d",&m);
					current->mid=m;
					break;
				case 2 : 
					printf("�⸻��� ������ �Է��ϼ���.: ");
					scanf("%d",&m);
					current->final=m;
					break;
				case 3 : 
					printf("����1 ������ �Է��ϼ���.: ");
					scanf("%d",&m);
					current->quiz1=m;
					break;
				case 4 : 
					printf("����2 ������ �Է��ϼ���.: ");
					scanf("%d",&m);
					current->quiz2=m;
					break;
			}
		}
		current =current->link;
	}while(current->link != NULL);
}


void Delete()
{
	pscore *prev;
	int hacb;
	current =ptr;

	printf("������ �й��� �Է��Ͻÿ�:");
	scanf("%d", &hacb);
	
	do{
		prev = current;
		current = current->link;

		if (current->number==hacb) {
			prev->link = current->link;
			free(current);
			break;
		}
	}while (current->link != NULL);
	return;
}

void Dataprint(char *fname, int*arr)
{
	int i;
	for(i =0; i<40;i++){
		printf("%d ",arr[i]);
	}
}

void Dataload(FILE *f, char *fname)
{
	int arr[500];
	fread(arr, sizeof(arr),1,f);
	Dataprint(fname, arr);
}



int * grade()
{
	current=ptr;
	static int sumi[40];
	int sumwhole=0;
	int i=0, j=0;
	while (current != NULL) {
		sumi[i]= current->mid + current->final + current->quiz1 + current->quiz2;
		printf("�̸�: %s   �����հ�: %d", current->name, sumi[i]);
		sumwhole+=sumi[i];
		i++;
		current = current->link;
		printf("\n");
	}
	current=ptr;
	while(current!=NULL)
	{
		if(((float)sumi[j]/400)>=0.8){
			printf("�̸�: %s   ��������: A\n", current->name);
		}
		else if(((float)sumi[j]/400)<0.8 && ((float)sumi[j]/400)>=0.6){
			printf("�̸�: %s   ��������: B\n", current->name);
		}
		else if(((float)sumi[j]/400)<0.6 && ((float)sumi[j]/400)>=0.4){
			printf("�̸�: %s   ��������: C\n", current->name);
		}
		else
		{
			printf("���������� �����ϴ�.");
		}
		j++;
		current = current->link;
	
	}
	
	printf("\n");
	return sumi;
}

void first(int*sumind)
{
	int max=0;
	int i=0;
	char firstname[40];
	current = ptr;
	while(current!=NULL)
	{
		if(*(sumind+i) >max)
		{
			max=(*(sumind+i));
			strcpy(firstname,current->name);
		}
		i++;
		current = current->link;
	}
	printf("��ü����1��: %s\n",firstname);
}

void hist(int*sumind)
{
	int starnum[40];
	int i=0, j=0;
	current = ptr;
	while(current!=NULL)
	{
		printf("%8s%-4d�� ",current->name, *(sumind+i));
		for(j=0; j<=*(sumind+i)/10;j++)
		{
			printf("*");
		}
		printf("\n");
		i++;
		current = current->link;
	}
}


int main()
{
	
	int choice;
	int *sumind;
	
	char fname[] = "test.bin";
	FILE *f;
	
	f = fopen(fname, "ab+");


	do {
		printf("1. �л������Է�\n");
		printf("2. �����Ϻμ���\n");
		printf("3. �л���������\n"); 
		printf("4. ���Ͽ��� �ҷ����� �� ����ϱ�\n");
		printf("5. �л�����������\n"); 
		printf("6. ��ü����1����ȸ\n");
		printf("7. ������׷�\n");
		printf("��ɾ �����Ͻÿ�: ");
		
		scanf("%d",&choice);

		switch(choice) {
			case 1 : 
				append(); 
				Datasave(fname);
				printscore();
				break;
			case 2 : 
				fix();
				Datasave(fname);
				printscore(); 
				break;
			case 3 : 
				Delete(ptr);
				Datasave(fname); 
				printscore();
				break;
			case 4 : 
				Dataload(f,fname); 
				break;
			case 5 : 
				sumind = grade(); 
				break;
			case 6 :
				first(sumind);
				break;
			case 7:
				hist(sumind);
				break;
		}
	}while(choice!=7);

	return 0;
}

	
	

	

