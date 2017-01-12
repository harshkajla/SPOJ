#include <bits/stdc++.h>
using namespace std;
long long segment[400000];
long long lazy[400000];
long long query(int start,int end,int in,int from,int to)
{
	int leftchild=(in<<1) + 1;
	int mid=(start+end)>>1;
	if(lazy[in])
	{
		if(start!=end)
		{
		lazy[leftchild]+=lazy[in];
		lazy[1+leftchild]+=lazy[in];
		}
		segment[in]+=((end-start+1)*lazy[in]);
		lazy[in]=0;
	}
	if(start>to || end <from)
	return 0;
	if(start>=from && end<=to)
	return segment[in];

	long long left=query(start,mid,leftchild,from,to) ;
	long long right= query(mid+1,end,1+leftchild,from,to);

	return left+right;
}
void update(int start,int end,int in,int from,int to,long long sum)
{
	int leftchild=(in<<1) + 1;
	int mid=(start+end)>>1;
	if(lazy[in])
	{
		if(start!=end)
		{
		lazy[leftchild]+=lazy[in];
		lazy[1+leftchild]+=lazy[in];
		}
		segment[in]+=((end-start+1)*lazy[in]);
		lazy[in]=0;
	}
	
	if(start>to || end <from)
	return ;
	if(start>=from && end<=to)
	{
		segment[in]+=((end-start+1)*sum);
		if(start!=end){
		lazy[leftchild]+=sum;
		lazy[1+leftchild]+=sum;
		}
		return ;
	}
	update(start,mid,leftchild,from,to,sum);
	update(mid+1,end,1+leftchild,from,to,sum);
	segment[in]=segment[leftchild]+segment[1+leftchild];
	return ;
}
int main() {
	int t,num,Q,state,a,b,size;
	long long s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&size,&Q);
		while(Q--)
		{
			scanf("%d",&state);
			if(state==0)
			{
				scanf("%d %d %lld",&a,&b,&s);
				update(0,size-1,0,a-1,b-1,s);
			}
			else
			{
				scanf("%d %d",&a,&b);
				printf("%lld\n",query(0,size-1,0,a-1,b-1));
			}
		}
		memset(lazy,0,sizeof(lazy));
		memset(segment,0,sizeof(segment));
	}
	return 0;
}