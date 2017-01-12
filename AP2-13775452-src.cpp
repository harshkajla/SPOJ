#include<iostream>
using namespace std;

int main()
{

	int t;
	
	cin>>t;
	long long a3,an3,sum,num,a,i;
	long long d;
	while(t--){
	cin>>a3>>an3>>sum;
	num=2*sum/(a3+an3);
		d=(an3-a3)/(num-5);
		a=a3-2*d;
		cout<<num<<endl;;
for(i=1;i<=num;i++)
{
	cout<<a+(i-1)*d<<" ";
		}	
		cout<<endl;	
}
	return 0;
}
