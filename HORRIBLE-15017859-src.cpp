#include <bits/stdc++.h>
using namespace std;
int ar[100003];
long long Tree[300483];
long long lazy[300483];
void initialize(int index,int start,int end)
{
	if(start>end)
	return ;
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

long long query2(int index,int start,int end,int from,int to)
{
		if(end<from || start>to|| start>end)
	return 0;
		if(lazy[index]!=0)
		{
		Tree[index]+=lazy[index]*(end-start+1);
		if(start!=end){
		lazy[2*index+1]+=lazy[index];
		lazy[2*index+2]+=lazy[index];
		}
		lazy[index]=0;
		}
	if(from<=start && end<=to)
	{
	return Tree[index];
	}
	
	int mid=(start+end)/2;
	
	long long left=query2(2*index+1,start,mid,from,to);
	long long right=query2(2*index+2,mid+1,end,from,to);

	return left+right;
}

void update2(int index,int start,int end,long long p,int x,int y)
{
	if(start>end)
	return ;
	if(lazy[index]!=0)
	{
		Tree[index]+=lazy[index]*(end-start+1);
		if(start!=end){
		lazy[2*index+1]+=lazy[index];
		lazy[2*index+2]+=lazy[index];
		}
		lazy[index]=0;
	}
	if(end<x || start>y)
	return ;
	
	if(start>=x && end<=y)
	{
		Tree[index]+=p*(end-start+1);
		if(start!=end){
		lazy[2*index+1]+=p;
		lazy[2*index+2]+=p;
		}
		return ;
	}
	
	int mid=(start+end)/2;
	
        	update2(2*index+1,start,mid,p,x,y);

         update2(2*index+2,mid+1,end,p,x,y);
    	Tree[index]=Tree[2*index+1]+Tree[2*index+2];
}
void call()
{
	for(int i=0;i<15;i++)
	cout<<Tree[i]<<" ";
}
int main() {
	// your code goes here
	int size,q,flag,p;

int t;
scanf("%d",&t);
while(t--)
{
	scanf("%d %d",&size,&q);
	
	 initialize(0,0,size-1);
	int st,end;
	while(q--)
	{
		// call();
		 //cout<<endl;
		
		scanf("%d",&flag);
		if(flag==0)
		cin>>st>>end>>p;
		else
		cin>>st>>end;
		if(flag==1)
		{
		printf("%lld\n",query2(0,0,size-1,st-1,end-1));
		}
		else
		update2(0,0,size-1,p,st-1,end-1);
	}
}	
	return 0;
}