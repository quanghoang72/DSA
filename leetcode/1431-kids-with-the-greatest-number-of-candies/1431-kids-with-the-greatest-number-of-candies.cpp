class Solution {
public:
    //time O(n)
    //space O(n)
    vector<bool> kidsWithCandies(vector<int>& a, int k) {
        int greatest=*max_element(a.begin(),a.end());
        vector<bool> res;
        for(auto num : a){
            if(num+k>=greatest) {
                res.push_back(true);
                continue;
            }
            res.push_back(false);
        }
        return res;
    }
};