class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen=s.size();
        int plen=p.size();
        if(slen<plen) return {};
        vector<int> res;
        //count freq of character 
        //1 for s; 2 for p
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        
        for(int i=0;i<plen;i++){
            count1[s[i]-'a']++;
            count2[p[i]-'a']++;
        }
        if(count1==count2)  res.push_back(0);
        
        //window sliding technique
        //add a new character's freq into count/window
        //remove the first idx of count
        for(int i=plen;i<slen;i++){
            count1[s[i]-'a']++; //add
            count1[s[i-plen]-'a']--; //remove
            
            if(count1==count2) res.push_back(i-plen+1);
        }
        return res;
        
    }
};