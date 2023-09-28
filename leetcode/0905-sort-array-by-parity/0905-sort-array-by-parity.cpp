class Solution {
public:
    //time O(n)
    //space O(1)
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]%2==0){
                l++;
            }
            else if(nums[l]&1==1 && nums[r]%2==0){
                swap(nums[r],nums[l]);
                r--;
                l++;
            }
            else 
                r--;
        }
        return nums;
    }
};