#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define LEN sizeof(struct student)//���ṹ�峤�ȶ���Ϊһ������
int studentTotle=0;//����ѧ������Ϊȫ�ֱ��� 
void manager_menu();//����Ա�˵� 
void addclass();//��ӿγ� 
void delclass();//ɾ���γ� 
void showclass();//��ѯ�γ� 
void addstudent();//���ѧ����Ϣ
void delstudent();//ɾ��ѧ����Ϣ 
void student_menu();//ѧ���˵� 
void choose();//ѡ��  
void *del();//ɾ����ѡ�γ� 
struct student *AppendNode(struct student *head);//����¼��
void DisplyNode(struct student *head);//���
struct student *DelNode(struct student *head,long num);//ɾ���ɼ� 
struct student *SelcetionSort(struct student *head,int choose);//����
struct student * QueryNode(struct student *head,long num);	//��ѯ
void ModifyNode(struct student *head,long num);//�޸�
void SwapInt(int *x,int *y);//��������
void SwapLong(long *x,long *y);//����������
struct student *ReadFile(struct student *head);//���ļ�������ݵ�����
int WriteFile(struct student *head);//������������д���ļ�

 
 
 struct teacherscore
 {
    long num;
    int score[100];
    struct teacherscore *next;
 }; 
 
 int teacherscoreTotle=0;//����ɼ�����Ϊȫ�ֱ���
 
 struct teacherscore *ReadFile(struct teacherscore *head);//���ļ�������ݵ�����
 void WriteFile(struct teacherscore *head);//������������д���ļ�


typedef struct manager//����Ա�ṹ�� 
{
	char classname[100];//�γ�����  
	char classroom[100];//���� 
	char classteacher[100];//��ʦ 
	int coursecode[100];//�γ̱�ţ�
	float classscore[100];//�γ�ѧ�֣�
	int term[100];//����ѧ�ڣ�
	int classhour[100];//�ڿ�ѧʱ�� 
	struct manager *next;
}MANAGER;

struct student//����ѧ���ṹ�����飻
{
    int num[100];//ѧ��ѧ�ţ�
    char stuname[50];//ѧ��������
    int stuchoose[100];//ѡ��Ŀγ̣�
    char password[100];//���� 
    char studentmajor[100];//רҵ
	char studentclass[100];//�༶ 
	int score[100];//�ɼ� 
	struct student *next;
}STUDENT;

int main()
{
	int i,j,k;
	printf("===================��Уѡ�޿ι���ϵͳ=======================");
	printf("\n------------------------���ܲ˵�--------------------------");
	printf("\n\t\t\t1.����Ա���");
	printf("\n\t\t\t2.ѧ�����");
	printf("\n\t\t\t0.�˳�ϵͳ");
	printf("\n----------------------------------------------------------");
	printf("\n��ѡ��(0-2):"); 
	scanf("%d",&j);
	switch(j)
	{
		case 1:
			    manager_menu();
			    scanf("%d",&i);
				switch(i)
				{
					case 1:
					    system("cls");
					    addclass();
					    break;
					case 2:
						system("cls");
						delclass();
						break;
					case 3:
						system("cls");
						addstudent();
						break;
					case 4:
						
						delstudent();
						break;
					case 5:
						struct teacherscore *input();
						break;
						
				}
						
			}while(i!=0);
	}
	
		
	
	


typedef struct node
{
	struct manager clas;
	struct node *next;
	
}NODE;

typedef struct node1
{
	struct student stu;
	struct node1 *next;
	
}NODE1;



NODE *head=NULL;//ͷ���
NODE1 *head1=NULL;//ͷ��� 
MANAGER *head2;//ͷ���


