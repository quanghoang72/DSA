class Solution {
public:
    //time O(n)
    //space O(1)
    int compress(vector<char>& a) {
        int i=0;
        int n=a.size();
        int j=0;
        while(i<n){
            int cnt=1;
            while(i+1 < n && a[i]==a[i+1]){
                cnt++;
                i++;
            }
            a[j++]=a[i];
            string s=to_string(cnt);
            if(cnt>1){
                for(int k=0;k<s.size();k++){
                    a[j++]=s[k];
                }
            }
            i++;
        }
        a.resize(j);
        return j;
    }
};
