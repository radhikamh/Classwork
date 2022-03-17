#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int a[2][2];
    struct Node *next;
};
typedef struct Node *node;

node getnode();
node insert_front(node head);
void display_list (node head);

main()
{
    node head=NULL;
    int choice;
    while(1)
    {
        printf("1-insert front\n2-display\n3-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head = insert_front(head);
                    break;
            case 2: printf("display  list inserted\n");
                    display_list(head);
                    break;
            case 3: exit(0);
        }
    }
}

node getnode()
{

    node p;
    int i,j;
    int b[2][3];
    p=(node)malloc(sizeof(struct Node));
    if(p==NULL)
    {
        printf("not created\n");
        exit(0);
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {

    printf("enter the number to be inserted\n");
    scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
    p->a[i][j]=b[i][j];
        }
    }


    return p;
}

void display_list(node head)
{
    node p;
    int i,j;
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    printf("elements are\n");
	p=head;
	while(p!=NULL)
	{
	    for(i=0;i<2;i++)
	    {
	      for(j=0;j<2;j++)
	      {
	         printf("%d\t",p->a[i][j]);
	         }
	         printf("\n");
        }

      p= p->next;
      printf("\n");
	}
	printf("\n");
}

node insert_front(node head)
 {
    node p;
    p=getnode();
    p->next=NULL;
    if(head==NULL)
        return p;
    p->next=head;
    return p;
 }



