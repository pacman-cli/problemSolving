class Solution {
    public void moveZeroes(int[] nums) {
        //solving using two pointer
        int n = nums.length;
        int j = 0; // pointer to place next non-zero element

        // Step 1: move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        // Step 2: fill the rest with zeros
        while (j < n) {
            nums[j] = 0;
            j++;
        }
    }
    }
