class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        //time O(n^2)
        //space O(n)
        // int n=a.size();
        // vector<int> dp(n,1);
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i+1;j<n;j++){
        //         if(a[i]<a[j]){ //when appear increasing subsequence
        //             dp[i]=max(dp[i],dp[j]+1); //compare to every element of j
        //         }
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());

        //time O(nlogn)
        //space O(n)
        vector<int> dp;
        int n=a.size();
        for(auto i : a){
            if(dp.empty() || dp.back() < i)
                dp.push_back(i);
            else {
                auto it=lower_bound(dp.begin(),dp.end(),i); //bs lower bound
                *it=i; //replace 
            }
        }
        return dp.size();
    }
};