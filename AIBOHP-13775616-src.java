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
						dp[i][i]=0;
						
					}
					
					
				else
				{
					if(a.charAt(i)==a.charAt(j))
						dp[i][j]=dp[i+1][j-1];
					else
						dp[i][j]=1+Math.min(dp[i][j-1], dp[i+1][j]);
					
				}
			}
		}
		}
		return dp[0][n-1];
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		while(t!=0){
		String a=br.readLine();
		int k=PalindromicString(a);
		System.out.println(k);
		t--;
		}
	}

}
