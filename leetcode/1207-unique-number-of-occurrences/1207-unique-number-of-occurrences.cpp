class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        int n=a.size();
        unordered_map <int,int> mp;
        set<int> st;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        for(auto it:mp){
            if(st.count(it.second))
                return false;
            st.insert(it.second);
        }
        return true;
    }
};