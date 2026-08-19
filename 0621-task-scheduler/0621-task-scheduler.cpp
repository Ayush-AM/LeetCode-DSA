class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequencies
        unordered_map<char, int> freq;
        for (char task : tasks) freq[task]++;
        
        // Step 2: Max-heap of frequencies
        priority_queue<int> maxHeap;
        for (auto& [task, count] : freq) {
            maxHeap.push(count);
        }
        
        // Step 3: Process tasks
        int cycles = 0;
        queue<pair<int, int>> cooldown; // {remaining_count, available_time}
        
        while (!maxHeap.empty() || !cooldown.empty()) {
            cycles++;
            
            // Check if any task is available
            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                count--;
                
                // If task still has remaining count, put in cooldown
                if (count > 0) {
                    cooldown.push({count, cycles + n});
                }
            }
            
            // Release tasks from cooldown
            if (!cooldown.empty() && cooldown.front().second == cycles) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        
        return cycles;
    }
};