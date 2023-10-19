public class reversal_using_rec {
    static Node head;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
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
    static Node recursion(Node head){
        if(head==null || head.next==null)
        return head;
        Node rest=recursion(head.next);
        head.next.next=head;
        head.next=null;
        return rest;
    }
    public static void main(String[] args){
        add_at_last(1);
        add_at_last(2);
        add_at_last(3);
        add_at_last(4);
        Node st=head;
        while(st!=null){
            System.out.print(st.data+"->");
            st=st.next;
        }
        System.out.println();
        st=recursion(head);
        while(st!=null){
            System.out.print(st.data+"->");
            st=st.next;
        }
        
        

    }
}