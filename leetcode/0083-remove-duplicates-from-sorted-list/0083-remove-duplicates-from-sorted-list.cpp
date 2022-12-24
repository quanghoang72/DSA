class Solution {
public:
    //time O(n)
    //space O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode *temp=head;
        while(temp && temp->next){
            while(temp->next && temp->next->val==temp->val)
            {
                temp->next=temp->next->next;  
            }
            temp=temp->next;
        }
        return head;
    }
};