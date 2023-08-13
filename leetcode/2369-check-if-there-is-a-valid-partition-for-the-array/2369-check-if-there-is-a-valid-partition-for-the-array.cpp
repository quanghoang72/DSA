class Solution {
public:
    //time O(n)
    //space O(n)
    bool validPartition(vector<int>& nums) {
        vector<bool> dp(nums.size());
        if(nums.size()==2)
            return nums[0]==nums[1];
        if(nums[0]==nums[1])
            dp[1]=1;
        if((nums[0]==nums[1] && nums[1]==nums[2]) || nums[0]+1==nums[1] && nums[1]+1==nums[2])
            dp[2]=1;
        for(int i=3;i<nums.size();i++){
            if (is3Valid(nums[i],nums[i-1],nums[i-2]))
                dp[i] =dp[i]|dp[i-3];
            if (is2Valid(nums[i],nums[i-1])) 
                dp[i]=dp[i]|dp[i-2];
        }
        return dp[nums.size()-1];
    }
    bool is2Valid(int a,int b){
        return a==b;
    }
    bool is3Valid(int a,int b,int c){
        if(a==b && b==c)   
            return true;
        if(c+1==b && b+1==a)
            return true;
        return false;
    }
};