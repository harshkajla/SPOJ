#include <bits/stdc++.h>
#define inf INT_MIN
using namespace std;
int ar[100003];
long long Tree[300483];
long long lazy[300483];
void initialize(int index,int start,int end)
{
	if(start==end)
	{
		Tree[index]=0;
		lazy[index]=0;
		return ;
	}
	int mid=(start+end)/2;
	initialize(2*index+1,start,mid);
	initialize(2*index+2,mid+1,end);
	lazy[index]=0;
	Tree[index]=Tree[2*index+1]+Tree[2*index+2];
}	
long long query(int index,int start,int end,int from,int to)
{
	if(end<from|| start>to)
	return 0;
	int mid=(start+end)/2;

		if(lazy[index]!=0)
		{
			Tree[index]=end-start+1-Tree[index];
			if(start!=end)
			{
				lazy[2*index+1]=!lazy[2*index+1];
				lazy[2*index+2]=!lazy[2*index+2];
			}
			lazy[index]=0;
		}
	if(from<=start && end<=to)
	return Tree[index];
	
	long long  left=query(2*index+1,start,mid,from,to);
	long long right=query(2*index+2,mid+1,end,from,to);
	
	return left+right;
}
void update(int index,int start,int end,int x,int y)
{
	int mid=(start+end)/2;
	int flag=0;
	if(lazy[index]!=0)
		{
			Tree[index]=end-start+1-Tree[index];
			if(start!=end)
			{
				lazy[2*index+1]=!lazy[2*index+1];
				lazy[2*index+2]=!lazy[2*index+2];
			}
			lazy[index]=0;
		}
	if(x>end || y<start)
		return ;
	if(x<=start && y>=end)
	{
		Tree[index]=end-start+1-Tree[index];
		if(start!=end)
		{
			lazy[2*index+1]=!lazy[2*index+1];
			lazy[2*index+2]=!lazy[2*index+2];
		}
		return ;
	}
	
	update(2*index+1,start,mid,x,y);
	update(2*index+2,mid+1,end,x,y);
	
	Tree[index]=Tree[2*index+1]+Tree[2*index+2];
}
void call()
{
	for(int i=0;i<7;i++)
				cout<<Tree[i]<<" ";
				cout<<endl;
}	
int main() {
	// your code goes here
	int size,q,flag,a,b;
	scanf("%d %d",&size,&q);
	//initialize(0,0,size-1);
	while(q--)
	{
		scanf("%d %d %d",&flag,&a,&b);
		if(flag==0)
			update(0,0,size-1,a-1,b-1);
		else
			printf("%d\n",query(0,0,size-1,a-1,b-1));
	}
	return 0;
}