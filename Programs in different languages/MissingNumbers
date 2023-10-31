import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MissingNumbers {
    public static void main(String[] args) {
        int[] arr = {4,2,3,1,6,6};
        List<Integer> ans = solution(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println(ans);
    }
    static List<Integer> solution(int [] arr){
        for(int i=0;i<arr.length;i++){
            if(arr[i]!= i+1){
                swap(arr,i,arr[i]-1);
            }
        }
//        for(int i= 0;i< arr.length;i++){
//            if(arr[i]!=i+1){
//                count++;
//            }
//        }

//        int[] ans = new int[count];
        List<Integer> ans = new ArrayList<>();
        for(int i= 0;i< arr.length;i++){
            if(arr[i]!=i+1){
                ans.add(i+1);
            }
        }
        return ans;
    }
    static void swap(int[] arr, int start, int end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}
