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
    ListNode* rev(ListNode* ll){
        ListNode* head=ll;
        ListNode* pre=NULL;
        ListNode* nxt;
        while(head){
            nxt=head->next;
            head->next=pre;
            pre=head;
            head=nxt;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l, ListNode* r) {
        l=rev(l);
        r=rev(r);
        ListNode res;
        ListNode *p= &res;
        int digit,remain=0;
        while(l || r){
            int nodeL= l ? l->val : 0;
            int nodeR= r ? r->val : 0;
            int temp=nodeL+nodeR + remain;
            digit=temp%10;
            p->next= new ListNode(digit);
            p=p->next;
            l=l ? l->next  : 0;
            r= r ? r->next : 0;
            remain=temp/10;
        }
        if(remain){
            p->next=new ListNode(remain);
            p=p->next;
        }
        p=rev(res.next);
        return p;
    }
};