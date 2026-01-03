class Solution {
    public int singleNumber(int[] nums) {
        int number =0;
        for(int n: nums){
            //apply XOR operation
            number ^=n;
        }
        return number;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {4,1,2,1,2};
        System.out.println("The single number is: " + sol
        .singleNumber(nums)); // Output: 4
    }
}