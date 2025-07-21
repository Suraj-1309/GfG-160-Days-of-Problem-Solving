# Day 8 – Stock Buy and Sell (Max One Transaction Allowed)

---

## 🔍 Problem Statement

You are given an array `prices` where `prices[i]` represents the stock price on the `i-th` day.

You are allowed to make **only one transaction** — buy once and sell once.  
Your goal is to **maximize the profit** from this transaction. If no profit is possible, return `0`.

You must solve this in **O(n)** time and **O(1)** space.

---

### ✅ Input

- An integer array `prices` of size `n`.

### ✅ Output

- An integer representing the maximum profit that can be made with at most one transaction.

---

### 🧪 Examples

**Input:** `prices = [7, 1, 5, 3, 6, 4]`  
**Output:** `5`  
**Explanation:** Buy on day 2 (price = 1), sell on day 5 (price = 6), profit = 5.

**Input:** `prices = [7, 6, 4, 3, 1]`  
**Output:** `0`  
**Explanation:** No profit can be made as the price only decreases.

**Input:** `prices = [2, 4, 1]`  
**Output:** `2`  
**Explanation:** Buy on day 1 (price = 2), sell on day 2 (price = 4), profit = 2.

---

## 💡 Solution in C++

```cpp
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0; // Maximum profit tracker
        int buy = prices[0]; // Minimum price to buy stock initially
        
        for (int i = 1; i < prices.size(); i++) {
            // Update profit if selling today gives a better profit
            if (prices[i] > buy && (profit < prices[i] - buy)) {
                profit = prices[i] - buy;
            }

            // Update the buying price if current price is lower
            if (prices[i] < buy) {
                buy = prices[i];
            }
        }

        return profit;
    }
};


```

---

## ⚙️ Complexity Analysis
__⏱️ Time Complexity: ```O(n)```__
A single pass through the array to find the minimum buy and maximum sell opportunity.

__📦 Space Complexity: ```O(1)```__
Only a few variables are used, no extra memory is allocated.
