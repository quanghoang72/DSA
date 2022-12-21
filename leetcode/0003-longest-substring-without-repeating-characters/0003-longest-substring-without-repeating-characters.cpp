
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Initialize variables
        int max_length = 0;
        int start = 0;
        std::unordered_map<char, int> char_map;
        
        // Iterate through the string
        for (int i = 0; i < s.size(); i++) {
            // Check if the current character is in the map
            if (char_map.count(s[i])) {
                // Update the start index if necessary
                // +1 = move to next idx of the repeat charac
                start = max(start, char_map[s[i]] + 1);
            }
            // Update the map and the maximum length
            char_map[s[i]] = i;
            max_length = max(max_length, i - start + 1);
        }
        
        return max_length;
    }
};
