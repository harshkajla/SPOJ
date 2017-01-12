#include<bits/stdc++.h>
using namespace std;

void shiftDown(int i,vector<int> &ar,int size)
{
	int l=2*i+1;
	int r=2*i+2;
	int left=l<size?ar[l]:INT_MIN;
	int right=r<size?ar[r]:INT_MIN;
	if(l<size || r<size)
	{
		int max=fmax(left,fmax(ar[i],right));
		if(max==ar[i])
		return ;
		else if(max==left)
		{
			int temp=ar[i];
			ar[i]=left;
			ar[l]=temp;
			shiftDown(l,ar,size);
		}
		else
		{
			int temp=ar[i];
			ar[i]=right;
			ar[r]=temp;
			shiftDown(r,ar,size);

		}
	}
}
void Print(vector<int> &ar)
{
	for(int i=0;i<ar.size();i++)
	{
		cout<<ar[i]<<"\n";
	}
	cout<<endl;

}
void buildheap(vector<int> &ar)
{
	for(int i=ar.size()/2 -1;i>=0;i--)
	{
		shiftDown(i,ar,ar.size());
	}	
}
void reHeap(vector<int> &ar,int i,int size)
{
	int temp=ar[0];
	ar[0]=ar[size-1];
	ar[size-1]=temp;
	shiftDown(i,ar,size-1);
}
void HeapSort(vector<int> &ar)
{
	buildheap(ar);
	int size=ar.size();
	for(int i=0;i<ar.size();i++)
		reHeap(ar,0,size--);
}
int main()
{
	int num,p;
	scanf("%d",&num);
	vector<int>ar;
	for(int i=0;i<num;i++){
	scanf("%d",&p);
	ar.push_back(p);
	}
	HeapSort(ar);
	
	Print(ar);
	return 0;
}