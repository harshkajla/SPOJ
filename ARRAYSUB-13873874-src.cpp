#include<iostream>
#include<cstdio>
using namespace std;
int nos[100000],tree[500000];

void initialize(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=start;
		return;
	}
	
	initialize(2*node+1,start,(start+end)/2);
	initialize(2*node+2,(start+end)/2 +1,end);
	
	if(nos[tree[2*node+1]]<nos[tree[2*node+2]])
	tree[node]=tree[2*node+2];
	else
	tree[node]=tree[2*node+1];	
}
int maxInRange(int node,int start,int end,int i,int j)
{
	if(i>end||j<start) 
	return -1;
	if(start>=i && end<=j) 
		return tree[node];	
	
	int k1=maxInRange(2*node+1,start,(start+end)/2 ,i,j);
	int k2=maxInRange(2*node+2,(start+end)/2 +1,end,i,j);
	if(k1==-1)
	return k2;
	if(k2==-1)
	return k1;
	
	if(nos[k1]<nos[k2])
		return k2;
	else
	return k1;
		
}
int main()
{
	int t,size,count=0,queries,a,b;
	scanf("%d",&size);

		for(int i=0;i<size;i++)
		scanf("%d",&nos[i]);
		int k;
		cin>>k;
		initialize(0,0,size-1);
		for(int i=0;i<=size-k;i++)
		printf("%d ",nos[maxInRange(0,0,size-1,i,i+k-1)]);
		
	
	return 0;
}