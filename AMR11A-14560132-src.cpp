#include<bits/stdc++.h>

#include<cstdio>
#define gc getchar_unlocked
using namespace std;
void scanint( int &x )
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        neg=1;
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if( neg )
        x=-x;
} 

int main()
{
	int A[501][501];
	int count,t,m,n,i,j,min,sum,num;
	cin>>t;
	while(t>0)
	{
		scanint(m);
		scanint(n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
			scanint(num);
			A[i][j]=num;
				
	}
    	int M = m;
            int N = n;
            vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
            hp[M][N - 1] = 1;
            hp[M - 1][N] = 1;
            for (int i = M - 1; i >= 0; i--) {
                for (int j = N - 1; j >= 0; j--) {
                    int need = fmin(hp[i + 1][j], hp[i][j + 1])-A[i][j];
                    hp[i][j] = need <= 0 ? 1 : need;
                }
            }
            cout<< hp[0][0]<<endl; 	
            
			
		t--;
	}
	
	
	
	
	return 0;
}
