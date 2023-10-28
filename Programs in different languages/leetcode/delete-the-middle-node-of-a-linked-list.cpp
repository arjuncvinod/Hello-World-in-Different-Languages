// question link - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int nodes = 0;
        ListNode* ptr = head;
        while(ptr != NULL ) {
            ptr = ptr->next;
            nodes++;
        }
        if(nodes == 1) {
            return NULL;
        }
        int mid = nodes/2;
        int i=0;
        ptr = head;
        // cout<<"middle node = "<<mid<<endl;
        while(i != mid-1) {
            ptr = ptr->next;
            i++;
        }
        // cout<<ptr->val<<endl;
        ptr->next = ptr->next->next;
        return head;
    }
};