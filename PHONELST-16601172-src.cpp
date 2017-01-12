#include <bits/stdc++.h>
using namespace std;
struct NodeTrie
{
	bool endmark;
	NodeTrie* child[10];
	NodeTrie()
	{
		endmark=false;
		for(int i=0;i<10;i++)
			child[i]=NULL;
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
	void insert(string s)
	{
		NodeTrie* curr=root;
		for(int i=0;i<s.length();i++)
		{
			int pos=s[i]-'0';
			if(!curr->child[pos])
			{
				NodeTrie* temp=new NodeTrie();
				curr->child[pos]=temp;
			}
			curr=curr->child[pos];
		}
		curr->endmark=true;
	}
	
	void print(NodeTrie* root,string sofar)
	{
		if(root==NULL)
		return ;
		if(root->endmark==true)
		cout<<sofar<<endl;
		for(int i=0;i<10;i++)
		{
			if(root->child[i])
				print(root->child[i],sofar+(char)('0'+i));
		}
	}
	void printAll()
	{
		string sofar;
		for(int i=0;i<10;i++)
		if(root->child[i])
			print(root->child[i],sofar+(char)('0'+i));
	}
	bool check(NodeTrie* root)
	{
		if(root->endmark==true)
		{
			for(int i=0;i<10;i++)
			{
				if(root->child[i])
				return false;
			}
			return true;
		}
		bool flag=true;
		for(int i=0;i<10;i++)
		{
			if(root->child[i])
			flag=flag && check(root->child[i]);
		}
		return flag;
	}
	bool checkhelp()
	{
		return check(root);
	}
	void del(NodeTrie *curr)
	{
    	for(int i=0;i<10;i++)
    	{
    	    if(curr->child[i])
        	    del(curr->child[i]);
    	}
  		delete(curr);
	}
	void delet()
	{
		for(int i=0;i<10;i++)
			if(root->child[i])
				del(root->child[i]);
	}
};
int main() 
{
	int t,num;
	char str[15];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		Trie a;
		for(int i=0;i<num;i++)
		{
			scanf("%s",str);
			a.insert(str);
		}
		if( (a.checkhelp() ) == true )
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	
	return 0;
}