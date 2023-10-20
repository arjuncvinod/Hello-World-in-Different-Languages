// The link for the problem -> https://leetcode.com/problems/add-two-numbers

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode head1, ListNode head2) {        
        int c = 0;
        ListNode an = new ListNode(-1);        
        ListNode t1 = head1, t2 = head2, temp = an;

        while(t1 != null || t2 != null) {
            int sum = (t1!=null?(t1.val):0) + (t2!=null?(t2.val):0) + c;
            c = sum/10;
            sum = sum % 10;

            ListNode node = new ListNode(sum);
            temp.next = node;

            t1 = t1 != null ? t1.next:null;
            t2 = t2 != null ? t2.next:null;            
            temp = temp.next;            
        }        
        if(c != 0) {
            ListNode cn = new ListNode(c);            
            temp.next = cn;
        }
        return an.next;
    }
}