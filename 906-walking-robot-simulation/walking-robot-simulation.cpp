#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors: North, East, South, West
        // North: (0, 1), East: (1, 0), South: (0, -1), West: (-1, 0)
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Use a set of pairs to store obstacles for fast lookup
        // Note: For very large coordinates, you might hash (x, y) into a long long
        set<pair<int, int>> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        int x = 0, y = 0, direction = 0; // Start at (0,0) facing North (index 0)
        int maxDistSq = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                // Turn left: (direction + 3) % 4
                direction = (direction + 3) % 4;
            } else if (cmd == -1) {
                // Turn right: (direction + 1) % 4
                direction = (direction + 1) % 4;
            } else {
                // Move forward k units step by step
                for (int i = 0; i < cmd; ++i) {
                    int nextX = x + dx[direction];
                    int nextY = y + dy[direction];
                    
                    // Check if the next step is an obstacle
                    if (obstacleSet.find({nextX, nextY}) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        // Update maximum squared Euclidean distance
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        // Hit an obstacle, stop moving for this command
                        break;
                    }
                }
            }
        }
        
        return maxDistSq;
    }
};