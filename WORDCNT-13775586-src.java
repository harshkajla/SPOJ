import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

 class ADDREV {

	public static void main(String[] args) throws IOException  {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t;
			t = Integer.parseInt(br.readLine());
		String k="";
		int count=0;
		
		int currlen=0;
		int i=0;
		int s=0;
		int count2=0;
		int maxcount=0;

		int prevlen=0;
		while(count<t)
		{
			k=br.readLine();
			k=k+" ";
			if((int)k.charAt(0) >122 || (int)k.charAt(0) <97 )
			{System.out.println(0);
			continue;
			}
			if(k.equals(" ")||k.equals(','))
				{System.out.println(0);
				continue;
				}
			
		
			maxcount=0;
			prevlen=0;
			currlen=0;
			count2=0;
			i=0;
			while(i<k.length())
			{
				if(i+1<k.length() && k.charAt(i)==' ' && k.charAt(i+1)==' ')
				{
					i++;
					continue;
				}
				if(k.charAt(i)!=' ')
				currlen++;
				else if(k.charAt(i)==' ')
				{
					if(prevlen==currlen)
					{
					    currlen=0;
					    count2++;
					}
					else if(prevlen!=currlen && prevlen!=0)
					{
						prevlen=currlen;
						currlen=0;
						if(count2>maxcount)
							maxcount=count2;
						count2=0;
					}
					else if(prevlen!=currlen && prevlen==0)
					{
						prevlen=currlen;	
						currlen=0;
					}
				
				}
				if(i+1==k.length())
					{
					if(maxcount<count2)
					maxcount=count2;
					}
				i++;
			}
			k="";
			System.out.println(maxcount+1);
			count++;
		}
		

	}

}
