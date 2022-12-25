class Solution {
public:
    // bool containsNearbyDuplicate(vector<int>& nums, int k) {
    //     unordered_map <int,int> res;
    //     for(int i=0;i<nums.size();i++){
    //         if(res.find(nums[i])!=res.end() && i-res[nums[i]] <=k) return true;
    //         res[nums[i]]=i;
    //     }
    //  return false; 
    // }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set <int> res;
        int w=0;
        for(int i=0;i<nums.size();i++){
            if(i-w>k) res.erase(nums[w++]);
            if(!res.insert(nums[i]).second) return true; //second pair value already exist=false
        }
     return false; 
    }
};