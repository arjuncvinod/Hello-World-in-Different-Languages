public class BST {
    static Node root;
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int d){
            this.data=d;
            left=null;
            right=null;
        }
    }
    static Node add(Node curr,int value){
        if(curr==null)
        {
            return new Node(value);
        }
        if(curr.data<value){
            curr.right=add(curr.right,value);
        }
        else if(curr.data>value){
            curr.left=add(curr.left,value);
        }
        return curr;
    }
    
    static void print(Node curr){
        if(curr.left!=null)
        print(curr.left);
        System.out.print(curr.data+"->");
        if(curr.right!=null)
        print(curr.right);

    }
    public static void main(String[] args){
        root=add(root,50);
        root=add(root,40);
        root=add(root,5);
        root=add(root,10);
        root=add(root,7);
        print(root);
        
    }
    
}
