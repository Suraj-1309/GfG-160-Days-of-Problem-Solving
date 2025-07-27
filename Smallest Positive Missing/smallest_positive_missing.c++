class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // Get the size of the array.
        int n = arr.size();

        // This loop uses the Cyclic Sort pattern to place each number
        // at its correct 0-indexed position (i.e., number 'k' should be at index 'k-1').
        // It iterates through the array.
        for (int i = 0; i < n; i++) {
            // While the current number `arr[i]` is:
            // 1. Positive (numbers outside the range [1, n] are ignored for sorting).
            // 2. Within the valid range [1, n] (since we are looking for a missing number
            //    in this range, and 'n' elements imply numbers from 1 to 'n' if no missing).
            // 3. Not already in its correct position (i.e., `arr[i]` should be `i + 1`,
            //    but we check `arr[i] != arr[arr[i] - 1]` to ensure the target position
            //    doesn't already have the correct number to avoid infinite swaps if duplicates existed,
            //    though this problem typically implies unique numbers for 'missing number').
            while ((arr[i] > 0 && arr[i] <= n) && (arr[i] != arr[arr[i] - 1])) {
                // Swap the current number with the number at its intended position.
                // For example, if arr[i] is 3, it should go to index 2 (arr[3-1]).
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // After the cyclic sort, iterate through the array again.
        // The first index `i` where `arr[i]` is not equal to `i + 1`
        // indicates that `i + 1` is the missing number.
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1; // Found the missing positive number.
            }
        }

        // If all numbers from 1 to 'n' are present in their correct positions,
        // it means the missing number is 'n + 1'. This applies when the input
        // array contains all numbers from 1 to 'n'.
        return n + 1;
    }
};
