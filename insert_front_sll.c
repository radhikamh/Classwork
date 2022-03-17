#include<stdio.h>
#include<stdlib.h>

struct NODE
{
  int data;
  struct NODE *next;
};
typedef struct NODE *node;

node getnode();
node insert_front(node first);

int main()
{
    node first = NULL;
    first = getnode();
    first = insert_front(first);
    display_list(first);
    return 0;
}

node getnode()
{
    int x;
    node first;
    x = (node*)malloc(sizeof(struct NODE));
    printf("Enter item to be inserted\n");
    scanf("%d\n",&x);
    first->next=x;
    first->next =NULL;
    return first;
}

node insert_front(node first)
{
    node p;
    int x;
    printf("Enter the data to be inserted\n");
    scanf("%d\n",&x);
    p=getnode();
    p->data=x;
    p->next=NULL;
    if(first==NULL)
        return p;
    p->next=first;
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

