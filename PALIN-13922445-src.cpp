#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
char next(char c)
{
	if(c=='0')
	return '1';
	else if(c=='1')
	return '2';
	else if(c=='2')
	return '3';
	else if(c=='3')
	return '4';
	else if(c=='4')
	return '5';
	else if(c=='5')
	return '6';
	else if(c=='6')
	return '7';
	else if(c=='7')
	return '8';
	else if(c=='8')
	return '9';
	else
	return '0';
}
char n[1000001];
int main()
{
	int flag=0,flag2=0;
	int i,len,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&n);
		
		 len=strlen(n);	
			flag=0,flag2=0;	
			if(len%2==0)
			{
			
			
			for( i=0;i<len/2;i++)
				{					
					if(flag==0 && flag2==0 && ((int)n[len/2-i-1]<(int)n[len/2+i]))
					{
					flag=1;
					}
					else if(flag2==0 && flag==0 && ((int)n[len/2-i-1]>(int)n[len/2+i]))
					{
					flag2=1;
					}
				}	
					if(flag2==1 && flag==0)
					{
						for(i=0;i<len/2;i++)
						{
						n[len-i-1]=n[i];	
						}	
					}			
					else 
					{
						if(n[len/2-1]=='9')
						{
						
						n[len/2-1]=next(n[len/2-1]);
						n[len/2]=next(n[len/2]);
						
							for( i=len/2-2;i>=0;i--)
								{
								if( n[i+1]=='0')
									{
									
									n[i]=next(n[i]);	
									n[len-i-1]=next(n[len-i-1]);
								
									}
								else
									break;
							
								}			
					
						}	
							else
							{
							n[len/2-1]=next(n[len/2-1]);
							for(i=0;i<len/2;i++)
							{
							n[len/2+i]=n[len/2-i-1];
							}
						
						}
					}			
					if(n[0]=='0')
					{
						cout<<"1"<<n+1<<"1"<<endl;
					}
					else
					{
					cout<<n<<endl;	
					}							
			}
			
			else
			{
				for( i=0;i<len/2;i++)
				{					
					if(flag==0 && flag2==0 && ((int)n[len/2-i-1]<(int)n[len/2+i+1]))
					{
					flag=1;
					}
					else if(flag2==0 && flag==0 && ((int)n[len/2-i-1]>(int)n[len/2+i+1]))
					{
					flag2=1;
					}
				}	
				//cout<<"flag : "<<flag<<"flag2"<<flag2<<endl;
					if(flag==0 && flag2==1)
					{
						//cout<<"hey"<<endl;
						for(i=0;i<len/2;i++)
						{
							n[len-i-1]=n[i];
						}			
					}
					else
					{
						
							if(n[len/2]=='9')
							{
						
								n[len/2]=next(n[len/2]);
				
								for(i=len/2-1;i>=0;i--)
								{
								if( n[i+1]=='0')
									{
									n[i]=next(n[i]);									
									n[len-i-1]=n[i];
									}
									else
										break;								
								}																
							
							}
					   		else
							{
						
							n[len/2]=next(n[len/2]);
							
							for(i=0;i<len/2;i++)
								n[len-i-1]=n[i];
							
					
							}
					
					}			

					if(n[0]=='0')
					{
						cout<<"1"<<n+1<<"1"<<endl;
					}
					else
					{
					cout<<n<<endl;	
					}			
				}
				
			}
	
	
			
	
	
	return 0;
}