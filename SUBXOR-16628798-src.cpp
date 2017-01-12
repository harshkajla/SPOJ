#include <bits/stdc++.h>
using namespace std;
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
struct NodeTrie
{
	bool endmark;
	NodeTrie* left;
	NodeTrie* right;
	int leftLeaves;
	int rightLeaves;
	NodeTrie()
	{
		endmark=false;
		left=right=NULL;
		leftLeaves=rightLeaves=0;
	}
};
class Trie
{
	NodeTrie* root;
	public :
	Trie()
	{
		root=new NodeTrie();
	}
	void insert(int num)
	{
		NodeTrie* curr=root;
		
		for(int i=20;i>=0;i--)
		{
			int ch=num & (1<<i);
			if(ch==0)
			{
				if(!curr->left)
					curr->left=new NodeTrie();
				curr->leftLeaves++;
				curr=curr->left;
			}
			else
			{
				if(!curr->right)
					curr->right=new NodeTrie();
				curr->rightLeaves++;
				curr=curr->right;
			}
		}
		curr->endmark=true;
	}
	long long calculate(int q,int k)
	{
		long long ans=0;
		NodeTrie* curr=root;
			for(int i=20;i>=0;i--)
			{
				int qi= (bool)(q & (1<<i));
				int ki=(bool)(k & (1<<i));
		
				if(qi==0 && ki==1)
				{
					ans+=curr->leftLeaves;
					if(!curr->right)
						return ans;
					curr=curr->right;
				}
				else if(qi==0 && ki==0)
				{
					if(!curr->left)
						return ans;
					curr=curr->left;
				}
				else if(qi==1 && ki==0)
				{
					if(!curr->right)
						return ans;
					curr=curr->right;
				}
				else 
				{
					// cout<<qi<<" , "<<ki<<endl;
					ans+=curr->rightLeaves;
					if(!curr->left)
						return ans;
					curr=curr->left;
				}
		}
		return ans;
	}
};

int main() {
	// your code goes here
	
	int num;
	int t,k;
	scanint(t);
	long long sum=0;
	while(t--)
	{
		Trie* a=new Trie();
		scanint(num);
		scanint(k);
		int temp2=0,temp;
		sum=0;
		a->insert(0);
		for(int i=0;i<num;i++)
		{
			scanint(temp);
            temp2= temp2^temp;
			sum+=(long long )a->calculate(temp2,k);
			a->insert(temp2);
		}
		printf("%lld\n",sum);
		
	}
	return 0;
}
