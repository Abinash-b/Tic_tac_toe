#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
{ system("clear");  int z;
      for(z=0;z<9;z++)
	{  cout<<c[z];
	  if((z+1)%3!=0)
	  cout<<"|";
	  else if(z<8)
	  cout<<"\n-----\n";
	 }
}
int cdouble(char c[9][2])
{  int i,j,k,m,q;
   for(i=0;i<9;i++)
   {       m=k=0;
	   for(j=i;j<9;j+=3)
	   { if(strcmp(c[j],"x")==0)
	       m++;
	     if(strcmp(c[j],"o")==0)
	       k++;}
	   if(k==2)
	    { if(m==0)
	       { for(j=i;j<9;j+=3)
		     if(strcmp(c[j]," ")==0)
		      { c[j][0]='o'; return 0;}
	       }

	    }
	   else if(m==2)
	    {  if(k==0)
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
		 if(k==2)
	    { if(m==0)
	       { for(j=i;j<9;j+=(4-i))
		     if(strcmp(c[j]," ")==0)
		      {c[j][0]='o'; return 0;}
	       }

	    }
	   else if(m==2)
	    {  if(k==0)
		{ for(j=i;j<9;j+=(4-i))
		     if(strcmp(c[j]," ")==0)
		       {c[j][0]='o'; return 0;}
		 }

	    }}}
    for(i=0;i<9;i++)
      { m=k=0;
      if(i%3==0)
      {for(j=i;j<i+3;j++)
       { if(strcmp(c[i],"x")==0)
	     m++;
	   else if(strcmp(c[i],"o")==0)
	     k++;}
        }
	   if(k==2)
	    { if(m==0)
	       { for(j=i;j<i+3;j++)
		     if(strcmp(c[j]," ")==0)
		      {c[j][0]='o'; return 0;}
	       }

	    }
	   else if(m==2)
	    {  if(k==0)
		{ for(j=i;j<i+3;j++)
		     if(strcmp(c[j]," ")==0)
		      { c[j][0]='o'; return 0;}
		 }

	    }}
	     for(i=0;i<9;i++)
	      {if((i==0)||i%2==0)
		{  for(q=0;q<9;q+=2)
		   {if(strcmp(c[q]," ")==0)
		      { c[q][0]='o';return 0;}
		    }
		}
	       else
		{    for(q=1;q<9;q+=2)
		    if(strcmp(c[q]," ")==0)
		      { c[q][0]='o'; return 0; }
		}
		 }
	   return 0;
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
		    else
		    return 3;
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
		    else
		    return 3;
		   }
		  }
	  for(i=0;i<3;i+=2)
	  {n=0;
	   for(k=i;k<9;k+=(4-i))
	   {if(strcmp(c[i],c[k])==0)
	       n++;  }
	       if(n==3)
	       {if(strcmp(c[i],"x")==0)
		  return 1;
		if(strcmp(c[i],"o")==0)
		  return 2;
		else if(strcmp(c[i]," ")==0)
		    {}
		 else
		    return 3;
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
int posff(char c[9][2])
{ int i;
 for(i=0;i<9;i++)
 { if(strcmp(c[i]," ")!=0)
   {break;}
 }
 return(i+1);
}
int main()
{  int g,m,i,r,d,o;
   char ph[9][2],p;
   do
   {   d=0;
	clear(ph);
	box(ph);
	g=start1();
	if(g==1)
       { for(i=0;i<9;i++)
	 {if(strcmp(ph[i]," ")==0)
	   { gets(ph[i]);
	  if(strcmp(ph[i],"x")==0)
	    {if(d==0)
	     {m=posff(ph);
	     if(m!=5)
	      {if(m%2==0)
	       {ph[m+1][0]='o';
	       ph[m+1][1]='\0'; box(ph);}
	      else
	       {ph[4][0]='o';
	       ph[4][1]='\0'; box(ph);}
	      }
	      else
	       {ph[0][0]='o';
	       ph[0][1]='\0'; box(ph);}
	      }
	     else
	    {r=cdouble(ph);
	     if(r==0)
	     {box(ph);}
	      o=check(ph);
	      if(o==0&&d==9)
	       {
	       cout<<"it's a tie\n"; break;}
	      if(o==1)
	       {cout<<" x wins\n"; break;}
	      if(o==2)
	       {cout<<" o wins\n"; break;}
	       }
	       d++;
	      }
	      else if(strcmp(ph[i]," ")==0)
	      {box(ph);
	      ph[i][0]=' ';
	      }
	      else
	      {cout<<"enter valid charecter";
	      ph[i][0]=' ';
	      ph[i][1]='\0';
	      ph[i-1][0]=' ';
	      ph[i-1][1]='\0';
	      i--;
	       }
		if(i==8)
	       {i=0;}
	      }
	      }}
	 else if(g==2)
	      {  d=0;
	      ph[0][0]='o';
	      ph[0][1]='\0';box(ph);
		 for(i=0;i<9;i++)
		 {
		  if(strcmp(ph[i]," ")==0)
		    { gets(ph[i]);
		     if(strcmp(ph[i],"x")==0)
		      {r=cdouble(ph);
		       if(r==0)
			{box(ph);}
			o=check(ph);
			if(o==0&&d==9)
			{cout<<"it's a tie\n"; break;}
			if(o==1)
			{cout<<" x wins\n"; break;}
			if(o==2)
			{cout<<" o wins\n"; break;}
			d++;
		     }
		    else if(strcmp(ph[i]," ")==0)
		      {box(ph);
		      ph[i][0]=' ';
		      ph[i][1]='\0';
			   }
		    else
		    {cout<<"enter valid charecter";
			ph[i][0]=' ';
			ph[i][1]='\0';
		       ph[i-1][0]=' ';
			ph[i-1][1]='\0';
		  i--;
			}
		if(i==8)
	       {i=0;}
	       }}
	      }
	     cout<<"want to play again Y or N\n";
	     cin>>p;
	     }while(p=='y'||p=='Y');
	     return 0;
}
