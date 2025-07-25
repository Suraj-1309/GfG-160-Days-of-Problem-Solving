class Solution {
public:
    int maxProduct(std::vector<int> &arr) {
        // Initialize max_prod to the smallest possible integer value.
        // This ensures that any valid product found (even negative ones like in [-1, -2, -3])
        // will be greater than or equal to max_prod and correctly update it.
        int max_prod = std::numeric_limits<int>::min(); // Use std::numeric_limits for robustness

        // Get the size of the input array.
        int n = arr.size();

        // Initialize left_pro and right_pro to 1.
        // These variables will store the product of contiguous subarrays
        // encountered during the left-to-right and right-to-left traversals, respectively.
        // We start with 1 because 1 is the multiplicative identity.
        int left_pro = 1;
        int right_pro = 1;

        // Iterate through the array using a single loop for both traversals.
        // 'i' is used for the left-to-right pass.
        // 'n - i - 1' calculates the corresponding index for the right-to-left pass.
        for (int i = 0; i < n; i++) {
            // If left_pro becomes 0, it means a 0 was encountered in the array.
            // A 0 "breaks" any continuous product sequence. To start a new sequence
            // for elements after the 0, we reset left_pro to 1.
            // If we didn't reset, left_pro would remain 0, and subsequent products
            // would also be 0, potentially missing larger products.
            if (left_pro == 0) {
                left_pro = 1;
            }

            // Similarly, if right_pro becomes 0, reset it to 1.
            // This ensures that products are correctly calculated for subarrays
            // starting from the right and moving left, especially after encountering a 0.
            if (right_pro == 0) {
                right_pro = 1;
            }

            // Multiply left_pro by the current element from the left.
            // This continuously updates the product of the subarray ending at arr[i].
            left_pro *= arr[i];

            // Multiply right_pro by the current element from the right.
            // This continuously updates the product of the subarray ending at arr[n - i - 1].
            right_pro *= arr[n - i - 1];

            // Update max_prod with the maximum of:
            // 1. The current product from the left (left_pro)
            // 2. The current product from the right (right_pro)
            // 3. The previously stored maximum product (max_prod)
            // This step ensures that we capture the maximum product subarray,
            // regardless of whether it was found from the left or right pass,
            // or if it was already updated in a previous iteration.
            max_prod = std::max({left_pro, right_pro, max_prod});
        }

        // After iterating through the entire array, max_prod will hold the maximum product
        // of any contiguous subarray.
        return max_prod;
    }
};
