#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>

#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VC vector<char>
#define VVI vector<VI>
#define VVF vector<VF>
#define VVD vector<VD>
#define VVC vector<VC>
#define SI set<int>
#define SF set<float>
#define SD set<double>
#define SC set<char>
#define SSI set<SI>
#define SSF set<SF>
#define SSD set<SD>
#define SSC set<SC>
#define STI stack<int>
#define STF stack<float>
#define STD stack<double>
#define STC stack<char>
#define STSTI stack<STI>
#define STSTF stack<STF>
#define STSTD stack<STD>
#define STSTC stack<STC>

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD mulmod(LLD a, LLD b, LLD c){
	long long x = 0,y=a%c;
	while(b > 0){
		if(b%2 == 1){
		    x = (x+y)%c;
		}
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
}


int main(){
	
	LLD fact, res, m, n;
	LLD MOD = 109546051211LL;
	
	scanf("%lld", &n);
	
	if(n > 587116)
		printf("0");
	else{
		m = n-1;
		res = 1;
		fact = 1;
		for(LLD i=2;i<=n;i++){
			fact = mulmod(fact, i, MOD);
			res = mulmod(res, fact, MOD);
			if(res == 0)
				break;
		}
	
		printf("%lld", res);
	}
    return 0;
}