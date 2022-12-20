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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow in middle
        ListNode *pre=slow;
        slow=slow->next;pre->next=NULL;
        ListNode *nxt;
        while(slow){
            nxt=slow->next;
            slow->next=pre;
            pre=slow;
            slow=nxt;
        }
        //slow at null in reverse order
        fast=head;slow=pre;
        while(slow){
            if(fast->val != slow->val) return false;
            else {
                fast=fast->next;
                slow=slow->next;
            }
        }
        return true;
        
    }
};