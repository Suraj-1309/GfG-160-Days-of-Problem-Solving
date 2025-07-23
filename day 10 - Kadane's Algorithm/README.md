# Day 10 – Kadane's Algorithm

---

## 🔍 Problem Statement

Given an integer array `arr[]` of size `n`, find the **maximum sum of a contiguous subarray** within the array.

This is a classic problem solved using **Kadane's Algorithm**, which runs in linear time.

---

### ✅ Input

- An integer array `arr` of size `n`.

### ✅ Output

- An integer representing the maximum sum of any contiguous subarray.

---

### 🧪 Examples

**Input:** `arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`  
**Output:** `6`  
**Explanation:** The subarray `[4, -1, 2, 1]` has the maximum sum = 6.

**Input:** `arr = [1]`  
**Output:** `1`

**Input:** `arr = [5, 4, -1, 7, 8]`  
**Output:** `23`

---

## 💡 Approach (Kadane’s Algorithm)

1. Start with the first element as both `currentSum` and `maxSum`.
2. Traverse the array from index 1:
   - If adding the current element to `currentSum` gives a larger sum than the current element itself, keep adding.
   - Otherwise, start a new subarray from the current element.
3. At each step, update `maxSum` with the highest sum found so far.

---

## 💡 Solution in C++

```cpp
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int currentSum = arr[0], maxSum = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            // Update currentSum: either extend the previous subarray or start new
            currentSum = max(arr[i], currentSum + arr[i]);
            
            // Update maxSum if currentSum is greater
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};


```

---

## 📘 Explanation

- **Extend or Restart:** At each index, decide whether to extend the previous subarray or start fresh.
- **Track Maximum:** Maintain a global `maxSum` that keeps track of the highest subarray sum encountered so far.

---

## ⚙️ Complexity Analysis

**⏱️ Time Complexity:** `O(n)`  
Single pass through the array.

**📦 Space Complexity:** `O(1)`  
Constant extra space used for tracking sums.
