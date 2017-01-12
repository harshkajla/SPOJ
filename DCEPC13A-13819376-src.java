
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;



class Palindrome{

	
	public static void nextNumber(String num)
	{
		if(num.equals("9"))
		{
			System.out.println("66");
			return;
		}
	
	
	int len=num.length();
	String ans="";int i;
	if(Integer.parseInt(num.charAt(0)+"")<6)
		{
			ans=ans+"6";
		for(i=0;i<len-1;i++)
			{
			ans=ans+"6";
			}	
		}
	else if(Integer.parseInt(num.charAt(0)+"")<9 && Integer.parseInt(num.charAt(0)+"")>6)
		{
		ans=ans+"9";
		for(i=0;i<len-1;i++)
			{
			ans=ans+"6";
			}	
		}
	else
		{
			int count=0;
			for(i=0;i<len;i++)
			{
			if(Integer.parseInt(num.charAt(i)+"")!=6 && Integer.parseInt(num.charAt(i)+"")!=9) 
				{
				count=i;
				break;
				}
			}
			if(count!=0)
			{
				ans="";
				if(Integer.parseInt(num.charAt(count)+"")<6)
				{
				ans=ans+"6";
				}
				else
				{
				ans=ans+"9";
				}
				for(i=count+1;i<len;i++)
				{ans=ans+"6";
				}
				ans=num.substring(0,count)+ans;
				}
			else
			{
				char a;
				String str="",str2="";
				a=num.charAt(0);
				for(i=0;i<len;i++)
				{
					if(a!=num.charAt(i))
					{
					break;
					}
				str=str+"6";
										
				}	
				if(i==num.length())
				{
					if(a=='6')
					ans=num.substring(0,num.length()-1)+"9";
					else
					ans=str+"6";	
				}
				else
				{
				int loc=0;
					for(i=num.length()-1;i>=0;i--)
					{
						if(num.charAt(i)=='6')
						{ loc=i;break;
						}
					}
					ans=num.substring(0,loc)+"9";
					for(i=loc+1;i<num.length();i++)
					{
						ans=ans+"6";
					}
				}		
			}
		}		
		System.out.println(ans);	
}
	public static void main(String[] args) throws IOException
	{
		int t,n,i,j,H=0;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		t=Integer.parseInt(br.readLine());
		String num="";
		while(t--!=0)
		{
			num=br.readLine();
			nextNumber(num);
		
		}

	}
}
