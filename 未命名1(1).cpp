#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define LEN sizeof(struct student)//将结构体长度定义为一个常量
int studentTotle=0;//定义学生人数为全局变量 
void manager_menu();//管理员菜单 
void addclass();//添加课程 
void delclass();//删除课程 
void showclass();//查询课程 
void addstudent();//添加学生信息
void delstudent();//删除学生信息 
void student_menu();//学生菜单 
void choose();//选课  
void *del();//删除所选课程 
struct student *AppendNode(struct student *head);//批量录入
void DisplyNode(struct student *head);//输出
struct student *DelNode(struct student *head,long num);//删除成绩 
struct student *SelcetionSort(struct student *head,int choose);//排序
struct student * QueryNode(struct student *head,long num);	//查询
void ModifyNode(struct student *head,long num);//修改
void SwapInt(int *x,int *y);//交换正数
void SwapLong(long *x,long *y);//交换长整数
struct student *ReadFile(struct student *head);//读文件里的内容到链表
int WriteFile(struct student *head);//将链表结点数据写入文件

 
 
 struct teacherscore
 {
    long num;
    int score[100];
    struct teacherscore *next;
 }; 
 
 int teacherscoreTotle=0;//定义成绩总数为全局变量
 
 struct teacherscore *ReadFile(struct teacherscore *head);//读文件里的内容到链表
 void WriteFile(struct teacherscore *head);//将链表结点数据写入文件


typedef struct manager//管理员结构体 
{
	char classname[100];//课程名称  
	char classroom[100];//教室 
	char classteacher[100];//教师 
	int coursecode[100];//课程编号；
	float classscore[100];//课程学分；
	int term[100];//开课学期；
	int classhour[100];//授课学时； 
	struct manager *next;
}MANAGER;

struct student//定义学生结构体数组；
{
    int num[100];//学生学号；
    char stuname[50];//学生姓名；
    int stuchoose[100];//选择的课程；
    char password[100];//密码 
    char studentmajor[100];//专业
	char studentclass[100];//班级 
	int score[100];//成绩 
	struct student *next;
}STUDENT;

int main()
{
	int i,j,k;
	printf("===================高校选修课管理系统=======================");
	printf("\n------------------------功能菜单--------------------------");
	printf("\n\t\t\t1.管理员入口");
	printf("\n\t\t\t2.学生入口");
	printf("\n\t\t\t0.退出系统");
	printf("\n----------------------------------------------------------");
	printf("\n请选择(0-2):"); 
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



NODE *head=NULL;//头结点
NODE1 *head1=NULL;//头结点 
MANAGER *head2;//头结点


//管理员界面
void manager_menu()
{
	printf("=====================管理员操作界面=========================");
	printf("\n------------------------功能菜单--------------------------");
	printf("\n\t\t\t1.添加选课信息");
	printf("\n\t\t\t2.删除课程信息");
	printf("\n\t\t\t3.添加学生信息");
	printf("\n\t\t\t4.删除学生信息");
	printf("\n\t\t\t5.录入选课成绩");
	printf("\n\t\t\t0.退出管理员菜单");
	printf("\n----------------------------------------------------------");
	printf("请输入0-5间数字，进行管理员功能选择：");
	int answer;
	scanf("%d",&answer) ;
	while(1)
	{
		switch(answer)
		{
			case 1:
				system("cls");
				addclass();//添加选课信息 
				printf("     按任意键返回主菜单……");
				getch();
				break; 
			case 2:
				system("cls");
				delclass();//删除课程
				printf("     按任意键返回主菜单……");
				getch();
				break;
			case 3:
				system("cls");
				addstudent();//添加学生信息 
				printf("     按任意键返回主菜单……");
				getch();
				break;
			case 4:
				system("cls");
				delstudent();//删除学生信息
				printf("     按任意键返回主菜单……");
				getch();
				break; 			
			case 5:
				system("cls");
				struct teacherscore *input();//录入选课成绩
				printf("     按任意键返回主菜单……");
				getch(); 
				break;
			case 0:
				system("cls");
				printf("\n");
				return ;
				break;
			default:
			{
			    printf("\n\n您的选项不正确，请选择1-6中的一个数字");
			}
		}
	}
	
} 

void student_menu()//学生界面 
{
    int option;
	printf("\t********查询课程********\n\n");
    printf("\t1.查询所有课程\n\n");
	printf("\t2.查询已选课程\n\n");
	printf("\t3.查询课程成绩\n\n");
	printf("\t4.选择课程\n\n");
	printf("\t0.退出查询课程\n\n");
	printf("\t请选择0-4中的数字之一，进行选课查询");
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
		    printf("\n\n您的选项不正确，请选择0-3中的一个数字");
		}	
	}
    
}
    



