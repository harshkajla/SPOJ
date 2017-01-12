#include <bits/stdc++.h>
using namespace std;
struct Node
{
pair<int,int> l;
pair<int,int> r;
pair<int,int> m;

}Tree[3000001];
Node combine(Node a,Node b)
{
	Node res;
	if(a.l.first==b.r.first)
	{
		// Managing the case since array is sorted like majority in first left is same as majority in second right 
        res.m.first=res.l.first=res.r.first=a.l.first;
        res.m.second=res.l.second=res.r.second=a.l.second+b.r.second;
    }
    else{
        // Update res.l, res.r
        res.l=a.l;
        res.r=b.r;
        if(a.l.first==b.l.first){                       
            res.l.second=a.l.second+b.l.second;
        }
        if(a.r.first==b.r.first){                       
            res.r.second=a.r.second+b.r.second;
        }
 
        // Update res.M
        if(a.m.second>b.m.second)
        res.m=a.m;
        else
        res.m=b.m;
 
        if(a.r.first==b.l.first){                       
            int temp=a.r.second+b.l.second;
            if(temp>res.m.second){
                res.m.first=a.r.first;
                res.m.second=temp;
            }
        }
    }
    return res;
}
int ar[100001];
void initialize(int index,int start,int end)
{
	if(start>end)
	return ;
	if(start==end)
	{
	Tree[index].l=make_pair(ar[start],1);
	Tree[index].r=make_pair(ar[start],1);
	Tree[index].m=make_pair(ar[start],1);
	return ;
	}
	initialize(2*index+1,start,(start+end)/2);
	initialize(2*index+2,(start+end)/2 +1,end);
	// Merging two child to 
	Node a=Tree[2*index+1];
	Node b=Tree[2*index+2];
	Tree[index]=combine(a,b);
	
	
}
Node query(int index,int start,int end,int from,int to)
{
	if(start>to || end<from)
	{
		Node t;
		t.l.second=t.r.second=t.m.second=0;
		return t;
	}
	if(start>=from && end<=to)
	return Tree[index];
	
	Node left=query(2*index+1,start,(start+end)/2,from,to);
	Node right=query(2*index+2,(start+end)/2 +1,end,from,to);
	if(left.l.second==0)
	return right;
	if(right.l.second==0)
	return left;
	
	return combine(left,right);
	
}
int main() {
	
	int q,size,i,j;
	int n;
	 while(scanf("%d",&size)==1){
        if(size==0)
        	break;
		cin>>q;
		for(int i=0;i<size;i++)
			scanf("%d",&ar[i]);
		initialize(0,0,size-1);
		while(q--)
		{
		scanf("%d %d",&i,&j);
		printf("%d\n",query(0,0,size-1,i-1,j-1).m.second);
		}
}

	return 0;
}