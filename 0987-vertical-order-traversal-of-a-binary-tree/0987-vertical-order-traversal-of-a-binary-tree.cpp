/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;

        if(root == NULL) return ans;

        q.push({root, {0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int r = it.second.first;
            int c = it.second.second;

            mp[c][r].insert(node->val);
            if(node -> left){
                q.push({node->left, {r+1, c-1}});
            }
            if(node -> right){
                q.push({node->right, {r+1, c+1}});
            }
        }
        for(auto a: mp){
            vector<int> temp;
            for(auto b: a.second){
                temp.insert(temp.end(), b.second.begin(), b.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};