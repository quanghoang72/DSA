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
    int getDecimalValue(ListNode* head) {
        vector<int> value(30);
        int i=0;
        while(head){
            value[i++]=head->val;
            head=head->next;
        }
        int n=i,idx=i,res=0;
        for(i=0;i<n;i++){
            if(value[i]) {res+=pow(2,--idx);continue;}
            --idx;
        }
        return res;
    }
};