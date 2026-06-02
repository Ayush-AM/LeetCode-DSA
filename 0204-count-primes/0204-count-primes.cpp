class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // Since we only track odd numbers, we need a bitset size of n / 2.
        // Using 64-bit integers (uint64_t) allows us to pack 64 numbers per element.
        int bitsetSize = (n >> 1);
        vector<uint64_t> isComposite((bitsetSize >> 6) + 1, 0);
        
        // 2 is prime. Start counting from 1.
        int primeCount = 1; 
        
        // Loop through odd numbers starting from 3 up to sqrt(n)
        for (int i = 3; i * i < n; i += 2) {
            // i >> 1 maps the odd number 'i' to its bit index
            int bitIdx = i >> 1;
            
            // Check if the bit is 0 (which means it's prime)
            if (!(isComposite[bitIdx >> 6] & (1ULL << (bitIdx & 63)))) {
                // Mark all odd multiples of i starting from i * i
                for (int j = i * i; j < n; j += (i << 1)) {
                    int compIdx = j >> 1;
                    isComposite[compIdx >> 6] |= (1ULL << (compIdx & 63));
                }
            }
        }
        
        // Count remaining odd numbers that are prime
        for (int i = 3; i < n; i += 2) {
            int bitIdx = i >> 1;
            if (!(isComposite[bitIdx >> 6] & (1ULL << (bitIdx & 63)))) {
                primeCount++;
            }
        }
        
        return primeCount;
    }
};