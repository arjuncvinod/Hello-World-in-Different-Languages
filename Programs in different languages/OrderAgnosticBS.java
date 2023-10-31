public class OrderAgnosticBS {
    public static void main(String[] args){
//        int arr[] = {1,3, 3,5 ,5,6,7, 8, 9, 12 , 15, 19, 22, 25,27 };
        int arr[] = {100, 87, 79,68,63, 54,52,51, 34, 22, 21, 18,14, 13,2,1};
        int target = 68;
        int index = binarySearch(arr, target);
        System.out.println(index);
    }
    public static int binarySearch(int[] arr, int target){
        int start = 0;
        int end = arr.length- 1;
        boolean asc = arr[start] <= arr[end];
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target){
                return mid;
            }
            if(asc){
                if(arr[mid] > target){
                    end = mid -1;
                }else {
                    start = mid + 1;
                }
            }
            else{
                if(arr[mid] > target){
                    start = mid +1;
                }else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
}
