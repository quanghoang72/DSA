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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode res(0);
        ListNode *temp=&res;
        int digit=0,sum;
        while(l1 || l2 || digit){
            sum=(l1 ==0 ? 0 : l1->val) + (l2==0 ? 0 : l2->val)+ digit;
            digit=sum/10;
            temp->next= new ListNode(sum%10);
            temp=temp->next;
            l1 = l1 == 0 ? 0 : l1->next;
            l2 = l2 == 0 ? 0 : l2->next;
        }
        return res.next;
    }
};