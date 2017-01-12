#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int num;int k,count=0;
	long long sum=0;
	while(std::cin)
	{
		cin>>num;
		k=num;
		if(k==0)
		break;
		count=0;
		sum=0;
		int ar[k];
		num--;
		while(k--)
		{
			cin>>ar[count]	;	
			//cout<<(int)pow(2,(int)log2(num))<<endl;
	
		if(num%2==0 && count>=num/2)
		sum=sum+ar[count];
		if(num%2!=0 && count>=num/2 +1)
			sum+=ar[count];
			
			count++;
		}
		cout<<sum<<endl;		
	}
	
	
	return 0;
}