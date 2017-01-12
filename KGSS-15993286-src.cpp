#include <bits/stdc++.h>
using namespace std;
struct Node
{
int max2;
int max;
}ar[350005];
int ar2[100005];
void initialize(int start,int end,int index)
{
	if(start==end)
	{
		ar[index].max2=0;
		ar[index].max=ar2[start];
		return ;
	}
	int mid=(start+end)/2;
	initialize(start,mid,2*index+1);
	initialize(mid+1,end,2*index+2);
	ar[index].max=fmax(ar[2*index+1].max,ar[2*index+2].max);
	if(ar[index].max==ar[2*index+1].max)
		ar[index].max2=fmax(ar[2*index+1].max2,ar[2*index+2].max);	
	else
		ar[index].max2=fmax(ar[2*index+2].max2,ar[2*index+1].max);
		
		return ;
}
Node query(int start,int end ,int index, int from,int to)
{
	Node k;
	if(from>end || to<start)
		{
			k.max=0;
			k.max2=0;
			return k;
		}
	//out of bound 
	if(from<=start && to>=end)
	return ar[index]; 
	int mid=(start+end)/2;
	Node left=query(start,mid,2*index+1,from,to);
	Node right=query(mid+1,end,2*index+2,from,to);
	
	k.max=fmax(left.max,right.max);
	if(k.max==left.max)
	k.max2=fmax(left.max2,right.max);
	else
	k.max2=fmax(left.max,right.max2);
	return k;
}
void update(int start,int end,int index,int x,int val)
{
	if(end<x || start>x)
	 return ;
	if(start==end)
	{
		if(start==x)
		{
			//cout<<"I am here "<<endl;
			 ar2[start]=val;
			 ar[index].max=val;
			 ar[index].max2=0;
			return ;
		}
		else
		return ;
	}
	int mid=(start+end)/2;
	update(start,mid,2*index+1,x,val);
	update(mid+1,end,2*index+2,x,val);
	ar[index].max=fmax(ar[2*index+1].max,ar[2*index+2].max);
	if(ar[index].max==ar[2*index+1].max)
		ar[index].max2=fmax(ar[2*index+1].max2,ar[2*index+2].max);	
	else
		ar[index].max2=fmax(ar[2*index+2].max2,ar[2*index+1].max);
		
		return ;

}
void print()
{
	for(int i=0;i<15;i++)
	cout<<ar[i].max<<" "<<ar[i].max2<<endl;
}
int main() {
	// your code goes here
	int num,t;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&ar2[i]);
	}
	initialize(0,num-1,0);
	scanf("%d",&t);
	char c;
	//print();
	int a,b;
	while(t--)
	{
		cin>>c>>a>>b;
		if(c=='U'){
			//cout<<"Updating :"<<"A["<<a-1<<"]"<<"="<<b<<endl;
			ar2[a-1]=b;
			//	initialize(0,num-1,0);
			update(0,num-1,0,a-1,b);
			//print();
		}
		else
		{
			//cout<<"querying for "<<a-1<<" "<<b-1<<endl;
			Node ret=query(0,num-1,0,a-1,b-1);
			cout<<ret.max+ret.max2<<endl;
		}
	}
	return 0;
}