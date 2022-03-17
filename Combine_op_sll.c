#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *node;
node getnode();
node insert_front(node first);
node insert_rear(node first);
node delete_front(node first);
node delete_rear(node first);
node insert_pos(int pos, node first);
node delete_pos(int pos,node first);
void display_list (node first);

main()
{
    node first=NULL;
    int item,pos,choice;
   while(1)
  {
   printf(" 1-Insert at front\n 2-Insert at rear\n 3-Delete at front\n 4-Delete at rear\n 5-Insert at specific position\n 6-Delete at specific position\n 7-Display List\n 8-Exit\n");
   scanf("%d",&choice);
        switch(choice)
         {
            case 1 : first=insert_front(first);
                        break;
            case 2 : first=insert_rear(first);
                        break;
            case 3 : first=delete_front(first);
                        break;
            case 4 : first=delete_rear(first);
                        break;
            case 5 : printf("enter the  position \n");
                     scanf("%d",&pos);
                     first=insert_pos(pos,first);
                        break;
            case 6 : printf("enter the  position \n");
                     scanf("%d",&pos);
                     first=delete_pos(pos,first);
                        break;
            case 7 : printf("Display List Inserted\n");
                     display_list(first);
                        break;
            case 8 : exit(0);
           }
        }
}

node getnode()
{
    node t;
    int item;
    t=(node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("not created\n");
        exit(0);
    }

    printf("enter the item to be inserted\n");
    scanf("%d",&item);
    t->data=item;
    t->next=NULL;
    return t;
}

node insert_front(node first)
{
  node t;
  t=getnode();

     t->next=NULL;
    if(first==NULL)
        return t;
    t->next=first;
        return t;
}

node insert_rear(node first)
{
  node t;
  node c;
  t=getnode();
  if(first==NULL)
  {
    return t;
  }
  c=first;
  while(c->next!=NULL)
  {
      c=c->next;
  }
  c->next=t;
  return  first;

}

node delete_front(node first)
{
  node t;
  if(first==NULL)
  {
      printf("the list is empty\n");
      return first;
  }

  t=first;
  first=first->next;
  printf("the item deleted is %d\n",t->data);
  t->next=NULL;
  free(t);

  return first;
}

node delete_rear(node first)
{
 node n,back;

  if(first==NULL)
  {
      printf("the list is empty\n");
    return first;
  }

    n=first;
    while(n->next!=NULL)
    {
        back=n;
        n=n->next;
    }

    back->next=NULL;
    free(n);
    return first;

}

node insert_pos(int pos, node first)
{
  node n,back,forth;
  int count;
  n=getnode();
  if(first==NULL && pos==1)
  {
    return n;
  }
  if(first==NULL)
  {
       printf("invalid position\n");
       return first;
  }

  if(pos==1)
  {
      n->next=first;
      return n;
  }
 count=1;
 back=NULL;
 forth=first;

 while(forth!=NULL && count!=pos)
 {
     back=forth;
     forth=forth->next;
     count++;
 }

 if(count==pos)
 {
     back->next=n;
     n->next=forth;
     return first;
 }
 else
 {
     printf("invalid\n");
 }
  return first;
}

node delete_pos(int pos,node first)
{
 node n,back;
 int count=1;
  if(first==NULL)
  {
       printf("invalid position or empty list\n");
       return ;
  }
  if(pos==1)
  {
      n=first;
      first=n->next;
      free(n);
      return first;
  }
n=first;
back=NULL;
while(n->next!=NULL && count!=pos)
  {
   back=n;
   n=n->next;
   count++;
  }
  if(count==pos)
  {
    n=n->next;
    back->next=n;
    return first;
  }
  else
  {
      printf("invalid position\n");
  }

return first;
}
void traverse(node first)
{
  node n;
  n=first;
  if(first==NULL)
  {
      printf("this is an empty list\n");
      return;
  }
  while(n!=NULL)
  {
      printf("%d\t",n->data);
      n=n->next;
  }
  printf("\n");
}

void display_list (node first)
{
  node n;
  if(first==NULL)
  {
      printf("the list is empty\n");
      return first;
  }
  printf("The elements in the list are\n");
  n=first;
  while(n!=NULL)
  {
      printf("%d\t",n->data);
      n=n->next;

  }
  printf("\n");
}
