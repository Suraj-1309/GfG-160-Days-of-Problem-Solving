class Solution {
  public:
  
    void nextPermutation(vector<int>& A) {
        // code here
        
        // finding the pivot of the array where a[i] < a[i + 1]
        int pivot = -1 , n = A.size();
        
        for(int i = n-2; i >= 0;i--){
            if(A[i] < A[i + 1]){
                pivot = i;
                break;
            }
        }
        // if the permutation at it's end make the array sort
        if(pivot == -1){
            reverse(A.begin(), A.end());
            return;
        }
        
        // 2 step : next larger element
        // swapping the pivot with next greatest element
        for(int i = n - 1;i > pivot;i--){
            if(A[i] > A[pivot]){
                swap(A[i], A[pivot]);
                break;
            }
        }
        
        // 3 step : reverse from pivot + 1 to n - 1
        int low = pivot + 1, high = n - 1;
        while( low <= high){
            swap(A[low] , A[high]);
            low++;
            high--;
        }
    }
};
