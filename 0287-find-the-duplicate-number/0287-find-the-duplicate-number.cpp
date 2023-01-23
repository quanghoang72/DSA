class Solution {
public:
    // time O(n)
    //space O(1)
    int findDuplicate(vector<int>& a) {
        int slow=0;
        int fast=0;
        while(1){
            slow=a[slow];
            fast=a[a[fast]];
            if(slow==fast) break;
        }
        slow=0;
        while(slow!=fast){
            fast=a[fast];
            slow=a[slow];
        }
        return slow;
    }
};