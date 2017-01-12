#include <bits/stdc++.h>
using namespace std;
struct Node
{
int zero;
int one;
int two;
int three;
}segment[3000000];
int lazy[3000000];
Node combine(Node a,Node b)
{
	Node k;
	k.zero=a.zero+b.zero;
	k.one=a.one+b.one;
	k.two=a.two+b.two;
	k.three=a.three+b.three;
	return k;
}
	void init(int start,int end,int in)
	{
		if(start==end)
		{
			segment[in].zero=1;
			segment[in].one=0;
			segment[in].two=0;
			segment[in].three=0;
			return ;
		}
		int mid=(start+end)/2;
		init(start,mid,2*in+1);
		init(mid+1,end,2*in+2);
		
		segment[in]=combine(segment[2*in+1],segment[2*in+2]);
	}
	Node change(Node k,int c)
	{
		Node t;
		if(c==1)
		{
			t.zero=0;
			t.one=k.zero+k.three;
			t.two=k.one;
			t.three=k.two;
		}
		else if(c==2)
		{
			t.zero=0;
			t.one=k.two;
			t.two=k.three+k.zero;
			t.three=k.one;
		}
		else 
		{
			return k;
		}
		return t;
	}
	int query(int start,int end,int in,int from,int to)
	{
		if(lazy[in])
		{
			segment[in]=change(segment[in],lazy[in]%3);
			
			lazy[2*in+1]+=lazy[in];
			lazy[2*in+2]+=lazy[in];
			lazy[in]=0;
			
		}
		if(start>=from && end<=to)
			return segment[in].zero + segment[in].three;
			
		if(start>to || end <from)
		return 0;
		
		int mid=(start+end)/2;
		
		int left=query(start, mid,2*in +1,from,to);
		int right=query(mid+1, end,2*in +2,from, to);
		
		return left+right;
	}
	
	void update(int start,int end,int in,int from,int to)
	{
		if(lazy[in])
		{
			segment[in]=change(segment[in],lazy[in]%3);
			
			lazy[2*in+1]+=lazy[in];
			lazy[2*in+2]+=lazy[in];
			lazy[in]=0;
			
		}
		if(start>to || end <from)
		return;
		if(start>=from && end<=to)
		{
			Node t=segment[in];
			segment[in].zero=0;
			segment[in].one=t.zero+t.three;
			segment[in].two=t.one;
			segment[in].three=t.two;
			lazy[2*in+1]+=1;
			lazy[2*in+2]+=1;
			return ;
		}
		// if(start==end)
		// {
		// 	if(segment[in].one)
		// 	{
		// 		segment[in].one=0;
		// 		segment[in].two=1;
		// 	}
		// 	else if(segment[in].two)
		// 	{
		// 		segment[in].two=0;
		// 		segment[in].three=1;
		// 	}
		// 	else if(segment[in].zero)
		// 	{
		// 		segment[in].zero=0;
		// 		segment[in].one=1;
		// 	}
		// 	else if(segment[in].three)
		// 	{
		// 		segment[in].one=1;
		// 		segment[in].three=0;
		// 	}
		// 	else
		// 	segment[in].one=1;
			
		// 	return ;	
		// }
		int mid=(start+end)/2;
		update(start,mid,2*in+1,from,to);
		update(mid+1,end,2*in+2,from,to);
		
		segment[in]=combine(segment[2*in+1],segment[2*in+2]);
	}
	
int main() {
	int num,t,state,a,b;
	scanf("%d %d",&num,&t);
	init(0,num-1,0);
	while(t--)
	{
		scanf("%d %d %d",&state,&a,&b);
		//cout<<"Received Input : "<<a<<" "<<b<<endl;
		if(state)
			printf("%d\n",query(0,num-1,0,a,b));
		else
			update(0,num-1,0,a,b);
	}
	return 0;
}