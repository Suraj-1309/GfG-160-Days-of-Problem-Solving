# Day 5 – Next Permutation

---

## 🔍 Problem Statement

Given an array of size `n`, find the **next lexicographically greater permutation** of the array. If no such permutation exists (i.e., the array is the last permutation), rearrange it to the lowest possible order (i.e., sorted in ascending order).

You must perform the rearrangement **in-place**, using **`O(1)`** extra space.

---

### ✅ Input

- An integer array `arr` of size `n`.

### ✅ Output

- The same array rearranged into the next permutation in lexicographic order.

---

### 🧪 Examples

**Input:**  `arr = [1, 2, 3]`  
**Output:**  `[1, 3, 2]`

**Input:**  `arr = [3, 2, 1]`  
**Output:**  `[1, 2, 3]`

**Input:**  `arr = [1, 1, 5]`  
**Output:**  `[1, 5, 1]`

---

## 💡 Solution in C++

```cpp
class Solution {
  public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int pivot = -1;

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot, array is in descending order
        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find element just greater than A[pivot]
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 4: Reverse suffix starting from pivot + 1
        int low = pivot + 1, high = n - 1;
        while (low < high) {
            swap(A[low], A[high]);
            low++;
            high--;
        }
    }
}; ```

---

## ⚙️ Complexity Analysis
__⏱️ Time Complexity: ```O(n)```__
Each step involves a single pass over the array.

__📦 Space Complexity: ```O(1)```__
Rearrangement is done in-place with no extra memory used.

