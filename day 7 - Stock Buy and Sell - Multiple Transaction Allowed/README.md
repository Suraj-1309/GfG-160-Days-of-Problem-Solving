# Day 7 – Stock Buy and Sell – Multiple Transaction Allowed

---

## 🔍 Problem Statement

You are given an array `prices` where `prices[i]` represents the stock price on the `i-th` day. 

You can complete as many transactions as you like (i.e., buy and sell one share of the stock multiple times). However, you **must sell the stock before you buy again**.

Find the **maximum profit** you can achieve.

You must solve this in **O(n)** time and **O(1)** extra space.

---

### ✅ Input

- An integer array `prices` of size `n`.

### ✅ Output

- An integer representing the maximum profit achievable.

---

### 🧪 Examples

**Input:** `prices = [7, 1, 5, 3, 6, 4]`  
**Output:** `7`  
**Explanation:** Buy on day 2 (price=1), sell on day 3 (price=5), profit = 4. Then buy on day 4 (price=3), sell on day 5 (price=6), profit = 3. Total = 7.

**Input:** `prices = [1, 2, 3, 4, 5]`  
**Output:** `4`  
**Explanation:** You can buy and sell each day, total profit = 4.

**Input:** `prices = [7, 6, 4, 3, 1]`  
**Output:** `0`  
**Explanation:** No transactions are done since the price always goes down.

---

## 💡 Solution in C++

```cpp
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int res = 0;

        // Accumulate profit where next day's price is higher
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }

        return res;
    }
};


```

---

## ⚙️ Complexity Analysis
__⏱️ Time Complexity: ```O(n)```__
Single pass through the array to compute profit.

__📦 Space Complexity: ```O(1)```__
Only a few variables are used for calculations, no extra memory required.


