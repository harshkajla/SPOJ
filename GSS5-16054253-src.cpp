#include <bits/stdc++.h>
using namespace std;
int ar[10505];
struct Node
{
	long long lb;
	long long rb;
	long long ob;
	long long sum;
}segment[50005];
Node combine(Node a,Node b)
{
	Node k;
	k.sum=a.sum+b.sum;
	k.lb=fmax(a.lb,a.sum+b.lb);
	k.rb=fmax(a.rb+b.sum,b.rb);
	k.ob=fmax(a.ob,fmax(b.ob,a.rb+b.lb));
	return k;
}
void init(int start,int end,int in)
{
	int mid=(start+end)/2;
	if(start==end)
	{
		segment[in].lb=segment[in].rb=segment[in].ob=segment[in].sum=ar[start];
		return ;
	}
	init(start,mid,2*in +1);
	init(mid+1,end,2*in+2);
	
	segment[in]=combine(segment[2*in+1],segment[2*in+2]);
}
Node query_node(int start,int end,int in,int from,int to)
{
	if(to<start || from>end || from>to)
	{
		Node k;
		k.ob=k.lb=k.rb=k.sum=0;
		return k;
	}
	if(start>=from && end<=to)
	return segment[in];
	
	int mid=(start+end)/2;
	if(mid>=to)
	return query_node(start,mid,2*in + 1,from,to);
	if(mid+1<=from)
	return query_node(mid+1,end,2*in + 2,from,to);
	
	Node left=query_node(start,mid,2*in + 1,from,to);
	Node right=query_node(mid+1,end,2*in + 2,from,to);
	
	return combine(left,right);
}
long long query(int start,int end,int from,int to,int num)
{
	if(end<from)
	{
		//completely disjoint 
		Node starttoend=query_node(0,num-1,0,start,end);
		Node endtofrom=query_node(0,num-1,0,end+1,from-1);
		Node fromtoto=query_node(0,num-1,0,from,to);

		return starttoend.rb+endtofrom.sum+fromtoto.lb;
	}
	else
	{
		
		Node x1x2=query_node(0,num-1,0,start,from-1);
		 Node x2y1=query_node(0,num-1,0,from,end);
		 Node x2y2=query_node(0,num-1,0,from,to);
		 Node y1y2=query_node(0,num-1,0,end+1,to);
		 return fmax(x2y1.ob,fmax(x1x2.rb+x2y2.lb,x2y1.rb+y1y2.lb));
	}
	
}
int main() {
	// your code goes here
	int t,num,Q,m,n,p,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		for(int i=0;i<num;i++)
			scanf("%d",&ar[i]);
			
			init(0,num-1,0);
			
			scanf("%d",&Q);
			while(Q--)
			{
				scanf("%d%d%d%d",&m,&n,&p,&q);
				printf("%lld\n",query(m-1,n-1,p-1,q-1,num));
			}
	}
	return 0;
}