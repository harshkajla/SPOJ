#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t,i,j;
	cin>>t;
	char str[11];
	while(t--)
	{
		scanf("%s",&str);							
		
		i=0;j=strlen(str)-1;
		while(i<j)
		{
			if(str[i]==str[j])
			{
				i++;
				j--;
			}
			else 
			{
				break;
			}
		}
		if(i>=j)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	
	
	return 0;
}