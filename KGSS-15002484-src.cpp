#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int max;
	int secondmax;
}Tree[300002];
int ar[100002];
Node compare(Node a,Node b)
{
	Node c;
	if(ar[a.max]>ar[b.max])
	{
		c.max=a.max;
			if(a.secondmax==-1)
		c.secondmax=b.max;
		else
			c.secondmax=ar[b.max]>ar[a.secondmax]?b.max:a.secondmax;
	}
	else
	{
		c.max=b.max;
		if(b.secondmax==-1)
		c.secondmax=a.max;
		else
			c.secondmax=ar[a.max]>ar[b.secondmax]?a.max:b.secondmax;
		
	}
	return c;
}

void initialize(int index,int start,int end)
{
	if(start==end)
	{
		Tree[index].max=start;
		Tree[index].secondmax=-1;
		return ;
	}
	int mid=(start+end)/2;
	initialize(2*index+1,start,mid);
	initialize(2*index+2,mid+1,end);
	Tree[index]=compare(Tree[2*index+1],Tree[2*index+2]);
}
Node query(int index,int start,int end,int from,int to)
{
	if(from<=start && end <=to)
	return Tree[index];
	int mid=(start+end)/2;
	if(mid<from)
	{
		return query(2*index+2,mid+1,end,from,to);
	}
	if(mid>=to)
	{
		return query(2*index+1,start,mid,from,to);
	}
	
	Node left=query(2*index+1,start,mid,from,to);
	Node right=query(2*index+2,mid+1,end,from,to);
	
	return compare(left,right);
}
void update(int index,int start,int end,int i,int x)
{
	if(start==end)
	{
		if(start!=i)
		return ;
		ar[i]=x;
		Tree[index].max=i;
		return ;
	}
	int mid=(start+end)/2;
	if(i<=mid)
	{
		update(2*index+1,start,mid,i,x);
		Tree[index]=compare(Tree[2*index+1],Tree[2*index+2]);
	}
	else
	{
		update(2*index+2,mid+1,end,i,x);
		Tree[index]=compare(Tree[2*index+1],Tree[2*index+2]);
	}
}
int main() {
	int t,size,q,st,end,count=1;
		char ch='a';
		scanf("%d",&size);
		
		for(int i=0;i<size;i++)
		scanf("%d",&ar[i]);
		initialize(0,0,size-1);
		scanf("%d",&q);
		//cout<<"queries :"<<q<<endl;
		while(q--)
		{
			cin>>ch>>st>>end;
			if(ch=='Q')
			{
				Node k=query(0,0,size-1,st-1,end-1);
				printf("%lld\n",ar[k.max]+ar[k.secondmax]);
			}
			else if(ch=='U')
				update(0,0,size-1,st-1,end);
				
		}
		
	
	// your code goes here
	return 0;
}