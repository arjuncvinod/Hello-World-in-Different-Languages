public class doub_ll {
    static Node head;
    static class Node{
        int data;
        Node next;
        Node prev;
        Node(int d){
            this.data=d;
            this.next=null;
            this.prev=null;
        }
    }
    static void add_at_begin(int add){
        if(head!=null)
        {Node newnode=new Node(add);
        newnode.next=head;
        head.prev=newnode;
        head=newnode;}
        else{
            Node newnode=new Node(add);
            head=newnode;
        }
    }
    static void add_at_end(int d){
        Node newnode=new Node(d);
        Node st=head;
        while(st.next!=null){
            st=st.next;
        }
        newnode.prev=st;
        st.next=newnode;
    }
    static void delete_at_end(){
        Node st=head;
        while(st.next.next!=null){
            st=st.next;
        }
        st.next=null;
    }
    static void delete_at_begin(){
        head=head.next;
        head.prev=null;
    }
    public static void main(String[] args){
        
        add_at_begin(3);
        add_at_begin(2);
        add_at_end(4);
        add_at_begin(1);
        add_at_begin(7);
        Node st=head;
        while(st!=null){
            System.out.print(st.data+"->");
            st=st.next;
        }
    }
}
