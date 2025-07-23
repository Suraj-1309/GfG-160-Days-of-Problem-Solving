// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...

      //variables to store sum of current subarray and maximum sum of subarray
        int currentSum = arr[0], maxSum = arr[0];


        for(int i = 1;i < arr.size();i++){
          //if new element could be added in current subarray add
            if(currentSum + arr[i] > arr[i]){
                currentSum += arr[i];
            }
              // else start a new subarray
            else{
                currentSum = arr[i];
            }

          // if current subarray have big sum than previous one exchange it
            if(maxSum < currentSum){
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
};
