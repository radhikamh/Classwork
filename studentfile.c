#include<stdio.h>
#include<stdlib.h>
/*struct student sp
{
  char name[20];
  int roll.no;
  char div[10];
  }
typedef struct student *sp;*/

int main()
{
  FILE *fp;
  char ch;
  fp = fopen("student.dat","w");
  if(fp==NULL)
  {
    printf("Error in opening a file\n");
    exit(0);
    }
  printf("input some text");
  int roll_no;
  char div;
  while((ch = getchar())  !=EOF)
  fputc(ch,fp);
  fscanf(fp,"%d",&roll_no);
  fputs(div,fp);
  fclose(fp);
  printf("the file contains");
  fp = fopen("student.dat","r");
  while((ch=fgetc(fp))  !=EOF)
  putchar(ch);
  fprintf(fp,"%d",roll_no);
  putchar(div);
  fclose(fp);
  }

