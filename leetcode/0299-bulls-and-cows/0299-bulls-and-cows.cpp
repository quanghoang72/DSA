class Solution {
public:
    //time O(n)
    //space O(n)
    string getHint(string secret, string guess) {
        //count character
        unordered_map<char, int> s_map;
        unordered_map<char, int> g_map;
        int n = secret.size();
        //bull and cows
        int A = 0, B = 0;
        for (int i = 0; i < n; i++)
        {
            char s = secret[i];
            char g = guess[i];
            //same charac same position
            if (s == g)
                A++;
            else
            {
                //check if other map contain this charac or not
                //decrease the element's count if yes to avoid duplicate number
                //else add to their own map
                (s_map[g] > 0) ? s_map[g]--, B++ : g_map[g]++;
                (g_map[s] > 0) ? g_map[s]--, B++ : s_map[s]++; 
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};