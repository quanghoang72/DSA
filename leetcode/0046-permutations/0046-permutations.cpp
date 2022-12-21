class Solution {
public:
    void permute(vector<int> &a,vector<vector<int>>&res,int start){
        if(start==a.size()){
            res.push_back(a);
            return;
        }
        for(int i=start;i<a.size();i++){
            swap(a[i],a[start]);
            permute(a,res,start+1);
            swap(a[i],a[start]); //reset
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums,res,0);
        return res;
    }
};
