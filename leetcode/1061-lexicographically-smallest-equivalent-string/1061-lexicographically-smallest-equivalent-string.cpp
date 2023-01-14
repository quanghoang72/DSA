class Solution {
public:
    //time O(n)
    //space O(1)

    //create a alphabet vector
    //only replace equipvalent character with smallest character
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> v(26);
        for(int i=0;i<26;i++){
            v[i]=i;
        }
        for(int i=0;i<s1.size();i++){
            int replaced=max(v[s1[i]-'a'],v[s2[i]-'a']);
            int replaceWith=min(v[s1[i]-'a'],v[s2[i]-'a']);
            for(int i=0;i<26;i++){
                if(v[i]==replaced)
                    v[i]=replaceWith;
            }
        }
        string res;
        for(int i=0;i<baseStr.size();i++){
            res+=v[baseStr[i]-'a']+'a';
        }
        return res;
    }
};