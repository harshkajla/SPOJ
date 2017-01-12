#include <bits/stdc++.h>
using namespace std;
struct Node
{
long long left;
long long right;
long long best;
long long sum;
}segment[250000];
int ar[50005];

Node combineNode(Node a,Node b)
{
	Node k;
	k.best=fmax(a.best,b.best);
	k.best=fmax(k.best,a.right+b.left);
	k.left=fmax(a.left,a.sum+b.left);
	k.right=fmax(b.right,b.sum+a.right);
	k.sum=a.sum+b.sum;

	return k;
}
void initialize(int start,int end,int index)
{
	if(start==end)
	{
		segment[index].left=ar[start];
		segment[index].right=ar[start];
		segment[index].best=ar[start];
		segment[index].sum=ar[start];
		return ;
	}
	int mid=(start+end)/2;
	initialize(start,mid,2*index+1);
	initialize(mid+1,end,2*index+2);
	segment[index]=combineNode(segment[2*index+1],segment[2*index+2]);
}
Node query(int start,int end ,int index, int yhase,int yhatak)
{
	if(yhatak<start || yhase>end)
	{
		Node p;
		p.left=p.sum=p.right=p.best=INT_MIN;
		return p;
	}
	if(yhase<=start && yhatak>=end)
		return segment[index];
		
	int mid=(start+end)/2;
	if(mid>=yhatak)
	return query(start,mid,2*index+1,yhase,yhatak);
	if(mid+1<=yhase)
	return query(mid+1,end,2*index+2,yhase,yhatak);
	
	Node left=query(start,mid,2*index+1,yhase,yhatak);;
	Node right=query(mid+1,end,2*index+2,yhase,yhatak);
	
	if(left.best==INT_MIN)
	return right;
	if(right.best==INT_MIN)
	return left;
	return combineNode(left,right);
}
int main() {
	// your code goes here
	int num,t,a,b;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	scanf("%d",&ar[i]);
	scanf("%d",&t);
	initialize(0,num-1,0);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		Node out=query(0,num-1,0,a-1,b-1);
		printf("%lld\n",out.best);
	}
	return 0;
}