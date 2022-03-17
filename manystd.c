#include<stdio.h>
#include<stdlib.h>

int main()
{
  char name[50];
  int marks,i,num;
  FILE *fptr;
  fptr = fopen("program.dat","w");
  if(fptr==NULL)
  {
    printf("Error in opening a file\n");
    exit(1);
    }
  printf("Enter number of students:");
  scanf("%d",&num);

  for(i=0;i<num;++i)
  {
     printf("For student%d\nEnter name: ",i+1);
  scanf("%s",name);
  printf("Enter marks:");
  scanf("%d",&marks);
  fprintf(fptr,"%s\n %d\n",name,marks);
  }
  fclose(fptr);

  printf("the file contains");
  fptr = fopen("program.dat","r");
  if(fptr==NULL)
  {
    printf("Error!");
    exit(1);
    }
  for(;;)
   {
    fscanf(fptr,"%s",name);
    fscanf("%s\n%d\n",name,marks);
    printf("%s\n%d\n",name,marks);
    }
    fclose(fptr);
}
