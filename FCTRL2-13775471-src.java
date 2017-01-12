import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


class MaxSumSequence {

	
	public static void main(String[] args) throws IOException  {
		// TODO Auto-generated method stub
		
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	int t=0,n = 0,i;
	BigInteger big = BigInteger.valueOf(1),k=BigInteger.valueOf(1);
	BigInteger b=BigInteger.valueOf(1);
	t=Integer.parseInt(br.readLine());
	while(t!=0)
	{
		n=Integer.parseInt(br.readLine());
		big=BigInteger.valueOf(1);
		k=BigInteger.valueOf(1);
		b=BigInteger.valueOf(1);
		for(i=0;i<n;i++)	
		{
		big=big.multiply(k);
		k=k.add(b);
		}
	t--;
	System.out.println(big);
	
	}
		
		
	}

}
