# Day 3 – Reverse an Array

---

## 🔍 Problem Statement

Given an array of integers ````arr```` of size `n`, write a function to reverse the array **in-place**. That means you should not use extra space for another array. The original array should be modified to be reversed.

### ✅ Input
An array of integers.

### ✅ Output
The same array with its elements in reversed order.

---

### 🧪 Examples

```text
Input: arr = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]

Input: arr = [10, 20]
Output: [20, 10]

Input: arr = [7]
Output: [7]

```

---

## 💡 Solution in C++

```cpp
// User function template for C++
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
};
```

## ⚙️ Complexity Analysis

__⏱️ Time Complexity: ```O(n)```__
We traverse half the array while swapping.

__📦 Space Complexity: ```O(1)```__
The reversal is done in-place without using extra space.

--- 

## 📌 Notes
This approach works for arrays of any size, including edge cases like empty arrays or arrays with one element.

The use of two pointers ```(low and high)``` helps efficiently reverse the array in-place.
