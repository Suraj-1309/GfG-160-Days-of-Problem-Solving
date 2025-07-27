# Day 13 – Smallest Positive Missing Number

---

## 🔍 Problem Statement

Given an unsorted integer array `arr`, find the **smallest positive integer** that is **missing** from the array.

You must solve it in **O(n)** time and use **O(1)** extra space (i.e., in-place solution is required).

---

### ✅ Input

- An integer array `arr` of size `n` (may contain negative numbers, zeros, and duplicates).

### ✅ Output

- The smallest positive integer that is missing from the array.

---

### 🧪 Examples

```text

Input: arr = [1, 2, 3, 5]
Output: 4

Input: arr = [0, -10, 1, 3, -20]
Output: 2

Input: arr = [2, 3, 7, 6, 8, -1, -10, 15]
Output: 1


```


---

## 💡 Solution in C++

```cpp
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        // Place each positive number at its correct index
        for (int i = 0; i < n; i++) {
            while ((arr[i] > 0 && arr[i] < n) && (arr[i] != arr[arr[i] - 1])) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        // Find the first place where index doesn't match value
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        // All numbers 1..n are present
        return n + 1;
    }
};


```

---

## ⚙️ Complexity Analysis

- **⏱️ Time Complexity:** `O(n)`  
  Every element is swapped at most once, resulting in linear time.

- **📦 Space Complexity:** `O(1)`  
  The array is modified in-place with no additional space.

---

## 🧠 Explanation

This approach is a variation of **cyclic sort**, and works as follows:

- **🎯 Goal:**  
  Place each number `x` (where `1 ≤ x ≤ n`) at its correct index `x - 1`.

- **🔄 In-place Swapping:**  
  If `arr[i]` is in the valid range and not already in its correct position,  
  swap it with the element at index `arr[i] - 1`.

- **❓ Missing Positive:**  
  After rearrangement, the first index `i` where `arr[i] != i + 1`  
  indicates that `i + 1` is the smallest missing positive number.  
  If all elements are in the correct positions, return `n + 1`.

✅ This method is efficient and avoids using extra space like hash sets.

---

## 📌 Edge Cases

- ✅ **Array contains negatives and zeros** – Ignored by the logic.
- ✅ **All positive numbers present from 1 to n** – Return `n + 1`.
- ✅ **Duplicate values** – Doesn’t affect correctness due to index checks.
- ✅ **Smallest missing number is 1** – Handled by the final scan.
