#include<bits/stdc++.h>
using namespace std;
map<long long,long long> m;
long long sumdigit(long long num)
{
	if(num/10==0)
	return num*(num+1)/2;
	long long a;
	long long b;
	long long k;
	if(m[num])
	return m[num];
	k=log10(num);
	a=num/pow(10,k);
	b=num-a*pow(10,k);
	
	long long sum=45*a*k*pow(10,k-1)+((a*(a-1))*pow(10,k))/2 + a*(1+b)+sumdigit(b);
	m[num]=sum;
	return sum;
}

int main(){
	long long a,b;
	cin>>a>>b;
	while(a!=-1&& b!=-1)
	{
		long long sum=0;
		sum=sumdigit(b)-sumdigit(a-1);	
		cout<<sum<<endl;
		cin>>a>>b;
	}
}