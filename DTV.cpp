#include<iostream>
#include<stdlib.h>
using namespace std;
#define infinity 9999
typedef enum{tentative,permananent}label_state;
struct node_state
{
	int predecessor;
	int length;
	label_state label;
}state[7];
int i,k,min1,j,temp;
int n,dist[7][7];
int contine;
class router
{
	public:
	void shortest_path(int s,int t,int path[])
	{
		for(i=0;i<n;i++)
		{
			state[i].predecessor=-1;
			state[i].length=infinity;
			state[i].label=tentative;
			cout<<"Initialzing State for node "<<i<<endl;
		}
			state[s].length=0;
			state[s].label=permananent;
			k=s;
			contine=0;
			do
			{
				cout<<"current state of graph is :"<<endl;
				cout<<"node "<<" predecessor "<<"     length "<<" label "<<endl;
				for(i=0;i<n;i++)
				{
					cout<<" "<<i<<"\t"<<state[i].predecessor<<"\t\t"<<state[i].length<<"\t"<<state[i].label<<endl;
				}
			    for(i=0;i<n;i++)
			    {
					if(dist[k][i]!=0&&state[i].label==tentative)
					{
						if(state[k].length+dist[k][i]<state[i].length)
						{
							state[i].predecessor=k;
							state[i].length=state[k].length+dist[k][i];
							cout<<"\nUpdating node "<<i<<" adjacent to "<<k<<endl;
						}
					}
				}
				temp=0;min1=infinity;
				for(j=0;j<n;j++)
				{
					if(state[j].label==tentative&&state[j].length<min1)
					{
						min1=state[j].length;
						temp=j;
					}
				}
				cout<<"\nFound node"<<temp<<"with state label!"<<endl;
				state[temp].label=permananent;
				k=temp;
				cout<<"Temp node "<<k<<" as permananent!"<<endl;
			}while(k!=t);
			i=0;
			k=t;
			for(j=k;j>0;j--)
			{
				path[i++]=k;
				k=state[k].predecessor;
			}
			cout<<"The path is : ";
			
			for(j=i-1;j>0;j--)
			{
				cout<<path[j];
				cout<<" to ";
			}
			cout<<t;
			cout<<endl;
	}
};
int main()
{
	router r1;
	int s,t,path[10],j;
	char resp='y';
	cout<<"\nEnter the edge :";
	cin>>n;
	while(resp!='n')
	{
		cout<<"\nEnter the start node no. :";
		cin>>s;
		cout<<"\nEnter end node no. :";
		cin>>t;
		cout<<"\nEnter edge value :";
		cin>>dist[s][t];
		cout<<"\nEnter more edges(y/n) :";
		cin>>resp;
	}
	cout<<"\nPersenting adjacency node of graph:\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<" "<<dist[i][j];
		}
		cout<<endl;
	}
	cout<<"\nEnter start node of path :"<<endl;
	cin>>s;
	cout<<"\nEnter end node of path :";
	cin>>t;
	r1.shortest_path(s,t,path);
	return 0;
}
