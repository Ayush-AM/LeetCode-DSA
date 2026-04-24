class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount = 0;
        int rcount = 0;
        int underscores = 0;

        for(char c : moves){
            if(c == 'L') lcount++;
            else if(c == 'R') rcount++;
            else underscores++;
        }

        return abs(lcount - rcount) + underscores;
    }
};