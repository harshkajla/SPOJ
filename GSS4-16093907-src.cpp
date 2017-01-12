#include <bits/stdc++.h>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
long long segment[400000];
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
void init(int start,int end,int in)
{
	if(start==end)
	{
		scanf("%lld",&segment[in]);
		return ;
	}
	int mid=(start+end)>>1;
	int leftchild=(in<<1) + 1;
	init(start,mid,leftchild);
	init(mid+1,end,1+leftchild);
	segment[in]=segment[leftchild]+segment[1+leftchild];
}
long long query(int start,int end,int in,int from,int to)
{
	if(start>to || end <from)
	return 0;
	if(start>=from && end<=to)
	return segment[in];

	int mid=(start+end)>>1;
	int leftchild=(in<<1) + 1;
	
	if(mid>=to)
	return query(start,mid,leftchild,from,to);
	if(mid+1<=from)
	return query(mid+1,end,1+leftchild,from,to);
	
	return query(start,mid,leftchild,from,to) + query(mid+1,end,1+leftchild,from,to);
}
void print()
{
	cout<<"Segment Tree : "<<endl;
	for(int i=0;i<=8;i++)
	cout<<segment[i]<<" ";
	cout<<"\nEnd "<<endl;
}
void update(int start,int end,int in,int from,int to)
{
	if(start>to || end <from)
	return ;
	if(start==end)
	{
		//	segment[in]=(long long)sqrt(segment[in]);
			segment[in] = (long long)floor(sqrt((double)segment[in]));
			return ;
	}
	if(segment[in]==(end-start+1))
	return ;
	int mid=(start+end)>>1;
	int leftchild=(in<<1) + 1;
	if(mid>=to)
	update(start,mid,leftchild,from,to);
	else if(mid+1<=from)
	update(mid+1,end,1+leftchild,from,to);
	else
	{
		update(start,mid,leftchild,from,to);
		update(mid+1,end,1+leftchild,from,to);
	}
	segment[in]=segment[leftchild]+segment[1+leftchild];
	return ;
}
int main() {
	int num,Q,state,a,b,count=0;
	while(scanf("%d",&num)!=EOF)
	{
		count++;
		init(0,num-1,0);
		scanint(Q);
		printf("Case #%d:\n",count);
		while(Q--)
		{
			//print();
			scanint(state);
			scanint(a);
			scanint(b);
			//scanf("%d%d%d",&state,&a,&b);
			if(a>b)
			{
				int temp=a;
				a=b;
				b=temp;
			}
			if(state==1)
					printf("%lld\n",query(0,num-1,0,a-1,b-1));
			else
					update(0,num-1,0,a-1,b-1);
		}
		printf("\n");
	//	memset(segment,0,sizeof(segment));
	}
	return 0;
}