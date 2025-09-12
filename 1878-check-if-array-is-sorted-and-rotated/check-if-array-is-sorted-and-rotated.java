class Solution {
    public boolean check(int[] nums) {
        int n=nums.length;
        int count=0;
        for(int i =0; i<n;i++){
            // Compare current element with the next (wrap around using %)
            if(nums[i] > nums[(i+1) % n]){
                count++;
            }
        }
        return count<=1;
    }
}