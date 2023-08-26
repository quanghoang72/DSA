class Solution {
public:
    //time O(nlogn)
    //space O(1)
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int> &b){
                return a[1]==b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        int prev=-1001;
        int res=0;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0]>prev){
                res++;
                prev=pairs[i][1];
            }
        }
        return res;
    }
};