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
    int operationTimes(ListNode*head){
        int length=0;
        while(head){
            length++;
            head=head->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        int size=operationTimes(head);
        if(k==0) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* cur = head;
        ListNode* pre = dummy;
        ListNode* nxt;
        int time=size/k;
        while(time--){
            for(int i = 0; i < k && nxt!=NULL; i++){
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            after->next = cur;
            before->next = pre;
            before = after;
            after = cur;
            pre=before;
        }
        return dummy->next;
    }
};