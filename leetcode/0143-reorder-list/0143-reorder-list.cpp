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
    void reorderList(ListNode* head) {
        if(!head) return;
        // deque<int> d;
        // ListNode* temp=head;
        // while(temp){
        //     d.push_back(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // int i=0;
        // while(temp){
        //     if(i%2==0){temp->val=d.front();d.pop_front();}
        //     else {temp->val=d.back();d.pop_back();}
        //     temp=temp->next;
        //     i++;
        // }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* pre=slow;
        ListNode *nxt;
        slow=slow->next;pre->next=NULL;
        while(slow){
            nxt=slow->next;
            slow->next=pre;
            pre=slow;
            slow=nxt;
        }
        slow=pre;
        fast=head->next;
        pre=head;
        while(fast){
            pre->next=slow;
            pre=pre->next;
            slow=slow->next;
            if(!slow) break;
            pre->next=fast;
            pre=pre->next;
            fast=fast->next;
        }
        pre->next=NULL;
        head=pre;
    }
};