//����Ա����
void manager_menu()
{
	printf("=====================����Ա��������=========================");
	printf("\n------------------------���ܲ˵�--------------------------");
	printf("\n\t\t\t1.���ѡ����Ϣ");
	printf("\n\t\t\t2.ɾ���γ���Ϣ");
	printf("\n\t\t\t3.���ѧ����Ϣ");
	printf("\n\t\t\t4.ɾ��ѧ����Ϣ");
	printf("\n\t\t\t5.¼��ѡ�γɼ�");
	printf("\n\t\t\t0.�˳�����Ա�˵�");
	printf("\n----------------------------------------------------------");
	printf("������0-5�����֣����й���Ա����ѡ��");
	int answer;
	scanf("%d",&answer) ;
	while(1)
	{
		switch(answer)
		{
			case 1:
				system("cls");
				addclass();//���ѡ����Ϣ 
				printf("     ��������������˵�����");
				getch();
				break; 
			case 2:
				system("cls");
				delclass();//ɾ���γ�
				printf("     ��������������˵�����");
				getch();
				break;
			case 3:
				system("cls");
				addstudent();//���ѧ����Ϣ 
				printf("     ��������������˵�����");
				getch();
				break;
			case 4:
				system("cls");
				delstudent();//ɾ��ѧ����Ϣ
				printf("     ��������������˵�����");
				getch();
				break; 			
			case 5:
				system("cls");
				struct teacherscore *input();//¼��ѡ�γɼ�
				printf("     ��������������˵�����");
				getch(); 
				break;
			case 0:
				system("cls");
				printf("\n");
				return ;
				break;
			default:
			{
			    printf("\n\n����ѡ���ȷ����ѡ��1-6�е�һ������");
			}
		}
	}
	
} 

void student_menu()//ѧ������ 
{
    int option;
	printf("\t********��ѯ�γ�********\n\n");
    printf("\t1.��ѯ���пγ�\n\n");
	printf("\t2.��ѯ��ѡ�γ�\n\n");
	printf("\t3.��ѯ�γ̳ɼ�\n\n");
	printf("\t4.ѡ��γ�\n\n");
	printf("\t0.�˳���ѯ�γ�\n\n");
	printf("\t��ѡ��0-4�е�����֮һ������ѡ�β�ѯ");
	scanf("%d",&option) ;
	switch(option)
	{
		case 1:
		    system("cls");
		    showclass();

		    break;
		case 2:
		    system("cls");
		    choose();

		    break;
		case 3:
			system("cls");
			struct student * QueryNode(struct student *head,long num);;

			break;
			
		case 0:
		    system("cls");
		    printf("\n");
		    return ;
		    break;
		default:
		{
		    printf("\n\n����ѡ���ȷ����ѡ��0-3�е�һ������");
		}	
	}
    
}
    



void addclass()//��ӿγ���Ϣ 
{
	system("cls");
	NODE *newnode=(NODE *)malloc(sizeof(NODE));//�����½�� 
	newnode->next=NULL;
	printf("������γ�����:\n");       //���� 
	scanf("%s",newnode->clas.classname);
	printf("�����뿪��ѧ��:\n");       //ѧ�� 
	scanf("%d",newnode->clas.term);
	printf("������γ̽�ʦ:\n");       //��ʦ 
	scanf("%s",newnode->clas.classteacher);
	printf("������γ̽���:\n");       //���� 
	scanf("%s",newnode->clas.classroom);
	printf("������γ�ѧʱ:\n");       //ѧʱ 
	scanf("%d",newnode->clas.classhour);
	printf("������γ�ѧ��:\n");       //ѧ��
	scanf("%f",newnode->clas.classscore);
	printf("������γ̱��:\n");       //���
    scanf("%d",newnode->clas.coursecode);
	
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
	
	printf("##     ���ѡ����Ϣ�ɹ�     ##\n");
	char quit;
	printf("�Ƿ�������?(Y/N)");    //�Ƿ�������   
	    scanf("\t%c", &quit);
	    if(quit=='Y'||quit=='y'){
	    printf("\n");
	    addclass();}
	    else
	    return;
	system("cls");
	
}

