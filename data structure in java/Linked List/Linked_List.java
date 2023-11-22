import java.util.*;
public class Linked_List{
    static Node head;
    private int size;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    static void insertion_at_index(int i,int d){
        Node st=head;
        while(i!=1){
            st=st.next;
            i--;
        }
        Node newnNode=new Node(d);
        newnNode.next=st.next;
        st.next=newnNode;
    }
    static void add_at_last(int a){
        Node newNode=new Node(a);
        if(head==null){
            head=newNode;
            return;
        }
        else{
            Node st=head;
            while(st.next!=null)
            {
                st=st.next;
            }
            st.next=newNode;
        }
        }
    static void add_at_begin(int d){
        Node newnNode=new Node(d);
        newnNode.next=head;

        head=newnNode;
    }
    static void remove_from_last(){
        Node st=head;
        while(st.next.next!=null){
            st=st.next;
        }
        st.next=null;

    }
    static void remove_from_first(){
        head=head.next;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int a,b,c,d;
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();
        d=sc.nextInt();
        
        add_at_last(a);
        add_at_last(b);
        add_at_last(c);
        add_at_begin(d);
        Node st=head;
        while(st!=null){
            System.out.print(st.data+"->");
            st=st.next;
        }
        System.out.println();

        add_at_begin(6);
        add_at_last(5);
        insertion_at_index(2, 5);
        remove_from_first();
        remove_from_first();
        remove_from_last();
 st=head;
        while(st!=null){
            System.out.print(st.data+"->");
            st=st.next;
        }


        
        

    }
}