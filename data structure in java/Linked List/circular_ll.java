public class circular_ll {
    static Node head;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    static void add_at_begin(int d){
        Node newnode=new Node(d);
        newnode.next=head;
        Node st=head;
        if(head==null){
            head=newnode;
            newnode.next=newnode;
        }
        else{
            while(st.next!=head){
                st=st.next;
            }
            st.next=newnode;
            head=newnode;
        }
    }
    static void add_at_end(int d){
        Node newnode=new Node(d);
        newnode.next=head;
        Node st=head;
        if(head==null){
            head=newnode;
            newnode.next=newnode;
        }
        else{
            while(st.next!=head){
                st=st.next;
            }
            st.next=newnode;
        }
    }
    static void delete_at_begin(){
        Node st=head.next;
        while(st.next!=head){
            st=st.next;
        }
        st.next=head.next;
        head=head.next;
    }
    public static void main(String[] args){
        
        add_at_begin(5);
        add_at_end(0);
        add_at_begin(6);
        add_at_begin(7);
        add_at_begin(8);
        delete_at_begin();
        Node st=head;
        //System.out.print(st.data);
        while(st.next!=head){
            System.out.print(st.data+"->");
            st=st.next;
        }
        System.out.println(st.data);


    }
}
