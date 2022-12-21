/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow && fast && fast->next){ 
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){     //check cycle
                ListNode *start=head;
                while(start!=slow){   //find loop start
                    start=start->next;
                    slow=slow->next;
                }
                return start;
            }
        }
        return NULL;
    }
};