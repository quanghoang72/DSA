class Solution {
public:
    //time O(n)
    //space O(n)
    string minWindow(string s, string t) {
        vector<int> map(128,0); //store character of pattern
        int l=0,r=0,len=INT_MAX,start=0;
        string res;
        for(auto i : t) map[i]++;
        
        int require=t.size();
        while(r<s.size()){
            if(map[s[r]]-->0)
                require--;
            while(!require){ //valid window
                if( (r-l+1) < len){
                    len=r-l+1;
                    start=l;
                }
                
                if(map[s[l]]++==0){
                    require++;
                }
                l++;
            }
            r++;
        }
        res=s.substr(start,len);
        return (len==INT_MAX) ? "" : res;
        
    }
};