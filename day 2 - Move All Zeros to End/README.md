# Day 2 – Move All Zeros to End

---

## 🔍 Problem Statement

Given an array of integers arr of size n, write a function to move all zeros in the array to the end while maintaining the relative order of the non-zero elements. You must modify the array in-place and use O(1) extra space.

__Input__: An array of integers containing zero and non-zero values.

__Output__: The same array with all zeros moved to the end.

Example

```text
Input:  arr = [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
Explanation: All non-zero elements retain their order, zeros are shifted to the end.

Input:  arr = [1, 2, 3, 0]
Output: [1, 2, 3, 0]
Explanation: Only one zero at the end already.

Input:  arr = [0, 0, 0]
Output: [0, 0, 0]
Explanation: All elements are zero.

```

---

## Your Solution in C++

```code
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int low = 0 , high = 0;
        while(high < arr.size()){
            if(arr[low] != 0 and arr[high] != 0){
                low++;
                high++;
            }
            else if(arr[low] == 0 and arr[high] != 0){
                swap(arr[low], arr[high]);
                low++;
            }
            else{
                high++;
            }
        }
    }
};
```

---

## Complexities:

**⏱️ Time: O(n)** 

**📦 Space: O(1)**
