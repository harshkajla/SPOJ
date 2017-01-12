#include <bits/stdc++.h>
using namespace std;
int ar[55005];
struct Node
{
	long long lb;
	long long rb;
	long long ob;
	long long sum;
}segment[200005];
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
Node query(int start,int end,int in,int from,int to)
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
	return query(start,mid,2*in + 1,from,to);
	if(mid+1<=from)
	return query(mid+1,end,2*in + 2,from,to);
	
	Node left=query(start,mid,2*in + 1,from,to);
	Node right=query(mid+1,end,2*in + 2,from,to);
	
	return combine(left,right);
}
int main() {
	// your code goes here
	int num,t,a,b;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	scanf("%d",&ar[i]);
	scanf("%d",&t);
	init(0,num-1,0);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		Node out=query(0,num-1,0,a-1,b-1);
		printf("%lld\n",out.ob);
	}
	return 0;
}