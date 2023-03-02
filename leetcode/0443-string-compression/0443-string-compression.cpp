class Solution {
public:
    int compress(vector<char>& a) {
        int i=0;
        int n=a.size();
        int length=0;
        int idx=0;
        while(i<n){
            int cnt=1;
            int start=min(i,length);
            while(i+1 < n && a[i]==a[i+1]){
                cnt++;
                i++;
            }
            string s=to_string(cnt);
            if(cnt>1){
                for(int j=0;j<s.size();j++){
                    a[++start]=s[j];
                }
            }
            length=start;
            length++;
            i++;
            if(i < n) a[length]=a[i];
        }
        a.resize(length);
        return length;
    }
};
