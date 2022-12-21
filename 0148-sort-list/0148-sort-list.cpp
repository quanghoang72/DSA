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
    ListNode* mergesort(ListNode *l,ListNode * r){
        ListNode res;
        res.next=NULL;
        ListNode* p=&res;
        while(l && r){
            if(l->val < r->val){
                p->next=l;
                l=l->next;
            }
            else {
                p->next=r;
                r=r->next;
            }
            p=p->next;
        }
        if(l){
            p->next=l;
        }
        if(r){
            p->next=r;
        }
        return res.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * temp=head; 
        ListNode * slow=head;
        ListNode * fast=head;
        //split the list into half
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* l=sortList(head);
        ListNode* r=sortList(slow);
        return mergesort(l,r);
    }
};