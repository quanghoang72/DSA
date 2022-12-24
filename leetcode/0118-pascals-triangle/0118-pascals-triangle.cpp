class Solution {
public:
    //time O(n)
    //space O(n)
    vector<vector<int>> generate(int r) {
        vector<vector<int>> ret;
	    for (int i = 0; i < r; i++) {
		    vector<int> row(i + 1, 1);
		    for (int j = 1; j < i; j++) {
			row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		ret.push_back(row);
	}
	return ret;
    }
};