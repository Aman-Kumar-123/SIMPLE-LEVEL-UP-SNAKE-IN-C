#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int tailx[20]={6,7,8,9,10},taily[20]={10,10,10,10,10},tail=4;
COORD coord;
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void gameover()
{
    system("cls");
    printf("\n\n\n\t\t\t\tGAME OVER");
    getch();
    exit(0);
}
void boader()
{int i=0;
  for(i=0;i<=79;i++)
  {
      gotoxy(i,0);
      printf("-");
      gotoxy(i,20);
      printf("-");
  }
  for(i=0;i<=20;i++)
  {
      gotoxy(0,i);
      printf("|");
      gotoxy(79,i);
      printf("|");
  }

}
void clear()
{ int i;
    for(i=tail;i>=0;i--)
        if(tailx[i]!=0 && taily[i]!=0)
    {gotoxy(tailx[i],taily[i]);
     printf(" ");}
}
void sanke(int x,int y)
{int i,tx,ty,tx1,ty1;
   {tx1=tailx[tail];
   ty1=taily[tail];}
   tailx[tail]=x;
   taily[tail]=y;
  for(i=tail-1;i>=0;i--)
  {   tx=tailx[i];
      ty=taily[i];
      tailx[i]=tx1;
      taily[i]=ty1;
      tx1=tx;
      ty1=ty;
  }
  for(i=tail;i>=0;i--)
  {  if(tailx[i]!=0 && taily[i]!=0)
      {gotoxy(tailx[i],taily[i]);
        printf("%c",1);}
  }
}
void food(int *pos1,int *pos2)
{*pos1=(rand()%15)+1;
  *pos2=(rand()%65)+1;
  gotoxy(*pos2,*pos1);
  printf("F");
}
void main()
{ int a=10,b=10,i=0,x,y,speed=200,j;
    food(&x,&y);for(j=tail-1;j>=0;j--)
            if(a==tailx[j] && b==taily[j])
              gameover();
      boader();
    while(1)
    { if(kbhit())
        i=getch();
        for(j=tail-1;j>=0;j--)
            if(a==tailx[j] && b==taily[j])
              gameover();
        sanke(a,b);
      if(y==a && x==b)
        {food(&x,&y);++tail;
         speed=speed-20;}
       Sleep(speed);
       clear();
        if(i==0 || i==77)
       a++;
      else if(i==72)
       b--;
      else if(i==75)  //left
       a--;
      else if(i==80)  //down
       b++;
       else
        continue;
       if(!(a>0 && a<79)|| !(b>0 && b<20))
        gameover();
   }
}
