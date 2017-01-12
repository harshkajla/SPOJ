#include <bits/stdc++.h>
using namespace std;
int Tree[3*100002];
int ar[100002];
void initialize(int index,int start,int end)
{
	if(start==end)
	{
		Tree[index]=start;
		return ;
	}
	int mid=(start+end)/2;
	initialize(2*index+1,start,mid);
	initialize(2*index+2,mid+1,end);
	Tree[index]=ar[Tree[2*index+1]]>ar[Tree[2*index+2]]?Tree[2*index+2]:Tree[2*index+1];
}
int query(int index,int start,int end,int from,int to)
{
	if(from>end || to<start)
	return -1;
	if(from<=start && end <=to)
	return Tree[index];
	int mid=(start+end)/2;
	int left=query(2*index+1,start,mid,from,to);
	int right=query(2*index+2,mid+1,end,from,to);
	if(left==-1)
	return right;
	if(right==-1)
	return left;
	
	return ar[left]>ar[right]?right:left;
}
int main() {
	int t,size,q,st,end,count=1;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d",&size,&q);
		for(int i=0;i<size;i++)
		scanf("%d",&ar[i]);
		printf("Scenario #%d:\n",count);
		count++;
			initialize(0,0,size-1);
		while(q--)
		{
			scanf("%d %d",&st ,&end);
			printf("%d\n",ar[query(0,0,size-1,st-1,end-1)]);
		}
		
	}
	// your code goes here
	return 0;
}