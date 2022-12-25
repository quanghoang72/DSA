class Solution {
public:
    ListNode* removeElements(ListNode* head, int tar) {
        if(!head) return NULL;
         while(head!=NULL && head->val==tar){
                head = head->next;
        }
        ListNode * fast=head;
        while(fast!=NULL && fast->next!=NULL){
            if(fast->next->val==tar) {
                fast->next=fast->next->next;
            }
            else fast=fast->next;
        }
        return head;
    }
};