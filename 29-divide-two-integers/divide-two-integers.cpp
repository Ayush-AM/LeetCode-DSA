class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: Overflow handling
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the quotient
        // True if the result should be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both numbers to negative to avoid INT_MIN overflow when taking abs()
        // e.g., abs(-2147483648) overflows a 32-bit signed int
        int a = dividend < 0 ? dividend : -dividend;
        int b = divisor < 0 ? divisor : -divisor;

        int quotient = 0;

        // Perform bitwise long division
        // Since 'a' and 'b' are negative, "a <= b" means |a| >= |b|
        while (a <= b) {
            int shift = 0;
            // Guard against bit-shifting overflow (b << 1 can overflow)
            // also ensures we don't overshoot 'a'
            while (b >= (INT_MIN >> 1) && a <= (b << 1)) {
                b <<= 1;
                shift++;
            }

            // Add the power of 2 to the quotient
            quotient += (1 << shift);
            
            // Subtract the shifted divisor from dividend
            a -= b;

            // Reset 'b' back to the original divisor value for the next iteration
            b = divisor < 0 ? divisor : -divisor;
        }

        return isNegative ? -quotient : quotient;
    }
};