#include<stdio.h>
#include<malloc.h>
#include<conio.h>

typedef struct node
{
  int data;
  struct node *next;
  struct node *down;
}node;

node* createlist()
{
  node *p,*ptr,*head=NULL;
  int x,i,n;
  printf("\nEnter the number of elements: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     printf("\n Enter value: ");
     scanf("%d",&x);
     p = (node*)malloc(sizeof(node));
     p->data=x;
     p->next=NULL;
     p->down=NULL;

     if(head==NULL)
     head=p;
     else
     ptr->next=p;
     ptr=p;
     }
  return head;
  }

void displaylist(node *head)
{
   node *p;
   p=head;
   while(p!=NULL)
   {
     printf("%d",p->data);
     p = p->next;
     }
}

void swap(node *a, node *b)
{
   int tmp;
   tmp=a->data;
   a->data = b->data;
   b->data = tmp;
   }

void sort(node *head)
{
   int flag,i;
   node *ptr,*ptr1=NULL;

   if(head==NULL)
   return;

   do{
     flag=0;
     ptr = head;

     while(ptr->next!=ptr1)
     {
       if(ptr->data > ptr->next->data)
       {
          swap(ptr,ptr->next);
          flag=1;
          }
      ptr=ptr->next;
      }
    ptr1=ptr;
    }
   while(flag);
}

void flattening(node *head)
{
   node *p,*ptr,*ptr1,*ptrf,*headf=NULL;
   ptr =head;

   while(ptr!=NULL)
   {
     p=(node*)malloc(sizeof(node));
     p->data=ptr->data;
     p->next=p->down=NULL;

     if(headf=NULL)
       headf=p;

     else
     ptrf->next=p;

     ptrf=p;
     ptr1=ptr->down;

     while(ptr1!=NULL)
     {
        p= (node*)malloc(sizeof(node));
        p->data=ptr1->data;
        p->next=p->down=NULL;

        if(headf==NULL)
          headf=p;
        else
          ptrf->next=p;
        ptrf=p;
        ptr=ptr1->next;
        }
    ptr=ptr->next;
        }
    printf("\nThe list after flattening: ");
    sort(headf);
    displaylist(headf);
}

int main()
{
   node *head=NULL,*ptr;
   int i;
   head=createlist();
   printf("The main list is:\n");
   displaylist(head);
   ptr=head;
   i=1;
   while(ptr!=NULL)
  {
     printf("\nEnter subnode for %dth node: ",i);
     ptr->down=createlist();
     ptr=ptr->next;
     i++;
  }
     ptr=head;
     i=1;
   while(ptr!=NULL)
  {
    printf("\nThe %dth node's subnode are:",i);
    displaylist(ptr->down);
    ptr=ptr->next;
    i++;
  }
     flattening(head);
  return 0;
}


