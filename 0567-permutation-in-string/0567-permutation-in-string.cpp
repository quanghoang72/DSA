class Solution {
public:
    //window sliding technique
    bool checkInclusion(string s1, string s2) {
        //goal contains character of s1
         vector<int> cur(26), goal(26);
        for(char c : s1) goal[c - 'a']++;
        
        for(int i = 0; i < s2.size(); i++) {
            cur[s2[i] - 'a']++; //add character freq to cur
            
            //if current window length is larger than s1 than remove first char
            if(i >= s1.size()) cur[s2[i - s1.size()] - 'a']--;
            
            //after remove first char the current window length is ensured to be same as s1
            //now check if two vector is exactly equal then permuation found
            if(goal == cur) return true;
        }
        return false;
    }
};