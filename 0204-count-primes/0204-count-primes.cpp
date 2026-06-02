class Solution {
public:
    int countPrimes(int n) {
        // If n is 0, 1, or 2, there are no primes strictly less than n
        if (n <= 2) return 0;
        
        // vector<bool> is internally optimized to occupy 1 bit per element
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        // Only loop up to sqrt(n) for marking composites
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                // Start marking from i * i
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Count the remaining unmarked numbers
        int primeCount = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primeCount++;
            }
        }
        
        return primeCount;
    }
};