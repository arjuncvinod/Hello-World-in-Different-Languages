// import required classes and packages  
package javaTpoint.MicrosoftJava;  
  
import java.util.Scanner;  
  
// create class CountingSortExample to sort an array of elements using counting sort  
class CountingSortExample {  
      
    // create sortArray() method that sort the given array using counting sort mechanism  
    public static void sortArray(int inputArr[])  
    {  
        // calculate size of the array  
        int size = inputArr.length;  
  
        // create another array having same length of inputArr that will store elements in sorted way  
        int sortedArr[] = new int[size];  
  
        // Create countArr that will store count of occurrence of each number and initialize it with 0  
        int countArr[] = new int[256];  
        for (int i = 0; i < 256; ++i) {  
            countArr[i] = 0;  
        }  
  
        // use for loop to store the count of each number in the countArr  
        for (int i = 0; i < size; ++i)  
            ++countArr[inputArr[i]];  
  
        // modify the value of countArr[i] so that countArr[i] now contains actual position of the current number in the sortedArr  
        for (int i = 1; i <= 255; ++i)  
            countArr[i] += countArr[i - 1];  
  
        // iterate the inputArr in reverse order to perform counting sort.  
        for (int i = size - 1; i >= 0; i--) {  
            sortedArr[countArr[inputArr[i]] - 1] = inputArr[i];  
            --countArr[inputArr[i]];  
        }  
        // Copy the sortedArr to inputArr, so that inputArr now contains sorted elements  
        for (int i = 0; i < size; ++i)  
            inputArr[i] = sortedArr[i];  
          
        // print sorted array elements  
        System.out.print("Sorted numbers in the array is:");  
        for (int i = 0; i < inputArr.length; ++i)  
            System.out.print(inputArr[i]);  
    }  
    // main() method start  
    public static void main(String args[])  
    {  
          
        int size;    
          
        Scanner sc = new Scanner(System.in);    
        System.out.print("Enter the number of elements you want to store in the array: ");    
          
        //reading the number of elements from the that we want to enter    
        size = sc.nextInt();    
          
        //creates an array of the user input size    
        int[] inputArr = new int[size];    
        System.out.println("Enter the elements in the array: ");    
        for(int i=0; i<size; i++)    
        {    
            //reading array elements from the user     
            inputArr[i] = sc.nextInt();    
        }    
        // close scanner class object  
        sc.close();  
        sortArray(inputArr);  
          
    }  
}  
