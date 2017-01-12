#include <bits/stdc++.h>
using namespace std;
int ar[50005];
struct Node
{
	long long lb;
	long long rb;
	long long ob;
	long long sum;
}segment[150005];

Node combineNode(Node a,Node b)
{
	Node k;
	k.sum=a.sum+b.sum;
	k.ob=fmax(a.ob,fmax(b.ob,a.rb+b.lb));
	k.lb=a.lb;
	k.rb=b.rb;
	
	k.lb=fmax(k.lb,a.sum+b.lb);
	k.rb=fmax(k.rb,b.sum+a.rb);
	
	return k;
}
void initialize(int start,int end,int index)
{
		if(start==end){
			segment[index].lb=segment[index].sum=segment[index].rb=segment[index].ob=ar[start];			
		return ;
		}
		
	int mid=(start+end)/2;
	initialize(start,mid,2*index+1);
	initialize(mid+1,end,2*index+2);
	segment[index]=combineNode(segment[2*index+1],segment[2*index+2]);
}
void update(int start,int end,int in,int x,int val)
{
	if(start>x || x>end)
	return ;
	if(start==end)
	{
		if(start==x)
		{
			ar[x]=val;
			segment[in].lb=segment[in].sum=segment[in].rb=segment[in].ob=ar[start];	
			return ;
		}
		else
		return ;
	}
	int mid=(start+end)/2;
	update(start,mid,2*in+1,x,val);
	update(mid+1,end,2*in+2,x,val);
	
	segment[in]=combineNode(segment[2*in+1],segment[2*in+2]);
}
Node query(int start,int end,int in,int from,int to)
{
	if(start>to || from>end)
	{
		Node k;
		k.lb=k.rb=k.ob=k.sum=INT_MIN;
		return k;
	}
	int mid=(start+end)/2;
	if(from<=start && end <=to)
	return segment[in];
	if(mid>=to)
	return query(start,mid,2*in+1,from,to);
	if(mid+1<=from)
	return query(mid+1,end,2*in+2,from,to);
	
	Node left=query(start,mid,2*in+1,from,to);
	Node right=query(mid+1,end,2*in+2,from,to);
	return combineNode(left,right);
}
int main() {
	// your code goes here
	int num,t,a,b,type;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	scanf("%d",&ar[i]);
	scanf("%d",&t);
	initialize(0,num-1,0);
	while(t--)
	{
		scanf("%d %d %d",&type,&a,&b);
		if(type==1)
			cout<<query(0,num-1,0,a-1,b-1).ob<<endl;
		else
			update(0,num-1,0,a-1,b);
	}
	return 0;
}