

import java.util.*;
import java.lang.*;
import java.io.*;


class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		
		Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t>0) {
            int f = sc.nextInt();
            int s = sc.nextInt();
            int h = sc.nextInt();
            if ((f>s && f < h) || ( f> h && f<s) ) {
                System.out.println(f);
            }else if ((s>f && s<h) || (s>h && s<f)) {
                System.out.println(s);
            }else{
                System.out.println(h);
            }
            
            
            t--;
        }
	}
}
