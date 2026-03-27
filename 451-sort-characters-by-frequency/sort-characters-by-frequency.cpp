class Solution {
public:
    static bool comparator(pair<char, int>& p1, pair<char, int>& p2) {
        if (p1.second > p2.second) return true;
        if (p1.second < p2.second) return false;
        return p1.first < p2.first;
    }

    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(char c : s){
            mp[c]++;
        }

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(), comparator);

        string ans = "";
        for(auto &p : freq){
            ans += string(p.second, p.first);
        }

        return ans;
    }
};