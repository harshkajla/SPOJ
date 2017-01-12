#include<bits/stdc++.h>
using namespace std;
char number[26];
int psum[26];
int chop(int i,int len,int sum)
{
	if(i<len && i>0){
	int s1=psum[len-1]-psum[i-1];
	if(s1<sum)
	return 0;	
	}
	
	if(i==len)
	return 1;
	
	int k=0,s=0;
	for(int p=i;p<len;p++)
	{
		s+=((int)number[p]-'0');
			if(s>=sum)
				{
				k+=chop(p+1,len,s);
				}			
	}
	return k;
}

int main()
{
	cin>>number;
	int count=0;
	while(number[0]!='b')
	{
		int len=strlen(number);
		psum[0]=(int)number[0]-'0';
		for(int i=1;i<len;i++)
		psum[i]=psum[i-1]+(int)number[i]-'0';
		
		count++;
		cout<<count<<". "<<chop(0,len,0)<<endl;
		cin>>number;
	}
}