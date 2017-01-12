#include <bits/stdc++.h>
using namespace std;
pair<int,int> ar[40007];
set<int> out;
int segment[1000005];
int    lazy[1000005];
int s[1000005];
int binarysearch(int m,int n)
{
 
    int l,u,mid;
    int c=0;
l=0,u=n-1;
    while(l<=u)
        {
         mid=(l+u)/2;
         if(m==s[mid])
            {
             c=1;
             break;
         }
         else if(m<s[mid])
            {
             u=mid-1;
         }
         else
             l=mid+1;
    }
    return mid;
}
void update(int start,int end,int in,int from,int to,int poster)
{
	if(lazy[in])
	{
		segment[in]=lazy[in];
		if(start!=end)
		{
			lazy[2*in+1]=lazy[in];
			lazy[2*in+2]=lazy[in];
		}
		lazy[in]=0;
	}
	if(start>to || from>end)
	return ;
	
	if(start>=from && end<=to)
	{
		segment[in]=poster;
		if(start!=end){
		lazy[2*in+1]=poster;
		lazy[2*in+2]=poster;
		}
		return ;
	}
	int mid=(start+end)/2;
	update(start,mid,2*in+1,from,to,poster);
	update(mid+1,end,2*in+2,from,to,poster);
}
void count(int start,int end,int in)
{
	if(lazy[in])
	{
		segment[in]=lazy[in];
		if(start!=end)
		{
			lazy[2*in+1]=lazy[in];
			lazy[2*in+2]=lazy[in];
		}
		lazy[in]=0;
	}
	if(start==end)
	{
		if(segment[in])
		out.insert(segment[in]);
		// cout<<segment[in]<<endl;
		return ;
	}
	int mid=(start+end)/2;
	count(start,mid,2*in+1);
	count(mid+1,end,2*in+2);
}
int main() {
	// your code goes here
	int num,t,a,b;
	scanf("%d",&t);
	set<int> ::iterator it;
	pair<int,int>p;
	while(t--)
	{
		scanf("%d",&num);
		int idx=0;
		for(int i=0;i<num;i++)
		{	
			scanf("%d%d",&a,&b);
			p=make_pair(a,b);
			ar[i]=p;
			s[idx++]=a;
			s[idx++]=a-1;
			s[idx++]=a+1;
			s[idx++]=b;
			s[idx++]=b+1;
			s[idx++]=b-1;
		}
		int size=0;
		sort(s,s+idx);
		size=unique(s,s+idx)-s;
		int low=0,high=0;
		for(int i=0;i<num;i++)
		{
			// low=lower_bound(s,s+idx,ar[i].first)-s;
			low=binarysearch(ar[i].first,size);
			high=binarysearch(ar[i].second,size);
			// cout<<low<<" "<<high<<endl;
			update(0,size-1,0,low,high,i+1);
		}
		count(0,size-1,0);
		printf("%d\n",out.size());
		out.clear();
		memset(lazy,0,sizeof(lazy));
		memset(segment,0,sizeof(segment));
		memset(s,0,sizeof(s));
	}
	
	return 0;
}