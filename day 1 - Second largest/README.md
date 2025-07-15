# 📘 Day 1 – Second Largest

---

## 🔍 Problem Statement

Given an array of positive integers `arr` of size `n`, find the **second largest distinct** element in the array.

- If it exists, return its value.  
- If it does not exist (i.e., all elements are equal or there's only one unique value), return `-1`.

**Examples**

```text
Input: arr = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest is 35, the second largest distinct is 34.

Input: arr = [10, 5, 10]
Output: 5
Explanation: The largest is 10, the next distinct value is 5.

Input: arr = [10, 10, 10]
Output: -1
Explanation: Only one distinct value exists.

```
---

## Your Solution in C++
the code I came up with 
```code
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int lar = -1, sec_lar = -1;
        for (int x : arr) {
            if (x > lar) {
                sec_lar = lar;
                lar = x;
            }
            else if (x > sec_lar && x < lar) {
                sec_lar = x;
            }
        }
        return sec_lar;
    }
};
```

## Explanation
__Initialization:__

```lar``` (largest) and ```sec_lar``` (second largest) are both initialized to ```-1```.

__Single pass logic:__

__1.__ If the current element ```x``` is __greater than__ ```lar```:

* Update ```sec_lar = lar```

* Update ```lar = x```

__2.__ Else if ```x``` is __less than__ ```lar``` but __greater than__ ```sec_lar```:

* Update ```sec_lar = x```

This ensures we efficiently track the two highest __distinct__ values in one traversal of the array.

## Complexities:

**⏱️ Time: O(n)** 

**📦 Space: O(1)**


##  Edge Cases
* When the array has fewer than two __distinct__ elements, ```sec_lar``` remains ```-1```.

* Works even with repeated occurrences of the largest element.
