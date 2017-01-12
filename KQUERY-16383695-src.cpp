#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
using namespace std;
void scanint( int &x )
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        neg=1;
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if( neg )
        x=-x;
} 
 
struct node
{
	int val;
	int in;
}ar[30005];

struct query_node
{
	int i,j,k,in;	
}qry[2*100005];
int segment[6*100005];
int ans[2*100005];
int cmp1(query_node a,query_node b)
{
	return a.k<b.k ?1:0;
}
int cmp2(node a,node b)
{
	return a.val<b.val ? 1:0;
}
void init(int start,int end,int in)
{
	if(start==end)
	{
		segment[in]=1;
		return ;
	}
	int mid=(start+end)/2;
	init(start,mid,2*in+1);
	init(mid+1,end,2*in+2);
	segment[in]=segment[2*in+1]+segment[2*in+2];
}
void update(int start,int end,int in,int i)
{
	if(start>i || end<i)
	return ;
	if(start==end)
	{
		segment[in]=0;
		return ;
	}
	int mid=(start+end)/2;
	update(start,mid,2*in+1,i);
	update(mid+1,end,2*in+2,i);
	segment[in]=segment[2*in+1]+segment[2*in+2];
}
int sum(int start,int end,int in,int from,int to)
{
	if(from>end || start>to)
	return 0;
	if(start>=from && end<=to)
	return segment[in];
	int mid=(start+end)/2;
	return sum(start,mid,2*in+1,from,to)+sum(mid+1,end,2*in+2,from,to);
}
int main() 
{
	int num,query;
	// cin>>num;
	scanint(num);
	for(int i=0;i<num;i++)
	{
			cin>>ar[i].val;
			ar[i].in=i;
	}
	// cin>>query;
	scanint(query);
	for(int i=0;i<query;i++)
	{
		// cin>>qry[i].i>>qry[i].j>>qry[i].k;
		scanint(qry[i].i);
		scanint(qry[i].j);
		scanint(qry[i].k);
		// scanf("%d%d%d",&qry[i].i,&qry[i].j,&qry[i].k);
		qry[i].i--;qry[i].j--;
		qry[i].in=i;
	}
	sort(ar,ar+num,cmp2);
	sort(qry,qry+query,cmp1);
	init(0,num-1,0);
	
	int curr=0;
	for(int i=0;i<query;i++)
	{
		while(curr<num && ar[curr].val <= qry[i].k )
		{
			update(0,num-1,0,ar[curr].in);
			curr++;
		}
		ans[qry[i].in]=sum(0,num-1,0,qry[i].i,qry[i].j);
	}
	for(int i=0;i<query;i++)  printf("%d\n",ans[i]);
	// cout<<ans[i]<<"\n";
	return 0;
}