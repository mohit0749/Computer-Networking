#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
char msg_rec[30];
int n,r,temp1;
int bitcount=0,framecount=0;
char buf[4];
int receiver(char a,int i)
{
 bitcount++;
 buf[i]=a;
 r=rand()%4;

 for(i=0;i<4;i++)
 {
  if(buf[i]!='\0')
  {
  msg_rec[4*framecount+i]=buf[i];
  }
 }
 if(bitcount==1)
 {
  if(r==1)
  {
	  return r;
  }
  else 
  {
	  return -1;
  }
 }
 else
 {
  r=0;
  return -1;
 }
}
void sender()
{
 char msg[30],window[4];
 int x,l;
 cout<<"\nEnter the Message :";
 gets(msg);
 n=strlen(msg);
 int p=ceil(n/4.0);
 while(framecount<p)
 {
  cout<<"\nSending Window:"<<framecount+1<<"\n";
  for(int i=0;i<4;i++)
  {
   window[i]=msg[4*framecount+i];
  }
  for(int i=0;i<4;i++)
  {
   x=receiver(window[i],i);
   if(x==1&&r==1)
   {
     cout<<"\nNegative acknowledgement is received"<<x;
     x=receiver(window[i],framecount);
     cout<<"\nThe acknowledgement is received"<<x;
     for(l=0;l<4;l++)
     {
       if(window[l]>window[l+1])
        {
          temp1=window[l];
          window[l]=window[l+1];
          window[l+1]=temp1;
        }
     }
   }   
   else continue;
   bitcount=0;
  }
  framecount++;
 }
}
int main()
{
cout<<"\n\n\t\t\a\a\aSLIDING WINDOW SELECTIVE REPEAT PROTOCOL";
sender();
cout<<"\n\nReceived Message is :";
for(int i=0;i<n;i++)
{
	cout<<msg_rec[i];
}
return 0;
}

