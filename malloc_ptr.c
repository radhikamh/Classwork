#include<stdio.h>
#include<string.h>

typedef struct student
{
  int id;
  char name[20];
  float percentage;
  }S1;

int main()
{
   S1 *ptr;
   int n;
   printf("Enter the number of students:\n");
   scanf("%d",&n);

   ptr = (struct student*)malloc(n*sizeof(struct student));
   if(ptr == NULL)
   {
      printf("Error in opening file\n");
      }
   read(ptr,n);
   display(ptr,n);
   return 0;
}


void read(S1 *ptr,int n)
{
   int i=0;
   for(i=0;i<n;i++)
   {
      printf("%d student detailes:\n",i+1);
      printf("Enter %dst student id:\n",i+1);
      scanf("%d",&ptr->id);
      printf("Enter %dst student name:\n",i+1);
      scanf("%s",&ptr->name);
      printf("Enter %dst student percentage:\n",i+1);
      scanf("%f",&ptr->percentage);
      }
      return 0;
   }

void display(S1 *ptr,int n)
{
   int i=0;
   for(i=0;i<n;i++)
   {
      printf("%dst student id:\n",i+1);
      printf("%d",ptr->id);
      printf("\n");
      printf("%dst student name:\n",i+1);
      printf("%s",ptr->name);
      printf("\n");
      printf("%dst student percentage:\n",i+1);
      printf("%f",ptr->percentage);
      }
      return 0;
   }
