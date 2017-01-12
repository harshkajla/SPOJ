#include <bits/stdc++.h>
using namespace std;
struct Node
{
	pair<int,int> left;
	pair<int,int> right;
	pair<int,int> best;
}segment[3000002];

Node combine(Node l,Node r)
{
	Node k;
	pair<int,int> pbest;
	pair<int,int> pleft;
	pair<int ,int> pright;
	
	if(l.right.first==r.left.first)
	{
		int count1=l.best.second,count2=r.best.second,count3=l.right.second+r.left.second;
		int maxofall=fmax(count1,fmax(count2,count3));
		if(maxofall==count1)
		{
			pbest.second=count1;
			pbest.first=l.best.first;
			pleft=l.left,pright=r.right;
		}
		else if(maxofall==count2)
		{
			pbest.second=count2;
			pbest.first=r.best.first;
			pleft=l.left,pright=r.right;
		}
		else
		{
			pbest.second=count3;
			pbest.first=l.right.first;
			pleft=l.left,pright=r.right;
			if(l.left.first==l.right.first)
			{
			pleft.first=l.left.first;
			pleft.second=l.left.second+r.left.second;
			}
			if(r.left.first==r.right.first)
			{
			pright.first=r.right.first;
			pright.second=l.right.second+r.right.second;
			}
		}
	}
	else
	{
		pleft=l.left;
		pright=r.right;
		if(l.best.second>=r.best.second)
		{
			pbest.first=l.best.first;
			pbest.second=l.best.second;
		}
		else
		{
				pbest.first=r.best.first;
				pbest.second=r.best.second;
		}
	}
	
	k.best=pbest,k.left=pleft,k.right=pright;
	return k;
}
void init(int start,int end,int in)
{
	if(start==end)
	{
		Node k;
		int inp;
		scanf("%d",&inp);
		k.best.first=k.left.first=k.right.first=inp;
		k.left.second=k.right.second=k.best.second=1;
		segment[in]=k;
		return;
	}
	int mid=(start+end)/2;
	init(start,mid,2*in+1);
	init(mid+1,end,2*in+2);
	segment[in]=combine(segment[2*in+1],segment[2*in+2]);
}
Node query(int start,int end,int in,int from,int to)
{
	if(start>=from && end<=to)
	return segment[in];
	int mid=(start+end)/2;
	if(mid>=to)
		return query(start,mid,2*in+1,from,to);
	else if(mid+1<=from)
		return query(mid+1,end,2*in+2,from,to);
	else
		return combine(query(start,mid,2*in+1,from,to),query(mid+1,end,2*in+2,from,to));
}
int main() {
	// your code goes here
	int num,q,a,b,size;
	
	while(scanf("%d",&size)==1){
        if(size==0)
        	break;
	scanf("%d",&q);
	init(0,size-1,0);
	while(q--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",query(0,size-1,0,a-1,b-1).best.second);
	}
	}
	return 0;
}