import java.util.ArrayList;
public class ArrList {
    public static void main(String[] args){
        ArrayList<Integer> arr=new ArrayList<>();
        arr.add(1);
        arr.add(1);
        arr.add(1);
        arr.add(1);
        arr.add(2,2);// to add at an index
        System.out.println(arr);
        arr.get(0);//to get an element
        arr.remove(0);//to remove
        System.out.print(arr);

    }
}
