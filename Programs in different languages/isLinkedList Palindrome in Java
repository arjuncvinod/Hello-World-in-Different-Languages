class Node
{
	int data;
	Node next;
	
	Node(int d)
	{
		data = d;
		next = null;
	}
}

class Solution
{
    //Function to check whether the list is palindrome.
    boolean isPalindrome(Node head) 
    {
        //Your code here
        Node current = head;
        boolean flag = true;
        Stack<Integer> st = new Stack<Integer>();
        while(current != null) {
            st.push(current.data);
            current = current.next;
        }
        while(head != null) {
           int currentData = st.pop();
           if(head.data == currentData) {
               flag = true;
           }
           else {
               flag = false;
               break;
           }
           head = head.next;
        }
        return flag;
    }    
}
