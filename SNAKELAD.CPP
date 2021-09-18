//Snake and Ladder game
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
int rowls=0,rowle=0,prev=0,ladder_start[3][10],ladder_end[3][10],snake_head[3][10],snake_tail[3][10],rowh=0,rowt=0;
void board() //draws the board on the consol
{
	int x=40,y=40;
	for(int i=0;i<=10;i++)
	{
		line(0,y*i,400,y*i);
		line(x*i,0,x*i,400);
	}
}
void snake(int b,int a,int x,int y)//draws the snake on the consol
{
	int arr[10];
	if(a==6)
	{
		while(b>2)
		{
			for(int i=0;i<8;i+=2)
			{
				if(i==0||i==6)
					arr[i]=x;
				else
					arr[i]=x+40;
				if(i+1==1||i+1==3)
					arr[i+1]=y;
				else
					arr[i+1]=(y+40);
			}
			arr[8]=arr[0];
			arr[9]=arr[1];
			if(b==4)
			{
				//copying the coordinates of head of snake
				for(int i=0;i<10;++i)
					snake_head[rowh][i]=arr[i];
				rowh++;
			}
			setcolor(BROWN);
			setfillstyle(BKSLASH_FILL,BROWN);
			fillpoly(5,arr);
			x = arr[2];
			y = arr[3];
			--b;
			if(b==2)
			{
				x = arr[4];
				y = arr[5];
			}
			--a;
		}
	}
	while(b--)
	{
		for(int i=0;i<8;i+=2)
		{
			if(i==0||i==6)
				arr[i]=x;
			else
				arr[i]=x+40;
			if(i+1==1||i+1==3)
				arr[i+1]=y;
			else
				arr[i+1]=(y+40);
		}
		arr[8]=arr[0];
		arr[9]=arr[1];
		if(b==2)
		{
		       //	copying the coordinates of head of snake
			for(int i=0;i<10;++i)
				snake_head[rowh][i]=arr[i];
			++rowh;
		}
		if(b==1&&a==6)
		{
		     //	copying the coordinates of head of snake
			for(int i=0;i<10;++i)
				snake_head[rowh][i]=arr[i];
			++rowh;
		}
		if(b==0)
		{
		 //	copying the coordinates of tail of snake
			for(int i=0;i<10;++i)
				snake_tail[rowt][i]=arr[i];
			rowt++;
		 }
		 setcolor(BROWN);
		 setfillstyle(BKSLASH_FILL,BROWN);
		 fillpoly(5,arr);
		 x = arr[4];
		 y = arr[5];
	}
}
void call_snake()//calls the snake function and passes the starting coordinates for snake
{
	rowh=0;
	rowt=0;
	int k=3,a=6,x,y,b=0;
	while(k)
	{
		x=40*a;
		y=40*b;
		snake((k+1),a,x,y);
		if(a==0)
		{
			a=6;
			b+=3;
		}
		else
		{
			a=0;
			b+=5;
		}
		--k;
	}
}
void board_number()//displays the number on board
{
	int num=100,a=1;
	for(int i=1;i<=10;i++)
	{
		for(int k=1;k<=a;k++)
			cout<<"\n";
		if(a==3)
			a=1;
		int flag,j = 1;
		while(j<=10)
		{
			flag=0;
			if(i%2==1)
			{
				if(num%10==0)
					cout<<"  "<<num;
				else
					cout<<"  "<<num<<" ";
				--num;
				flag=1;
			}
			else
			{
				if(num%10==0)
					cout<<"  "<<num;
				else if(num>=0&&num<=9)
					cout<<"  "<<num<<"  ";
				else
					cout<<"  "<<num<<" ";
			       ++num;
			}
			++j;
		}		if(flag==1)
		num-=9;
		else
		num-=11;
	       ++a;
	}
}
void ladder_color(int x,int y,int i,int k)//draws ladder on the console
{
	int arr[10];
	while(k)
	{
		int b=1;
		for(int j=0;j<8;j+=2)
		{
			if(b==1||b==4)
				arr[j]=x;
			else
			{
				if(i==0)
					arr[j]=x+40;
				else
					arr[j]=x-40;
			}
			if(j+1==1||j+1==3)
				arr[j+1]=y;
			else
				arr[j+1]=(y+40);
			++b;
		}
		arr[8]=arr[0];
		arr[9]=arr[1];
		setcolor(YELLOW);
		setfillstyle(LTBKSLASH_FILL,YELLOW);
		fillpoly(5,arr);
		x=arr[4];
		y=arr[5];
		if((k==3)||(k==2&&i==0))
		{
			//copying the starting coordinates of ladder
			for(int i=0;i<10;++i)
				ladder_start[rowls][i]=arr[i];
			rowls++;
		}
		--k;
		if(k==0)
		{
			//copying the ending coordinates of ladder
			for(int i=0;i<10;++i)
				ladder_end[rowle][i]=arr[i];
			rowle++;
		}
	}
}
void ladder()//calls the ladder_color function and passes the starting coordinates of ladder
{
	int a=2;
	rowls=0;
	rowle=0;
	for(int i=0;i<=6;i+=3)
	{
		int x=40*a;
		int y=40*i;
		if(i%2==0)
			ladder_color(x,y,0,2);
		else
			ladder_color(x,y,1,3);
		if(a==8)
			a=2;
		a=8;
	}
}
int ladder_move(int arr[])//returns 1 if the player has encountered the ladder and 0 if not
{
	int count=0,row=-1;
	for(int i=0;i<rowle;++i)
	{
		count=0;
		for(int j=0;j<10;++j)
			if(arr[j]==ladder_end[i][j])
				++count;
		if(count==10)
		{
			row=i;
			break;
		}
	}
	if(row!=-1)
	{
		switch(row)
		{
			case 0:
				prev=98;
				break;
			case 1:
				prev=68;
				break;
			case 2:
				prev=32;
				break;
		}
		for(i=0;i<10;++i)
			arr[i]=ladder_start[row][i];
		setcolor(GREEN);
		setfillstyle(BKSLASH_FILL,GREEN);
		fillpoly(5,arr);
		return 1;
	}
	return 0;
}
int snake_bite(int arr[])//returns 1 if the player has encountered or has been bitten by the snake and 0 if not
{
	int count=0,row=-1;
	for(int i=0;i<rowh;++i)
	{
		count=0;
		for(int j=0;j<10;++j)
			if(arr[j]==snake_head[i][j])
				++count;
		if(count==10)
		{
			row=i;
			break;
		}
	}
	if(row!=-1)
	{
		//cout<<"\n\n\n\nSnake bites";
		switch(row)
		{
			case 0:
				prev=71;
				break;
			case 1:
				prev=23;
				break;
			case 2:
				prev=8;
				break;
		}
		for(i=0;i<10;++i)
			arr[i]=snake_tail[row][i];
		setcolor(GREEN);
		setfillstyle(BKSLASH_FILL,GREEN);
		fillpoly(5,arr);
		return 1;
	}
	return 0;
}
int cal_y(int prev1) //calculates the value of y coordinates for the movement of player
{
	int y;
	if(prev1>=1&&prev1<=10)
		y=360;
	else if(prev1>=11&&prev1<=20)
		y=320;
	else if(prev1>=21&&prev1<=30)
		y=280;
	else if(prev1>=31&&prev1<=40)
		y=240;
	else if(prev1>=41&&prev1<=50)
		y=200;
	else if(prev1>=51&&prev1<=60)
		y=160;
	else if(prev1>=61&&prev1<=70)
		y=120;
	else if(prev1>=71&&prev1<=80)
		y=80;
	else if(prev1>=81&&prev1<=90)
		y=40;
	else
		y=0;
	return y;
}
void cal_prev(int prev1)//calculates the position of the player depending on the previous position and dice value
{
	if((prev1>=1&&prev1<=9)||(prev1>=21&&prev1<=29)||(prev1>=41&&prev1<=49)||(prev1>=61&&prev1<=69)||(prev1>=81&&prev1<=89))
	{
		 prev = (prev%10);
		--prev;
	}
	else if(prev1%10==0)
	{
		if((prev1/10)%2==0)
			prev=0;
		else
			prev=9;
	}
	else
		prev = 10 - (prev%10);
}
int winner() //returns 1 if the player has won the game and 0 if not
{
	if(prev==100)
		return 1;
	return 0;
}
int movement(int a)//moves the player from previous position to new position
{
	if((prev+a)<=100)
		prev +=a;
	int d=winner();
	int x,y,arr[10],prev1;
	prev1=prev;
	y=cal_y(prev1);
	cal_prev(prev1);
	x = 40*prev;
	for(int j=0;j<8;j+=2)
	{
		if(j==0||j==6)
			arr[j]=x;
		else
			arr[j]=x+40;
		if(j+1==1||j+1==3)
			arr[j+1]=y;
		else
			arr[j+1]=(y+40);
	}
	arr[8]=arr[0];
	arr[9]=arr[1];
	int b = snake_bite(arr);
	int c = ladder_move(arr);
	if(b==0&&c==0)
	{
		setcolor(GREEN);
		setfillstyle(BKSLASH_FILL,GREEN);
		fillpoly(5,arr);
		prev=prev1;
	}
	return d;
}

