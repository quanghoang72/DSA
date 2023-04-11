class Solution {
public:
    //time O(n)
    //space O(1)
    string removeStars(string s) {
        int j=0;
        for(int i=0;i<s.size();i++){
            if( s[i] =='*') j--;
            else 
                s[j++] =s[i] ;


        }
        s.resize(j);
        return s;
    }
};