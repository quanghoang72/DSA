class Solution {
public:
    
    //create a 2d matrix to solve each substring from both given string
    //initallize both string as an empty string
    //the minimum operation of current string length is depend on the length-1 if two character is mismatch
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            //every character compare to empty string need 1 operation (insert/delete) 
            //and increment till the end
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //if 2 character are the same, do 0 operation
                //that substring is exactly same as up diagonal cell
                //up diagonal cell = minimum operation of (length string from a - 1 and from b - 1)
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
                
                //find the min operation of substring cell has been solved before
                else 
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
        //at the end of size
        return dp[m][n];
    }
};