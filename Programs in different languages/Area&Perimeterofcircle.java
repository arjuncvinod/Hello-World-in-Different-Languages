//Code
import java.util.Scanner;
public class Main
{
  public static void main(String  []arg)
  {
    Scanner sc=new Scanner(System.in);
    int r;
    double a,p;
    System.out.print("Enter Radius of circle: ");
    r=sc.nextInt();
    a=3.14*r*r;
    p=2*3.14*r;
    System.out.println("Area: "+a+"\nPerimeter: "+p);
  }
}

/*Ouput
Enter Radius of circle:  10
Area: 314.0
Perimeter: 62.800000000000004*/
