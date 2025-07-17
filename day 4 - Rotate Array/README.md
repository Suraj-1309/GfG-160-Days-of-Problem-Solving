# Day 4 – Rotate Array

---

## 🔍 Problem Statement

Given an array of size ```n``` and an integer ```d```, rotate the array in the counter-clockwise direction by ```d``` elements.

You must perform the rotation **in-place**, using __```O(1)```__ extra space.

---

### ✅ Input

- An integer array `arr` of size `n`.
- An integer `d` representing the number of positions to rotate.

### ✅ Output

- The same array after rotating it to the left by `d` positions.

---

### 🧪 Examples

__Input:__ arr = [1, 2, 3, 4, 5], d = 2 <br/>
__Output:__ [3, 4, 5, 1, 2]

__Input:__ arr = [10, 20, 30, 40], d = 1  <br/>
__Output:__ [20, 30, 40, 10]

__Input:___ arr = [1], d = 3 <br/>
__Output:__ [1]

---

## 💡 Solution in C++

```cpp
// User function template for C++
class Solution {
  public:
    void reverseArr(vector<int>& arr, int low, int high) {
        while (low < high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        d = d % arr.size();  // To handle d > n
        
        reverseArr(arr, 0, d - 1);              // Reverse first d elements
        reverseArr(arr, d, arr.size() - 1);     // Reverse the remaining elements
        reverseArr(arr, 0, arr.size() - 1);     // Reverse the whole array
    }
};

```

--- 

## ⚙️ Complexity Analysis
__⏱️ Time Complexity: ```O(n)```__
Each reversal is linear in time, and we do three of them.

__📦 Space Complexity: ```O(1)```__
Rotation is done in-place with no extra memory.

