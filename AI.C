#include<stdio.h>
#include<conio.h>
int player1=0,flag=0;
void win();
void win1();
void pic();
void draw();
void count(char box[3][3],int array[3][3],int* cross,int* zero,int offset1,int offset2);
void count1(char box[3][3],int array[3][3],int* cross,int* zero,int* computer);
void set(char box[3][3],int array[3][3],int* cross,int* zero);
void main()
{
	char box[3][3],choice;
	int offset2,offset1,offset3,offset4,chance;
	int array[3][3],loop=0,cross=0,zero=0,computer=0;

	for(offset1=0;offset1<3;offset1++)
	{
		for(offset2=0;offset2<3;offset2++)
		{
			box[offset1][offset2]='\0';
			array[offset1][offset2]=0;
		}
	}
	pic();
	delay(2000);
	clrscr();
 //	draw();
	gotoxy(26,3);
	printf("ENTER 0 FOR COMPUTER 1ST CHANCE\n");
	gotoxy(26,4);
	printf("ENTER 1 FOR PLAYER 1ST CHANCE\n");
	scanf("%d",&chance);
	draw();
	if(chance==0)
	{

	while(1)
	{
   if(computer==0)
	   {
		 while(loop!=4)
		 {
			if(box[0][0]=='\0' && array[0][0]==0 && loop==0)
		   {
			 box[0][0]='@';
			 array[0][0]=1;
			 zero++;
			 gotoxy(30,4);
			 printf("@");
			 gotoxy(3,2);
			 computer=1;
			 loop++;
			 break;
		   }
			if(box[0][2]=='\0' && array[0][2]==0 && loop==1)
		   {
			 box[0][2]='@';
			 array[0][2]=1;
			 zero++;
			 gotoxy(62,4);
			 printf("@");
			 gotoxy(3,2);
			 computer=1;
			 loop++;
			 break;
		   }
			 if(box[2][0]=='\0' && array[2][0]==0 && loop==2)
		   {
			 box[2][0]='@';
			 array[2][0]=1;
			 zero++;
			 gotoxy(30,16);
			 printf("@");
			 gotoxy(3,2);
			 computer=1;
			 loop++;
			 break;
		   }
			if(box[2][2]=='\0' && array[2][2]==0 && loop==3)
		   {
			 box[2][2]='@';
			 array[2][2]=1;
			 zero++;
			 gotoxy(62,16);
			 printf("@");
			 gotoxy(3,2);
			 computer=1;
			 loop++;
			 loop=loop%3;
			 break;
		   }
		 }
	   }

		if(player1%2==0)
		{
		 gotoxy(3,2);
		 printf("player1 chance\n");
		}
		else
		{
		 gotoxy(3,2);
		 printf("player2 chance\n");
		 }
		fflush(stdin);
		choice=getch();
		switch(choice)
		{
			case '1':
				if(array[0][0]==0 && player1==0)
				{

					fflush(stdin);
					box[0][0]='*';
					array[0][0]=1;
					offset1=0;
					offset2=0;
					cross++;
					gotoxy(30,4);
					printf("*");
					gotoxy(3,2);
					player1=1;
				if(cross==4)
					 {
					  gotoxy(3,2);
					  printf("GAME DRAW  ");
					  delay(999);
					  player1=0;
					  computer=0;
					  cross=zero=0;
					  flag=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					  }
						count1(box,array,&cross,&zero,&computer);

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '2':
				if(array[0][1]==0 && player1==0)
				{

					fflush(stdin);

					box[0][1]='*';
					array[0][1]=1;
					cross++;
					offset1=0;
					offset2=1;
					gotoxy(46,4);
					printf("*");
					gotoxy(3,2);

					player1=1;

					if(cross==4)
					{
					   gotoxy(3,2);
					   printf("GAME DRAW ");
					   delay(1000);
					   player1=0;
					   computer=0;
					   cross=zero=0;
					   set(box,array,&cross,&zero);
					   clrscr();
					   draw();
					}
						count1(box,array,&cross,&zero,&computer);
				 }
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '3':
				if(array[0][2]==0 && player1==0)
				{
				 //	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[0][2]);
					box[0][2]='*';
					array[0][2]=1;
					cross++;
					offset1=0;
					offset2=2;

					gotoxy(62,4);
					printf("*");
					gotoxy(3,2);
					player1=1;

					if(cross==4)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW  ");
					  delay(1000);
					  player1=0;
					  flag=0;
					  computer=0;
					  cross=zero=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}
					count1(box,array,&cross,&zero,&computer);
				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;

			case '4':
				if(array[1][0]==0 && player1==0)
				{
					fflush(stdin);
					box[1][0]='*';
					array[1][0]=1;
					cross++;
					offset1=1;
					offset2=0;
					gotoxy(30,10);
					printf("*");
					gotoxy(3,2);
					player1=1;
					if(cross==4)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW  ");
					  delay(1000);
					  player1=0;
					  flag=0;
					  computer=0;
					  cross=zero=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}

					count1(box,array,&cross,&zero,&computer);

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '5':
				if(array[1][1]==0 && player1==0)
				{
			   //		printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[1][1]);
					box[1][1]='*';
					array[1][1]=1;
					cross++;
					offset1=1;
					offset2=1;

					gotoxy(46,10);
					printf("*");
					gotoxy(3,2);
					player1=1;

			   if(cross==4)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW  ");
					  delay(1000);
					  player1=0;
					  flag=0;
					  cross=zero=0;
					  computer=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}

					count1(box,array,&cross,&zero,&computer);
				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '6':
				if(array[1][2]==0 && player1==0)
				{
				//	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[1][2]);
					box[1][2]='*';
					array[1][2]=1;
					cross++;
					offset1=1;
					offset2=2;
					gotoxy(62,10);
					printf("*");
					gotoxy(3,2);
				//	player2=0;
					player1=1;

					if(cross==4)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW  ");
					  delay(1000);
					  player1=0;
					  flag=0;
					  cross=zero=0;
					  computer=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}
						count1(box,array,&cross,&zero,&computer);
				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '7':
				if(array[2][0]==0 && player1==0)
				{
				//	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[2][0]);
					box[2][0]='*';
					array[2][0]=1;
					cross++;
					offset1=2;
					offset2=0;

					gotoxy(30,16);
					printf("*");
					gotoxy(3,2);
				  //	player2=0;
					player1=1;

					if(cross==4)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW ");
					  delay(1000);
					  player1=0;
					  flag=0;
					  cross=zero=0;
					  computer=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}
					count1(box,array,&cross,&zero,&computer);

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '8':
				if(array[2][1]==0 && player1==0)
				{
			  //		printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[2][1]);
					box[2][1]='*';
					array[2][1]=1;
					cross++;
					offset1=2;
					offset2=1;

					gotoxy(46,16);
					printf("*");
					gotoxy(3,2);
				   //	player2=0;
					player1=1;


					if(cross==4)
	{
	  gotoxy(3,2);
	  printf("GAME DRAW  ");
	   delay(1000);
	  player1=0;
	  flag=0;
	  cross=zero=0;
	  computer=0;
	  set(box,array,&cross,&zero);
	  clrscr();
	  draw();
	 }
	   count1(box,array,&cross,&zero,&computer);
				}
				else
				{
				printf("INVALID ENTRY\n");
				 delay(100);
				 gotoxy(1,3);
				 printf("                  ");
				}
				break;
			case '9':
				if(array[2][2]==0 && player1==0)
				{
				//	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[2][2]);
					box[2][2]='*';
					fflush(stdin);
					array[2][2]=1;
					cross++;
					offset1=2;
					offset2=2;

					gotoxy(62,16);
					printf("*");
					gotoxy(3,2);
				 //	player2=0;
					player1=1;


					if(cross==4)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW  ");
					   delay(1000);
					  player1=0;
					  flag=0;
					  cross=zero=0;
					  computer=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}
								count1(box,array,&cross,&zero,&computer);
				}
					else
				{
				printf("INVALID ENTRY\n");
				 delay(100);
				 gotoxy(1,3);
				 printf("                  ");
				}
				break;
			case '#':
				  exit(1);
				  break;
			case 'u':

/*  if(player2==0)
  {
   array[offset1][offset2]=0;
   box[offset1][offset2]='\0';
   player1=0;
	if(offset1==0 && offset2==0)
	{
	 gotoxy(30,4);
	 printf("1");
	}
	if(offset1==0 && offset2==1)
	{
	 gotoxy(46,4);
	 printf("2");
	}
	if(offset1==0 && offset2==2)
	{
	 gotoxy(62,4);
	 printf("3");
	}
	if(offset1==1 && offset2==0)
	{
	 gotoxy(30,10);
	 printf("4");
	}
	if(offset1==1 && offset2==1)
	{
	 gotoxy(46,10);
	 printf("5");
	}
	if(offset1==1 && offset2==2)
	{
	 gotoxy(62,10);
	 printf("6");
	}
	if(offset1==2 && offset2==0)
	{
	 gotoxy(30,16);
	 printf("7");
	}
	if(offset1==2 && offset2==1)
	{
	 gotoxy(46,16);
	 printf("8");
	}
	if(offset1==2 && offset2==2)
	{
	 gotoxy(62,16);
	 printf("9");
	}
	gotoxy(3,3);
  }
  else
  {
	array[offset1][offset2]=0;
	box[offset1][offset2]='\0';
	player2=0;
	player1=1;
		if(offset1==0 && offset2==0)
	{
	 gotoxy(30,4);
	 printf("1");
	}
	if(offset1==0 && offset2==1)
	{
	 gotoxy(46,4);
	 printf("2");
	}
	if(offset1==0 && offset2==2)
	{
	 gotoxy(62,4);
	 printf("3");
	}
	if(offset1==1 && offset2==0)
	{
	 gotoxy(30,10);
	 printf("4");
	}
	if(offset1==1 && offset2==1)
	{
	 gotoxy(46,10);
	 printf("5");
	}
	if(offset1==1 && offset2==2)
	{
	 gotoxy(62,10);
	 printf("6");
	}
	if(offset1==2 && offset2==0)
	{
	 gotoxy(30,16);
	 printf("7");
	}
	if(offset1==2 && offset2==1)
	{
	 gotoxy(46,16);
	 printf("8");
	}
	if(offset1==2 && offset2==2)
	{
	 gotoxy(62,16);
	 printf("9");
	}
	gotoxy(3,3);
  }

  continue;
  break; */
  case 'r':
	player1=0;
 //  player2=0;
	set(box,array,&cross,&zero);
	flag=0;
	computer=0;
	clrscr();
	draw();
	break;
  default:
		 printf("INVALID ENTRY");
		 delay(100);
		 gotoxy(1,3);
		 printf("                  ");
		 continue;
		 }
	}


	}
	else
 {
	while(1)
	{

		if(player1%2==0)
		{
		 gotoxy(3,2);
		 printf("player1 chance\n");
		}
		else
		{
		 gotoxy(3,2);
		 printf("player2 chance\n");
		 }
		fflush(stdin);
		choice=getch();
		switch(choice)
		{
			case '1':
				if(array[0][0]==0 && player1==0)
				{

					fflush(stdin);
					box[0][0]='*';
					array[0][0]=1;
					offset1=0;
					offset2=0;
					cross++;
					gotoxy(30,4);
					printf("*");
					gotoxy(3,2);
					player1=1;

				if(flag==0)
				{
					box[1][1]='@';
					array[1][1]=1;
					offset3=1;
					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				 }
					count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
					 {
					  gotoxy(3,2);
					  printf("GAME DRAW");
					  delay(100);
					  player1=0;
					  cross=zero=0;
					  flag=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					  }

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '2':
				if(array[0][1]==0 && player1==0)
				{

					fflush(stdin);

					box[0][1]='*';
					array[0][1]=1;
					cross++;
					offset1=0;
					offset2=1;
					gotoxy(46,4);
					printf("*");
					gotoxy(3,2);

					player1=1;
				 //	count(box,array,cross,zero);
				  if(flag==0)
				  {
					box[1][1]='@';
					array[1][1]=1;
					offset3=1;
					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				  //	count1(box,array,cross,zero);
				  }
					count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
						{
	  gotoxy(3,2);
	  printf("GAME DRAW");
	  delay(100);
	  player1=0;
	  flag=0;
	  cross=zero=0;
	  set(box,array,&cross,&zero);
	  clrscr();
	  draw();
	 }
		}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '3':
				if(array[0][2]==0 && player1==0)
				{
				 //	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[0][2]);
					box[0][2]='*';
					array[0][2]=1;
					cross++;
					offset1=0;
					offset2=2;

					gotoxy(62,4);
					printf("*");
					gotoxy(3,2);
				  //	player2=0;
					player1=1;
				//	count(box,array,cross,zero);

				   if(flag==0)
				{
					box[1][1]='@';
					array[1][1]=1;
					offset3=1;
					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				  //count1(box,array,cross,zero);
				 }
					count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW");
					   delay(100);
					  player1=0;
					  flag=0;
					  cross=zero=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;

			case '4':
				if(array[1][0]==0 && player1==0)
				{
					fflush(stdin);
					box[1][0]='*';
					array[1][0]=1;
					cross++;
					offset1=1;
					offset2=0;

					gotoxy(30,10);
					printf("*");
					gotoxy(3,2);
					player1=1;

				   if(flag==0)
				{
					box[1][1]='@';
					array[1][1]=1;
					offset3=1;
					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				  //count1(box,array,cross,zero);
				 }
					count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
	{
	  gotoxy(3,2);
	  printf("GAME DRAW");
	   delay(100);
	  player1=0;
	  flag=0;
	  cross=zero=0;
	  set(box,array,&cross,&zero);
	  clrscr();
	  draw();
	 }

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '5':
				if(array[1][1]==0 && player1==0)
				{
			   //		printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[1][1]);
					box[1][1]='*';
					array[1][1]=1;
					cross++;
					offset1=1;
					offset2=1;

					gotoxy(46,10);
					printf("*");
					gotoxy(3,2);
				  //	player2=0;
					player1=1;

				  if(flag==0)
				 {
					box[2][0]='@';
					array[2][0]=1;
					offset3=2;
					offset4=0;
					zero++;
					gotoxy(30,16);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				  //	count1(box,array,cross,zero);
				  }
				 count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
	{
	  gotoxy(3,2);
	  printf("GAME DRAW");
	  delay(100);
	  player1=0;
	  flag=0;
	  cross=zero=0;
	  set(box,array,&cross,&zero);
	  clrscr();
	  draw();
	 }

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '6':
				if(array[1][2]==0 && player1==0)
				{
				//	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[1][2]);
					box[1][2]='*';
					array[1][2]=1;
					cross++;
					offset1=1;
					offset2=2;
					gotoxy(62,10);
					printf("*");
					gotoxy(3,2);
				//	player2=0;
					player1=1;
				 //	count(box,array,cross,zero);
					   if(flag==0)
				{
					box[1][1]='@';
					array[1][1]=1;
					offset3=1;
					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				   //	count1(box,array,cross,zero);
				 }
				 count(box,array,&cross,&zero,offset1,offset2);
				 if(cross==5)
	{
	  gotoxy(3,2);
	  printf("GAME DRAW");
	  delay(100);
	  player1=0;
	  flag=0;
	  cross=zero=0;
	  set(box,array,&cross,&zero);
	  clrscr();
	  draw();
	 }

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '7':
				if(array[2][0]==0 && player1==0)
				{
				//	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[2][0]);
					box[2][0]='*';
					array[2][0]=1;
					cross++;
					offset1=2;
					offset2=0;

					gotoxy(30,16);
					printf("*");
					gotoxy(3,2);
				  //	player2=0;
					player1=1;

				if(flag==0)
				{
					box[1][1]='@';
					array[1][1]=1;
					offset3=1;
					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				   //	count1(box,array,cross,zero);
				 }

					count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
	{
	  gotoxy(3,2);
	  printf("GAME DRAW");
	  delay(100);
	  player1=0;
	  flag=0;
	  cross=zero=0;
	  set(box,array,&cross,&zero);
	  clrscr();
	  draw();
	 }

				}
				else
				{
				printf("INVALID ENTRY\n");
				delay(100);
				gotoxy(1,3);
				printf("                  ");
				}
				break;
			case '8':
				if(array[2][1]==0 && player1==0)
				{
			  //		printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[2][1]);
					box[2][1]='*';
					array[2][1]=1;
					cross++;
					offset1=2;
					offset2=1;

					gotoxy(46,16);
					printf("*");
					gotoxy(3,2);
				   //	player2=0;
					player1=1;
					if(flag==0)
				{
					box[1][1]='@';
					array[1][1]=1;
					offset3=1;
					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				   //	count1(box,array,cross,zero);
				 }

					count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
	{
	  gotoxy(3,2);
	  printf("GAME DRAW");
	   delay(100);
	  player1=0;
	  flag=0;
	  cross=zero=0;
	  set(box,array,&cross,&zero);
	  clrscr();
	  draw();
	 }

				}
				else
				{
				printf("INVALID ENTRY\n");
				 delay(100);
				 gotoxy(1,3);
				 printf("                  ");
				}
				break;
			case '9':
				if(array[2][2]==0 && player1==0)
				{
				//	printf("player1 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[2][2]);
					box[2][2]='*';
					fflush(stdin);
					array[2][2]=1;
					cross++;
					offset1=2;
					offset2=2;

					gotoxy(62,16);
					printf("*");
					gotoxy(3,2);
				 //	player2=0;
					player1=1;
					 if(flag==0)
				{
					box[1][1]='@';
					array[1][1]=1;
 //					offset3=1;
   //					offset4=1;
					zero++;
					gotoxy(46,10);
					printf("@");
					gotoxy(3,2);
					player1=0;
					flag=1;
				   //count1(box,array,cross,zero);
				 }

					count(box,array,&cross,&zero,offset1,offset2);
					if(cross==5)
					{
					  gotoxy(3,2);
					  printf("GAME DRAW");
					   delay(100);
					  player1=0;
					  flag=0;
					  cross=zero=0;
					  set(box,array,&cross,&zero);
					  clrscr();
					  draw();
					}

				}
		 /*		else if(array[2][2]==0 && player2==0)
				{
				//	printf("player2 chance\n");
					fflush(stdin);
				//	scanf("%c",&box[2][2]);
					box[2][2]='@';
					array[2][2]=1;
					zero++;
					offset1=2;
					offset2=2;

					gotoxy(62,16);
					printf("@");
					gotoxy(3,2);
					player1=0;
					player2=1;
					count1(box,array,cross,zero);

				}*/
				else
				{
				printf("INVALID ENTRY\n");
				 delay(100);
				 gotoxy(1,3);
				 printf("                  ");
				}
				break;
			case '#':
				  exit(1);
				  break;
			case 'u':

/*  if(player2==0)
  {
   array[offset1][offset2]=0;
   box[offset1][offset2]='\0';
   player1=0;
	if(offset1==0 && offset2==0)
	{
	 gotoxy(30,4);
	 printf("1");
	}
	if(offset1==0 && offset2==1)
	{
	 gotoxy(46,4);
	 printf("2");
	}
	if(offset1==0 && offset2==2)
	{
	 gotoxy(62,4);
	 printf("3");
	}
	if(offset1==1 && offset2==0)
	{
	 gotoxy(30,10);
	 printf("4");
	}
	if(offset1==1 && offset2==1)
	{
	 gotoxy(46,10);
	 printf("5");
	}
	if(offset1==1 && offset2==2)
	{
	 gotoxy(62,10);
	 printf("6");
	}
	if(offset1==2 && offset2==0)
	{
	 gotoxy(30,16);
	 printf("7");
	}
	if(offset1==2 && offset2==1)
	{
	 gotoxy(46,16);
	 printf("8");
	}
	if(offset1==2 && offset2==2)
	{
	 gotoxy(62,16);
	 printf("9");
	}
	gotoxy(3,3);
  }
  else
  {
	array[offset1][offset2]=0;
	box[offset1][offset2]='\0';
	player2=0;
	player1=1;
		if(offset1==0 && offset2==0)
	{
	 gotoxy(30,4);
	 printf("1");
	}
	if(offset1==0 && offset2==1)
	{
	 gotoxy(46,4);
	 printf("2");
	}
	if(offset1==0 && offset2==2)
	{
	 gotoxy(62,4);
	 printf("3");
	}
	if(offset1==1 && offset2==0)
	{
	 gotoxy(30,10);
	 printf("4");
	}
	if(offset1==1 && offset2==1)
	{
	 gotoxy(46,10);
	 printf("5");
	}
	if(offset1==1 && offset2==2)
	{
	 gotoxy(62,10);
	 printf("6");
	}
	if(offset1==2 && offset2==0)
	{
	 gotoxy(30,16);
	 printf("7");
	}
	if(offset1==2 && offset2==1)
	{
	 gotoxy(46,16);
	 printf("8");
	}
	if(offset1==2 && offset2==2)
	{
	 gotoxy(62,16);
	 printf("9");
	}
	gotoxy(3,3);
  }

  continue;
  break; */
  case 'r':
	player1=0;
 //  player2=0;
	set(box,array,&cross,&zero);
	flag=0;
	clrscr();
	draw();
	break;
  default:
		 printf("INVALID ENTRY");
		 delay(100);
		 gotoxy(1,3);
		 printf("                  ");
		 continue;
		 }
	}
  }
}
void count1(char box[3][3],int array[3][3],int* cross,int* zero,int* computer)
{

	if(box[0][0]=='*')
	{
		if(box[0][1]=='*')
		{
			if(box[0][2]=='*')
			{

		printf("player1 win");
		player1=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
	   *computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
  if(box[1][0]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[1][2]=='*')
			{

		printf("player1 win");
		player1=0;
	 //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
  if(box[2][0]=='*')
	{
		if(box[2][1]=='*')
		{
			if(box[2][2]=='*')
			{

		printf("player1 win");
		player1=0;
	   //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
  if(box[0][0]=='*')
	{
		if(box[1][0]=='*')
		{
			if(box[2][0]=='*')
			{

		printf("player1 win");
		player1=0;
		//player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
  if(box[0][1]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[2][1]=='*')
			{

		printf("player1 win");
		player1=0;
	  //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[0][2]=='*')
	{
		if(box[1][2]=='*')
		{
			if(box[2][2]=='*')
			{

		printf("player1 win");
		player1=0;
	  //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[0][0]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[2][2]=='*')
			{
		player1=0;
	  //	player2=0;
		printf("player1 win");
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[0][2]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[2][0]=='*')
			{

		printf("player1 win");
		player1=0;
	 //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
	   return;
			}
		}
	}

 if(box[0][0]=='@')
	{
		if(box[0][1]=='@')
		{
			if(box[0][2]=='@')
			{

		printf("CPU WINS");
		player1=0;
	 //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[1][0]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[1][2]=='@')
			{

		printf("CPU win");
		player1=0;
	 //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[2][0]=='@')
	{
		if(box[2][1]=='@')
		{
			if(box[2][2]=='@')
			{

		printf("cpu win");
		player1=0;
	   //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[0][0]=='@')
	{
		if(box[1][0]=='@')
		{
			if(box[2][0]=='@')
			{

		printf("cpu win");
		player1=0;
	  //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[0][1]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[2][1]=='@')
			{

		printf("cpu win");
		player1=0;
	//	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[0][2]=='@')
	{
		if(box[1][2]=='@')
		{
			if(box[2][2]=='@')
			{

		printf("cpu win");
		player1=0;
	  //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 if(box[0][0]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[2][2]=='@')
			{

		printf("cpu win");
		player1=0;
	 //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
  if(box[0][2]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[2][0]=='@')
			{

		printf("cpu win");
		player1=0;
   //		player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		*computer=0;
		clrscr();
		draw();
		return;
			}
		}
	}
 //PROCESS OF AI

 if(box[0][0]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;          //1st case
			 // offset1=2;
			 // offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  return;

			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][2]=='@')
			 {                           //2nd case
			   box[1][1]='@';
				array[1][1]=1;
				(*zero)++;
			   //	offset1=1;
			   //	offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
				delay(10000);
				*computer=0;
				set(box,array,&*cross,&*zero);
				flag=0;
				clrscr();
				draw();
				return;
			  }
		  }
	}
 if(box[0][0]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //3rd case
		   if(box[2][2]=='@')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
			//  offset1=0;
			 // offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  return;
			}
		 }
	}

  if(box[0][2]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
			//  offset1=2;             //4th case
			 // offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][0]=='@')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //5th case
				(*zero)++;
			 //	offset1=1;
			  //	offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  return;
			  }
		  }
	}

 if(box[0][2]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //6th case
		   if(box[2][0]=='@')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
		 //	  offset1=0;
		//	  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  *computer=0;
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  return;
			}
		 }
	}

 if(box[0][1]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[2][1]=='\0')
			{
			  box[2][1]='@';
			  array[2][1]=1;
			  (*zero)++;
	   //		  offset1=2;             //7th case
		//	  offset2=1;

			  gotoxy(46,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  *computer=0;
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][1]=='@')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //8th case
				(*zero)++;
		  //		offset1=1;
			//	offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  return;
			  }
		  }
	}

 if(box[0][1]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //9th case
		   if(box[2][1]=='@')
			{
			  box[0][1]='@';
			  array[0][1]=1;
			  (*zero)++;
		//	  offset1=0;
		  //	  offset2=1;

			  gotoxy(46,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero); flag=0;
			  clrscr();
			  draw();
			  return;
			}
		 }
	}

 if(box[0][2]=='@')
	 {
		if(box[1][2]=='@')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
		  //	  offset1=2;             //10th case
		//	  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			  return;
			}
		 }
		  if(box[1][2]=='\0')
		  {
			if(box[2][2]=='@')
			 {
			   box[1][2]='@';
				array[1][2]=1;                 //11th case
				(*zero)++;
		//		offset1=1;
		//		offset2=2;

				gotoxy(62,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][2]=='\0')
	 {
		if(box[1][2]=='@')
		 {                             //12th case
		   if(box[2][2]=='@')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
		//	  offset1=0;
		 //	  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[0][0]=='@')
	 {
		if(box[1][0]=='@')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
		 //	  offset1=2;             //13th case
		 //	  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  *computer=0;
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[1][0]=='\0')
		  {
			if(box[2][0]=='@')
			 {
			   box[1][0]='@';
				array[1][0]=1;                 //14th case
				(*zero)++;
	   //			offset1=1;
		 //		offset2=0;

				gotoxy(30,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][0]=='\0')
	 {
		if(box[1][0]=='@')
		 {                             //15th case
		   if(box[2][0]=='@')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
		 //	  offset1=0;
		 //	  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			}
		 }
	}

if(box[0][0]=='@')
	 {
		if(box[0][1]=='@')
		 {
		   if(box[0][2]=='\0')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
		//	  offset1=0;             //16th case
		//	  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  *computer=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[0][1]=='\0')
		  {
			if(box[0][2]=='@')
			 {
			   box[0][1]='@';
				array[0][1]=1;                 //17th case
				(*zero)++;
		  //		offset1=0;
		   //		offset2=1;

				gotoxy(46,4);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][0]=='\0')
	 {
		if(box[0][1]=='@')
		 {                             //18th case
		   if(box[0][2]=='@')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
		   //	  offset1=0;
		  //	  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[1][0]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[1][2]=='\0')
			{
			  box[1][2]='@';
			  array[1][2]=1;
			  (*zero)++;
		   //	  offset1=1;             //19th case
			 // offset2=2;

			  gotoxy(62,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[1][2]=='@')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //20th case
				(*zero)++;
			   //	offset1=1;
			 //	offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[1][0]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //21th case
		   if(box[1][2]=='@')
			{
			  box[1][0]='@';
			  array[1][0]=1;
			  (*zero)++;
  //			  offset1=1;
	//		  offset2=0;

			  gotoxy(30,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[2][0]=='@')
	 {
		if(box[2][1]=='@')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
	  //		  offset1=2;             //22th case
		//	  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[2][1]=='\0')
		  {
			if(box[2][2]=='@')
			 {
			   box[2][1]='@';
				array[2][1]=1;                 //23th case
				(*zero)++;
   //				offset1=2;
	 //			offset2=1;

				gotoxy(46,16);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			  }
		  }
	}

if(box[2][0]=='\0')
	 {
		if(box[2][1]=='@')
		 {                             //24th case
		   if(box[2][2]=='@')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
//			  offset1=2;
  //			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  *computer=0;
			  clrscr();
			  draw();
			}
		 }
	}

if(box[0][0]=='*')
{   //cases for draw	 {
		if(box[1][1]=='*')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;          //1st case
	//		  offset1=2;
	  //		  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][2]=='*')
			 {                           //2nd case
			   box[1][1]='@';
				array[1][1]=1;
				(*zero)++;
//				offset1=1;
  //				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}
 if(box[0][0]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //3rd case
		   if(box[2][2]=='*')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
//			  offset1=0;
  //			  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][2]=='*')
	 {
		if(box[1][1]=='*')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
//			  offset1=2;             //4th case
//			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][0]=='*')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //5th case
				(*zero)++;
  //				offset1=1;
	//			offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][2]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //6th case
		   if(box[2][0]=='*')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
//			  offset1=0;
//			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][1]=='*')
	 {
		if(box[1][1]=='*')
		 {
		   if(box[2][1]=='\0')
			{
			  box[2][1]='@';
			  array[2][1]=1;
			  (*zero)++;
//			  offset1=2;             //7th case
//			  offset2=1;

			  gotoxy(46,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][1]=='*')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //8th case
				(*zero)++;
//				offset1=1;
//				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][1]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //9th case
		   if(box[2][1]=='*')
			{
			  box[0][1]='@';
			  array[0][1]=1;
			  (*zero)++;
//			  offset1=0;
//			  offset2=1;

			  gotoxy(46,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][2]=='*')
	 {
		if(box[1][2]=='*')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
//			  offset1=2;             //10th case
//			  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][2]=='\0')
		  {
			if(box[2][2]=='*')
			 {
			   box[1][2]='@';
				array[1][2]=1;                 //11th case
				(*zero)++;
  //				offset1=1;
  //				offset2=2;

				gotoxy(62,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][2]=='\0')
	 {
		if(box[1][2]=='*')
		 {                             //12th case
		   if(box[2][2]=='*')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
//			  offset1=0;
//			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][0]=='*')
	 {
		if(box[1][0]=='*')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
 //			  offset1=2;             //13th case
 //			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][0]=='\0')
		  {
			if(box[2][0]=='*')
			 {
			   box[1][0]='@';
				array[1][0]=1;                 //14th case
				(*zero)++;
//				offset1=1;
  //				offset2=0;

				gotoxy(30,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][0]=='\0')
	 {
		if(box[1][0]=='*')
		 {                             //15th case
		   if(box[2][0]=='*')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
	//		  offset1=0;
	  //		  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][0]=='*')
	 {
		if(box[0][1]=='*')
		 {
		   if(box[0][2]=='\0')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
//			  offset1=0;             //16th case
  //			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[0][1]=='\0')
		  {
			if(box[0][2]=='*')
			 {
			   box[0][1]='@';
				array[0][1]=1;                 //17th case
				(*zero)++;
	//			offset1=0;
	  //			offset2=1;

				gotoxy(46,4);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][0]=='\0')
	 {
		if(box[0][1]=='*')
		 {                             //18th case
		   if(box[0][2]=='*')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
		//	  offset1=0;
		//	  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[1][0]=='*')
	 {
		if(box[1][1]=='*')
		 {
		   if(box[1][2]=='\0')
			{
			  box[1][2]='@';
			  array[1][2]=1;
			  (*zero)++;
		//	  offset1=1;             //19th case
		  //	  offset2=2;

			  gotoxy(62,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[1][2]=='*')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //20th case
				(*zero)++;
			//	offset1=1;
			  //	offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[1][0]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //21th case
		   if(box[1][2]=='*')
			{
			  box[1][0]='@';
			  array[1][0]=1;
			  (*zero)++;
  //			  offset1=1;
	//		  offset2=0;

			  gotoxy(30,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[2][0]=='*')
	 {
		if(box[2][1]=='*')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
	  //		  offset1=2;             //22th case
		//	  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[2][1]=='\0')
		  {
			if(box[2][2]=='*')
			 {
			   box[2][1]='@';
				array[2][1]=1;                 //23th case
				(*zero)++;
		  //		offset1=2;
			//	offset2=1;

				gotoxy(46,16);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[2][0]=='\0')
	 {
		if(box[2][1]=='*')
		 {                             //24th case
		   if(box[2][2]=='*')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
		   //	  offset1=2;
		   //	  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}
	if(box[0][0]=='@')
	{
	 if(box[1][1]=='*')
	 {
		if(box[2][2]=='\0')
		{
			  box[2][2]='@';
			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			 (*zero)++;
			  return;
		}
	 }
	}
	if(box[0][2]=='@')
	{
	 if(box[1][1]=='*')
	 {
		if(box[2][0]=='\0')
		{
			  box[2][0]='@';
			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
		}
	 }
	}

	if(box[0][2]=='\0')
	{
	 if(box[1][1]=='*')
	 {
		if(box[2][0]=='@')
		{
			  box[0][2]='@';
			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
		}
	 }
	}
	if(box[0][0]=='\0')
	{
	 if(box[1][1]=='*')
	 {
		if(box[2][2]=='@')
		{
			  box[0][0]='@';
			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
		}
	 }
	}
if(box[0][0]=='@')
	{
   //	 if(box[0][1]=='*')
	// {
   //		if(box[0][2]=='\0')
   //		{
		  if(box[1][0]=='\0')
		   {
			 if(box[2][0]=='\0')
			 {
			  box[2][0]='@';
			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
			 }
		   }
	  //	}
	// }
	}

	if(box[0][2]=='@')
	{
//	 if(box[1][2]=='*')
//	 {
//		if(box[2][2]=='\0')
//		{
		  if(box[0][1]=='\0')
		   {
			 if(box[0][0]=='\0')
			 {
			  box[0][0]='@';
			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
			 }
		   }
//		}
//	 }
	}

if(box[0][2]=='@')
	{
//	 if(box[0][1]=='*')
//	 {
//		if(box[0][0]=='\0')
//		{
		  if(box[1][2]=='\0')
		   {
			 if(box[2][2]=='\0')
			 {
			  box[2][2]='@';
			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
			 }
		   }
//		}
//	 }
	}

//if(box[0][2]=='\0')
//	{
//	 if(box[1][2]=='*')
//	 {
		if(box[2][2]=='@')
		{
		  if(box[2][1]=='\0')
		   {
			 if(box[2][0]=='\0')
			 {
			  box[2][0]='@';
			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
			 }
		   }
		}
//	 }
//	}


//if(box[0][0]=='\0')
//	{
//	 if(box[1][0]=='*')
//	 {
		if(box[2][0]=='@')
		{
		  if(box[2][1]=='\0')
		   {
			 if(box[2][2]=='\0')
			 {
			  box[2][2]='@';
			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
			 }
		   }
		}
//	 }
//	}
if(box[0][0]=='\0')
	{
	 if(box[1][0]=='\0')
	 {
		if(box[2][0]=='@')
		{
 //		  if(box[2][1]=='*')
//		   {
//			 if(box[2][2]=='\0')
//			 {
			  box[0][0]='@';
			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
//			 }
//		   }
		}
	 }
 }

if(box[0][0]=='@')
{
//	 if(box[1][0]=='*')
//	 {
//		if(box[2][0]=='\0')
//		{
		  if(box[0][1]=='\0')
		   {
			 if(box[0][2]=='\0')
			 {
			  box[0][2]='@';
			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
			 }
		   }
//		}
  //	 }
}

if(box[2][2]=='@')
	{
//	 if(box[2][1]=='*')
//	 {
//		if(box[2][0]=='\0')
//		{
		  if(box[0][2]=='\0')
		   {
			 if(box[1][2]=='\0')
			 {
			  box[0][2]='@';
			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  (*zero)++;
			  return;
			 }
		   }
  //		}
//	 }
 }


if(player1==1)
 {
   if(box[0][0]=='\0')
   {                         //random position
	 box[0][0]='@';
	 array[0][0]=1;
	 (*zero)++;
  //	 offset1=0;
//	 offset2=0;

	 gotoxy(30,4);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
  if(box[0][2]=='\0')
   {
	 box[0][2]='@';
	 array[0][2]=1;
	 (*zero)++;
   //	 offset1=0;
   //	 offset2=2;

	 gotoxy(62,4);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
  if(box[2][0]=='\0')
   {
	 box[2][0]='@';
	 array[2][0]=1;
	 (*zero)++;
  //	 offset1=2;
   //	 offset2=0;

	 gotoxy(30,16);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
   if(box[2][2]=='\0')
   {
	 box[2][2]='@';
	 array[2][2]=1;
	 (*zero)++;
//	 offset1=2;
//	 offset2=2;

	 gotoxy(62,16);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }

 if(box[0][1]=='\0')
   {
	 box[0][1]='@';
	 array[0][1]=1;
	 (*zero)++;
//	 offset1=0;
//	 offset2=1;

	 gotoxy(46,4);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;

   }
 if(box[1][0]=='\0')
   {
	 box[1][0]='@';
	 array[1][0]=1;
	 (*zero)++;
//	 offset1=1;
//	 offset2=0;

	 gotoxy(30,10);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;

   }
 if(box[1][1]=='\0')
   {
	 box[1][1]='@';
	 array[1][1]=1;
	 (*zero)++;
//	 offset1=1;
//	 offset2=1;

	 gotoxy(46,10);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }

 if(box[1][2]=='\0')
   {
	 box[1][2]='@';
	 array[1][2]=1;
	 (*zero)++;
//	 offset1=1;
//	 offset2=2;

	 gotoxy(62,10);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
	if(box[2][1]=='\0')
   {
	 box[2][1]='@';
	 array[2][1]=1;
	 (*zero)++;
//	 offset1=2;
//	 offset2=1;

	 gotoxy(46,16);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
  }
}




void count(char box[3][3],int array[3][3],int* cross,int* zero,int offset1,int offset2)
{

	if(box[0][0]=='*')
	{
		if(box[0][1]=='*')
		{
			if(box[0][2]=='*')
			{

		printf("player1 win");
		player1=0;
	  //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
  if(box[1][0]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[1][2]=='*')
			{

		printf("player1 win");
		player1=0;
	 //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
  if(box[2][0]=='*')
	{
		if(box[2][1]=='*')
		{
			if(box[2][2]=='*')
			{

		printf("player1 win");
		player1=0;
	   //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
  if(box[0][0]=='*')
	{
		if(box[1][0]=='*')
		{
			if(box[2][0]=='*')
			{

		printf("player1 win");
		player1=0;
		//player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
  if(box[0][1]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[2][1]=='*')
			{

		printf("player1 win");
		player1=0;
	  //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[0][2]=='*')
	{
		if(box[1][2]=='*')
		{
			if(box[2][2]=='*')
			{

		printf("player1 win");
		player1=0;
	  //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[0][0]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[2][2]=='*')
			{
		player1=0;
	  //	player2=0;
		printf("player1 win");
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[0][2]=='*')
	{
		if(box[1][1]=='*')
		{
			if(box[2][0]=='*')
			{

		printf("player1 win");
		player1=0;
	 //	player2=0;
		win();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}

 if(box[0][0]=='@')
	{
		if(box[0][1]=='@')
		{
			if(box[0][2]=='@')
			{

		printf("player2 win");
		player1=0;
	 //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[1][0]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[1][2]=='@')
			{

		printf("player2 win");
		player1=0;
	 //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();

			}
		}
	}
 if(box[2][0]=='@')
	{
		if(box[2][1]=='@')
		{
			if(box[2][2]=='@')
			{

		printf("player2 win");
		player1=0;
	   //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[0][0]=='@')
	{
		if(box[1][0]=='@')
		{
			if(box[2][0]=='@')
			{

		printf("player2 win");
		player1=0;
	  //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[0][1]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[2][1]=='@')
			{

		printf("player2 win");
		player1=0;
	//	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[0][2]=='@')
	{
		if(box[1][2]=='@')
		{
			if(box[2][2]=='@')
			{

		printf("player2 win");
		player1=0;
	  //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 if(box[0][0]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[2][2]=='@')
			{

		printf("player2 win");
		player1=0;
	 //	player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
  if(box[0][2]=='@')
	{
		if(box[1][1]=='@')
		{
			if(box[2][0]=='@')
			{

		printf("player2 win");
		player1=0;
   //		player2=0;
		win1();
		delay(10000);
		set(box,array,&*cross,&*zero);
		flag=0;
		clrscr();
		draw();
			}
		}
	}
 //PROCESS OF AI

 if(box[0][0]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;          //1st case
			  offset1=2;
			  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();

			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][2]=='@')
			 {                           //2nd case
			   box[1][1]='@';
				array[1][1]=1;
				(*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
				delay(10000);
				set(box,array,&*cross,&*zero);
				flag=0;
				clrscr();
				draw();

			  }
		  }
	}
 if(box[0][0]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //3rd case
		   if(box[2][2]=='@')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();

			}
		 }
	}

  if(box[0][2]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
			  offset1=2;             //4th case
			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][0]=='@')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //5th case
				(*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][2]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //6th case
		   if(box[2][0]=='@')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[0][1]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[2][1]=='\0')
			{
			  box[2][1]='@';
			  array[2][1]=1;
			  (*zero)++;
			  offset1=2;             //7th case
			  offset2=1;

			  gotoxy(46,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][1]=='@')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //8th case
				(*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);
			  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][1]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //9th case
		   if(box[2][1]=='@')
			{
			  box[0][1]='@';
			  array[0][1]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=1;

			  gotoxy(46,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero); flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[0][2]=='@')
	 {
		if(box[1][2]=='@')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
			  offset1=2;             //10th case
			  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[1][2]=='\0')
		  {
			if(box[2][2]=='@')
			 {
			   box[1][2]='@';
				array[1][2]=1;                 //11th case
				(*zero)++;
				offset1=1;
				offset2=2;

				gotoxy(62,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][2]=='\0')
	 {
		if(box[1][2]=='@')
		 {                             //12th case
		   if(box[2][2]=='@')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[0][0]=='@')
	 {
		if(box[1][0]=='@')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
			  offset1=2;             //13th case
			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[1][0]=='\0')
		  {
			if(box[2][0]=='@')
			 {
			   box[1][0]='@';
				array[1][0]=1;                 //14th case
			   (*zero)++;
				offset1=1;
				offset2=0;

				gotoxy(30,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][0]=='\0')
	 {
		if(box[1][0]=='@')
		 {                             //15th case
		   if(box[2][0]=='@')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

if(box[0][0]=='@')
	 {
		if(box[0][1]=='@')
		 {
		   if(box[0][2]=='\0')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
			  offset1=0;             //16th case
			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);               flag=0;
			  set(box,array,&*cross,&*zero);
			  clrscr();
			  draw();
			}
		 }
		  if(box[0][1]=='\0')
		  {
			if(box[0][2]=='@')
			 {
			   box[0][1]='@';
				array[0][1]=1;                 //17th case
				(*zero)++;
				offset1=0;
				offset2=1;

				gotoxy(46,4);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[0][0]=='\0')
	 {
		if(box[0][1]=='@')
		 {                             //18th case
		   if(box[0][2]=='@')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[1][0]=='@')
	 {
		if(box[1][1]=='@')
		 {
		   if(box[1][2]=='\0')
			{
			  box[1][2]='@';
			  array[1][2]=1;
			  (*zero)++;
			  offset1=1;             //19th case
			  offset2=2;

			  gotoxy(62,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[1][2]=='@')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //20th case
				(*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

 if(box[1][0]=='\0')
	 {
		if(box[1][1]=='@')
		 {                             //21th case
		   if(box[1][2]=='@')
			{
			  box[1][0]='@';
			  array[1][0]=1;
			  (*zero)++;
			  offset1=1;
			  offset2=0;

			  gotoxy(30,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

 if(box[2][0]=='@')
	 {
		if(box[2][1]=='@')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
			  offset1=2;             //22th case
			  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
		  if(box[2][1]=='\0')
		  {
			if(box[2][2]=='@')
			 {
			   box[2][1]='@';
				array[2][1]=1;                 //23th case
				(*zero)++;
				offset1=2;
				offset2=1;

				gotoxy(46,16);
				printf("@");
				gotoxy(3,2);
				player1=0;
				win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			  }
		  }
	}

if(box[2][0]=='\0')
	 {
		if(box[2][1]=='@')
		 {                             //24th case
		   if(box[2][2]=='@')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
			  offset1=2;
			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  win1();
			  delay(10000);
			  set(box,array,&*cross,&*zero);  flag=0;
			  clrscr();
			  draw();
			}
		 }
	}

if(box[0][0]=='*')
{   //cases for draw	 {
		if(box[1][1]=='*')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;          //1st case
			  offset1=2;
			  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][2]=='*')
			 {                           //2nd case
			   box[1][1]='@';
				array[1][1]=1;
				(*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}
 if(box[0][0]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //3rd case
		   if(box[2][2]=='*')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][2]=='*')
	 {
		if(box[1][1]=='*')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
			  offset1=2;             //4th case
			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][0]=='*')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //5th case
				(*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][2]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //6th case
		   if(box[2][0]=='*')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][1]=='*')
	 {
		if(box[1][1]=='*')
		 {
		   if(box[2][1]=='\0')
			{
			  box[2][1]='@';
			  array[2][1]=1;
			  (*zero)++;
			  offset1=2;             //7th case
			  offset2=1;

			  gotoxy(46,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[2][1]=='*')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //8th case
				(*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][1]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //9th case
		   if(box[2][1]=='*')
			{
			  box[0][1]='@';
			  array[0][1]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=1;

			  gotoxy(46,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][2]=='*')
	 {
		if(box[1][2]=='*')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
			  offset1=2;             //10th case
			  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][2]=='\0')
		  {
			if(box[2][2]=='*')
			 {
			   box[1][2]='@';
				array[1][2]=1;                 //11th case
				(*zero)++;
				offset1=1;
				offset2=2;

				gotoxy(62,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][2]=='\0')
	 {
		if(box[1][2]=='*')
		 {                             //12th case
		   if(box[2][2]=='*')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][0]=='*')
	 {
		if(box[1][0]=='*')
		 {
		   if(box[2][0]=='\0')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
			  offset1=2;             //13th case
			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][0]=='\0')
		  {
			if(box[2][0]=='*')
			 {
			   box[1][0]='@';
				array[1][0]=1;                 //14th case
				(*zero)++;
				offset1=1;
				offset2=0;

				gotoxy(30,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][0]=='\0')
	 {
		if(box[1][0]=='*')
		 {                             //15th case
		   if(box[2][0]=='*')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[0][0]=='*')
	 {
		if(box[0][1]=='*')
		 {
		   if(box[0][2]=='\0')
			{
			  box[0][2]='@';
			  array[0][2]=1;
			  (*zero)++;
			  offset1=0;             //16th case
			  offset2=2;

			  gotoxy(62,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[0][1]=='\0')
		  {
			if(box[0][2]=='*')
			 {
			   box[0][1]='@';
				array[0][1]=1;                 //17th case
				(*zero)++;
				offset1=0;
				offset2=1;

				gotoxy(46,4);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[0][0]=='\0')
	 {
		if(box[0][1]=='*')
		 {                             //18th case
		   if(box[0][2]=='*')
			{
			  box[0][0]='@';
			  array[0][0]=1;
			  (*zero)++;
			  offset1=0;
			  offset2=0;

			  gotoxy(30,4);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[1][0]=='*')
	 {
		if(box[1][1]=='*')
		 {
		   if(box[1][2]=='\0')
			{
			  box[1][2]='@';
			  array[1][2]=1;
			  (*zero)++;
			  offset1=1;             //19th case
			  offset2=2;

			  gotoxy(62,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[1][1]=='\0')
		  {
			if(box[1][2]=='*')
			 {
			   box[1][1]='@';
				array[1][1]=1;                 //20th case
			   (*zero)++;
				offset1=1;
				offset2=1;

				gotoxy(46,10);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[1][0]=='\0')
	 {
		if(box[1][1]=='*')
		 {                             //21th case
		   if(box[1][2]=='*')
			{
			  box[1][0]='@';
			  array[1][0]=1;
			  (*zero)++;
			  offset1=1;
			  offset2=0;

			  gotoxy(30,10);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(box[2][0]=='*')
	 {
		if(box[2][1]=='*')
		 {
		   if(box[2][2]=='\0')
			{
			  box[2][2]='@';
			  array[2][2]=1;
			  (*zero)++;
			  offset1=2;             //22th case
			  offset2=2;

			  gotoxy(62,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
		  if(box[2][1]=='\0')
		  {
			if(box[2][2]=='*')
			 {
			   box[2][1]='@';
				array[2][1]=1;                 //23th case
				(*zero)++;
				offset1=2;
				offset2=1;

				gotoxy(46,16);
				printf("@");
				gotoxy(3,2);
				player1=0;
				return;
			  }
		  }
	}

if(box[2][0]=='\0')
	 {
		if(box[2][1]=='*')
		 {                             //24th case
		   if(box[2][2]=='*')
			{
			  box[2][0]='@';
			  array[2][0]=1;
			  (*zero)++;
			  offset1=2;
			  offset2=0;

			  gotoxy(30,16);
			  printf("@");
			  gotoxy(3,2);
			  player1=0;
			  return;
			}
		 }
	}

if(player1==1)
 {
 if(box[0][1]=='\0')
   {
	 box[0][1]='@';
	 array[0][1]=1;
	 zero++;
	 offset1=0;
	 offset2=1;

	 gotoxy(46,4);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;

   }
 if(box[1][0]=='\0')
   {
	 box[1][0]='@';
	 array[1][0]=1;
	 zero++;
	 offset1=1;
	 offset2=0;

	 gotoxy(30,10);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;

   }
 if(box[1][2]=='\0')
   {
	 box[1][2]='@';
	 array[1][2]=1;
	 zero++;
	 offset1=1;
	 offset2=2;

	 gotoxy(62,10);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
	if(box[2][1]=='\0')
   {
	 box[2][1]='@';
	 array[2][1]=1;
	 zero++;
	 offset1=2;
	 offset2=1;

	 gotoxy(46,16);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }




   if(box[0][0]=='\0')
   {                         //random position
	 box[0][0]='@';
	 array[0][0]=1;
	 zero++;
	 offset1=0;
	 offset2=0;

	 gotoxy(30,4);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
if(box[0][2]=='\0')
   {
	 box[0][2]='@';
	 array[0][2]=1;
	 zero++;
	 offset1=0;
	 offset2=2;

	 gotoxy(62,4);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;

   }
 if(box[1][1]=='\0')
   {
	 box[1][1]='@';
	 array[1][1]=1;
	 zero++;
	 offset1=1;
	 offset2=1;

	 gotoxy(46,10);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }

 if(box[2][0]=='\0')
   {
	 box[2][0]='@';
	 array[2][0]=1;
	 zero++;
	 offset1=2;
	 offset2=0;

	 gotoxy(30,16);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }

 if(box[2][2]=='\0')
   {
	 box[2][2]='@';
	 array[2][2]=1;
	 zero++;
	 offset1=2;
	 offset2=2;

	 gotoxy(62,16);
	 printf("@");
	 gotoxy(3,2);
	 player1=0;
	 return;
   }
  }
}
void draw()
{
	int left=3,top=2;
	clrscr();
	gotoxy(30,4);
	printf("1");
	gotoxy(46,4);
	printf("2");
	gotoxy(62,4);
	printf("3");
	gotoxy(30,10);
	printf("4");
	gotoxy(46,10);
	printf("5");
	gotoxy(62,10);
	printf("6");
	gotoxy(30,16);
	printf("7");
	gotoxy(46,16);
	printf("8");
	gotoxy(62,16);
	printf("9");
	while(left<22)
	{
		gotoxy(left,top);
		left++;
	}
	while(left<70)
	{
		gotoxy(left,top);
		printf("*");
		left++;
	}

	while(top<19)
	{
		gotoxy(left,top);
		printf("*");
		top++;
	}
	while(left>22)
	{
		gotoxy(left,top);
		printf("*");
		left--;
	}

	while(top>2)
	{
		gotoxy(left,top);
		printf("*");
		top--;
	}
		while(left<38)
	{
		gotoxy(left,top);
		left++;
	}
	while(top<19)
	{
	  gotoxy(left,top);
	  printf("*");
	  top++;
	}
		while(top!=2)
	{
	  gotoxy(left,top);
	  top--;
	}
		while(left<54)
	{
		gotoxy(left,top);
		left++;
	}
		while(top<19)
	{
	  gotoxy(left,top);
	  printf("*");
	  top++;
	}
	   while(left<70)
	{
	   gotoxy(left,top);
	   left++;
	}
	   while(top>13)
	{
	   gotoxy(left,top);
	   top--;
	}
	   while(left>22)
	{
	  gotoxy(left,top);
	  printf("*");
	  left--;
	}
	   while(top>7)
	{
	   gotoxy(left,top);
	   top--;
	}
	   while(left<70)
	{
	  gotoxy(left,top);
	  printf("*");
	  left++;
	}

  //	gotoxy(3,2);
	gotoxy(72,2);
	printf("#-QUIT");
	gotoxy(72,4);
	printf("r-RESET");
	gotoxy(72,6);
	printf("u-UNDO");
	gotoxy(3,2);

 }
void set(char box[3][3],int array[3][3],int* cross,int* zero)
{
 int offset,offset1;
  for(offset=0;offset<3;offset++)
 {
  for(offset1=0;offset1<3;offset1++)
  { box[offset][offset1]='\0';
	array[offset][offset1]=0;
  }
 }
 *zero=*cross=0;
}
void pic()
{
 int left=3,top=2;
 clrscr();
 while(left<10)
 {
  gotoxy(left,top);
  left++;
 }
 while(left<17)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 while(left>13)
 {
  gotoxy(left,top);
  left--;
  }
 while(top<7)
 {gotoxy(left,top);
  printf("*");
  top++;
 }
 delay(100);
 left=19;
 top=2;
 gotoxy(left,top);

 while(top<7)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 left=22;
 top=2;
 gotoxy(left,top);
 delay(100);
 while(left<26)
 {
  gotoxy(left,top);
  printf("*");
  left++;
  }
 left=22;
 top=2;
 gotoxy(left,top);
 while(top<6)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 while(left<26)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 delay(100);
 top=4;
 gotoxy(left,top);
 while(left<28)
 {
 gotoxy(left,top);
 printf("*");
 left++;
 }
 delay(100);
 left=30;
 top=2;
 gotoxy(left,top);

 while(left<37)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }

 left=33;
 gotoxy(left,top);

  while(top<7)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 delay(100);
  left=39;
  top=6;
  gotoxy(left,top);
  while(top>2)
  {
   gotoxy(left,top);
   printf("*");
   top--;
  }
  while(left<46)
  {
   gotoxy(left,top);
   printf("*");
   left++;
  }
  while(top<7)
  {
   gotoxy(left,top);
   printf("*");
   top++;
  }
  delay(100);
  top=4;
  gotoxy(left,top);
  while(left!=39)
  {
   gotoxy(left,top);
   printf("*");
   left--;
  }
  delay(100);
  left=49;
  top=2;
  gotoxy(left,top);
  while(left<53)
  {
   gotoxy(left,top);
   printf("*");
   left++;
  }
  left=49;
  top=2;
  while(top<6)
  {
   gotoxy(left,top);
   printf("*");
   top++;
  }
  delay(100);
  while(left<53)
  {
   gotoxy(left,top);
   printf("*");
   left++;
  }
  top=4;
  while(left<55)
  {
   gotoxy(left,top);
   printf("*");
   left++;
  }
  left=57;
  top=2;
  while(left<64)
  {
   gotoxy(left,top);
   printf("*");
   left++;
   }
   left=60;
   while(top<7)
   {
	gotoxy(left,top);
	printf("*");
	top++;
	}
	delay(100);
	left=66;
	top=2;
	gotoxy(left,top);
	while(left<71)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	}
	while(top<6)
	{
	gotoxy(left,top);
	printf("*");
	top++;
	}
	delay(100);
	while(left>66)
	{
	 gotoxy(left,top);
	 printf("*");
	 left--;
	 }
	 delay(100);
	while(top!=2)
	{
	gotoxy(left,top);
	printf("*");
	top--;
	}
	left=74;
	top=2;
	gotoxy(left,top);
	//E
	delay(100);
	while(top!=6)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	while(left<78)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	}
	left=74;
	top=4;
	gotoxy(left,top);
	while(left<78)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	 }
	 left=74;
	 top=2;
		while(left<78)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	 }
	//BOX
	delay(100);
  left=14;
  top=8;
  gotoxy(left,top);
  while(left<54)
  {
   gotoxy(left,top);
   printf("*");
   left++;
  }
  while(top<25)
  {
   gotoxy(left,top);
   printf("*");
   top++;
  }
  while(left>14)
  {
   gotoxy(left,top);
   printf("*");
   left--;
  }
  while(top>8)
  {
   gotoxy(left,top);
   printf("*");
   top--;
  }
  left=27;
  gotoxy(left,top);
  while(top<25)
  {
   gotoxy(left,top);
   printf("*");
   top++;
  }
  left=42;
  top=8;
  gotoxy(left,top);
  while(top<25)
  {
   gotoxy(left,top);
   printf("*");
   top++;
  }
  left=14;
  top=13;
  gotoxy(left,top);
  while(left<54)
  {
   gotoxy(left,top);
   printf("*");
   left++;
  }
  left=14;
  top=19;
  gotoxy(left,top);
  while(left<54)
  {
   gotoxy(left,top);
   printf("*");
   left++;
  }
  gotoxy(21,10);
  printf("*");
  delay(100);
  gotoxy(35,16);
   delay(100);
  printf("*");
  gotoxy(48,22);
   delay(100);
  printf("*");
  gotoxy(48,10);
   delay(100);
  printf("@");
  gotoxy(35,16);
   delay(100);
  printf("@");
  gotoxy(21,22);
   delay(100);
  printf("@");

 }
 void win()
{
 int left=3,top=20;
 gotoxy(left,top);
 //p
 while(top<25)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 left=3,top=20;
 while(left<7)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 while(top<22)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 while(left>3)
 {
  gotoxy(left,top);
  printf("*");
  left--;
  }
//l
 left=10;
 top=20;
 while(top<24)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 while(left<13)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 //A
 left=15;
 while(top>=20)
 {
 gotoxy(left,top);
 printf("*");
 top--;
 }
 top=20;
 while(left<20)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
  while(top<25)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 left=23;
 top=20;
 gotoxy(left,top);
 //Y
 while(top<22)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 while(left<27)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 left=26;
 top=20;
 gotoxy(left,top);
 while(top<25)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 top=24;
 left=29;
 //E
 gotoxy(left,top);
 while(left<34)
 {
  printf("*");
  left++;
 }
 left=29;
 while(top>20)
 {
  gotoxy(left,top);
  printf("*");
  top--;
  }
  while(left<34)
  {
   gotoxy(left,top);
   printf("*");
   left++;
   }
   left=29;
   top=22;
   gotoxy(left,top);
   while(left<34)
   {
	gotoxy(left,top);
	printf("*");
	left++;
   }
   //R
   left=37;
   top=20;
   gotoxy(left,top);
   while(top<25)
   {
	gotoxy(left,top);
	printf("*");
	top++;
   }
   left=37;
   top=20;
   while(left<41)
   {
	gotoxy(left,top);
	printf("*");
	left++;
   }
   while(top<22)
   {
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
   while(left>37)
   {
	gotoxy(left,top);
	printf("*");
	left--;
	}
	gotoxy(37,22);
	printf("*");
	gotoxy(39,23);
	printf("*");
	gotoxy(41,24);
	printf("*");
	//1
	left=45;
	top=20;
	while(top<25)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	//W
	left=49;
	top=20;
	while(top<24)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	while(left<53)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	}
	while(top>21)
	{
	 gotoxy(left,top);
	 printf("*");
	 top--;
	}
	top=24;
	while(left<57)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	}
	while(top>=20)
	{
	 gotoxy(left,top);
	 printf("*");
	 top--;
	}
	//I
	left=59;
	top=20;
	while(top<25)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	//N
	left=61;
	top=20;
	while(top<25)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	top=21;
	left=62;
	gotoxy(left,top);
	printf("*");
	top=22;
	left=63;
	gotoxy(left,top);
	printf("*");
	top=23;
	left=64;
	gotoxy(left,top);
	printf("*");
	top=24;
	left=65;
	gotoxy(left,top);
	printf("*");
	while(top>=20)
	{
	 gotoxy(left,top);
	 top--;
	 printf("*");
	}
 }
 void win1()
{
 int left=3,top=20;
 gotoxy(left,top);
 //p
 while(top<25)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 left=3,top=20;
 while(left<7)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 while(top<22)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 while(left>3)
 {
  gotoxy(left,top);
  printf("*");
  left--;
  }
//l
 left=10;
 top=20;
 while(top<24)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 while(left<13)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 //A
 left=15;
 while(top>=20)
 {
 gotoxy(left,top);
 printf("*");
 top--;
 }
 top=20;
 while(left<20)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
  while(top<25)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 left=23;
 top=20;
 gotoxy(left,top);
 //Y
 while(top<22)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 while(left<27)
 {
  gotoxy(left,top);
  printf("*");
  left++;
 }
 left=26;
 top=20;
 gotoxy(left,top);
 while(top<25)
 {
  gotoxy(left,top);
  printf("*");
  top++;
 }
 top=24;
 left=29;
 //E
 gotoxy(left,top);
 while(left<34)
 {
  printf("*");
  left++;
 }
 left=29;
 while(top>20)
 {
  gotoxy(left,top);
  printf("*");
  top--;
  }
  while(left<34)
  {
   gotoxy(left,top);
   printf("*");
   left++;
   }
   left=29;
   top=22;
   gotoxy(left,top);
   while(left<34)
   {
	gotoxy(left,top);
	printf("*");
	left++;
   }
   //R
   left=37;
   top=20;
   gotoxy(left,top);
   while(top<25)
   {
	gotoxy(left,top);
	printf("*");
	top++;
   }
   left=37;
   top=20;
   while(left<41)
   {
	gotoxy(left,top);
	printf("*");
	left++;
   }
   while(top<22)
   {
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
   while(left>37)
   {
	gotoxy(left,top);
	printf("*");
	left--;
	}
	gotoxy(37,22);
	printf("*");
	gotoxy(39,23);
	printf("*");
	gotoxy(41,24);
	printf("*");
	//2
	left=44;
	top=20;
	gotoxy(left,top);
	printf("*");
	left=45;
	while(top<22)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	top=22;
	gotoxy(left,top);
	printf("*");
	 left=44;
	 gotoxy(left,top);
	 printf("*");
	 top=23;
	 gotoxy(left,top);
	 printf("*");
	 top=24;
	 gotoxy(left,top);
	 printf("*");
	 left=45;
	 gotoxy(left,top);
	 printf("*");
	/* while(top<24)
	 {
	   gotoxy(left,top);
	   printf("*");
	   top++;
	 }
	 left=45;
	 gotoxy(left,top);
	 printf("*");*/
	//W
	left=49;
	top=20;
	while(top<24)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	while(left<53)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	}
	while(top>21)
	{
	 gotoxy(left,top);
	 printf("*");
	 top--;
	}
	top=24;
	while(left<57)
	{
	 gotoxy(left,top);
	 printf("*");
	 left++;
	}
	while(top>=20)
	{
	 gotoxy(left,top);
	 printf("*");
	 top--;
	}
	//I
	left=59;
	top=20;
	while(top<25)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	//N
	left=61;
	top=20;
	while(top<25)
	{
	 gotoxy(left,top);
	 printf("*");
	 top++;
	}
	top=21;
	left=62;
	gotoxy(left,top);
	printf("*");
	top=22;
	left=63;
	gotoxy(left,top);
	printf("*");
	top=23;
	left=64;
	gotoxy(left,top);
	printf("*");
	top=24;
	left=65;
	gotoxy(left,top);
	printf("*");
	while(top>=20)
	{
	 gotoxy(left,top);
	 top--;
	 printf("*");
	}
 }
