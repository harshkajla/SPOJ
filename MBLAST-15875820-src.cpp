#include <bits/stdc++.h>
using namespace std;
int table[2002][2002];
int Partition(string a,string b,int i,int j,int cost)
{
	if(i==a.length())
	return cost*(b.length()-j);
	if(j==b.length())
	return cost*(a.length()-i);
	
	if(a[i]==b[j])
	return Partition(a,b,i+1,j+1,cost);
	else
return fmin( abs(a[i]-b[j])+Partition(a,b,i+1,j+1,cost) , cost+fmin(Partition(a,b,i+1,j,cost),Partition(a,b,i,j+1,cost)) );
}
int Partition2(string a,string b,int cost)
{
	for(int i=0;i<=a.length();i++)
		table[i][b.length()]=cost*(a.length()-i);
	for(int j=0;j<=b.length();j++)
	table[a.length()][j]=cost*(b.length()-j);
	
	for(int i=a.length()-1;i>=0;i--)
	{
		for(int j=b.length()-1;j>=0;j--)
		{
			if(a[i]==b[j])
			{
				table[i][j]=table[i+1][j+1];
			}
			else
			{
				table[i][j]=fmin( abs(a[i]-b[j])+table[i+1][j+1] , cost+fmin(table[i+1][j],table[i][j+1]));
			}
		}
	}
	return table[0][0];
}
int main() {
	// your code goes here
	string a,b;
	int num;
	cin>>a>>b;
	cin>>num;
	cout<<Partition2(a,b,num);
	
	return 0;
}