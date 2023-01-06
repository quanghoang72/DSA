class Solution {
public:
    //time O(n*m)
    //space O(n*m)
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        // for(int i=0;i<a.size();i++){
        //     string temp=a[i];
        //     sort(temp.begin(),temp.end());
        //     mp[temp].push_back(a[i]);
        // }
        // for(auto x : mp){
        //     res.push_back(x.second);
        // }
        // return res;
        for(int i=0;i<a.size();i++){
            string key=sortstring(a[i]);
            mp[key].push_back(a[i]);
        }
        for(auto x : mp){
            res.push_back(x.second);
        }
        return res;
    }
    string sortstring(string s){
        vector<int> alpha(26);
        for(int i=0;i<s.size();i++){
            alpha[s[i]-'a']++;
        }
        string ret;
        for(int i=0;i<26;i++){
            ret.append(to_string(alpha[i]+'a'));
        }
        return ret;
    }
};