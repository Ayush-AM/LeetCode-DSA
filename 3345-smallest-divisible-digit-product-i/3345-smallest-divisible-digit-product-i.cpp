class Solution {
public:
    int smallestNumber(int n, int t) {
        int original = n;
        
        while (true) {
            int mul = 1;
            int num = original;  // using a temp variable to not lose original
            
            while (num > 0) {
                int digits = num % 10;
                mul = mul * digits;
                num = num / 10;
            }
            
            if (mul % t == 0) {
                return original;
            }
            
            original++;  // try the next number
        }
    }
};