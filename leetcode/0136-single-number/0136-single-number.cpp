class Solution {
public:
    //time O(n)
    //space O(n)
    // int singleNumber(vector<int>& nums) {
    //     unordered_map <int,int> res;
    //     for(int i=0;i<nums.size();i++){
    //         res[nums[i]]++;
    //     }
    //     for(auto x: res){
            // check appear once
    //         if(x.second==1) return x.first;
    //     }
    // return -1;
    // }
    
    //time O(n)
    //space O(1)
    //every element appears twice --> xor =0
    //the last element will be the remain
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            nums[i+1]=nums[i]^nums[i+1];
        }
    return nums[nums.size()-1];
    }
};