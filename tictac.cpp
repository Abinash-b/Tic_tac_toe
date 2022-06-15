#include<iostream>
#include<stdio.h>
#include<string.h>
#include "graphics.h"
#include<stdlib.h>
using namespace std;
void setbig(int *x,int*y,int *x1,int *y1)
{ int p,q;
  if(*x>*x1)
    {p=*x;     q=*y;
     *x=*x1;   *y=*y1;
     *x1=p;    *y1=q;
    }

}
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    float m;
    x=x0;
    y=y0;
    setbig(&x,&y,&x1,&y1);

    dx=x1-x;
    dy=y1-y;

    m=(float)dy/dx;
    if (m>=0&&m<=1)
    {p=2*dy-dx;
     while(x<x1)
     {
         if(p>=0)
         {
             y=y+1;
             putpixel(x+300,250-y,GREEN);
             p=p+2*dy-2*dx;
         }
         else
         {
             putpixel(x+300,250-y,RED);
             p=p+2*dy;
         }
             x=x+1;
     }
    }
    else if (m>1)
    {p=2*dx-dy;
     while(y<y1)
     {
         if(p>=0)
         {
             x=x+1;
             putpixel(x+300,250-y,GREEN);
             p=p+2*dx-2*dy;
         }
         else
         {
             putpixel(x+300,250-y,RED);
             p=p+2*dx;
         }
             y=y+1;
     }
    }
    else if (m<0&&m>=-1)
    {p= -1*2*dy-dx;
     while(x<x1)
     {
         if(p>=0)
         {
             y=y-1;
             putpixel(x+300,250-y,GREEN);
             p=p-2*dy-2*dx;
         }
         else
         {
             putpixel(x+300,250-y,RED);
             p=p-2*dy;
         }
             x=x+1;
     }
    }
    else if (m<-1)
    {p=2*dx+dy;
     while(y>y1)
     {
         if(p>=0)
         {
             x=x+1;
             putpixel(x+300,250-y,GREEN);
             p=p+2*dy+2*dx;
         }
         else
         {
             putpixel(x+300,250-y,RED);
             p=p+2*dx;
         }
             y=y-1;
     }
    }
};
void drawarcs(int x,int y,int x0,int y0)
{  putpixel(x+300,250-y,GREEN);
   putpixel(x+300,250+y-2*y0,GREEN);
   putpixel(2*x0-x+300,250-y,GREEN);
   putpixel(2*x0-x+300,250+y-2*y0,GREEN);
}
void drawcircle(int x0,int y0,int r=10)
{  int x,y,p,a,b;
   x=x0;
   y=y0+r;
   p=1-r;
   while(y-y0>=x-x0)
   { if(p>0)
     { p=p+2*(x-x0)-2*(y-y0)+5;
       y--;
       drawarcs(x,y,x0,y0);
     }
     else if(p<=0)
     { p=p+2*(x-x0)+3;
      drawarcs(x,y,x0,y0);
     }
     x++;
   }
   y=y0;
   x=x0+r;
   p=1-r;
   while(x-x0>=y-y0)
   { if(p>0)
     { p=p+2*(y-y0)-2*(x-x0)+5;
       x--;
       drawarcs(x,y,x0,y0);
     }
     else if(p<=0)
     { p=p+2*(y-y0)+3;
      drawarcs(x,y,x0,y0);
     }
     y++;
   }

};
void lines()
{ drawline(15,-45,15,45);
  drawline(-15,-45,-15,45);
  drawline(-45,15,45,15);
  drawline(-45,-15,45,-15);
}
void drawcrox(int x,int y)
{  drawline(x,y,x+10,y+10);
   drawline(x,y,x+10,y-10);
   drawline(x,y,x-10,y-10);
   drawline(x,y,x-10,y+10);
}
	 /* this function assign every element of box
						 a " " character*/
void clear(char c[9][2])
{  int i;
	 for(i=0;i<9;i++)
	 {
	   c[i][0]=' ';
	   c[i][1]='\0';
	  }
 }
