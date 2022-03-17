#include<stdio.h>
#include<stdlib.h>

int main()
{
  FILE *fp;
  char ch;
  fp = fopen("check.dat","w");
  if(fp==NULL)
  {
    printf("Error in opening a file\n");
    exit(0);
    }
  printf("input some text");
  while((ch = getchar())  !=EOF)
  fputc(ch,fp);
  fclose(fp);
  printf("the file contains");
  fp = fopen("check.dat","r");
  while((ch=fgetc(fp))  !=EOF)
  putchar(ch);
  fclose(fp);
}


