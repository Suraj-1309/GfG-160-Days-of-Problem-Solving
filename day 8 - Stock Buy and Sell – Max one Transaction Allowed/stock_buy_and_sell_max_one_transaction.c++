class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int profit = 0; // to store the profit 
        int buy = prices[0]; // varible to store the price at which we shoutld buy the stock
        
        for(int i = 1;i < prices.size();i++){
            
            // check that if we can make profit than we will sell stocks
            if(prices[i] > buy && (profit < prices[i] - buy)){
                profit = prices[i] - buy;
            }
            
            // if prices are low,buy at that day
            if(prices[i] < buy){
                buy = prices[i];
            }
        }
        
        return profit;
    }
};
