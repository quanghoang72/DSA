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
    int find(ListNode* head){
        int res=1;
        while(head && head->next){
            res++;
            head=head->next;
        }
        return res;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int length=find(head);

        ListNode* temp1=head;
        ListNode* temp2=head;
        int pos=length-k+1; 

        for(int i=1;i<k && temp1 && temp1->next;i++){
            temp1=temp1->next;
        }
        for(int i=1;i<pos && temp2 && temp2->next;i++){
            temp2=temp2->next;
        }
        swap(temp2->val,temp1->val);
        return head;
    }
};