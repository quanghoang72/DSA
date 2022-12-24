class Solution {
public:
    //time O(n)
    //space O(n)
    bool containsDuplicate(vector<int>& a) {
        set <int> res;
        for(int i=0;i<a.size();i++){
            if(res.empty()!=true && res.find(a[i])!=res.end()) return true;
            res.insert(a[i]);
        }
    return false;
    }
};