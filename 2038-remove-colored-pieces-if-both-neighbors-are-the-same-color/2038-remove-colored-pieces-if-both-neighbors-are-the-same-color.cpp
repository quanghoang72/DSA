class Solution {
public:
    //time O(n)
    //space O(1)
    bool winnerOfGame(string s) {
        int cnt_A=0;
        int cnt_B=0;
        for(int i=1;i<s.size()-1;i++){
            string temp=s.substr(i-1,3);
            if("AAA"==temp)
                cnt_A++;
            else if("BBB"==temp)
                cnt_B++;
        }
        return cnt_A > cnt_B ? 1:0;
    }
};