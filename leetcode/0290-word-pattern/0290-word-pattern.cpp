class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char, int> pmp;
        unordered_map<string, int> wmp;
        
        stringstream in(s); string word;
        int i = 0, n = p.size();

        
        for(word; in>>word; i++){
            if(i==n || pmp[p[i]] != wmp[word]) 
                return false;
            
            pmp[p[i]] = wmp[word] = i+1;
        }
        return i==n;
    }
};