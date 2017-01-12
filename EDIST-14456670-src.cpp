#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
char num1[2001];
char num2[2001];
int dparray[2001][2001];
int editDistance(int len1,int len2)
{
	int i=0,j=0;
	
	for(i=0;i<len1;i++)
	{
		dparray[0][i]=i;
	}
	for(i=0;i<len2;i++)
	{
		dparray[i][0]=i;
	}
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(num1[i-1]==num2[j-1])
			{
				dparray[i][j]=dparray[i-1][j-1];
			}
			else
			{
				dparray[i][j]=fmin(1+dparray[i-1][j-1],fmin(1+dparray[i-1][j],1+dparray[i][j-1]));
			}
		}
	}
	return dparray[len1][len2];
}
int main()
{
	int t,len1,len2;
	cin>>t;
	while(t--)
	{
		scanf("%s",&num1);
		scanf("%s",&num2);
		
		len1=strlen(num1);
		len2=strlen(num2);

		printf("%d\n",editDistance(len1,len2));
	}
	
	return 0;
}