#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n,i,count=0,num,number;
    scanf("%d",&n);
    while(n!=0)
    {
        stack<int> s;
        queue<int> q;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            q.push(num);
        }
        count=1;
        while(!q.empty())
        {
            number = q.front();

            if(!s.empty() && s.top()==count)
            {
                s.pop();
                count++;
                continue;
            }
            if(number==count)
            {
                count++;
              
            }

            else 
			{
               s.push(q.front());
               
            }
  			q.pop();

        }
        while(!s.empty())
        {
            number = s.top();
            if(number!=count)
            {
                break;
            }
            else{
                s.pop();
                count++;
            }
        }
        if(!s.empty())
        {
            printf("no\n");
        }
        else{
            printf("yes\n");
        }

        scanf("%d",&n);

    }
    return 0;
}
