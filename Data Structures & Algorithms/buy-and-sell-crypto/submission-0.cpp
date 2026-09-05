class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        int minIndex = 0;
        for(int i=1 ;i<n ;i++){
            if(prices[i] > prices[minIndex]){
                result = max(result,prices[i]-prices[minIndex]);
            }
            else{
                minIndex = i;
            }
        }
        return result;
    }
};
