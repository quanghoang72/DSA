class Solution {
public:
    int distinctAverages(vector<int>& a) {
        sort(a.begin(), a.end());
        
        unordered_set<double> u;
        int n = a.size();
        
        for(int i = 0; i < n/2; ++i)
            u.insert((a[i] + a[n-i-1]) / 2.0);

        return u.size();
    }
};