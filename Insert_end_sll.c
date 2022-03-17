#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *node;
node insert_rear(int item,node first);
node getnode();
void display_list(node first);
main()
{
    node first=NULL;
    int item,choice;
    while(1)
    {
        printf("1-insert rear\n2-display\n3-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter items to be inserted\n");
                    scanf("%d",&item);
                    first=insert_rear(item,first);
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
node insert_rear(int item,node first)
{
    node p,c;
    p=getnode();
    p->data=item;
    if(first==NULL)
        return p;
    c=first;
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=p;
    return first;
}
