class Solution {
public:
    string multiply(string n1, string n2) {
        
        int m=n1.size(),n=n2.size();
        string res(m+n,'0');
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int prod= (n1[i]-'0') * (n2[j]-'0') + (res[i+j+1]-'0');
                res[i+j+1]= prod%10 + '0';
                res[i+j]+=prod/10;
            }
        }
        for(int i=0;i<m+n;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";
    }
};