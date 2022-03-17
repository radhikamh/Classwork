#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct Node *node;
node insert_front(node first);
node getnode();
node insert_pos(int pos, node first);
void display_list(node first);
main()
{
    node first=NULL;
    int item,choice;
    while(1)
    {
        printf("1-insert front\n2-display\n3-insert position\n4-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter items to be inserted\n");
                    scanf("%d",&item);
                    first=insert_front(item,first);
                    break;
            case 2: printf("display  list inserted\n");
                    display_list(first);
                    break;
            case 3: exit(0);
        }
    }
}
node getnode()
{

    node p;
    p=(node)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("not created\n");
        exit(0);
    }
    p->next=NULL;
    return p;
}
void display_list(node first)
{
    node p;
    if(first==NULL)
    {
        printf("empty list\n");
        return;
    }
    printf("elements are\n");
	p=first;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p= p->next;
	}
	printf("\n");
}
node insert_front(int item,node first)
{
    node p,c;
    p=getnode();
    p->data=item;
    p->next=NULL;
        if(first==NULL)
        return p;
        p->next=first;
    return p;
}
node insert_pos(int pos, node first)
{

    node t,prev,cur;
    int count;
    t=getnode();
    if(first ==NULL &&pos==1)
	  return t;
    if(first == NULL)
    {

        printf("invalid position\n");
        return first;
    }
if(pos==1)
{

    t->next= first;
    return t;
}
count=1;
prev=NULL;
cur= first;
while(cur!=NULL && count!=pos)
{

    prev=cur;
    cur=cur->next;
    count++;
}
if(count==pos)
{

    prev->next=t;
    t->next=cur;
    return first;
    }
    return first;
}
