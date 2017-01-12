#include <bits/stdc++.h>
using namespace std;
int editDistance(string a,string b,int i,int j)
{
	if(i==a.length())
	return b.length()-j;
	if(j==b.length())
	return a.length()-i;
	
	if(a[i]==b[j])
	return editDistance(a,b,i+1,j+1);
	else
	return 1+fmin(editDistance(a,b,i+1,j+1),fmin(editDistance(a,b,i,j+1),editDistance(a,b,i+1,j)));
}
int table[2101][2101];
int edit2(string a,string b)
{
	
	for(int i=0;i<=a.length();i++)
		table[i][b.length()]=a.length()-i;
	
	for(int j=0;j<=b.length();j++)
		table[a.length()][j]=b.length()-j;
		
		for(int i=a.length()-1;i>=0;i--)
		{
			for(int j=b.length()-1;j>=0;j--)
			{
					if(a[i]==b[j])
					table[i][j]=table[i+1][j+1];
					else
					table[i][j]=1+fmin(table[i+1][j+1],fmin(table[i][j+1],table[i+1][j]));
			}
		}
		return table[0][0];
}
int main() {
	string a,b;
	int t;
	cin>>t;
	while(t--){
	cin>>a>>b;
	cout<<edit2(a,b)<<endl;
	}
	return 0;
}