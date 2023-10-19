public class stack {
    static Node head;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    static void push(int data){
        Node newnNode=new Node(data);
        if(head==null){
            head=newnNode;
        }
        else{
            newnNode.next=head;
        head=newnNode;
        }
    }
    static void pop(){
        head=head.next;
    }
    public static void main(String[] args){
        push(10);
        push(20);
        push(30);
        push(40);
        pop();
        Node st=head;
        while(st!=null){
            System.out.print(st.data+",");
            st=st.next;
        }

    }
}
