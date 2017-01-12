#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int input,num;int k,count=0,sum=0;
	while(std::cin)
	{
		cin>>num;
		k=num;
		if(k==0)
		break;
		count=0;
		sum=0;
		
		num--;
		while(k--)
		{
			cin>>input;	;	
		
	
		if(num%2==0 && count>=num/2)
		sum=sum+input;
		if(num%2!=0 && count>=num/2 +1)
			sum+=input;
			
			count++;
		}
		cout<<sum<<endl;		
	}
	
	
	return 0;
}