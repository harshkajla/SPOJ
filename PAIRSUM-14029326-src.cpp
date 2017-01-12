#include<iostream>
#include<stdio.h>
int main()
{
	long long i,num,a,t,b;
	scanf("%lld",&num);
	long long ar[num];
	long long psum[num];
	long long square[num];
	
	for(i=0;i<num;i++)
	{
	scanf("%lld",&ar[i]);
	if(i==0)
		psum[i]=ar[i];
	else
		psum[i]=psum[i-1]+ar[i];
	//
	if(i==0)
		square[i]=ar[i]*ar[i];
	else
		square[i]=square[i-1]+ar[i]*ar[i];
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		long long sq,t;
		if(a>=1)
		 t=psum[b]-psum[a-1];
		else
		t=psum[b];
			if(a>=1)		
		 sq=square[b]-square[a-1];
	else
		sq=square[b];
	printf("%lld\n",(t*t+sq)/2);
		
	}
	return 0;
}