void delclass(struct manager *node)//ɾ���γ� 
{
	system("cls");
    struct manager *p;
    p=node->next;
    
	
}
void showclass()//��ѯ�γ� 
{
	system("cls");
	NODE *p=head;
	printf("============================================================");
	printf("# ����\t\tѧ��\t\t��ʦ\t\t���� #\n");
	while(1)
	{
		printf("# %s\t\t%d\t\t%s\t\t%s #\n",p->clas.classname,p->clas.term,p->clas.classteacher,p->clas.classroom);
		p=p->next;
	}
	printf("============================================================");
	system("cls");
}

void addstudent()//���ѧ����Ϣ 
{
	system("cls");
	NODE1 *newnode1=(NODE1 *)malloc(sizeof(NODE1));//�����½�� 
	newnode1->next=NULL;
	printf("������ѧ������:\n");       //���� 
	scanf("%s",newnode1->stu.stuname);
	printf("������ѧ��ѧ��:\n");       //ѧ��
	scanf("%d",newnode1->stu.num);
	printf("������רҵ�༶:\n");       //רҵ�༶
	scanf("%s",newnode1->stu.studentmajor);

	if(head1==NULL)
	{
		head1=newnode1;
	}
	else
	{
		newnode1->next=head1;
		head1=newnode1;
	}
	
	printf("##     ���ѧ����Ϣ�ɹ�     ##\n");
	char quit;
		printf("�Ƿ�������?(Y/N)");    //�Ƿ�������   
		    scanf("\t%c", &quit);
		    if(quit=='Y'||quit=='y'){
		    printf("\n");
		    addstudent();}
		    else
		    return;
	system("cls");
	
}
//����ѧ�Ų�ѯѧ����Ϣ
struct student *QueryNode(struct student *head,long num)
{
    struct student *p=NULL;
    p=head;
    while(*p->num!=num&&*p->next!=NULL)
    {
        p=p->next ;
    }
    if(*p->num==num)
    {
        printf("\n\n\t*********��ѯ����ѧ����¼*********\n\n",studentTotle);
        printf("\t��������������������������������\n\n");
        printf("\t\t%-15s%-15s\n\n","ѧ��","�ɼ�");
        printf("\t\t%-15ld%-15d\n\n",p->num,p->score);
        printf("\t********************************\n\n");
    }
    else
    {
        printf("\n\n\t��Ǹ��û���ҵ�ѧ��Ϊ%ld��ѧ������Ϣ\n\n\n",num);
        p=NULL;
    }
    return p;

}

void password()//�������� 
{
	system("cls");
	char input[100]={0};
	FILE *fp;
	printf("������������룺");//�������� 
	fp=fopen("file\\data2.txt","wb");
	scanf("%s",input);
	fwrite(&input,sizeof(struct student),1,fp);
	int temp=0;
	while((temp=getchar())!='\n')
	{
	      ;
	}
	printf("��ȷ��������룬�Ӽ������루Y/N��ѡ��");//ȷ������ 
	int ch=getchar();
	if (ch=='Y')
	{
		printf("ȷ�ϳɹ���\n");
	}
	else
	{
		printf("ȷ��ʧ�ܣ�\n");
	}
	
}


