import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Palindrome {

	public static int PalindromicString(String a)
	{
		int n=a.length();
		int dp[][]=new int[n][n];
		int i,j;
		int k=0;
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(i<=j)
				{
					if(i==j)
					{
						dp[i][i]=1;
						k++;
					}
					else if((j-i)==1)
					{
						if(a.charAt(i)==a.charAt(j))
							{dp[i][j]=1;
							k++;
							}
						else
							dp[i][j]=0;
					}
					else
					{
					if(dp[i+1][j-1]==1 && a.charAt(i)==a.charAt(j))
						{
						dp[i][j]=1;
						k++;
						}
					else
						dp[i][j]=0;
						
					}
					
				}
			}
		}
		
	
		return k;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		String a=br.readLine();
		int k=PalindromicString(a);
		System.out.println(k);
	}

}
