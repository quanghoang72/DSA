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
    //time O(n)
    //space O(1)
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode*dummy = new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* before=dummy;
        ListNode* cur=head, *after=head;
        ListNode* nxt;
        while(cur){
            //normal reverse
            for(int i=0;i<2 && nxt!=NULL ;i++){
                nxt=cur->next;
                cur->next=pre;
                pre=cur;
                cur=nxt;
            }
            before->next=pre;
            after->next=cur;
            before=after;
            after=cur;
            pre=before;
        }
        return dummy->next;
    }
};