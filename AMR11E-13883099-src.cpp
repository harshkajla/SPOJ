#include <cstdio>
using namespace std;

const int MAX = 3001;

int cnt[MAX];
int lucky[1001];

void sieve() {	
	int i, j;
	cnt[2] = 1;
	for(i = 4; i < MAX; i+=2) 
	cnt[i]++;
	for(i = 3; i < MAX; i+=2) {
		if(!cnt[i]) {
			cnt[i] = 1;
			for(j = i<<1; j < MAX; j+=i) 
			cnt[j]++;
		}
	}
	int k=0;
	for(int i=1;i<MAX;i++)
	{
		if(k==1001)
		break;
		if(cnt[i]>=3)
		{
			lucky[k]=i;
			k++;
		}
	}
		
}

int main() {
	int t, a, b, n;
	sieve();
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &a);
		printf("%d\n",lucky[a-1]);
		
	}
	return 0;
}