class Solution {
public:
    //time O(n)
    //space O(1)
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        int sz=k*2+1;
        int l=-1,r=k;
        long long sum=0;
        for(int i=0,idx=0;i<sz && idx < n;i++,idx++){
            sum+=nums[idx];
        }
        vector<int> res(n,-1);
        while(n-r > k){
            res[r]= sum/sz;
            l++;
            r++;
            if(r==n) break;
            sum = sum -nums[l] + nums[min(n-1,sz+l)];
        }
        return res;
    }
};