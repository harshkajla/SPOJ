import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

class COINS {

	public static long gold(long n,HashMap<Long,Long> h)
	{
	if(h.containsKey(n))
	{
		Long p=h.get(n);
		return p;
	}
		if(n<0)
			return 0;
		if(n==0||n==1)
		return n;
	else{
		Long p=(Long)Math.max(n, (gold(n/2, h)+gold(n/3,h)+gold(n/4,h)));
		h.put(n, p);
		return p;
	}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t,count=0;Long num;
		String l;
		
		HashMap<Long,Long> h=new HashMap<Long,Long>();
	
		while((l = br.readLine()) != null){
		
		num =  Long.parseLong(l);
		System.out.println(gold(num,h));
	count++;
	}
	
	}
	}