//¼��ɼ���Ϣ 
//���򴴽�����
struct student *AppendNode(struct student *head)
{
    struct student *p=NULL;//Ҫ������½��
    struct student *q=NULL;//
    p=(struct student *)malloc(LEN);
    if(p==NULL)
    {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    printf("\n\n\t������ѧ����ѧ�źͳɼ�(����֮���ÿո�ָ���������ɰ��س���ȷ�ϡ�\n\n\t��������¼�빤����������ɼ�-1����\n");
    scanf("%ld",&p->num);
    scanf("%d",&p->score);
    if(head!=NULL)//����ǲ����и�ѧ��
    {
        q=head;
        while(q->num !=p->num &&q->next !=NULL)
            q=q->next ;
        if(q->num ==p->num )
        {
            printf("\n\n\n\t���ź�������Ҫ�����ѧ��%ld�Ѿ����ڣ��������Ҫ�޸ļ�¼���������˵�ѡ���޸�ѧ����¼��\n\n\n",p->num );
            return 0;

        }
    }
    while(*p->score!=-1)
    {
        studentTotle++;
        if(head==NULL)
        {
            head=p;
            p->next=NULL;
        }
        else//�������
        {
            p->next=head;
            head=p;
        }
        p=(struct student * )malloc(LEN);
        scanf("%ld",&p->num );
        scanf("%d",&p->score);

    }
    WriteFile(head);//����������д���ļ�
    return(head);
}
//��ʾѧ���ɼ�
void output(struct teacherscore *head)
{
    struct teacherscore *p=NULL;	//����ָ������ǰ����ָ��
       p=head;
       if(head!=NULL)
       {
           printf("\n\n\t*********���� %d ����¼*********\n\n",teacherscoreTotle);
           printf("\t��������������������������������\n\n");
           printf("\t\t%-15s%-15s\n\n","ѧ��","�ɼ�");
           while(p!=NULL)
           {
               printf("\t\t%-15ld%-15d\n\n",p->num,p->score);
               p=p->next;
           }
           printf("\t********************************\n\n");
       }
       else
           printf("\n\n\t��Ǹ��û��ѧ���ɼ����ݣ�\n\n");
}


//ɾ��ѧ���ɼ�
struct teacherscore *cut(struct teacherscore *head,long num)
{
        struct teacherscore *p=NULL;//Ҫɾ���Ľ��
	    struct teacherscore *pr=NULL;//Ҫɾ���Ľ���ǰһ�����
	    p=head;
	    while(p->num!=num&&p->next !=NULL)
	    {
	        pr=p;
	        p=p->next ;
	    }
	    if(p->num==num)
	    {
	        if(p==head)
	            head=p->next ;
	        else
	            pr->next =p->next ;
	
	        teacherscoreTotle=teacherscoreTotle-1;
	        printf("\n\n\n\t�ѳɹ�ɾ��ѧ��Ϊ%ld��ѧ���ɼ�\n\n\n\n",num);
	        free(p);
	
	    }
	    else
	        printf("\n\n\t��Ǹ��û���ҵ�ѧ��Ϊ%ld��ѧ���ĳɼ�\n\n\n",num);
	
