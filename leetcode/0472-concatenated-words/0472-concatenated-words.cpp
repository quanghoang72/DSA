class Solution {
public:
    //time O(n*m^2) m:maximum length word
    //space O(n*m)
    bool check(string word,unordered_set<string> &s){
        for(int i=0;i<word.size();i++){
            string pre=word.substr(0,i);
            string suf=word.substr(i,word.size()-i);
            if(s.count(pre)!=0 && (s.count(suf)!=0 || check(suf,s))) return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& a) {
        unordered_set<string> s;
        for(auto &word: a) s.insert(word);
        vector<string> v;
        for(auto &word:a){
            if(check(word,s)){
                v.push_back(word);
            }
        }
        return v;
    }
};