class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long int res=0;
        int sign=1;
        int idx=0;
        
        //avoid space
        while(idx < n && s[idx]==' ') idx++;
        if(idx==n) return 0;
        
        //detect negative or positive
        if(s[idx]=='-') sign=-1,idx++;
        else if(s[idx]=='+') idx++;
        
        while(idx < n && isdigit(s[idx])){
            int last_digit= s[idx]-'0';
            
            if(res > INT_MAX/10 || res==INT_MAX/10 && last_digit > 7) return sign==1 ? INT_MAX : INT_MIN;
            
            res=res*10+last_digit;
            idx++;
        }
        return res*sign;
    }
};