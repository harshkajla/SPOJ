#include <bits/stdc++.h>
using namespace std;
int ar[50000];
struct Node
{
	long long sum;
	long long best;
	long long leftsum;
	long long rightsum;
}Tree[200483];

Node combine(Node b,Node c)
{
	Node a;
	a.sum=b.sum+c.sum;
	a.leftsum=fmax(b.leftsum,b.sum+c.leftsum);
	a.rightsum=fmax(c.rightsum,c.sum+b.rightsum);
	a.best=fmax(b.rightsum+c.leftsum,fmax(c.best,b.best));
	return a;
}
void initialize(int index,int start,int end)
{
	if(start==end)
	{
		Tree[index].sum=Tree[index].best=Tree[index].leftsum=Tree[index].rightsum=ar[start];
		return ;
	}
	int mid=(start+end)/2;
	initialize(2*index+1,start,mid);
	initialize(2*index+2,mid+1,end);
	
	Node b=Tree[2*index+1];
	Node c=Tree[2*index+2];
	Tree[index]=combine(b,c);
	 return ;
	 
}	
Node query(int index,int start,int end,int from,int to)
{
	if(from>end || to<start)
	{
		Node a;
		a.sum=INT_MIN;
		a.best=INT_MIN;
		return a;
	}
	if(from<=start && end<=to)
	return Tree[index];
	
	int mid=(start+end)/2;
	Node left=query(2*index +1,start,mid,from,to);
	Node right=query(2*index +2,mid+1,end,from,to);
	if(left.best==INT_MIN)
	return right;
	if(right.best==INT_MIN);
	return left;
	
	return combine(left,right);
}
Node ans(int index, int from, int to, int a, int b) {
    if (from >= a && to <= b)
    {
        return Tree[index];
    }
    int mid = (from+to)/2;
    if (b <= mid) {
        return ans((index<<1)+1, from, mid, a, b);
    }
    if (a > mid) {
        return ans((index<<1) + 2, mid+1,to,a,b);
    }
    Node l = ans((index<<1)+1, from, mid, a, mid);
    Node r = ans((index<<1) + 2, mid+1,to,mid+1,b);
    return combine(l,r);
}
int main() {
	// your code goes here
	int size,q;

	scanf("%d",&size);
	
	for(int i=0;i<size;i++)
		scanf("%d",&ar[i]);
		
	initialize(0,0,size-1);
	
	scanf("%d",&q);
	int st,end;
	while(q--)
	{
		scanf("%d %d",&st,&end);
		printf("%lld\n",ans(0,0,size-1,st-1,end-1).best);
	}
	return 0;
}