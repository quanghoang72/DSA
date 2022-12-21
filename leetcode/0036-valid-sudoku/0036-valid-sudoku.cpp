class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        // use the coordinary i and j as row
        // the repeat number will define if it is already there or not as col
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        //used1 to check same row
        //used2 to check same col
        //used 3 to check sub box
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {

                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    //K is the represent row of sub box. // num will give the same number and convert to col
                     //    0  1  2   3  4  5   6  7  8
                    // 0 | *  0  0 | 1  1  1 | 2  2  2
                    // 1 | 0  0  0 | *  1  1 | 2  2  2
                    // 2 | 0  0  0 | 1  1  1 | *  2  2
                    //     --------+---------+---------
                    // 3 | *  3  3 | 4  4  4 | 5  5  5
                    // 4 | 3  3  3 | 4  4  * | 5  5  5
                    // 5 | 3  3  3 | 4  4  4 | 5  5  *
                    //     --------+----------+--------
                    // 6 | 6  *  6 | 7  7  7 | 8  8  8
                    // 7 | 6  6  6 | 7  *  7 | 8  8  8
                    // 8 | 6  6  6 | 7  7  7 | 8  *  8
                    //every subbox will all be assigned in the same coressponding row.
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};