# Day 11 – Maximum Product Subarray

---

## 🔍 Problem Statement

Given an integer array `arr`, find a contiguous non-empty subarray that has the **largest product**, and return the product.

A **subarray** is a contiguous part of an array.

> 💡 Note: It is guaranteed that the answer fits in a 32-bit integer.

---

### ✅ Input

- An integer array `arr` of size `n`.

### ✅ Output

- An integer representing the maximum product of any contiguous subarray.

---

### 🧪 Examples

```text

Input: arr = [2, 3, -2, 4]
Output: 6
Explanation: The subarray [2, 3] has the largest product 6.

Input: arr = [-2, 0, -1]
Output: 0
Explanation: The subarray [0] has the largest product 0.

Input: arr = [-1, -2, -9, -6]
Output: 108
Explanation: The subarray [-1, -2, -9, -6] has the largest product 108.

```

---

## 💡 Solution in C++

```cpp
class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int max_prod = INT_MIN;
        int n = arr.size();

        int left_pro = 1, right_pro = 1;

        for (int i = 0; i < n; i++) {
            if (left_pro == 0) left_pro = 1;
            if (right_pro == 0) right_pro = 1;

            left_pro *= arr[i];
            right_pro *= arr[n - i - 1];

            max_prod = max({max_prod, left_pro, right_pro});
        }

        return max_prod;
    }
};

```
---

## ⚙️ Complexity Analysis
__⏱️ Time Complexity:__  ``O(n)`` 

Only a single traversal of the array is needed.

__📦 Space Complexity:__ ``O(1)``

Constant extra space is used — no additional data structures.


---

### 🧠 Explanation

#### Dual-Directional Traversal:

- `left_pro`: Tracks the product from **left to right**.
- `right_pro`: Tracks the product from **right to left**.
- This two-way scan handles **negative numbers** and **zeros** more effectively than a single-direction pass.

---

#### Handling Zeros:

- If the current product becomes `0`, it's reset to `1` for the next iteration.
- This allows starting a new subarray immediately after a zero, ensuring segments before and after zeros are considered independently.

---

#### Why Both Directions?

- In cases with an **odd number of negative numbers**, the maximum product may not include all elements.
- Scanning from both directions ensures the algorithm captures the **largest possible product**, regardless of where the subarray begins or ends.

---

## 📌 Edge Cases

- ✅ **Single element array** – Automatically returns that element.
- ✅ **Array with multiple zeros** – Each segment is considered individually.
- ✅ **All negative numbers** – If the count is even, product is positive; if odd, one negative may be excluded.
- ✅ **Mixed positive and negative numbers** – Handled smoothly by continuous product tracking.

---

This algorithm is both **efficient** and **robust**, using a smart two-directional scan to reliably compute the maximum product subarray in linear time with constant space.
