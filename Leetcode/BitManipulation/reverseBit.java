class ReverseBitSolution {
    public int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            // Shift result to the left to make space for the next bit
            result = (result << 1) | (n & 1); // Add the last bit of n to result
            // Shift n to the right to process the next bit.
            n >>= 1;
        }
        return result;
    }
}
