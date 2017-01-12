import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class MaxSumSequence {

	
	public static void main(String[] args) throws IOException  {
		// TODO Auto-generated method stub
		
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String a="";
		String k="";
		long p;
		long num,near2;
		a=br.readLine();
		while(!a.equals("00e0"))
		{
	
		k=a.substring(0,2);
		
			
			for(int i=0;i<Integer.parseInt(a.charAt(3)+"");i++)
			{
			k=k+"0";
			}
			num=Long.parseLong(k);
			 p=(long)(Math.log10(num)/Math.log10(2));
			near2=(long)Math.pow(2,p);
			System.out.println(2*(num-near2)+1);
			
	a=br.readLine();
		}
		
		
	}

}
