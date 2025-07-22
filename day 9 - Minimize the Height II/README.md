# Day 9 – Minimize the Heights II

---

## 🔍 Problem Statement

Given an array `arr[]` representing the heights of `n` towers and an integer `k`, you can increase or decrease the height of every tower by **at most `k`** (only once).

The task is to **minimize the difference** between the maximum and minimum heights after the modification, and return this minimum difference.

You must ensure **no height becomes negative** after modification.

---

### ✅ Input

- An integer array `arr` of size `n` representing tower heights.
- An integer `k` representing the maximum modification allowed per tower.

### ✅ Output

- Return the minimum possible difference between the tallest and shortest tower heights after modification.

---

### 🧪 Examples

**Input:** `arr = [1, 5, 8, 10], k = 2`  
**Output:** `5`  
**Explanation:** Modify the array to `[3, 3, 6, 8]`. Maximum difference is `8 - 3 = 5`.

**Input:** `arr = [3, 9, 12, 16, 20], k = 3`  
**Output:** `11`  
**Explanation:** Modified array can be `[6, 6, 9, 13, 17]`. Max difference = `17 - 6 = 11`.

---

## 💡 Approach

__1. Sort the Array:__ Sorting helps to handle the smallest and largest elements systematically. <br>
__2. Initial Difference:__ Calculate the initial difference between the tallest and shortest towers before any operations.<br>
__3. Iterate and Adjust Heights:__ For each tower, calculate the new possible heights after either increasing or decreasing by K. Ensure that no height becomes negative.<br>
__4. Minimize the Difference:__ While iterating, we compute the difference between the maximum and minimum tower heights after the operation and keep track of the minimum possible difference.<br>


### Key Points:
We have to add or subtract K from each element.<br>
After sorting, the minimum difference will depend on the difference between the largest and smallest possible heights after the operations.

---

## 💡 Solution in C++

```cpp
class Solution {
public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;  // Only one tower

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Initial max difference
        int result = arr[n - 1] - arr[0];

        // Step 3: Set baseline for smallest and largest
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        // Step 4: Traverse and minimize the difference
        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);

            if (minHeight < 0) continue;

            result = min(result, maxHeight - minHeight);
        }

        return result;
    }
};


```

---

## 📘 Explanation

- **Initial Difference:** Start with the difference between the tallest and shortest tower before any changes.
- **Adjust Heights:** For each tower, check the impact of adding or subtracting `k`.
- **Skip Invalids:** Ensure no height becomes negative during the operation.
- **Update Result:** Keep updating the minimum difference found so far during traversal.

---

## ⚙️ Complexity Analysis

**⏱️ Time Complexity:** `O(n log n)`  
Sorting the array takes `O(n log n)`, and the linear pass takes `O(n)`.

**📦 Space Complexity:** `O(1)`  
No extra space used other than a few variables.

