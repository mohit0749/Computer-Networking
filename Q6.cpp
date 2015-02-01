#include<iostream>
using namespace std;
struct node
{
	int dist[5];
	int from[5];
}rt[5];
int main()
{
	int costmat[5][5];
	int nodes,i,j,k;
	cout<<"\nEnter the no. of the nodes: ";
	cin>>nodes;
	cout<<"\nEnter the cost matrix";
	for(i=0;i<nodes;i++)
	{
		cout<<"\nEnter the distance from router "<<i+1<<" : ";
		for(j=0;j<nodes;j++)
		{
			cin>>costmat[i][j];
			costmat[i][i]=0;
			rt[i].dist[j]=costmat[i][j];
			rt[i].from[j]=j;
		}
	}
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			for(k=0;k<nodes;k++)
			{
				if(rt[i].dist[j]>rt[i].dist[k]+rt[j].dist[k])
				{
					rt[i].dist[j]=rt[i].dist[k]+rt[j].dist[k];
					rt[i].from[j]=k;
				}
			}
		}
	}
	for(i=0;i<nodes;i++)
	{
		cout<<"\nFor router"<<i+1;
		for(j=0;j<nodes;j++)
		{
			cout<<"\nNode "<<j+1<<" Via "<<rt[i].from[j]+1<<" Distance : "<<rt[i].dist[j];
		}
		cout<<"\n";
	}
	return 0;
}
