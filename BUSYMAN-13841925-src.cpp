#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
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
		cin>>num;
		count=0;
		for(i=0;i<num;i++)
        {
            scanf("%d %d",&act[i].first,&act[i].second);
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