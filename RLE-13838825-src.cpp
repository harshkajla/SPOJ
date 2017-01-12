#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
	string num;
	int i,count=1,j,flag=0;
	char prev,curr;
	char num2[100000];
	while(scanf("%s",&num2)!=EOF)
	{
		
		num="";
		num.append(num2);
		num=num+" ";
		curr=num[0];
		prev=' ';
		for(i=1;i<num.length();i++)
		{
			prev=num[i-1];
			curr=num[i];				
			flag=1;
			if(prev!=curr)
			{
				if(count<=3 && flag!=0)
				{
				for(j=0;j<count;j++)
					cout<<prev;
				}
				else
					{
					cout<<count<<"!"<<prev;
					}
				count=1;	
			}
			else
			count++;
			
			
		}
		cout<<endl;
	}	
	
	
}