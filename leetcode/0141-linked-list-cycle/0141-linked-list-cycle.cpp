class Solution {
public:
    //Floyd algorithm
    //time O(n)
    //space O(1)
    bool hasCycle(ListNode *head) {
        struct ListNode *slow=head;
        struct ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
        
    }
};