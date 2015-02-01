#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
char msg_rec[40];
int n;
int j=0,g=0;
char buffer[4];
int receiver(char a, int i)
{
    g++;
    buffer[i]=a;
    int r=rand()%4;
    for(i=0; i<4; i++)
    {
        if(buffer[i]!='\0')
        {
            msg_rec[4*j+i]=buffer[i];
        }
    }
    if(g==1)
    {
        if(r==1)
        {
            return i;
        }
        else if(r==2)
        {
            if(i<3)return(i+1);
            else return -1;
        }
        else return -1;
    }
    else return 0;
}
void sender()
{
    char msg[40],window[4];
    int x;
    cout<<"\nEnter the message or data : ";
    gets(msg);
    n=strlen(msg);
    int p=ceil(n/4.0);
    while(j<p)
    {
        for(int i=0; i<4; i++)
        {
            window[i]=msg[4*j+i];
        }
        for(int i=0; i<4; i++)
        {
            x=receiver(window[i],i);
            if(x==i)
            {
                cout<<"\nThe acknowledgement is negative";
                x=receiver(window[i],i);
                
            }
            else cout<<" ";
            g++;
        }
        j++;
    }
}

int main()
{
    sender();
    cout<<"\n\n\t\t\aSending Data Bit by Bit\t\t\n\n";
    cout<<"Data Received by Receiver is :";
    for(int i=0; i<n; i++)cout<<msg_rec[i];
    cout<<"\n";
    return 0;
}
