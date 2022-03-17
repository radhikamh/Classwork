#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *node;
node delete_end(int item,node first);
node getnode();
void display_list(node first);
main()
{
    node first=NULL;
    int item,choice;
    while(1)
    {
        printf("1-Delete rear\n2-display\n3-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter items to be deleted\n");
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
node delete_end(int item,node first)
{
    //node q,t;
    if(start==NULL)
    {
        printf("The list is empty!!");
        return start;
    }
    else if(start->next==NULL)
    {
       free(start);
       return NULL;
    }
    else
    {
        node prev,curr;
        prev=NULL;
        curr=start;
        while (curr->next != NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        free(curr);
    }
}
