class Solution {
public:
    //time O(nlogn)
    //space O(n)
    bool closeStrings(string word1, string word2) {
        //exist to check if the character appear
        //freq check the freq
        //return true if only two string contain same exist character
        //and the freq of exist character can be swap to each other 
        vector<int> freq1(26,0),freq2(26,0),exist1(26,0),exist2(26,0);
        for(auto c:word1){
            freq1[c-'a']++;
            exist1[c-'a']=1;
        }
        for(auto c:word2){
            freq2[c-'a']++;
            exist2[c-'a']=1;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2 && exist1==exist2;
    }
};