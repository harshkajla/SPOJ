#include<iostream>
using namespace std;
long long calculate(int N)
	{
	if (N > 1)
	{
	  int iter = 0;
	  int i;
	  long long totalCount = 10; // this is when N = 1 ...
      long long A[10]; 
	  for (i=0; i <= 9; ++i)  // earlier   for (int i=0; i < 9; ++i) 
	    A[i] = 1;

	 while(++iter < N)
	 {
	    for (i = 8; i > 0 ; --i)
	    {
	         A[i]+= A[i+1];        // earlier  A[i]+= A[i-1] 
	         totalCount +=A[i];
	    }
	     totalCount+=1;
	 }
	return totalCount;
	}
	else
	return 10;
	}

int main()
{
	int t=0,i,count=1,a,b;
	cin>>t;
	while(t+1!=count)
	{
		cin>>a;
		cin>>b;
		cout<<a<<" "<<calculate(b)<<endl;
		count++;
	}
	
	return 0;
}
