# Day 6 – Majority Element II

---

## 🔍 Problem Statement

Given an integer array `arr` of size `n`, find all elements that appear **more than ⌊ n/3 ⌋ times**.

You must solve this in **O(n)** time and **O(1)** extra space.

This is an extension of the [Moore’s Voting Algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm) which is used to find the majority element occurring more than ⌊n/2⌋ times.

---

### ✅ Input

- An integer array `arr` of size `n`.

### ✅ Output

- A sorted list of all elements that appear more than `n/3` times.

---

### 🧪 Examples

**Input:** `arr = [3, 2, 3]`  
**Output:** `[3]`

**Input:** `arr = [1, 1, 1, 3, 3, 2, 2, 2]`  
**Output:** `[1, 2]`

**Input:** `arr = [1]`  
**Output:** `[1]`

---

## 💡 Solution in C++

```cpp
class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        vector<int> ans;
        
        // Step 1: Find candidates using extended Moore's Voting
        int ele1 = 0, ele2 = 0;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (count1 == 0 && arr[i] != ele2) {
                ele1 = arr[i];
                count1 = 1;
            } else if (count2 == 0 && arr[i] != ele1) {
                ele2 = arr[i];
                count2 = 1;
            } else if (arr[i] == ele1) {
                count1++;
            } else if (arr[i] == ele2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify the candidates
        count1 = 0, count2 = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == ele1) count1++;
            else if (arr[i] == ele2) count2++;
        }

        int threshold = arr.size() / 3 + 1;
        if (count1 >= threshold) ans.push_back(ele1);
        if (count2 >= threshold) ans.push_back(ele2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};


```

---

## ⚙️ Complexity Analysis
__⏱️ Time Complexity: ```O(n)```__
The algorithm runs two linear scans: one to find candidates and another to verify them.

__📦 Space Complexity: ```O(1)```__
Only a fixed number of variables are used regardless of input size.
