class Solution {
public:

    void backtrack(int idx, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result){
        // target is 0  then starting elemet is the only option = current
        if(target == 0) {
            result.push_back(current);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;

            current.push_back(candidates[i]);
            backtrack(i+1, target - candidates[i], candidates, current, result);
            current.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sorting to eleminate duplicates combinations
        sort(candidates.begin(), candidates.end());
        //storing the 2d result
        vector<vector<int>> result;
        //pointing to current
        vector<int> current;
        //backtrack to find sum of elements
        backtrack(0,target,candidates,current,result);
        return result; 
    }
};