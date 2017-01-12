#include <bits/stdc++.h>
using namespace std;
int segment[400005],lazy[400005];
int prime[2500005];
void sieve()
{
	for(int i=2;i<2500005;i++)
	prime[i]=1;
	prime[1]=0;
	for(int i=2;i*i<=2500005;i++)
	{
		if(prime[i])
		{
			for(int j=2*i;j<2500005;j+=i)
				prime[j]=0;			
		}
	}
}
void init(int start,int end,int in)
{
	if(start==end)
	{
		int k;
		lazy[in]=0;
		scanf("%d",&k);
		segment[in]=(int)prime[k];
		return ;
	}
	int mid=(start+end)/2;
	init(start,mid,2*in+1);
	init(mid+1,end,2*in+2);
	segment[in]=segment[2*in+1]+segment[2*in+2];
	lazy[in]=0;
}
int query(int start,int end,int in,int from,int to)
{
	if(lazy[in])
	{
		lazy[2*in+1]=lazy[in];
		lazy[2*in+2]=lazy[in];
		if(lazy[in]==1)
			segment[in]=end-start+1;
		else
			segment[in]=0;
		
		lazy[in]=0;
	}
	if(start> to || from > end )
	return 0;
	if(start>=from && end<=to)
	return segment[in];
	int mid=(start+end)/2;
	int left=query(start,mid,2*in+1,from,to);
	int right=query(mid+1,end,2*in+2,from,to);
	
	segment[in]=segment[2*in+1]+segment[2*in+2];
	
	return left+right;
	
}
void update(int start,int end,int in,int from,int to,int x)
{
	if(lazy[in])
	{
		lazy[2*in+1]=lazy[in];
		lazy[2*in+2]=lazy[in];
		if(lazy[in]==1)
			segment[in]=end-start+1;
		else
			segment[in]=0;
		
		lazy[in]=0;
	}
	if(start> to || from > end )
	return ;
    if(start>=from && end<=to)
	{
		if(prime[x])
		{
		segment[in]=(end-start+1);
		lazy[2*in+1]=1;
		lazy[2*in+2]=1;
		}
		else
		{
			segment[in]=0;
			lazy[2*in+1]=-1;
			lazy[2*in+2]=-1;
		}
		return ;
	}
	int mid=(start+end)/2;
	
	update(start,mid,2*in+1,from,to,x);
	update(mid+1,end,2*in+2,from,to,x);
	
	segment[in]=segment[2*in+1]+segment[2*in+2];
}
int main() {
	// your code goes here
	int state,t,num,q,a,b,x;
	scanf("%d",&t);
	//memset(prime,1,sizeof(prime));
	sieve();
	int count=0;
	while(t--)
	{
		scanf("%d %d",&num,&q);
		count++;
		init(0,num-1,0);
		printf("Case %d:\n",count);
		while(q--)
		{
		scanf("%d",&state);
			if(state==0)
			{
				scanf("%d %d %d",&a,&b,&x);
				update(0,num-1,0,a-1,b-1,x);
			}
			else
			{
			scanf("%d %d",&a,&b);
			printf("%d\n",query(0,num-1,0,a-1,b-1));
			}
		}
		//memset(lazy,0,sizeof(lazy));
	}
	return 0;
}