import java.util.Scanner;
public class Main{
   static boolean check(int sum){
       if(sum%2==0)return true;
       else return false;
       
    }
static int sum(int x,int y){
    return x+y;
}

static int dsum(int num){
    int sum =0;
      while(num>0){
         // rem=n%10;
          sum+=(num%10);
          num=num/10;
       }
       return sum;
}
    static int fdigits(int num){
        int count=0;
        while(num>0){
            num/=10;
            count++;
        }
        return count;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
       int n=sc.nextInt();
       int s=dsum(n);
       int a=fdigits(n);
      // int rem;
     
       System.out.println("sum of digits: "+s);
       System.out.println("frequencyof digits: "+fdigits(n));
       System.out.println("Is even: "+check(dsum(n)));
       System.out.println("SUM: "+sum(s,a)); 
       // System.out.println("Is number divisible by 3 or 5? "+check(n));
        //System.out.println("sum of two no.= "+sum(2,3));
}
}


/*Output
 
54321
sum of digits: 15
frequencyof digits: 5
Is even: false
SUM: 20

*/
