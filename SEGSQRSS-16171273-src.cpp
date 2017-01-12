#include <bits/stdc++.h>
using namespace std;
long long segment[400005],lazy[400005],sum[400005];
long long lazy2[400005];
void init(int start,int end,int in)
{
	if(start==end)
	{
		int k;
		scanf("%d",&k);
		segment[in]=k*k;
		sum[in]=k;
		lazy2[in]=0;
		return ;
	}
	int mid=(start+end)/2;
	init(start,mid,2*in+1);
	init(mid+1,end,2*in+2);
	
	segment[in]=segment[2*in+1]+segment[2*in+2];
	sum[in]=sum[2*in+1]+sum[2*in+2];
	lazy[in]=0;
	lazy2[in]=0;
}
long long query(int start,int end,int in,int from,int to)
{
	if(lazy[in])
	{
		lazy[2*in+1]=lazy[in];
		lazy[2*in+2]=lazy[in];
		sum[in]=lazy[in]*(end-start+1);
		segment[in]=(long long )((lazy[in]*lazy[in])*(end-start+1));
		lazy[in]=0;
	}
	if(lazy2[in])
	{
			sum[in]+=lazy2[in]*(end-start+1);
			segment[in]+=(long long )(lazy2[in]*lazy2[in])*(end-start+1)+(2*lazy2[in]*sum[in]);
			lazy2[2*in+1]+=lazy2[in];
			lazy2[2*in+2]+=lazy2[in];
			lazy2[in]=0;
			
	}
	if(start> to || from > end )
	return 0;
	
	if(start>=from && end<=to)
	return segment[in];
	
	int mid=(start+end)/2;
	int left=query(start,mid,2*in+1,from,to);
	int right=query(mid+1,end,2*in+2,from,to);
	
	segment[in]=segment[2*in+1]+segment[2*in+2];
	sum[in]=sum[2*in+1]+sum[2*in+2];
	return left+right;
	
}
void update(int start,int end,int in,int from,int to,int x)
{
	if(lazy[in])
	{
		sum[in]=lazy[in]*(end-start+1);
		lazy[2*in+1]=lazy[in];
		lazy[2*in+2]=lazy[in];
		segment[in]=(long long )(lazy[in]*lazy[in])*(end-start+1);
		
		lazy[in]=0;
	}
	if(lazy2[in])
	{
			sum[in]+=lazy2[in]*(end-start+1);
			segment[in]+=(long long )(lazy2[in]*lazy2[in])*(end-start+1)+(2*lazy2[in]*sum[in]);
			lazy2[2*in+1]+=lazy2[in];
			lazy2[2*in+2]+=lazy2[in];
			lazy2[in]=0;
			
	}
	if(start> to || from > end )
	return ;
    if(start>=from && end<=to)
	{
			sum[in]=lazy[in]*(end-start+1);
			segment[in]=(long long )(end-start+1)*(x*x);
			lazy[2*in+1]=x;
			lazy[2*in+2]=x;
			
			if(lazy2[in])
			{
				lazy2[in]=0;
			}
			return ;
	}
	// if(start==end)
	// {
	// 	segment[in]=x*x;
	// 	return ;
	// }
	int mid=(start+end)/2;
	
	update(start,mid,2*in+1,from,to,x);
	update(mid+1,end,2*in+2,from,to,x);
	sum[in]=sum[2*in+1]+sum[2*in+2];
	segment[in]=segment[2*in+1]+segment[2*in+2];
}
void add(int start,int end,int in,int from,int to,int x)
{
	if(lazy[in])
	{
		sum[in]=lazy[in]*(end-start+1);
		lazy[2*in+1]=lazy[in];
		lazy[2*in+2]=lazy[in];
		segment[in]=(long long )(lazy[in]*lazy[in])*(end-start+1);
		lazy[in]=0;
	}
	if(lazy2[in])
	{
			sum[in]+=lazy2[in]*(end-start+1);
			segment[in]+=(long long )(lazy2[in]*lazy2[in])*(end-start+1)+(2*lazy2[in]*sum[in]);
			lazy2[2*in+1]=lazy2[in];
			lazy2[2*in+2]=lazy2[in];
			lazy2[in]=0;
		
	}
	int mid=(start+end)/2;
	if(start>to || end< from)
	return ;
	if(start>=from && end<=to)
	{
		sum[in]+=(x*(end-start+1));
		segment[in]+=(long long )(x*x)*(end-start+1)+(2*x*sum[in]);
		// have to return from here to apply logn query
		lazy2[2*in+1]+=x;
		lazy2[2*in+2]+=x;
		return ;
	}
	// if(start==end)
	// {
	// 	segment[in]=(sqrt(segment[in])+x)*(sqrt(segment[in])+x);
	// 	return ;
	// }
	add(start,mid,2*in+1,from,to,x);
	add(mid+1,end,2*in+2,from,to,x);
	sum[in]=sum[2*in+1]+sum[2*in+2];
	segment[in]=segment[2*in+1]+segment[2*in+2];
}
int main() {
	// your code goes here
	int state,t,num,q,a,b,x;
	scanf("%d",&t);
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
			else if(state==2)
			{
			scanf("%d %d",&a,&b);
			printf("%d\n",query(0,num-1,0,a-1,b-1));
			}
			else
			{
				scanf("%d %d %d",&a,&b,&x);
				add(0,num-1,0,a-1,b-1,x);
			}
		}
		//memset(lazy,0,sizeof(lazy));
	}
	return 0;
}