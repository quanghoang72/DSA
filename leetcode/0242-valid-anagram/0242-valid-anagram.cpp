class Solution {
public:
    //time O(n)
    //space O(26)
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        //count word in s
        for (auto c: s)mp[c]++;
        for (auto c: t){
            //appear in t -> decrease freq
            mp[c]--;
            if (mp[c]==0)mp.erase(c);
        }
        return mp.empty();
    }
};