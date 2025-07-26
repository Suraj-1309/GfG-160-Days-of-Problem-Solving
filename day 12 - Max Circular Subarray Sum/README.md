# Day 12 – Maximum Circular Subarray Sum

---

## 🔍 Problem Statement

Given a **circular** integer array `arr`, find the maximum possible sum of a **non-empty subarray** of `arr`.

A circular array means that the end of the array connects back to the beginning. The subarray may only include each element at most once.

Return the **maximum sum** possible for any non-empty subarray (circular or non-circular).

---

### ✅ Input

- An integer array `arr` of size `n`.

### ✅ Output

- An integer representing the maximum possible subarray sum (considering circular wrapping).

---

### 🧪 Examples

```text

Input: arr = [1, -2, 3, -2]
Output: 3
Explanation: The subarray [3] has the maximum sum.

Input: arr = [5, -3, 5]
Output: 10
Explanation: The subarray [5, ..., 5] wrapping around has the maximum sum.

Input: arr = [-3, -2, -3]
Output: -2
Explanation: All numbers are negative. Max subarray is [-2].

```

---


## 💡 Solution in C++

```cpp
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        int currentMaxSum = 0, currentMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];
        
        for (int i = 0; i < arr.size(); i++) {
            currentMaxSum = max(currentMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currentMaxSum);
            
            currentMinSum = min(currentMinSum + arr[i], arr[i]);
            minSum = min(minSum, currentMinSum);
            
            totalSum += arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;

        // Edge case: if all numbers are negative
        if (totalSum == minSum) {
            return normalSum;
        }

        return max(normalSum, circularSum);
    }
};


```

---

## ⚙️ Complexity Analysis

- **⏱️ Time Complexity:** `O(n)`  
  A single pass is made through the array to compute:
  - Maximum subarray sum using Kadane's Algorithm.
  - Minimum subarray sum.
  - Total sum of the array.

- **📦 Space Complexity:** `O(1)`  
  The algorithm uses a constant amount of space, requiring only a few tracking variables.

---

## 🧠 Explanation

This problem is an extension of **Kadane's Algorithm** and requires handling two scenarios:

### 1. Normal Subarray (No Wrap-around)

- Use standard Kadane’s Algorithm to find the **maximum subarray sum** (`normalSum`).
- This is the max subarray that lies **entirely within** the array without wrapping.

### 2. Circular Subarray (Wrap-around)

- The **maximum circular sum** can be computed as:
circularSum = totalSum - minSubarraySum

markdown
Copy
Edit
- Why? Because if the subarray with the **minimum sum** is removed from the total, the remaining elements **wrap around**, giving the max circular sum.

---

## ⚠️ Special Case

- If **all elements are negative**, then:
- `totalSum == minSubarraySum`
- This means `circularSum` becomes `0`, which is invalid.
- In this case, we must **return the maximum single element**, which is already captured as `normalSum`.

```cpp
if (totalSum == minSum) return normalSum;


```

## 📌 Edge Cases

- ✅ **All positive numbers** – Both normal and circular sum will be equal and valid.

- ✅ **All negative numbers** – Only one element (the maximum one) should be returned, since wrapping would result in an invalid sum.

- ✅ **Mixed positive and negative numbers** – Both normal and circular subarray paths are evaluated, and the maximum is chosen.

- ✅ **Maximum sum involves wrapping** – The `circularSum` path (totalSum - minSubarraySum) correctly identifies such cases where the max sum is achieved by wrapping around the array.

