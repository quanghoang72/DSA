class Solution {
public:
    //time O(n*26)
    //space O(26)
    int partitionString(string s) {
        vector<int> v(26);
        int res=0;
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']!=0){
                for(int j=0;j<26;j++){
                    v[j]=0;
                }
                res++;
            }
            v[s[i]-'a']++;
        }
        for(int j=0;j<26;j++){
            if(v[j]!=0) return res+1;
        }
        return res;
    }
};