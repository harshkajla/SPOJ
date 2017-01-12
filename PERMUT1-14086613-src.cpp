#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> m;
int Inversion(int n,int k)
{
	if(k==0)
	return 1;
	if(k<0)
	return 0;
	
	if(m[make_pair(n,k)])
	return m[make_pair(n,k)];
	
	int i,out=0;	
	
	
	for(i=0;i<n;i++)
		out+=Inversion(n-1,k-i);
	
	m[make_pair(n,k)]=out;
	return out;
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		printf("%d\n",Inversion(n,k));
	}
	
	
	return 0;
}