	    return(head);
}

//���ݳɼ�����
struct teacherscore *sort(struct teacherscore *head,int choose)
{
       struct teacherscore *p=NULL;  
       struct teacherscore *q=NULL;  
       struct teacherscore *k=NULL;  
       if(head!=NULL)
       {
           for(p=head; p!=NULL; p=p->next)  
           {
               k=p;
               for(q=p->next; q!=NULL; q=q->next)  
               {
                   if((q->score>k->score)&&choose==0)//����
                       k=q;
                   else if((q->score<k->score)&&choose==1)//����
                       k=q;
               }
               if(k!=p)
               {
                    SwapInt(&*p->score,&*k->score);
				    SwapLong(&p->num,&k->num);
               }
           }
       }
       else
           printf("\n\n\t��Ǹ��û��ѧ���ɼ���\n\n");
       output(head);
       return(head);

}
void SwapInt(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void SwapLong(long *x,long *y)
{
    long temp;
    temp=*x;
    *x=*y;
    *y=temp;
}



struct teacherscore *ReadFile(struct teacherscore *head)
{
        FILE *fp;
		    struct teacherscore *p=NULL;
		    if((fp=fopen("file\\stuinfo.dat","r"))==NULL)	//���ı��ļ�������
		    {
		        printf("���ļ�ʧ�ܣ�\n");
		        return head;
		    }
		    p=(struct teacherscore *)malloc(LEN);
		    fread(p,LEN,1,fp);
		    p->next=NULL;
		    studentTotle=0;
		    while(!feof(fp))
		    {
		        //���ļ�������һ��ѧ����������ӵ������һ���ڵ���
		        studentTotle++;
		        if(head==NULL)
		        {
		            head=p;
		        }
		        else
		        {
		            p->next=head;
		            head=p;
		        }
		        p=(struct teacherscore *)malloc(LEN);
		        fread(p,LEN,1,fp);						//���ļ��ж���һ��ѧ����¼��p�ڵ���
		        p->next=NULL;
		    }
		
		    fclose(fp);//�ر��ļ�
		    printf("\n\t���ļ��й��ɹ�����%d��ѧ���ĳɼ�\n",studentTotle);
		    return head;
}
void WriteFile(struct teacherscore *head)
{
   FILE *fp;
   	    struct teacherscore *p=head;
   	    int count=0;	//�����������еĽڵ����
   	    if(head==NULL)
   	    {
   	        printf("��ѧ���ɼ���\n");
   	        return;
   	    }
   	    if((fp=fopen("file\\stuinfo.dat","wb"))==NULL)		//���ı��ļ�����д��
   	    {
   	        printf("�ļ���ʧ��!\n");
   	        return;
   	    }
   	    while(p!=NULL)				//�������ȫ������д���ļ���
   	    {
   	        count++;
   	        fwrite(p,LEN,1,fp);		//��p��ָ���1���ڵ�����д���ļ�
   	        p=p->next;
   	    }
   	    fclose(fp);	//�ر��ļ�
   	    printf("\n\t%d��ѧ���ĳɼ��ɹ�д���ļ���\n",count);
   	    return;
}


void *del()  //ɾ����ѡ�γ�
{
	MANAGER *p1,*p2;//����ṹ��ָ��ָ������ṹ��
	char ch,ch1;
	int num;
	while(ch!='0')
	{
		printf("������Ҫɾ���Ŀγ̱��:[    ]\b\b\b\b\b");
		scanf("%d",&num);
		if(*head2->coursecode==num) 
		{
			p2=head2;
			head2=head2->next;
			free(p2);
		}
		if(head2==NULL)
			return NULL;
		p1=head2;
		p2=head2->next;
		while(p2)
		{
			if(*p2->coursecode==num)
			{
				p1->next=p2->next;
				free(p2);
			}
			else 
				p1=p2;
			p2=p1->next;
		}
		printf("\n����ɾ���밴�س�\n");
		printf("\n����ɾ���γ̰� 0: [ ]\b\b");
		ch1=getchar();                       //���س�������CH1,����num�����������Ļس����ḳ��CH,�����CH1���
		ch=getchar();
		printf("\nɾ�����,����Ϣ�����ļ���\n");
		system("pause"); 
	}
	return head2;
	system("pause");
}


void choose()//ѡ�¿γ�--ѧ��ѡ�κ���
{
	MANAGER *p,*q;
	int a[5];
	int num,i=0,j;  //totalΪ��ѧ�֣�iΪnum�����鵥Ԫ
	printf("����Ҫѡ�޵Ŀγ̵ı��,���֮���Կո�ֿ�\n");
	scanf("%d",&num);
	printf("���ȷ��������Ҫѡ�޵Ŀγ̵ı��,������0: [ ]\b\b");
	
	FILE *fp;    //����fp��ָ�룬����ָ��FILE���͵Ķ���fp��ָ���ļ��ṹ���ָ�����
	fp=fopen("3.txt","w"); 	  //fprintf(fp,"�γ̱�� �γ�����  �ڿ�ѧʱ  ����ѧ��\n");
	for(j=0;j<i;j++)
	for(q=head2;q;q=q->next)
		if(*q->coursecode==a[j])
		fprintf(fp,"%5d%12s%9d%7d\n",q->coursecode,q->classname,q->classhour,q->term);
	fclose(fp);  //�ر�
	printf("\t\t\n*****ѡ�޳ɹ�!****\n");
	printf("\n��ѡ�޵Ŀγ̷ֱ�Ϊ:\n");
	printf("\n�γ̱��  �γ�����  �ڿ�ѧʱ  ����ѧ��\n");
	for(j=0;j<i;j++)
	for(q=head2;q;q=q->next)
		if(*q->coursecode==a[j])
			printf("%5d%12s%9d%7d\n",q->coursecode,q->classname,q->classhour,q->term);
	printf("\n������Ϣȫ��������'3.txt'��\n");
	
	system("pause");   //��ͣ��û������㿪���ɵ�.exe�ļ�
}
