class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        int n=a.size();
        int same=a[0].length();
        
        for(int i=1;i<n;i++){
            int idx=0;
            while(idx<a[i].size() && a[i][idx]==a[0][idx])
                idx++;
            same=min(idx,same);
        }
        return a[0].substr(0,same);
    }
};
