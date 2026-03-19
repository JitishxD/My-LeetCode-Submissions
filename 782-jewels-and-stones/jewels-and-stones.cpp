class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;
        // mp: jewels->count
        if (stones.size() == 0) {
            return 0;
        }
        int jewel = 0;
        for (int i = 0; i < jewels.size(); i++) {
            mp[jewels[i]]++;
        }
        for (int i = 0; i < stones.size(); i++) {
            if (mp[stones[i]] != 0) {
                jewel++;
            }
        }
        return jewel;
    }
};