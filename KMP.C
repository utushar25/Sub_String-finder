#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
void main()
{
//	clrscr();
	FILE* fptr;
	char ch;
	char* text;
	int offset=0,counter=0,i=1,j=0,flag=0,len;
	int*array;
	clrscr();
	//display part of file
	fptr=fopen("add.c","r");
	while(1)
	{
	  ch=fgetc(fptr);
	  if(ch==EOF)
	  {
	   break;
	  }
	 // delay(50);
	  printf("%c",ch);
	}
	//entering of substring
	printf("\nEnter your substring to find\n");
	ch=fgetc(stdin);
	text=(char*)calloc(stdin->level+1,sizeof(char));//substring
	array=(int*)calloc(stdin->level,sizeof(int));
	while(1)
	{
	 if(ch=='\n')
	 {
	  if(flag==0)
	  {
	   printf("Invalid input\nEnter again");
	   goto down;
	  }
	  text[offset]='\0';
	  break;
	 }
	 flag=1;
	 text[offset++]=ch;
down:	 ch=fgetc(stdin);
	}

	//lookup table
	array[j]=0;
	while(text[i]!='\0')
	{
	 if(text[i]==text[j])
	 {
	   array[i]=j+1;
	   i++;
	   j++;
	 }
	 else
	 {
	  if(j==0)
	  {
	   array[i]=j;
	   i++;
	  }
	  else
	  {
	   j=array[j-1];
	  }
	 }
	}

	//finding word in file
	i=0;j=0;
	len=strlen(text);
	fptr=fopen("add.c","r");
	while(1)
	{
	  ch=fgetc(fptr);
	  if(ch==EOF)
		{
		  break;
		}
	 else if(text[i]==ch)
	   {
		 j++;
		 i++;
		 if(j==len)
		 {
		  counter++;
		  j=0;
		 }
	   }
	else
	   {
		  if(i==0)
		  {
		   j=0;
		   continue;
		  }
		  else
		  { j=0;
			i=array[i-1];
		  }
	   }
	}
	printf("the word to be find is %s\n",text);
	printf("it occurs %d times",counter);
	getch();
}