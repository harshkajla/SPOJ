#include <bits/stdc++.h>
using namespace std;
int ar[300000];
int inputar[100002];
void initialize(int start,int end,int index)
{
	if(start==end)
	{
		ar[index]=inputar[end];
		return ;
	}
	initialize(start,(start+end)/2 , 2*index+1);
	initialize(1+ (start+end)/2 ,end, 2*index+2);
	ar[index]=fmin(ar[2*index + 1],ar[2*index +2]);
	return ;
}
int query(int start,int end,int index,int first,int last)
{
	if(last<start || end<first)
	return INT_MAX;
	
	if(first<=start && end<=last)
	return ar[index];
	
	int leftcall=query(start,(start+end)/2, 2*index+1 , first,last);
	int rightcall=query(1+ (start+end)/2,end, 2*index+2 , first,last);
		
		return fmin(leftcall,rightcall);
}
int main() {
	// your code goes here
	int t,a,b,q1,q2,count=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)
		scanf("%d",&inputar[i]);
		initialize(0,a-1,0);
		printf("Scenario #%d:\n",count++);
		while(b--)
		{
			scanf("%d %d",&q1,&q2);
			printf("%d\n",query(0,a-1,0,q1-1,q2-1));
		}
	}
	return 0;
}