public class reversal_using_iteration{
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
        Node curr=head;
        Node prev=null;
        Node nxt=null;
        while(curr!=null){
            nxt=curr.next;
            curr.next=prev;
            prev=curr;
            curr=nxt;
        }
        st=prev;
        while(st!=null){
            System.out.print(st.data+"->");
            st=st.next;
        }
        
        

    }
}