void box(char c[9][2])                   /*this function creat a tic tac box*/
{     system("cls");
   int gdriver=DETECT, gmode, x0, y0, r;
    initgraph(&gdriver, &gmode, NULL);
    lines();
    int z,x,y;
      for(z=0;z<9;z++)
	 {x=z%3;
	  y=z/3;
      if(strcmp(c[z],"o")==0)
       { drawcircle(x*30-30,30-y*30);
       }
      else if(strcmp(c[z],"x")==0)
       { drawcrox(x*30-30,30-y*30);
       }
	 }
	 getch();
	 closegraph();
}
int cdouble(char c[9][2])
{  int i,j,k,m,q;
   for(i=0;i<3;i++)
   {       m=k=0;
	   for(j=i;j<9;j+=3)
	   { if(strcmp(c[j],"x")==0)
	       m++;
	     if(strcmp(c[j],"o")==0)
	       k++;}
	   if(k==0)
	    { if(m==2)
	       { for(j=i;j<9;j+=3)
		     if(strcmp(c[j]," ")==0)
		      { c[j][0]='o'; return 0;}
	       }

	    }
	   else if(m==0)
	    {  if(k==2)
		{ for(j=i;j<9;j+=3)
		     if(strcmp(c[j]," ")==0)
		       {c[j][0]='o'; return 0;}
		 }

	    }
	   if((i==0)||i==2)
	   {   k=m=0;
	     for(j=i;j<9;j+=(4-i))
	     {if(strcmp(c[j],"x")==0)
		m++;
	      if(strcmp(c[j],"o")==0)
		k++;}
		 if(k==0)
	    { if(m==2)
	       { for(j=i;j<9;j+=(4-i))
		     if(strcmp(c[j]," ")==0)
		      {c[j][0]='o'; return 0;}
	       }

	    }
	   else if(m==0)
	    {  if(k==2)
		{ for(j=i;j<9;j+=(4-i))
		     if(strcmp(c[j]," ")==0)
		       {c[j][0]='o'; return 0;}
		 }


	    }}}
    for(i=0;i<9;i+=3)
      { m=k=0;

      for(j=i;j<(i+3);j++)
       { if(strcmp(c[j],"x")==0)
	     m++;
	   else if(strcmp(c[j],"o")==0)
	     k++;}

	   if(k==0)
	    { if(m==2)
	       { for(j=i;j<(i+3);j++)
		     if(strcmp(c[j]," ")==0)
		      {c[j][0]='o'; return 0;}
	       }

	    }
	   else if(m==0)
	    {  if(k==2)
		{ for(j=i;j<(i+3);j++)
		     if(strcmp(c[j]," ")==0)
		      { c[j][0]='o'; return 0;}
		 }

	    }}
	     if(strcmp(c[4]," ")==0)
	     {c[4][0]='o'; return 0;
	      }
          if(strcmp(c[4],"x")==0)
	       for(i=0;i<9;i+=2)
	       {if(strcmp(c[i]," ")==0)
		       { c[i][0]='o'; return 0; }
	        }

	       for(q=0;q<9;q++)
	 	   { if(strcmp(c[q]," ")==0)
		      { c[q][0]='o'; return 0; }
	       }

	   return 0;
 }
int askpos(char c[9][2],char x)
    { int pos;
      while(1)
      {cout<<"\nenter the postion of your input:";
       cin>>pos;
       if(pos>=1&&pos<=9&&(strcmp(c[pos-1]," ")==0))
       {
         c[pos-1][0]=x;
         break;
       }
       else
       {cout<<"\nenter valid position.\n";
       }
      }

    return pos;
    }
int check(char c[9][2])
{       int n,i,k;                       /* The function check will check who
						is the winner */
	for(i=0;i<3;i++)
	   { n=0;
	    for(k=i;k<9;k+=3)
		{ if(strcmp(c[i],c[k])==0)
		     n++;  }
		   if(n==3)
		   {if(strcmp(c[i],"x")==0)
		      return 1;
		    if(strcmp(c[i],"o")==0)
		    return 2;
		    else if(strcmp(c[i]," ")==0)
		    {}
		   }
	     }
	for(i=0;i<9;i+=3)
	{ n=0;
	  for(k=i;k<(i+3);k++)
		{ if(strcmp(c[i],c[k])==0)
		   n++;}
		   if(n==3)
		   {if(strcmp(c[i],"x")==0)
		      return 1;
		    if(strcmp(c[i],"o")==0)
		      return 2;
		    else if(strcmp(c[i]," ")==0)
		    {}
        }
    }
	  for(i=0;i<3;i+=2)
	  {  n=0;
	   for(k=i;k<9;k+=(4-i))
	   {  if(strcmp(c[i],c[k])==0)
	       n++;  }
	       if(n==3)
	       {if(strcmp(c[i],"x")==0)
		    return 1;
		    if(strcmp(c[i],"o")==0)
		    return 2;
		    else if(strcmp(c[i]," ")==0)
		    {}
		    }
	  }
return 0; }
int start1()
{
 cout<<"welcome to automatic tic tac game\n";
 int o;
 cout<<"use space to change the position of box\n";
 cout<<"press 1:-if U want to start\n";
 cout<<"press 2:-if computer to start\n";
 cin>>o;
 cout<<"your charecter is x\n";
 return(o);
}

int main()
{  int g,m,i,r,d,o,pos;
   char ph[9][2],p;
   do
   {   d=0;
	clear(ph);
	g=start1();
	if(g==1)
       {
        for(i=0;i<9;i++)
	    { pos=askpos(ph,'x');
	      r=cdouble(ph);
	     if(r==0)
	     {box(ph);}
	      o=check(ph);
        if(i>=3)
	    { if(o==0)
	       {
	       cout<<"it's a tie\n"; break;}}
	      if(o==1)
	       {cout<<" x wins\n"; break;}
	      if(o==2)
	       {cout<<" o wins\n"; break;}

        }
        }
	 else if(g==2)
	      {
	      ph[0][0]='o';
	      ph[0][1]='\0';box(ph);
		  for(i=1;i<9;i++)
	    { pos=askpos(ph,'x');
	      r=cdouble(ph);
	     if(r==0)
	     {box(ph);}
	      o=check(ph);
        if(i>=3)
	    { if(o==0)
	       {
	       cout<<"it's a tie\n"; break;}}
	      if(o==1)
	       {cout<<" x wins\n"; break;}
	      if(o==2)
	       {cout<<" o wins\n"; break;}

        }
        }
	     cout<<"want to play again Y or N\n";
	     cin>>p;
	     }while(p=='y'||p=='Y');
	     return 0;
}
