#include"graphics.h"
#include"dos.h"
#include"stdio.h"
#include"math.h"
union REGS i,o;
char *text[]={ "7","8","9","*","4","5","6","/","1","2","3","+","0","00",".","-","sin","cos","tan","+/-","log","^","x^2","sqt","OFF","AC","CE","="};
int k=0,pass,op,prop,newnum=1,bt,memo=1,d=0,sq;
long double num=0,accum=0,m;
void emergency()                                   //function to send sms to nearest
    {                                              //police station
int i,j;
char a;


	for(j=0;j<20;j++)
	{
		for(i=0;i<640;i+=20)
		{
			line(0+i+j,0,j+0+i,640);              //Change to new graphic window 
		}
		delay(100);
	}
	setcolor(1);
	delay(1000);                                 //To make the graphic windows wait 
	outtextxy(200,20,"lodge complaint? (y/n)");  //To print the quoted text on the graphic window
	a=getch();                                   //To get confirmation from user
	if(a=='y')
	{
		clrscr();
		outtextxy(200,20,"complaint placed to the nearest police station... ");
		getch();                                                                  
		// OFF
		hidemouseptr();                          //To vanish the mouse pointer
		clrscr();
		outtextxy(8,9,"Thanks for using!");
		exit();                                 //Program termination
	}
	else
	{
		clrscr();
		outtextxy(200,20,"complaint has been cancelled and saved as draft.."); //Response to user
		getch();
		// OFF
		hidemouseptr();
		clrscr();
		outtextxy(8,9,"Thanks for using!");
		exit();
	}
}
void storehistory()                                                      //Function to store accumulator value in file
{
	float y= accum;
	char buf[100];
	FILE *fpt;                                                      //File pointer
	gcvt(y,9,buf);                                                  //Float value conversion to null terminated string
	fpt=fopen("repo.txt","a");                                     //open file in append mode
	fputs(buf, fpt);                                              //store accumulator value in file
	fputs("\t",fpt);
	fclose(fpt);
}
void displayfile()
{
	char c;
	int i,j;
	FILE *fptr;
	fptr=fopen("repo.txt","r");                               //open file in read mode
	delay(2000);
	setcolor(13);                                            //color set to lightmagenta
	for(j=0;j<20;j++)
	{
		for(i=0;i<640;i+=20)
		{
			line(0+i+j,0,j+0+i,640);                         
		}
		delay(100);
	}
	setcolor(1);
	delay(1000);
	outtextxy(200,20,"History Values of accumulator");
	gotoxy(20,30);
	do
	{
		c=fgetc(fptr);
		printf("%c",c);
	}while(c!=EOF);
	fclose(fptr);
	getch();
	// OFF
	hidemouseptr();
	clrscr();
	outtextxy(8,9,"Thanks for using!");
	exit();
}
void normalbutton(int ,int ,int ,int,char**);
void main()
{
	int gd=DETECT,gm,x1,x2,y1,y2,i,j,maxx,maxy,x,y,button;
	char *text1[]={" ","T","o"," ","K","n","o","w"," ","a","b","o","u","t"," ","m","e"," ","l","o","g","o","n"," ",":"};
	char *text2[]={"w","w","w",".","g","e","o","c","i","t","i","e","s",".","c","o","m","/","t","a","l","k","d","e","e","p","e","s","h"};
	initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");                                                                     //location of graphics.h
	if(initmouse()==0)                                                                                         //check loading of mouse pointer
	{
		closegraph();
		restorecrtmode();
		printf("Mouse driver not loded");                                                                     //error message
		exit(1);
	}
	showmouseptr();
	movemouseptr(&x,&y);
	setbkcolor(11);
	setcolor(1);
	rectangle(198,140,417,163);                                                                               // setting boundaries for     
	rectangle(199,141,418,164);                                                                                //calculator
	rectangle(197,139,416,162);                                                                           
	rectangle(185,130,430,450);                                                                                           
	rectangle(184,129,431,451);                                                                            //setting booundaries for display 
	rectangle(182,127,433,454);                                                                        //screen
	rectangle(181,126,434,453);                                                                                
	outtextxy(200,50,"A Calculator in C");
	outtextxy(200,100,"Press OFF button to exit....");
	y1=140;
	y2=160;
	for(j=0;j<7;j++)
	{
		x1=200;
		x2=235;
		y1+=40;                                                                                          //To create buttons 
		y2+=40;                                                                                         //in 7 rows and
		for(i=0;i<4;i++)                                                                                //4 columns
		{
			normalbutton(x1,x2,y1,y2,text);
			x1+=60;
			x2+=60;
		}
	}
	while(1)
	{
		getmousepos(&button,&x,&y);                                                                     //Get x and y co-ordinates 
		y1=140;                                                                                         //when mouse is focused 
		y2=160;
		for(j=0;j<7;j++)
		{
			x1=200;
			x2=235;
			y1+=40;
			y2+=40;
			for(i=0;i<4;i++)
			{
				if((x<x2&&x>x1)&&(y<y2&&y>y1))                                                          //compare the focused point with
				{                                                                                      //the co-ordinates of button
					if((button & 1)==1)
					{
						gotoxy(28,10);
						bt=j*4+i;
						setcolor(11);
						outtextxy(x1+12,y1+7,text[j*4+i]);                                            //change the color of button
						if(num>pow(10.0,18))
						{
							exit();
						}
						//sound(500);
						delay(10);
						//nosound();
						delay(250);
						//sound(400);
						delay(10);
						//nosound();
						switch (bt)
						{
							case  8 :
								addnum(1);
								break;
							case  9 :
								addnum(2);
								break;
							case  10 :
								addnum(3);
								break;
							case  4 :
								addnum(4);
								break;
							case  5 :
								addnum(5);
								break;
							case  6 :
								addnum(6);
								break;
							case  0 :
								addnum(7);
								break;
							case  1 :
								addnum(8);
								break;
							case  2 :
								addnum(9);
								break;
							case  12 :
								addnum(0);
								break;
							case  11 :
								// plus
								operation(1);
								break;
							case  15 :
								// minus
								operation(2);
								break;
							case  3 :
								// multiplication
								operation(3);
								break;
							case  7 :
								// division
								operation(4);
								break;
							case 13:
								doublezero();
								break;
							case  14 :
								decimal();
								break;
							case 16:
								operation(7);//sin
								break;
							case 20:
								operation(6); //log
								break;
							case 19:
								plusminus();
								break;
							case 17:
								operation(8);//cos
								break;
							case 18:
								operation(9);//tan
								break;
							case 21:
								operation(5);
								break;
							case 22 :
								square();
								break;
							case 23:
								sqroot();
								break;
							case 24:
								// OFF
								hidemouseptr();
								clrscr();
								outtextxy(8,9,"Thanks you!!!");
								exit();
								break;
							case 25:
								allclear();
								break;
							case 26:
								clear();
								break;

							case 27:
								//  equalto
								operation(12);
								break;
						}
						setcolor(1);
						outtextxy(x1+12,y1+7,text[j*4+i]);
					}
				}
				x1+=60;
				x2+=60;
			}
		}
	}
}
void normalbutton(int x1,int x2,int y1,int y2,char **text)
{
	setcolor(15);
	rectangle(x1-2,y1-2,x2+1,y2+1);
	rectangle(x1-1,y1-1,x2+2,y2+2);
	setcolor(7);
	rectangle(x1,y1,x2+2,y2+2);
	rectangle(x1,y1,x2+1,y2+1);
	setfillstyle(SOLID_FILL,14);
	bar(x1,y1,x2,y2);
	setcolor(1);
	outtextxy(x1+12,y1+7,text[k]);
	k++;
}
/* initmouse */
initmouse()
{
	i.x.ax=0;
	int86 (0x33,&i,&o);
	return(o.x.ax);
}
/*hide mouse pointer*/
hidemouseptr()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}
/* displays mouse pointer */
showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
	return 0;
}
/*gets mouse coordinates and button status*/
getmousepos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
	return 0;
}
/* Move mouse ptr to x,y */
movemouseptr(int *x,int *y)
{
	i.x.ax=4;
	int86(0x33,&i,&o);
	o.x.cx=*x;
	o.x.dx=*y;
	return 0;
}
addnum(int pass)
{
	if(sq)
		newnum=1;
	if(newnum)
	{
		if(d)
		{
			num=pass/(pow(10.0,d));
			d++;
			newnum=0;
		}
		else
		{
		num=pass;
		newnum=0;
		}
	  }
	else
	{
	{if(d)
	{
		if(num<0)
			num=num-pass/(pow(10.0,d));
		else
			num=num+pass/(pow(10.0,d));
		d++;
	}
	else
	{
	num=num*10+pass;
	}
	}
	}
	printf("%25.5Lf",num);
	/* storehistory();  */

	if((int)num==100)
	{
		emergency();
	}
	if((int)num==3177)
	{
		displayfile();
	}
}
operation(int opr)
{
	long double pnum;
	pnum=num;
	if(newnum && (prop != 5) && memo)
	{
	}
	else
	{
		newnum=1;
		d=0;
		sq=0;
		switch(prop)
		{
			case 1:
				accum=accum+pnum;
				break;
			case 2:
				accum=accum-pnum;
				break;
			case 3:
				accum=accum*pnum;
				break;
			case 4:
				accum=accum/pnum;
				break;
			case 5:
				accum=pow(accum,pnum);
				break;
			case 6:
				accum=log(accum);
				break;
			case 7:
				accum=sin(accum);
				break;
			case 8:
				accum=cos(accum);
				break;
			case 9:
				accum=tan(accum);
				break;
			default:
				accum=pnum;
		}
	}
	prop=opr;
	num=accum;
	printf("%25.5Lf",num);
	storehistory();
}
allclear()
{
	sq=0;
	accum=0;
	num=0;
	d=0;
	newnum=1;
	printf("%25.5Lf",num);
	storehistory();

}
plusminus()
{
	if(num!=0)
	{
		num*=-1;
		printf("%25.5Lf",num);
		storehistory();
	}
}
decimal()
{
	if(!d)
	{
		d=1;
		if(newnum==1)
		{
			num=0;
		}
		printf("%25.5Lf",num);

	}
}
square()
{
	sq=1;
	num*=num;
	printf("%25.5Lf",num);
	storehistory();
}
sqroot()
{
	sq=1;
	num=pow(num,0.5);
	printf("%25.5Lf",num);
	storehistory();
}
doublezero()
{
	if(d)
	{
		d++;
		d++;
	}
	else
		num*=100;
	printf("%25.5Lf",num);
}
clear()
{
	num=0;
	printf("%25.5Lf",num);
}
