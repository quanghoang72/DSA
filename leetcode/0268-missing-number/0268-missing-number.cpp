class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        int i=0;
        for(auto a:nums){
            res^=a;
            res^=i++;
        }
    return res;
        
    }
};