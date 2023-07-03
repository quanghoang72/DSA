class Solution {
public:
    //time O(n)
    //space O(n)
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) 
            return 0;

        vector<int> v(26);
        bool dup=0; 
        
        //check duplicate character
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']!=0){
                dup=1;
                break;
            }
            v[s[i]-'a']=1;
        }

        int diff=0;
        int idx1=-1,idx2=-1;
        
        //find out only 1 pair of different character
        for(int i=0;i<s.size();i++){
            if(idx1==-1 && s[i]!=goal[i]) {idx1=i;diff++;}
            else if(idx2==-1 && s[i]!=goal[i]) {idx2=i;diff++;}
            else if(s[i]!=goal[i]) diff++;
        }
        
        if(idx1==idx2 && dup) return 1; 
        
        
        return diff==2 ? s[idx1]==goal[idx2] && s[idx2]==goal[idx1] : 0;
    }

};

