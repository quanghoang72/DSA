class Solution {
public:
    //time O(n^2)
    //space O(n)
    int bestTeamScore(vector<int>& a, vector<int>& b) {
        vector<pair<int,int>> v;
        int n=a.size();
        for(int i=0;i<n;i++){
            v.push_back({b[i],a[i]});
        }
        sort(v.begin(),v.end()); //sort by the age and if same age --> increasing order of score
        int res=0;
        vector<int> dp(n,0); //store the path that has increasing subsequnce
        
        //only consider player has higher score
        for(int i=n-1;i>=0;i--){
            dp[i]=v[i].second;
            for(int j=i+1;j<n;j++){
                if(v[j].second>=v[i].second) //to maintain the increasing trait
                    dp[i]=max(dp[i],dp[j]+v[i].second); 
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