int main()
{
	int gd=DETECT,gm;
	int m,num,a=0,i=0;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"\n*********************SNAKE AND LADDER********************************";
	cout<<"\nTHIS IS A SINGLE PLAYER GAME";
	cout<<"\nRULES:";
	cout<<"\n1: THE YELLOW COLORED BLOCKS ARE THE LADDER";
	cout<<"\n2: THE BROWN COLORED BLOCKS ARE THE SNAKE";
	cout<<"\n3: YOU ARE IN GREEN COLOR";
	cout<<"\n4: PRESS 1 AND ENTER TO START THE GAME";
	cout<<"\n5: PRESS X AND ENTER TO END THE GAME";
	cin>>num;
	if(num==1)
	{
		do
		{
			delay(800);
			clrscr();
			cleardevice();
			setbkcolor(BLUE);
			ladder();
			call_snake();
			if(a!=0)
			       i = movement(a);
			board_number();
			board();
			if(i==0)
			{
				cout<<"\n\n\nPRESS ENTER TO ROLL THE DICE";
				m=getch();
				if(m==88||m==120)
				{
					cout<<"\n************************************THANK YOU***********************************";
					exit(1);
				}
				srand(time(0));
				a=rand()%6+1;
				cout<<"\nNUMBER:  "<<a;
			}
		}while(i==0);
	}
	clrscr();
	cleardevice();
	cout<<"\n*************************************WINNER*************************************";
	cout<<"\n************************************THANK YOU***********************************";
	getch();
	return 0;
}