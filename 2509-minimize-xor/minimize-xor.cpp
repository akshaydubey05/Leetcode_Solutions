
class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }

    int minimizeXor1(int num1, int num2) {
        int setBits = countSetBits(num2);
        int x = 0;

        // Start from the most significant bit and try to set bits
        for (int i = 31; i >= 0; --i) {
            // Check if we can set the i-th bit
            if (setBits > 0 && (num1 & (1 << i))) {
                x |= (1 << i); // Set the bit in x
                setBits--; // Decrease the count of set bits needed
            }
        }

        // If we still need to set more bits, set the lowest bits
        for (int i = 0; i < 32 && setBits > 0; ++i) {
            if (!(x & (1 << i))) { // If the i-th bit is not set
                x |= (1 << i); // Set the i-th bit
                setBits--; // Decrease the count of set bits needed
            }
        }
        return x;
    }
    int minimizeXor(int num1, int num2) {
        return minimizeXor1(num1,num2);
    }
};