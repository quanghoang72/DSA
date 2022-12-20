class Solution {
public:
    bool isAlienSorted(vector<string> a, string order) {
        int map[26];
        //create order in map
        for (int i = 0; i < 26; i++)
            map[order[i] - 'a'] = i;
        for (string &w : a)
            for (char &c : w)
                c = map[c - 'a'];
        return is_sorted(a.begin(), a.end());
    }
};
