#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char name[20];
	char id[20];
	char ex;
	float math;
	float english;
}ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

Node* initial()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;	
	return L;
} 
int add(Node* L,ElemType stu,int i)
{
	Node* p = L;
	//找到要插入位置的前一个节点 
	while(p->next && i-->1)
	{
		p = p->next;
	}
	//插入新节点 
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = stu;
	q->next = p->next;
	p->next = q;
	return 1;	
}

int fun1(Node* L,float x)
{
	Node* p = L;
	int total = 0;//统计人数 
	while(p->next)
	{
		p = p->next;
		if(p->data.math>x && p->data.english)
		{
			total++;
		}
	} 
	return total;
}

Node* NewList(Node* L,float min_score,float max_score)
{
	Node* cur = L;
	Node* head = initial();//新链表的头指针 
	while(cur->next)
	{
		Node* pre = cur;
		cur = cur->next;
		if(cur->data.math > min_score && cur->data.math < max_score && cur->data.english > min_score && cur->data.english <max_score)
		{
			head->next = cur;
			pre->next = cur->next;
		}
	}
	return head;
}

void browse(Node*L)
{
	Node* p = L;
	printf("学号\t姓名\t性别\t英语\t数学\t总成绩\n");
	while(p->next)
	{
		p = p->next;
		printf("%s\t%s\t%c\t%.2f\t%.2f\t%.2f\n",p->data.id,p->data.name,p->data.ex,p->data.english,p->data.math);
	}
}

int main()
{
	Node* L = initial();
	Node* L2 = NULL; 
	int choice;
	do
	{
		printf("1.功能1\n2.功能2\n3.功能3\n4.浏览链表\n"); 
		printf("请输入对应功能的序号：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					ElemType stu; 
					printf("请输入学生的信息");
					printf("姓名：");
					scanf("%s",stu.name);
					printf("学号：");
					scanf("%s",stu.id);
					printf("性别：");
					getchar();
					scanf("%c",&stu.ex);
					printf("数学成绩：");
					scanf("%f",&stu.math);
					printf("英语成绩：");
					scanf("%f",&stu.english);
					printf("请输入要插入的位置：");
					int i;
					scanf("%d",&i); 
					add(L,stu,i);
				}
				break;
			case 2:
				{
					int x;
					printf("统计单链表L中高等数学大于x并且大学英语大于x的学生人数\n请输入x的值：");
					scanf("%d",&x);
					int sum = fun1(L,x);
					printf("L中高等数学大于%d并且大学英语大于%d的学生人数为：%d人",x,x,sum);
				}
				break;
			case 3:
				{
					int min,max;
					printf("请输入min_score的值：");
					scanf("%d",&min);
					printf("请输入max_score的值：");
					scanf("%d",&max);
					L2 = NewList(L,min,max);
				}
				break;
			case 4:
				{
					int index;
					printf("请输入你要查看第几个链表：");
					scanf("%d",&index);
					if(index==1)
					{
						browse(L);
					}else
					{
						browse(L2);
					}	
				}
		} 
	}while(choice!=0); 
	return 0;	
} 
/*
typedef struct Node
{
	ElemType data;
	struct Node* pre;
	struct Node* next; 
}Node;

Node* initial()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->pre = L;
	L->next = L;
	return L;
}

int add(Node* L,ElemType stu,int i)
{
	if(i<=0)
	{
		return 0;//位置不合理，返回0 
	}
	Node* p = L;
	while(i-->1)//找到要插入位置的前一个节点 
	{
		p = p->next
		if(!p)
		{
			return 0;
		}
	}
	//添加新节点
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = stu;
	q->next = p->next;
	q->pre = p;
	p->next = q;
	if(q->next)//如果新节点的下一个节点非空 
	{
		q->next->pre = q;
	}
	return 1;
}

int deleteStu(Node* L,int i,ElemType* stu)
{
	if(i<=0)
	{
		return 0;//位置不合理返回0 
	}
	Node* p = L;
	while(i-->1)//找到要删除位置的前一个节点 
	{
		p = p->next;
	 	if(p == L)
	 	{
	 		return 0;	
		}	
	}
	Node* q = p->next;
	p->next = q->next;
	q->next->pre = p;
	free(q);//释放节点 
	return 1; 
}*/


