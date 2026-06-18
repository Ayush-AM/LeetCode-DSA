class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } 
            else if (bill == 10) {
                if (five == 0) return false; // \$5 bill nahi hai toh change nahi de sakte
                five--;
                ten++;
            } 
            else { // bill == 20
                // Greedy choice: Pehle $10 aur $5 dene ki koshish karo
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                // Agar $10 nahi hai, toh teen $5 ke bills do
                else if (five >= 3) {
                    five -= 3;
                } 
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};