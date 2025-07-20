
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        
        // if array have size less then 1 
        if(prices.size() <= 1){
            return 0;
        }
        
        
        int res = 0;
        
        // check for each day is it have inceases prices and if yes then how much then yesterday it is the profide
        for(int i = 1;i < prices.size();i++){
            if(prices[i] > prices[i - 1]){
                res += prices[i] - prices[i -1 ];
            }
        }
        
        return res;
    }
};
