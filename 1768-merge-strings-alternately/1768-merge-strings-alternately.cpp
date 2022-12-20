class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        int n=n1+n2;
        string ans="";
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(i%2==0) 
                ans+= j < n1 ? s1[j++] : s2[k++];
            else
                ans+= k < n2 ? s2[k++] : s1[j++];
        }
        return ans;
    }
};
