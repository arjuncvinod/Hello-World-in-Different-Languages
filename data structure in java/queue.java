public class queue {
    static Node head;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    static void enqueue(int data){
        Node newnNode=new Node(data);
        Node st=head;
        if(head==null){
            head=newnNode;
        }
        else{
            while(st.next!=null){
                st=st.next;
            }
            st.next=newnNode;
        }
    }
    static void deque(){
        head=head.next;
    }
    public static void main(String[] args){
        enqueue(10);
        enqueue(20);
        enqueue(30);
        enqueue(40);
        deque();
        Node st=head;
        while(st!=null){
            System.out.print(st.data+",");
            st=st.next;
        }

    }
}