void addclass()//添加课程信息 
{
	system("cls");
	NODE *newnode=(NODE *)malloc(sizeof(NODE));//创建新结点 
	newnode->next=NULL;
	printf("请输入课程名称:\n");       //名称 
	scanf("%s",newnode->clas.classname);
	printf("请输入开课学期:\n");       //学期 
	scanf("%d",newnode->clas.term);
	printf("请输入课程教师:\n");       //教师 
	scanf("%s",newnode->clas.classteacher);
	printf("请输入课程教室:\n");       //教室 
	scanf("%s",newnode->clas.classroom);
	printf("请输入课程学时:\n");       //学时 
	scanf("%d",newnode->clas.classhour);
	printf("请输入课程学分:\n");       //学分
	scanf("%f",newnode->clas.classscore);
	printf("请输入课程编号:\n");       //编号
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
	
	printf("##     添加选课信息成功     ##\n");
	char quit;
	printf("是否继续添加?(Y/N)");    //是否继续添加   
	    scanf("\t%c", &quit);
	    if(quit=='Y'||quit=='y'){
	    printf("\n");
	    addclass();}
	    else
	    return;
	system("cls");
	
}

void delclass(struct manager *node)//删除课程 
{
	system("cls");
    struct manager *p;
    p=node->next;
    
	
}
void showclass()//查询课程 
{
	system("cls");
	NODE *p=head;
	printf("============================================================");
	printf("# 名称\t\t学期\t\t教师\t\t教室 #\n");
	while(1)
	{
		printf("# %s\t\t%d\t\t%s\t\t%s #\n",p->clas.classname,p->clas.term,p->clas.classteacher,p->clas.classroom);
		p=p->next;
	}
	printf("============================================================");
	system("cls");
}

void addstudent()//添加学生信息 
{
	system("cls");
	NODE1 *newnode1=(NODE1 *)malloc(sizeof(NODE1));//创建新结点 
	newnode1->next=NULL;
	printf("请输入学生姓名:\n");       //姓名 
	scanf("%s",newnode1->stu.stuname);
	printf("请输入学生学号:\n");       //学号
	scanf("%d",newnode1->stu.num);
	printf("请输入专业班级:\n");       //专业班级
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
	
	printf("##     添加学生信息成功     ##\n");
	char quit;
		printf("是否继续添加?(Y/N)");    //是否继续添加   
		    scanf("\t%c", &quit);
		    if(quit=='Y'||quit=='y'){
		    printf("\n");
		    addstudent();}
		    else
		    return;
	system("cls");
	
}
//根据学号查询学生信息
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
        printf("\n\n\t*********查询到的学生记录*********\n\n",studentTotle);
        printf("\t————————————————\n\n");
        printf("\t\t%-15s%-15s\n\n","学号","成绩");
        printf("\t\t%-15ld%-15d\n\n",p->num,p->score);
        printf("\t********************************\n\n");
    }
    else
    {
        printf("\n\n\t抱歉，没有找到学号为%ld的学生的信息\n\n\n",num);
        p=NULL;
    }
    return p;

}

void password()//设置密码 
{
	system("cls");
	char input[100]={0};
	FILE *fp;
	printf("请输入你的密码：");//设置密码 
	fp=fopen("file\\data2.txt","wb");
	scanf("%s",input);
	fwrite(&input,sizeof(struct student),1,fp);
	int temp=0;
	while((temp=getchar())!='\n')
	{
	      ;
	}
	printf("请确认你的密码，从键盘输入（Y/N）选择");//确定密码 
	int ch=getchar();
	if (ch=='Y')
	{
		printf("确认成功！\n");
	}
	else
	{
		printf("确认失败！\n");
	}
	
}


