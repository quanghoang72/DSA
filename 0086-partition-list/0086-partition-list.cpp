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
    ListNode* partition(ListNode* head, int x) {
        //create two new dummy node for 2 pointers
        ListNode* res=new ListNode();
        ListNode* dummy=new ListNode();
        //before points to the node less than x
        //target points to node >= x
        ListNode* before=res;
        ListNode* target=dummy;
        
        //start of the right parition
        ListNode* parti=target;
        
        while(head){
            if (head->val < x)
            {
                before->next=head;
                before=before->next;
            }
            else
            {
                target->next=head;
                target=target->next;

            }
            head=head->next;
        }
        //set end to the left partiion
        target->next=nullptr;
        
        before->next=parti->next;
        return res->next;
    }
};

