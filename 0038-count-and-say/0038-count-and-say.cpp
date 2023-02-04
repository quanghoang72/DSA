class Solution {
public:
    //time O(n)
    //space O(1)
    string countAndSay(int n) {
        if(n==1) return "1";
        vector<string> v(n+1);
        string res="1";
        for(int i=2;i<=n;i++){
            string s=res;
            int idx=0;
            int sz=s.size();
            string temp;
            while(idx<sz){
                int j=idx;
                while(j+1 < sz && s[j]==s[j+1])
                    j++;
                int length=j-idx+1;
                temp+=to_string(length);
                temp+=s[idx];
                idx=max(idx,j);
                idx++;
            }
            res=temp;
        }
        return res;
    }
};
