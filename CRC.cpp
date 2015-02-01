#include<iostream>
using namespace std;
class sender
{
public:
    int i,n,g,m;
    int ar[20],ar2[20],gen[20];
    void send();
    void rec();
};
void sender::send()
{

    cout<<"Enter the no. of generator bit : ";
    cin>>g;
    cout<<"Enter the generator bits :";
    for(i=0; i<g; i++)
    {
        cin>>gen[i];
    }

    cout<<"Enter no. of the bits"<<" : ";
    cin>>n;
    cout<<"Enter the bits :";
    for(i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    int	r=g-1;
    m=n+r;
    for(i=n; i<m; i++)
    {
        ar[i]=0;
    }
    cout<<"Appended Data : ";
    for(i=0; i<m; i++)
    {
        ar2[i]=ar[i];
        cout<<ar[i];
    }
    cout<<"\n";

    for(i=0; i<n; i++)
    {
        cout<<"Bit position :"<<i<<"\n";
        if(ar[i]==0||m-i<g)
        {
            cout<<"Left bits :"<<m-i<<"\n";
            cout<<"Passed bits :"<<i<<"\n";
        }
        else
        {
            for(int j=0; j<g; j++)
            {
                ar[i+j]=ar[i+j]^gen[j];
            }
        }
    }
    cout<<"Remainder bits are :";
    for(i=0; i<m; i++)
    {
        cout<<ar[i];
    }
    cout<<"\n";
    for(i=0; i<m; i++)
    {
        ar2[i]=ar2[i]^ar[i];
    }
    cout<<"Check Sum frame :";
    for(i=0; i<m; i++)
        cout<<ar2[i];
}
void sender::rec()
{
    for(i=0; i<n; i++)
    {
        if(ar2[i]==0||m-i<g)
        {
            continue;
        }
        else
        {
            for(int j=0; j<g; j++)
            {
                ar2[i+j]=ar2[i+j]^gen[j];
            }
        }
    }
    int count=0;
    for(i=0; i<m; i++)
    {
        count;
        count+=ar2[i];
    }
    if(count==0)
    {
        cout<<"\nData received with no error : ";
        for(i=0; i<n; i++)
        {
            cout<<ar2[i];
        }
    }
    else
    {
        cout<<"\nData received with error : ";
        for(i=0; i<n; i++)
            cout<<ar2[i];
    }
}
int main()
{
    sender s;
    s.send();
    s.rec();
    return 0;
}

