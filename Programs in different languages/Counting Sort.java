public class Counting_Sort {
    public static void main(String[] args) {
        int[] arr = {2,6,4,1,6,9,8,4,2,3,6};
        arr = sort(arr);
        for (int i : arr){
            System.out.print(i+" ");
        }
    }

    private static int[] sort(int[] arr){
        int max = Arrays.stream(arr).max().getAsInt();

        int[] freq = new int[max+1];
        for (int i = 0; i < freq.length; i++) {
            freq[arr[i]]++;
        }

        for (int i = 1; i < freq.length; i++) {
            freq[i] = freq[i-1]+freq[i];
        }

        int[] res = new int[arr.length];
        for (int i = arr.length-1; i >= 0 ; i--) {
            int pos = freq[arr[i]];
            res[pos-1] = arr[i];
            freq[arr[i]]--;
        }

        return res;
    }
}
