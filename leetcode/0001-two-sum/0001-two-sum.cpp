class Solution {
public:
    //time: O(n) 
    //space: O(n)
        vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> res;
        for(int i=0;i<nums.size();i++){
            if(res.find(target-nums[i])!=res.end()){
                return{res[target-nums[i]],i};
            }
            res.insert({nums[i],i});
        }
        return {-1,-1};
    }
};