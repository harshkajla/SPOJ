/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int k=Integer.parseInt(br.readLine());
		BigInteger a=new BigInteger("2");
		BigInteger b=new BigInteger("1");
		while(k-1!=0)
		{
			BigInteger temp=a;
			a=a.add(b);
			b=temp;
			k--;
		}
		System.out.println(a);
		
	}
}