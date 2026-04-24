class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount = 0;      // Left moves ka count
        int rcount = 0;      // Right moves ka count
        int underscores = 0; // '_' (flexible) moves ka count

        //puro string ko ek baar scan karo
        for(char c : moves){
            if(c == 'L') lcount++; // Agar 'L' mile toh left counter badhao
            else if(c == 'R') rcount++; // Agar 'R' mile toh right counter badhao
            else underscores++; // Agar '_' mile toh isse baad mein use karenge
        }

        /* LOGIC: 
           1. abs(lcount - rcount) se humein fixed displacement milti hai.
           2. Max distance ke liye hum saare underscores ko usi direction mein 
              maan lete hain jidhar displacement pehle se zyada hai.
        */

        return abs(lcount - rcount) + underscores;
    }
};