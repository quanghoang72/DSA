class Solution {
public:
    //time O(nlogm)
    //space O(1)
    
    //sort to minimize the difference between two adjacent number
    //bs the target and find if there are p pairs satisfy - have the difference <= target - or not.
    int minimizeMax(vector<int>& nums, int p) {
        int res=0;
        int l=0,r=1e9;
        sort(nums.begin(),nums.end());
        while (l<=r){
            int m=l+(r-l)/2;
            if(good(m,nums,p)){
                res=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return res;
    }
    bool good(int target,vector<int>&nums,int p){
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=target){
                cnt++;
                i++;
            }
            if(cnt==p)
                return true;
        }
        return false;
    }
};