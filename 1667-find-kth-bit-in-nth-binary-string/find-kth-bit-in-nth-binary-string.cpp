class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';  // Base case: S1 is "0"
        }

        int len = (1 << n) - 1;  // Length of Sn is 2^n - 1
        int mid = len / 2 + 1;   // Middle position

        if (k == mid) {
            return '1';  // The middle bit is always '1'
        } else if (k < mid) {
            return findKthBit(n - 1, k);  // Check in the left half (Sn-1)
        } else {
            // Check in the right half (reverse(invert(Sn-1)))
            int mirrorK = len - k + 1;
            char mirroredBit = findKthBit(n - 1, mirrorK);
            return mirroredBit == '0' ? '1' : '0';  // Invert the mirrored bit
        }
    }
};