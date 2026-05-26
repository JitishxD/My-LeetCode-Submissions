class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower_present(26, false);
        vector<bool> upper_present(26, false);
        
        // Mark the presence of lowercase and uppercase characters
        for (char c : word) {
            if (std::islower(c)) {
                lower_present[c - 'a'] = true;
            } else if (std::isupper(c)) {
                upper_present[c - 'A'] = true;
            }
        }
        
        int special_count = 0;
        
        // Count characters that appear in both arrays
        for (int i = 0; i < 26; ++i) {
            if (lower_present[i] && upper_present[i]) {
                special_count++;
            }
        }
        
        return special_count;
    }
};