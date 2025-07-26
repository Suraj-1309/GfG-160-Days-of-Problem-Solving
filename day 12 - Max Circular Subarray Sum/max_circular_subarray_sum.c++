class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
      
        // totalSum: Stores the sum of all elements in the array.
        int totalSum = 0;
        
        // currentMaxSum: Tracks the maximum sum of a subarray ending at the current position.
        int currentMaxSum = 0;
        // currentMinSum: Tracks the minimum sum of a subarray ending at the current position.
        int currentMinSum = 0;
        
        // maxSum: Stores the overall maximum sum subarray found so far (Kadane's algorithm).
        int maxSum = arr[0];
        // minSum: Stores the overall minimum sum subarray found so far (Kadane's algorithm variation).
        int minSum = arr[0];
            
        // Iterate through the array to calculate sums.
        for(int i = 0; i < arr.size();i++){
            
            // Kadane's algorithm to find the maximum sum subarray.
            // currentMaxSum is either the current element itself or the current element added to the previous currentMaxSum.
            currentMaxSum = max(currentMaxSum + arr[i], arr[i]);
            // Update maxSum with the larger value between current maxSum and currentMaxSum.
            maxSum = max(maxSum, currentMaxSum);
            
            // Kadane's algorithm variation to find the minimum sum subarray.
            // currentMinSum is either the current element itself or the current element added to the previous currentMinSum.
            currentMinSum = min(currentMinSum + arr[i], arr[i]);
            // Update minSum with the smaller value between current minSum and currentMinSum.
            minSum = min(minSum, currentMinSum);
            
            // Accumulate the total sum of the array.
            totalSum += arr[i];
        }
            
        // The maximum sum can be either:
        // 1. The maximum sum of a non-circular subarray (normal Kadane's result).
        int normalSum = maxSum;
        
        // 2. The maximum sum of a circular subarray. This can be found by
        //    (total sum of array) - (minimum sum subarray).
        //    This is because if we remove the minimum sum subarray, the remaining
        //    elements form the maximum sum circular subarray.
        int circularSum = totalSum - minSum;
            
        // Edge case: If all numbers are negative, totalSum will be equal to minSum.
        // In this scenario, circularSum would be 0, which is incorrect if all numbers are negative.
        // For example, if arr = {-1, -2, -3}, totalSum = -6, minSum = -6. circularSum = 0.
        // However, the actual max sum is -1 (the largest single element).
        // In such a case, the normalSum (which would be the max single element) is the answer.
        if(totalSum == minSum){
            return normalSum;
        }
            
        // Return the maximum of the non-circular sum and the circular sum.
        return max(normalSum, circularSum);
    }
};
