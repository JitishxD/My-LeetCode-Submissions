class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dt = 0;
        int currentPrice = 0, minPrice = prices[0];
        for(int i=1; i<n; i++){
            currentPrice = prices[i];
            int cost = currentPrice-minPrice;
            if(cost<0){
                minPrice = currentPrice;
                continue;
            }

            dt = max(dt, cost);
        }

        return dt;
    }
};