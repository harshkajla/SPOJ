#include <bits/stdc++.h>
using namespace std;

int segment[300000];
bool lazy[300000];
int query(int start,int end,int in,int from,int to)
{
	if(lazy[in])
	{
		segment[in]=end-start-segment[in]+1;
		lazy[in]=0;
		if(start!=end){
		lazy[2*in+1]=!lazy[2*in+1];
		lazy[2*in+2]=!lazy[2*in+2];
		}
	}
	if(start>=from && end<=to)
	return segment[in];
	
	if(start >to || end<from )
	return 0;
	int mid=(start+end)/2;
	return query(start,mid,2*in+1,from,to)+query(mid+1,end,2*in+2,from,to);
}
void update(int start,int end,int in,int from,int to)
{
	if(lazy[in]==1)
	{
		segment[in]=end-start-segment[in]+1;
		lazy[in]=0;
		if(start!=end){
		lazy[2*in+1]=!lazy[2*in+1];
		lazy[2*in+2]=!lazy[2*in+2];
		}
	}
	if(start >to || end<from )
	return;

	if(start>=from && end <=to)
	{
		
		segment[in]=end-start-segment[in]+1;
		if(start!=end){
		lazy[2*in+1]=!lazy[2*in+1];
		lazy[2*in+2]=!lazy[2*in+2];
		}
		return ;
	}
	
	int mid=(start+end)/2;
	update(start,mid,2*in+1,from,to);
	update(mid+1,end,2*in+2,from,to);
	
	segment[in]=segment[2*in+1]+segment[2*in+2];
}
int main() {
	// your code goes here
	int num,Q,state,a,b;
	scanf("%d %d",&num,&Q);
	//init(0,num-1,0);
	while(Q--)
	{
		scanf("%d %d %d",&state,&a,&b);
		if(state==0)
			update(0,num-1,0,a-1,b-1);
		else
			printf("%d\n",query(0,num-1,0,a-1,b-1));
	}
	return 0;
}