//录入成绩信息 
//逆序创建链表
struct student *AppendNode(struct student *head)
{
    struct student *p=NULL;//要插入的新结点
    struct student *q=NULL;//
    p=(struct student *)malloc(LEN);
    if(p==NULL)
    {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    printf("\n\n\t请输入学生的学号和成绩(数据之间用空格分隔，输入完成按回车键确认。\n\n\t如果想结束录入工作，请输入成绩-1）：\n");
    scanf("%ld",&p->num);
    scanf("%d",&p->score);
    if(head!=NULL)//检查是不是有该学号
    {
        q=head;
        while(q->num !=p->num &&q->next !=NULL)
            q=q->next ;
        if(q->num ==p->num )
        {
            printf("\n\n\n\t很遗憾，您需要插入的学号%ld已经存在，如果您需要修改记录，请在主菜单选择”修改学生记录“\n\n\n",p->num );
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
        else//逆序插入
        {
            p->next=head;
            head=p;
        }
        p=(struct student * )malloc(LEN);
        scanf("%ld",&p->num );
        scanf("%d",&p->score);

    }
    WriteFile(head);//将链表数据写入文件
    return(head);
}
//显示学生成绩
void output(struct teacherscore *head)
{
    struct teacherscore *p=NULL;	//定义指向链表当前结点的指针
       p=head;
       if(head!=NULL)
       {
           printf("\n\n\t*********共有 %d 个记录*********\n\n",teacherscoreTotle);
           printf("\t————————————————\n\n");
           printf("\t\t%-15s%-15s\n\n","学号","成绩");
           while(p!=NULL)
           {
               printf("\t\t%-15ld%-15d\n\n",p->num,p->score);
               p=p->next;
           }
           printf("\t********************************\n\n");
       }
       else
           printf("\n\n\t抱歉，没有学生成绩数据！\n\n");
}


//删除学生成绩
struct teacherscore *cut(struct teacherscore *head,long num)
{
        struct teacherscore *p=NULL;//要删除的结点
	    struct teacherscore *pr=NULL;//要删除的结点的前一个结点
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
	        printf("\n\n\n\t已成功删除学号为%ld的学生成绩\n\n\n\n",num);
	        free(p);
	
	    }
	    else
	        printf("\n\n\t抱歉，没有找到学号为%ld的学生的成绩\n\n\n",num);
	
	    return(head);
}

//根据成绩排序
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
                   if((q->score>k->score)&&choose==0)//降序
                       k=q;
                   else if((q->score<k->score)&&choose==1)//升序
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
           printf("\n\n\t抱歉，没有学生成绩！\n\n");
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
		    if((fp=fopen("file\\stuinfo.dat","r"))==NULL)	//打开文本文件用来读
		    {
		        printf("打开文件失败！\n");
		        return head;
		    }
		    p=(struct teacherscore *)malloc(LEN);
		    fread(p,LEN,1,fp);
		    p->next=NULL;
		    studentTotle=0;
		    while(!feof(fp))
		    {
		        //从文件读出的一个学生的数据添加到链表的一个节点中
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
		        fread(p,LEN,1,fp);						//从文件中读出一条学生记录到p节点中
		        p->next=NULL;
		    }
		
		    fclose(fp);//关闭文件
		    printf("\n\t从文件中共成功读出%d个学生的成绩\n",studentTotle);
		    return head;
}
void WriteFile(struct teacherscore *head)
{
   FILE *fp;
   	    struct teacherscore *p=head;
   	    int count=0;	//用来对链表中的节点计数
   	    if(head==NULL)
   	    {
   	        printf("无学生成绩！\n");
   	        return;
   	    }
   	    if((fp=fopen("file\\stuinfo.dat","wb"))==NULL)		//打开文本文件用来写入
   	    {
   	        printf("文件打开失败!\n");
   	        return;
   	    }
   	    while(p!=NULL)				//将链表的全部数据写入文件中
   	    {
   	        count++;
   	        fwrite(p,LEN,1,fp);		//将p所指向的1个节点数据写入文件
   	        p=p->next;
   	    }
   	    fclose(fp);	//关闭文件
   	    printf("\n\t%d个学生的成绩成功写入文件！\n",count);
   	    return;
}


void *del()  //删除所选课程
{
	MANAGER *p1,*p2;//定义结构体指针指向这个结构体
	char ch,ch1;
	int num;
	while(ch!='0')
	{
		printf("输入想要删除的课程编号:[    ]\b\b\b\b\b");
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
		printf("\n继续删除请按回车\n");
		printf("\n结束删除课程按 0: [ ]\b\b");
		ch1=getchar();                       //将回车键赋给CH1,否则num输完后再输入的回车键会赋给CH,因此用CH1填补。
		ch=getchar();
		printf("\n删除完毕,新信息存入文件中\n");
		system("pause"); 
	}
	return head2;
	system("pause");
}


void choose()//选新课程--学生选课函数
{
	MANAGER *p,*q;
	int a[5];
	int num,i=0,j;  //total为总学分，i为num的数组单元
	printf("输入要选修的课程的编号,编号之间以空格分开\n");
	scanf("%d",&num);
	printf("如果确认输入完要选修的课程的编号,请输入0: [ ]\b\b");
	
	FILE *fp;    //声明fp是指针，用来指向FILE类型的对象，fp是指向文件结构体的指针变量
	fp=fopen("3.txt","w"); 	  //fprintf(fp,"课程编号 课程名称  授课学时  开课学期\n");
	for(j=0;j<i;j++)
	for(q=head2;q;q=q->next)
		if(*q->coursecode==a[j])
		fprintf(fp,"%5d%12s%9d%7d\n",q->coursecode,q->classname,q->classhour,q->term);
	fclose(fp);  //关闭
	printf("\t\t\n*****选修成功!****\n");
	printf("\n您选修的课程分别为:\n");
	printf("\n课程编号  课程名称  授课学时  开课学期\n");
	for(j=0;j<i;j++)
	for(q=head2;q;q=q->next)
		if(*q->coursecode==a[j])
			printf("%5d%12s%9d%7d\n",q->coursecode,q->classname,q->classhour,q->term);
	printf("\n以上信息全部保存在'3.txt'中\n");
	
	system("pause");   //暂停，没这个语句点开生成的.exe文件
}
