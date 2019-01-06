package FactorialDigitSUm;

import java.util.*;
import java.math.*;

public class FactorialDigitSUm{

	public static void main(String[] args) {
		
			Scanner sc = new Scanner(System.in);
			int t = sc.nextInt();
			for(int i=0;i<t;i++)
			{
					int n = sc.nextInt();
					BigInteger ans= BigInteger.ONE;
                    for(int j=1;j<=n;j++)
                        ans = ans.multiply(BigInteger.valueOf(j));
                    System.out.println(ans);
                    BigInteger sum= BigInteger.ZERO;
                    
                    while(ans.compareTo(BigInteger.ZERO)!=0)
                    {
                        sum = sum.add(ans.mod(BigInteger.valueOf(10)));
                        ans = ans.divide(BigInteger.valueOf(10));
                    }
                    System.out.println(sum);
                                
                                
                                              
                                        
			}
	}

}