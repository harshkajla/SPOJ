#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#include<cstdio>
#define gc getchar_unlocked

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
struct activity
{
	int first,second;
};

bool val(struct activity a,struct activity b)
{
	if (a.first == b.first)
		return a.second>b.second;
	return a.first<b.first;
}
activity act[100001];

int main()
	{
	
	int t,i,count,num;
	cin>>t;
	
	while(t--)
	{
	scanint(num);
		count=0;
		for(i=0;i<num;i++)
        {
            scanint(act[i].first);
            scanint(act[i].second);
        }
        sort(act,act+num,val);
        count=1;
        int lowerbound=act[num-1].first;
        for(i=num-2;i>=0;i--)
        {
        	if(lowerbound>=act[i].second)
        	{
			count++;
			lowerbound=act[i].first;
			}
        	
		}
		printf("%d\n",count);
	}	
		
}