#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *node;

node getnode();
node insert_rear(head);
node swap_pair(head);
void display_list(head);
void display_swap(head);

int main()
{
   node head=NULL;
   int N;
   printf("Enter the size of linked list:\n");
   scanf("%d",&N);
   for(int i=0;i<N;i++)
   {
        head = insert_rear(head);
   }

    printf("Display List Inserted\n");
    display_list(head);

    head = swap_pair(head);

    printf("Display The List After swap\n");
    display_swap(head);
    return 0;
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

node insert_rear(node head)
{
  node t;
  node c;
  t=getnode();
  if(head==NULL)
  {
    return t;
  }
  c=head;
  while(c->next!=NULL)
  {
      c=c->next;
  }
  c->next=t;
  return  head;
}

void display_list(node head)
{
  node n;
  if(head==NULL)
  {
      printf("the list is empty\n");
      return head;
  }
  printf("The elements in the list are\n");
  n=head;
  while(n!=NULL)
  {
      printf("%d\t",n->data);
      n=n->next;
  }
  printf("\n");
}

void display_swap(node head)
{
  node n;
  if(head==NULL)
  {
      printf("the list is empty\n");
      return head;
  }
  printf("The elements in the list are\n");
  n=head;
  while(n!=NULL)
  {
      printf("%d\t",n->data);
      n=n->next;
  }
  printf("\n");
}

node swap_pair(node head)
{
  node cur;
  node temp;
  if(head==NULL)
  {
      printf("The list is empty\n");
      return head;
  }
  cur = head;
  while(cur->next != NULL)
  {
    temp = cur->data;
    cur->data = (cur->next)->data;
    (cur->next)->data = temp;
    cur=(cur->next)->next;
    }
    return head;
}







