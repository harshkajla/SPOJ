#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int open;
	int close;
	
}segment[95000];
Node combine(Node l, Node r) {
        Node k;
        int mi = min(l.open, r.close);
        k.open = l.open - mi + r.open;
        k.close = l.close + r.close - mi;
        return k;
    }
void init(int start,int end,int in,string &s)
{
	if(start==end)
	{
		Node k;
		if(s[start]==')')
		{
			k.open=0;
			k.close=1;
		}
		else
		{
			k.open=1;
			k.close=0;
		}
		segment[in]=k;
		return ;
	}
	int mid=(start+end)/2;
	init(start,mid,2*in+1,s);
	init(mid+1,end,2*in+2,s);
	segment[in]=combine(segment[2*in+1],segment[2*in+2]);
}	

void update(int in,int start,int end,int x)
{

	if(end<x || start>x)
	return ;
	
	if(start<=x && end>=x)
	{
		if(start==end)
		{
		Node k;
		if(segment[in].open==1 && segment[in].close==0)
		{
			k.open=0;
			k.close=1;
		}
		else
		{
			k.open=1;
			k.close=0;
		}
		segment[in]=k;
		return ;
		}
	}
		int mid=(start+end)/2;
        update(2*in+1,start,mid,x);
        update(2*in+2,mid+1,end,x);
    	segment[in]=combine(segment[2*in+1],segment[2*in+2]);
}
int main() {
	// your code goes here
	int Q,state;
string s;
int count=1,num;
int t=10;
Node ts;
ts.open=0;
ts.close=0;
while(t--)
{
	scanf("%d",&num);
	cin>>s;	
	scanf("%d",&Q);
	init(0,num-1,0,s);
	printf("Test %d:\n",count);
	count++;
	while(Q--)
	{
		scanf("%d",&state);
		if(state==0)
		{
			if(segment[0].open==0 && segment[0].close==0)
				printf("YES\n");
			else
			printf("NO\n");
		}
		else
		update(0,0,num-1,state-1);
	}
	memset(segment,0,sizeof(segment));
}	
	return 0;
}